cmake_minimum_required(VERSION 3.20)
project(Common)

add_library(common winapi_utils.cpp)
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET common PROPERTY CXX_STANDARD 17)
endif()
