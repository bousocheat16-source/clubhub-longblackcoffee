#pragma once

#include <algorithm>
#include <chrono>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace clubhub {

enum class SyncState { Pending, Sent, Accepted, Rejected };

// One check-in recorded on an organiser's phone while offline.
struct QueuedCheckIn {
    std::string localId;   // UUID made on the device ensuring idempotency
    std::string deviceId;
    std::string eventId;
    std::string studentId;
    std::chrono::sys_seconds scannedAt; // device clock: relative order only; server validates against server time
    SyncState state = SyncState::Pending;
    int attempts = 0;
    std::optional<std::string> rejectReason;
};

class CheckInQueue {
public:
    // false if this student is already queued for this event
    bool enqueue(QueuedCheckIn item) {
        auto exists = std::any_of(items_.begin(), items_.end(), [&](const QueuedCheckIn& existing) {
            return existing.eventId == item.eventId &&
                   existing.studentId == item.studentId &&
                   existing.state != SyncState::Rejected;
        });
        if (exists) {
            return false;
        }
        item.state = SyncState::Pending;
        items_.push_back(std::move(item));
        return true;
    }

    // oldest first; what the next sync attempt uploads
    std::vector<QueuedCheckIn> pending() const {
        std::vector<QueuedCheckIn> result;
        for (const auto& item : items_) {
            if (item.state == SyncState::Pending) {
                result.push_back(item);
            }
        }
        return result;
    }

    void markAccepted(const std::string& localId) {
        for (auto& item : items_) {
            if (item.localId == localId) {
                item.state = SyncState::Accepted;
                item.rejectReason.reset();
                return;
            }
        }
    }

    void markRejected(const std::string& localId, std::string reason) {
        for (auto& item : items_) {
            if (item.localId == localId) {
                item.state = SyncState::Rejected;
                item.rejectReason = std::move(reason);
                return;
            }
        }
    }

private:
    std::vector<QueuedCheckIn> items_;
};

} // namespace clubhub