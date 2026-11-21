// tests/ConsoleOutputTest.cpp
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team longblackcoffee, ITC Club Hub contributors
#include "clubhub/ConsoleOutput.h"

#include <gtest/gtest.h>
#include <string>

namespace clubhub {

TEST(ConsoleOutput, StatusIsReadableWithoutColour) {
    EXPECT_EQ(formatStatus(RegistrationStatus::Registered, false), "[REGISTERED]");
    EXPECT_EQ(formatStatus(RegistrationStatus::Cancelled, false), "[CANCELLED]");
    EXPECT_EQ(formatStatus(RegistrationStatus::CheckedIn, false), "[CHECKED IN]");
    EXPECT_EQ(formatStatus(RegistrationStatus::Waitlisted, false), "[WAITLISTED]");
}

TEST(ConsoleOutput, ColourOnlyRepeatsTheWord) {
    const std::string coloured = formatStatus(RegistrationStatus::Cancelled, true);
    EXPECT_NE(coloured.find("[CANCELLED]"), std::string::npos);
    EXPECT_NE(coloured, "[CANCELLED]");
}

TEST(ConsoleOutput, ErrorSaysWhatWhyAndNextStep) {
    const std::string msg = formatError(
        "cannot register for E-017",
        "the event is full (40 of 40 seats)",
        "clubhub waitlist E-017");

    EXPECT_EQ(msg,
              "Error: cannot register for E-017: the event is full (40 of 40 seats).\n"
              "Next step: clubhub waitlist E-017");
    EXPECT_NE(msg.find("Next step:"), std::string::npos);
}

}  
