add_test([=[StudentPrivacy.RedactedHidesPersonalData]=]  [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build/Debug/student_privacy_test.exe]==] [==[--gtest_filter=StudentPrivacy.RedactedHidesPersonalData]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[StudentPrivacy.RedactedHidesPersonalData]=]
  PROPERTIES
    
    _CMAKE_TEST_BUILD_DEPENDS [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build/Debug/student_privacy_test.exe]==]
    DEF_SOURCE_LINE [==[D:\ClubHub (ISE project)\clubhub-longblackcoffee\tests\StudentPrivacyTest.cpp:15]==]
    WORKING_DIRECTORY [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[StudentPrivacy.OptionalConsentsStartOff]=]  [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build/Debug/student_privacy_test.exe]==] [==[--gtest_filter=StudentPrivacy.OptionalConsentsStartOff]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[StudentPrivacy.OptionalConsentsStartOff]=]
  PROPERTIES
    
    _CMAKE_TEST_BUILD_DEPENDS [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build/Debug/student_privacy_test.exe]==]
    DEF_SOURCE_LINE [==[D:\ClubHub (ISE project)\clubhub-longblackcoffee\tests\StudentPrivacyTest.cpp:25]==]
    WORKING_DIRECTORY [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[StudentPrivacy.WithdrawingSmsConsentErasesPhone]=]  [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build/Debug/student_privacy_test.exe]==] [==[--gtest_filter=StudentPrivacy.WithdrawingSmsConsentErasesPhone]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[StudentPrivacy.WithdrawingSmsConsentErasesPhone]=]
  PROPERTIES
    
    _CMAKE_TEST_BUILD_DEPENDS [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build/Debug/student_privacy_test.exe]==]
    DEF_SOURCE_LINE [==[D:\ClubHub (ISE project)\clubhub-longblackcoffee\tests\StudentPrivacyTest.cpp:32]==]
    WORKING_DIRECTORY [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[StudentPrivacy.RejectsEmailWithoutAt]=]  [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build/Debug/student_privacy_test.exe]==] [==[--gtest_filter=StudentPrivacy.RejectsEmailWithoutAt]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[StudentPrivacy.RejectsEmailWithoutAt]=]
  PROPERTIES
    
    _CMAKE_TEST_BUILD_DEPENDS [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build/Debug/student_privacy_test.exe]==]
    DEF_SOURCE_LINE [==[D:\ClubHub (ISE project)\clubhub-longblackcoffee\tests\StudentPrivacyTest.cpp:40]==]
    WORKING_DIRECTORY [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[StudentPrivacy.RejectsPhoneWithLetters]=]  [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build/Debug/student_privacy_test.exe]==] [==[--gtest_filter=StudentPrivacy.RejectsPhoneWithLetters]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[StudentPrivacy.RejectsPhoneWithLetters]=]
  PROPERTIES
    
    _CMAKE_TEST_BUILD_DEPENDS [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build/Debug/student_privacy_test.exe]==]
    DEF_SOURCE_LINE [==[D:\ClubHub (ISE project)\clubhub-longblackcoffee\tests\StudentPrivacyTest.cpp:45]==]
    WORKING_DIRECTORY [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[StudentPrivacy.MaskIdHidesShortIdsCompletely]=]  [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build/Debug/student_privacy_test.exe]==] [==[--gtest_filter=StudentPrivacy.MaskIdHidesShortIdsCompletely]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[StudentPrivacy.MaskIdHidesShortIdsCompletely]=]
  PROPERTIES
    
    _CMAKE_TEST_BUILD_DEPENDS [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build/Debug/student_privacy_test.exe]==]
    DEF_SOURCE_LINE [==[D:\ClubHub (ISE project)\clubhub-longblackcoffee\tests\StudentPrivacyTest.cpp:51]==]
    WORKING_DIRECTORY [==[D:/ClubHub (ISE project)/clubhub-longblackcoffee/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(student_privacy_test_TESTS [==[StudentPrivacy.RedactedHidesPersonalData]==] [==[StudentPrivacy.OptionalConsentsStartOff]==] [==[StudentPrivacy.WithdrawingSmsConsentErasesPhone]==] [==[StudentPrivacy.RejectsEmailWithoutAt]==] [==[StudentPrivacy.RejectsPhoneWithLetters]==] [==[StudentPrivacy.MaskIdHidesShortIdsCompletely]==])
