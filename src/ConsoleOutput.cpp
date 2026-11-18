// src/ConsoleOutput.cpp
// SPDX-License-Identifier: Apache-2.0
#include "clubhub/ConsoleOutput.h"

#include <cstdlib>
#include <string>
#include <string_view>

namespace clubhub {

std::string_view statusLabel(RegistrationStatus s) {
    switch (s) {
        case RegistrationStatus::Registered:
            return "REGISTERED";
        case RegistrationStatus::Cancelled:
            return "CANCELLED";
        case RegistrationStatus::CheckedIn:
            return "CHECKED IN";
        case RegistrationStatus::Waitlisted:
            return "WAITLISTED";
    }
    return "UNKNOWN";
}

bool colourEnabled(bool noColorFlag) {
    if (noColorFlag) {
        return false;
    }
    const char* noColorEnv = std::getenv("NO_COLOR");
    return noColorEnv == nullptr || noColorEnv[0] == '\0';
}

std::string formatStatus(RegistrationStatus s, bool colour) {
    std::string plain = "[" + std::string{statusLabel(s)} + "]";
    if (!colour) {
        return plain;
    }

    std::string_view ansiCode = "\033[0m";
    switch (s) {
        case RegistrationStatus::Registered:
        case RegistrationStatus::CheckedIn:
            ansiCode = "\033[32m";  // Green
            break;
        case RegistrationStatus::Cancelled:
            ansiCode = "\033[31m";  // Red
            break;
        case RegistrationStatus::Waitlisted:
            ansiCode = "\033[33m";  // Yellow
            break;
    }
    return std::string{ansiCode} + plain + "\033[0m";
}

std::string formatError(std::string_view what, std::string_view why,
                        std::string_view next) {
    std::string result = "Error: ";
    result += what;
    result += ": ";
    result += why;
    if (why.empty() || why.back() != '.') {
        result += '.';
    }
    result += "\nNext step: ";
    result += next;
    return result;
}

}
