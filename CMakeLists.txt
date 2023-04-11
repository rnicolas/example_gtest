cmake_minimum_required(VERSION 3.14)

project(example_gtest)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(DOWNLOAD_EXTRACT_TIMESTAMP true)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)

include_directories(
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/src
)


# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  mathTest
  test/mathTest.cpp
  src/math.cpp
  src/status.cpp
)

target_link_libraries(
  mathTest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(mathTest)