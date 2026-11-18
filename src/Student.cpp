// src/Student.cpp
#include "clubhub/Student.h"

#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <utility>

namespace clubhub {

// With 3 characters or fewer, showing the first 2 and the last 1
// would reveal the whole ID, so short IDs are masked completely.
std::string maskId(std::string_view id) {
    if (id.size() <= 3) {
        return std::string(id.size(), '*');
    }
    std::string masked(id.substr(0, 2));
    masked.append(id.size() - 3, '*');
    masked.push_back(id.back());
    return masked;
}

Student::Student(std::string id, std::string name, std::string email)
    : id_(std::move(id)), name_(std::move(name)), email_(std::move(email)) {
    if (id_.empty()) {
        throw std::invalid_argument("student id must not be empty");
    }
    if (name_.empty()) {
        throw std::invalid_argument("student name must not be empty");
    }
    if (email_.find('@') == std::string::npos) {
        throw std::invalid_argument("email must contain '@'");
    }
}

void Student::giveSmsConsent(std::string phone) {
    const bool valid =
        !phone.empty() &&
        std::all_of(phone.begin(), phone.end(), [](unsigned char c) {
            return std::isdigit(c) || c == '+' || c == ' ';
        });
    if (!valid) {
        throw std::invalid_argument(
            "phone may contain only digits, '+' and spaces");
    }
    phone_ = std::move(phone);
}

void Student::withdrawSmsConsent() noexcept {
    phone_.reset();
}

void Student::setFacultyAndYear(std::string value) {
    if (value.empty()) {
        throw std::invalid_argument("faculty and year must not be empty");
    }
    facultyAndYear_ = std::move(value);
}

std::string Student::redacted() const {
    return "Student{id=" + maskId(id_) + "}";
}

}  // namespace clubhub