cmake_minimum_required(VERSION 3.20)
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
endif()

project(NamedPipeEmployees)

add_subdirectory(common)
add_subdirectory(server)
add_subdirectory(client)
add_subdirectory(tests)
