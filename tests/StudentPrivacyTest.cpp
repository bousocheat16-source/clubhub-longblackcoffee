// tests/StudentPrivacyTest.cpp
#include "clubhub/Student.h"

#include <gtest/gtest.h>

#include <stdexcept>
#include <string>

using clubhub::maskId;
using clubhub::Student;

// Invented test data only: never real students.
TEST(StudentPrivacy, RedactedHidesPersonalData) {
    Student s{"e20990417", "Test Student", "test@example.edu"};
    s.giveSmsConsent("012 345 678");
    const std::string r = s.redacted();
    EXPECT_EQ(r, "Student{id=e2******7}");
    EXPECT_EQ(r.find("Test"), std::string::npos);
    EXPECT_EQ(r.find("example.edu"), std::string::npos);
    EXPECT_EQ(r.find("345"), std::string::npos);
}

TEST(StudentPrivacy, OptionalConsentsStartOff) {
    Student s{"e20990417", "Test Student", "test@example.edu"};
    EXPECT_FALSE(s.phone().has_value());
    EXPECT_FALSE(s.facultyAndYear().has_value());
    EXPECT_FALSE(s.remindersByEmail());
}

TEST(StudentPrivacy, WithdrawingSmsConsentErasesPhone) {
    Student s{"e20990417", "Test Student", "test@example.edu"};
    s.giveSmsConsent("012 345 678");
    ASSERT_TRUE(s.phone().has_value());
    s.withdrawSmsConsent();
    EXPECT_FALSE(s.phone().has_value());
}

TEST(StudentPrivacy, RejectsEmailWithoutAt) {
    EXPECT_THROW((Student{"e20990417", "A", "no-at-sign"}),
                 std::invalid_argument);
}

TEST(StudentPrivacy, RejectsPhoneWithLetters) {
    Student s{"e20990417", "Test Student", "test@example.edu"};
    EXPECT_THROW(s.giveSmsConsent("012abc678"), std::invalid_argument);
    EXPECT_FALSE(s.phone().has_value());  // nothing was stored
}

TEST(StudentPrivacy, MaskIdHidesShortIdsCompletely) {
    EXPECT_EQ(maskId("abc"), "***");
    EXPECT_EQ(maskId("ab"), "**");
    EXPECT_EQ(maskId("a"), "*");
    EXPECT_EQ(maskId(""), "");
}