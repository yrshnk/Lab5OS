cmake_minimum_required(VERSION 3.20)
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
endif()

project(Tests)

enable_testing()
find_package(GTest REQUIRED)

add_executable(tests
    test_employee_storage.cpp
    test_protocol.cpp
    test_concurrency.cpp
    test_validation.cpp
)

target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(tests PRIVATE GTest::gtest_main common)

add_test(NAME AllTests COMMAND tests)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET tests PROPERTY CXX_STANDARD 17)
endif()
