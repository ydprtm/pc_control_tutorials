cmake_minimum_required(VERSION 3.5.1)

project(client)

set(QT_DIR "C:/Qt/5.14.2/msvc2017_64")
set(Qt5_DIR "C:/Qt/5.14.2/msvc2017_64/lib/cmake/Qt5")

find_package(Qt5 COMPONENTS Core Widgets Network REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(client main.cpp)
target_link_libraries (client Qt5::Core Qt5::Widgets Qt5::Network)

# Utilities

set(CMAKE_DIR "C:/Program Files/CMake")
find_program(CMAKE_EXECUTABLE NAMES cmake HINTS ${CMAKE_DIR} ENV CMAKE_DIR PATH_SUFFIXES bin)
find_program(WINDEPLOYQT_EXECUTABLE NAMES windeployqt HINTS ${QT_DIR} ENV QT_DIR PATH_SUFFIXES bin)

# Build

set_property(TARGET client PROPERTY CXX_STANDARD 17)

add_custom_command(TARGET client POST_BUILD COMMAND ${WINDEPLOYQT_EXECUTABLE} $<TARGET_FILE:client>)

# Install

install(TARGETS client DESTINATION ${PROJECT_SOURCE_DIR}/bin)
install(CODE "execute_process(COMMAND ${WINDEPLOYQT_EXECUTABLE} \"${PROJECT_SOURCE_DIR}/bin/client.exe\")")
