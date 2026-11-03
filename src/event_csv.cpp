#include "clubhub/event_csv.hpp"

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace clubhub {

EventLoadResult loadEventsCsv(std::istream& in) {
    EventLoadResult result;
    std::string line;
    int lineNo = 1;
    std::getline(in, line);
    while (std::getline(in, line)) {
        ++lineNo;

        if (!line.empty() && line.back() == '\r') line.pop_back();

        std::istringstream row{line};
        std::vector<std::string> fields;
        std::string field;
        while (std::getline(row, field, ',')) {
            fields.push_back(field);
        }

        if (fields.size() != 5) {
            result.errors.push_back(
                {lineNo, "expected 5 fields but found " +
                             std::to_string(fields.size())});
            continue;
        }

        try {
            result.events.emplace_back(fields[0], fields[1],
                                       parseTimePoint(fields[2]), fields[3],
                                       std::stoi(fields[4]));
        } catch (const std::invalid_argument& e) {
            result.errors.push_back({lineNo, e.what()});
        } catch (const std::out_of_range&) {
            result.errors.push_back({lineNo, "capacity is too large"});
        }
    }
    return result;
}

} // namespace clubhub