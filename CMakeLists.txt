cmake_minimum_required(VERSION 3.11)

message("${CMAKE_SOURCE_DIR}   ${CMAKE_BINARY_DIR}")

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()

project(HackCPP VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(01.hello-world)
add_subdirectory(02.basic)
add_subdirectory(03.smart-ptr)
add_subdirectory(04.static)