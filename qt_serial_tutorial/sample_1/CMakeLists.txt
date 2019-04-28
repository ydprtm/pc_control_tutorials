cmake_minimum_required(VERSION 3.5.1)

project(sample_1)

set(CMAKE_DIR "C:/Program Files/CMake")
set(QT_DIR "C:/Qt/5.12.2/msvc2017_64")

set(Qt5_DIR "C:/Qt/5.12.2/msvc2017_64/lib/cmake/Qt5")

find_package(Qt5 COMPONENTS Core Widgets SerialPort REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(sample_1 main.cpp)
target_link_libraries (sample_1 Qt5::Core Qt5::Widgets Qt5::SerialPort)

# Utilities

find_program(CMAKE_EXECUTABLE NAMES cmake HINTS ${CMAKE_DIR} ENV CMAKE_DIR PATH_SUFFIXES bin)

find_program(WINDEPLOYQT_EXECUTABLE NAMES windeployqt HINTS ${QT_DIR} ENV QT_DIR PATH_SUFFIXES bin)

# Build

add_custom_command(TARGET sample_1 POST_BUILD COMMAND ${WINDEPLOYQT_EXECUTABLE} $<TARGET_FILE:sample_1>)

# Install

install(TARGETS sample_1 DESTINATION ${PROJECT_SOURCE_DIR}/bin)
install(CODE "execute_process(COMMAND ${WINDEPLOYQT_EXECUTABLE} \"${PROJECT_SOURCE_DIR}/bin/sample_1.exe\")")
