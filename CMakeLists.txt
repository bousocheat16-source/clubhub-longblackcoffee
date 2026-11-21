cmake_minimum_required(VERSION 3.28)
project(clubhub VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(clubhub_core 
    src/event.cpp 
    src/event_csv.cpp 
    src/ConsoleOutput.cpp
    src/Student.cpp
)
target_include_directories(clubhub_core PUBLIC include)
target_compile_definitions(clubhub_core PRIVATE CLUBHUB_VERSION="${PROJECT_VERSION}")
    
if(MSVC)
    target_compile_options(clubhub_core PRIVATE /W4)
else()
    target_compile_options(clubhub_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(clubhub src/main.cpp)
target_link_libraries(clubhub PRIVATE clubhub_core)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(clubhub_tests tests/ConsoleOutputTest.cpp tests/StudentPrivacyTest.cpp)
target_link_libraries(clubhub_tests PRIVATE clubhub_core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(clubhub_tests)