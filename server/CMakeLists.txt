cmake_minimum_required(VERSION 3.20)
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
endif()

project(Server)

add_executable(Server
    server_main.cpp
    pipe_server.cpp
    employee_storage.cpp
)

target_include_directories(Server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(Server PRIVATE common)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET Server PROPERTY CXX_STANDARD 17)
endif()
