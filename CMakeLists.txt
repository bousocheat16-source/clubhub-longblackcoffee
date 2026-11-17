# CMakeLists.txt
cmake_minimum_required(VERSION 3.28)
project(clubhub VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Library: all code except main(); later labs link tests to it
add_library(clubhub_core src/event.cpp src/event_csv.cpp src/Student.cpp)
target_include_directories(clubhub_core PUBLIC include)
target_compile_definitions(clubhub_core
    PRIVATE CLUBHUB_VERSION="${PROJECT_VERSION}")
if(MSVC)
    target_compile_options(clubhub_core PRIVATE /W4)
else()
    target_compile_options(clubhub_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Executable: the command-line front end
add_executable(clubhub src/main.cpp)
target_link_libraries(clubhub PRIVATE clubhub_core)

# Tests: GoogleTest, downloaded at configure time
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # needed on Windows/MSVC
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(student_privacy_test tests/StudentPrivacyTest.cpp)
target_link_libraries(student_privacy_test
    PRIVATE clubhub_core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(student_privacy_test)

