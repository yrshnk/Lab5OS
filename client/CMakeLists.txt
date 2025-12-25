cmake_minimum_required(VERSION 3.20)
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
endif()

project(Client)

add_executable(Client
    client_main.cpp
    pipe_client.cpp
)

target_include_directories(Client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(Client PRIVATE common)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET Client PROPERTY CXX_STANDARD 17)
endif()
