cmake_minimum_required(VERSION 3.5.1)

project(server)

set(CMAKE_DIR "C:/Program Files/CMake")
set(QT_DIR "C:/Qt/5.12.2/msvc2017_64")

set(Qt5_DIR "C:/Qt/5.12.2/msvc2017_64/lib/cmake/Qt5")

find_package(Qt5 COMPONENTS Core Widgets Network REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(server main.cpp)
target_link_libraries (server Qt5::Core Qt5::Widgets Qt5::Network)

# Utilities

find_program(CMAKE_EXECUTABLE NAMES cmake HINTS ${CMAKE_DIR} ENV CMAKE_DIR PATH_SUFFIXES bin)

find_program(WINDEPLOYQT_EXECUTABLE NAMES windeployqt HINTS ${QT_DIR} ENV QT_DIR PATH_SUFFIXES bin)

# Build

add_custom_command(TARGET server POST_BUILD COMMAND ${WINDEPLOYQT_EXECUTABLE} $<TARGET_FILE:server>)

# Install

install(TARGETS server DESTINATION ${PROJECT_SOURCE_DIR}/bin)
install(CODE "execute_process(COMMAND ${WINDEPLOYQT_EXECUTABLE} \"${PROJECT_SOURCE_DIR}/bin/server.exe\")")
