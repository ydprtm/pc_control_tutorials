cmake_minimum_required(VERSION 3.5.1)

project(project)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(project main.cpp)

set(CMAKE_DIR "C:/Program Files/CMake")
find_program(CMAKE_EXECUTABLE NAMES cmake HINTS ${CMAKE_DIR} ENV CMAKE_DIR PATH_SUFFIXES bin)

# Build

# Install

install(TARGETS project DESTINATION ${PROJECT_SOURCE_DIR}/bin)

