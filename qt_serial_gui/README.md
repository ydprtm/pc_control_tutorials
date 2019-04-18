# Tutorial 1: Serial Communication

Welcome to my tutorial on how to use Qt to communicate over a serial port.

## Introduction

## Requirements

To complete this tutorial, you will need CMake, Qt, an Integrated Development Environment (IDE), and an Arduino, or similar.

### Windows

To build the source code listed in this tutorial, you need to have the following installed on your computer:

1. [CMake](https://cmake.org/)
1. [Qt](https://www.qt.io/)
1. [Visual Studio IDE](https://visualstudio.microsoft.com/)
1. [Arduino IDE](https://www.arduino.cc/) (Optional)

If you haven't got these installed, click on a link to go to the tool's website. Download and install the relevant system installer, e.g. CMake's "cmake-3.14.2-win64-x64.msi"; Qt's "Qt Online Installer for Windows"; Microsoft's "Community" version, and (optionally) Arduino's "Windows app".

This tutorial has been validated using the following software versions:

1. CMake 3.14
1. Qt 5.12.2
1. Visual Studio IDE 2017
1. Arduino 1.8.9

If you'd like to use a different IDE, consider Microsoft's [Visual Studio Code](https://code.visualstudio.com/): It's a light-weight, flexible alternative.

Once you've got CMake, Qt, and an IDE installed, you're ready to get started.

## How to Build the Tutorial's Samples and Activity

This tutorial contains the following files:

1. [activity_1/CMakeLists.txt](./activity_1/CMakeLists.txt)
1. [activity_1/main.cpp](./activity_1/main.cpp)
1. [activity_1/main.h](./activity_1/main.h)
1. [sample_1/CMakeLists.txt](./sample_1/CMakeLists.txt)
1. [sample_1/gui.cpp](./sample_1/gui.cpp)
1. [sample_1/gui.hpp](./sample_1/gui.hpp)
1. [sample_1/main.cpp](./sample_1/main.cpp)
1. [sample_1/main.hpp](./sample_1/main.hpp)
1. [sample_1/serial.cpp](./sample_1/serial.cpp)
1. [sample_1/serial.hpp](./sample_1/serial.hpp)

The sample_1 sub-directory contains source code that transmits and receives strings via a COM port. The activity_1 sub-directory contains a project for you to use to complete the tutorial's activity.

### Windows

The following sections describe how to build the tutorial's sample and activity using either: 1) console commands, or 2) Visual Studio IDE.

### Console Commands

To build a Debug version of a sample or activity, browse to its directory via the command line and use the following commands:

    mkdir build
    cd build
    cmake -G "Visual Studio 15 2017 Win64" ..
    cmake --build . --config Debug --target install

To run the built executable, browse to the bin sub-directory and use the following commands:

    cd ..
    cd bin
    .\project.exe

To build a Release version of a sample or activity, browse to its directory via the command line and use the following commands:

    mkdir build
    cd build
    cmake -G "Visual Studio 15 2017 Win64" ..
    cmake --build . --config Release --target install

To run the built executable, browse to the bin sub-directory and use the following commands:

    cd ..
    cd bin
    .\project.exe

### Visual Studio IDE

To build a Debug version of a sample or activity:

1. Open Visual Studio IDE
1. Click on 'File > Open > CMake'
1. Browse to the sample or activity's directory
1. Select 'CMakeLists.txt' and click on 'Open'
1. Click 'CMake > Build All'

To run the built executable:

1. Click 'CMake > Bebug from Build Folder'

To change the build configuration:

1. Click 'CMake > Change CMake Settings > project'
1. Select the build configuration

To build a 64-bit, debug application, select 'x64-Debug'; to build a 64-bit, release application, select 'x64-Release'. CMake's default is a x64-bin, debug configuration.

## Sample 1: Transmitting and Receiving a String via a COM Port

Browse to the 'sample_1' sub-directory and open each of the sample's files.

Here, I will explain what each file is doing.

CMakeLists.txt

```[cpp]
cmake_minimum_required(VERSION 3.5.1)

project(project)

set(CMAKE_DIR "C:/Program Files/CMake")
set(QT_DIR "C:/Qt/5.12.2/msvc2017_64")

set(Qt5_DIR "C:/Qt/5.12.2/msvc2017_64/lib/cmake/Qt5")

find_package(Qt5 COMPONENTS Core Gui SerialPort Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(gui gui.cpp serial.cpp)
target_link_libraries(gui Qt5::Core Qt5::Gui Qt5::SerialPort Qt5::Widgets)

add_executable(project WIN32 main.cpp)
target_link_libraries (project gui)

# Utilities

find_program(CMAKE_EXECUTABLE NAMES cmake HINTS ${CMAKE_DIR} ENV CMAKE_DIR PATH_SUFFIXES bin)

find_program(WINDEPLOYQT_EXECUTABLE NAMES windeployqt HINTS ${QT_DIR} ENV QT_DIR PATH_SUFFIXES bin)

# Build

add_custom_command(TARGET project POST_BUILD COMMAND ${WINDEPLOYQT_EXECUTABLE} $<TARGET_FILE:project>)

# Install

install(TARGETS project DESTINATION ${PROJECT_SOURCE_DIR}/bin)
install(CODE "execute_process(COMMAND ${WINDEPLOYQT_EXECUTABLE} \"${PROJECT_SOURCE_DIR}/bin/project.exe\")")

```

CMakeLists.txt is the CMake build system's input file. It tells the build system what the project's name is, where it can find configuration files, what source files are required, what libraries to link against, and allows for pre- and post-build actions, e.g. copying a Dynamically Linked Library (DLL) to an installation directory. For more information about CMake and CMakeLists.txt, see [here](https://cmake.org/) and [here](https://cmake.org/cmake-tutorial/).

Going through CMakeLists.txt block by block:

The line

```[cpp]
cmake_minimum_required(VERSION 3.5.1)
```

sets the minimum CMake version to 3.5.1. For Qt 5.12.2, the minimum CMake version is 3.1.0. Here, I've opted to use 3.5.1, as that's the minimum CMake version OpenCV 4.0.1 requires, which we'll use in subsequent tutorials. Typically, configuration files, e.g. Qt5Config.cmake, specify the minimum CMake version they require.

The line

```[cpp]
project(project)
```

defines the project's name and stores it in the variable `project`. For more information about `project`, see [here](https://cmake.org/cmake/help/v3.14/command/project.html?highlight=project).

The block

```[cpp]
set(CMAKE_DIR "C:/Program Files/CMake")
set(QT_DIR "C:/Qt/5.12.2/msvc2017_64")
```

defines the variables `CMAKE_DIR` and `QT_DIR`, which specify where CMake and Qt are installed. Because we want to build a x64-bit program for Windows, we use the msvc2017_64 sub-directory. This contains the include, bin, and lib sub-directories, which contain Qt's header files, x64-bit DLLs, and import libraries. For more information about `set`, see [here](https://cmake.org/cmake/help/v3.14/command/set.html?highlight=set).

The line

```[Cpp]
set(Qt5_DIR "C:/Qt/5.12.2/msvc2017_64/lib/cmake/Qt5")
```

defines the variable `Qt5_DIR`, which specifies where the Qt5 package's CMake configuration file, Qt5Config.cmake, is. We use this later when we want to find the `Qt5` package. For more information about packages and configuration files, see [here](https://gitlab.kitware.com/cmake/community/wikis/doc/tutorials/How-to-create-a-ProjectConfig.cmake-file).

The line

```[Cpp]
find_package(Qt5 COMPONENTS Core Gui SerialPort Widgets REQUIRED)
```

specifies that the `Qt5` package is required and that we want to use the `Core`, `Gui`, `SerialPort`, and `Widgets` components. Because we defined `Qt5_DIR` previously, it's already taken care of finding the components' configuration files, e.g. `Gui` and Qt5GuiConfig.cmake. For more information about `find_package`, see [here](https://cmake.org/cmake/help/v3.14/command/find_package.html?highlight=find_package).

The block

```[cpp]
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
```

sets the variables `CMAKE_AUTOMOC`, `CMAKE_AUTOUIC`, and `CMAKE_INCLUDE_CURRENT_DIR`, which makes CMake handle Qt's moc and uic automatically; it also includes the current source and build directory to the include path. For more information about `CMAKE_AUTOMOC`, see [here](https://cmake.org/cmake/help/v3.14/variable/CMAKE_AUTOMOC.html?highlight=cmake_automoc). For more information about `CMAKE_AUTOUIC`, see [here](https://cmake.org/cmake/help/v3.14/variable/CMAKE_AUTOUIC.html?highlight=cmake_autouic). For more information about `CMAKE_INCLUDE_CURRENT_DIR`, see [here](https://cmake.org/cmake/help/v3.14/variable/CMAKE_INCLUDE_CURRENT_DIR.html?highlight=cmake_include_current_dir).

The block

```[cpp]
add_library(gui gui.cpp serial.cpp)
target_link_libraries(gui Qt5::Core Qt5::Gui Qt5::SerialPort Qt5::Widgets)
```

adds a library named `gui` to the project, which is built using the `gui.cpp` and `serial.cpp` source files and linked with Qt's `Core`, `Gui`, `SerialPort`, and `Widgets` libraries. For more information about `add_library`, see [here](https://cmake.org/cmake/help/v3.14/command/add_library.html?highlight=add_library). For more information about `target_link_libraries`, see [here](https://cmake.org/cmake/help/v3.14/command/target_link_libraries.html?highlight=target_link#command:target_link_libraries).

The block

```[cpp]
add_executable(project WIN32 main.cpp)
target_link_libraries (project gui)
```

adds an executable named `project` to the project, which is built using `main.cpp` and linked using the `gui` library. For more information about `add_executable`, see [here](https://cmake.org/cmake/help/v3.14/command/add_executable.html?highlight=add%20executable).

The line

```[cpp]
find_program(CMAKE_EXECUTABLE NAMES cmake HINTS ${CMAKE_DIR} ENV CMAKE_DIR PATH_SUFFIXES bin)
```

defines the variable `CMAKE_EXECUTABLE` and looks for the program named `cmake`, starting in the directory defined by `CMAKE_DIR`, which was defined as `C:/Program Files/CMake`, and looking in the `bin` sub-directory. We can use CMake to do things like copy a file from a directory to the build or installation directories. For more information about `find_program`, see [here](https://cmake.org/cmake/help/v3.14/command/find_program.html?highlight=find_program).

The line

```[cpp]
find_program(WINDEPLOYQT_EXECUTABLE NAMES windeployqt HINTS ${QT_DIR} ENV QT_DIR PATH_SUFFIXES bin)
```

defines the variable `WINDEPLOYQT` and looks for the program named `windeployqt`, starting in directory `QT_DIR`, which was defined as `C:/Qt/5.12.2/msvc2017_64`, and looking in the `bin` sub-directory. We use Qt's windeployqt to copy all the required DLLs and files from the Qt's installation to the build or installation directories.

The line

```[cpp]
add_custom_command(TARGET project POST_BUILD COMMAND ${WINDEPLOYQT_EXECUTABLE} $<TARGET_FILE:project>)
```

adds a post-build command, which calls Qt's windeployqt program and is used to copy all the required DLLs and files into the build directory. For more information about `add_custom_command`, see [here](https://cmake.org/cmake/help/v3.14/command/add_custom_command.html?highlight=custom_command#command:add_custom_command).

The block

```[cpp]
install(TARGETS project DESTINATION ${PROJECT_SOURCE_DIR}/bin)
install(CODE "execute_process(COMMAND ${WINDEPLOYQT_EXECUTABLE} \"${PROJECT_SOURCE_DIR}/bin/project.exe\")")
```

generates the installation instructions for the project. Here, the build files are installed into the `bin` sub-directory and Qt's windeployqt program is used to copy all the required DLLs and files into the sub-directory. For more information about `install`, see [here](https://cmake.org/cmake/help/v3.14/command/install.html?highlight=install).




## Activity 1: Controlling an Arduino via a Graphical User Interface


## Conclusion

## Credit

Dr Frazer K. Noble  
Department of Mechanical and Electrical Engineering  
School of Food and Advanced Technology  
Massey University  
New Zealand  

Follow <a href="http://twitter.com/DrFrazerNoble" class="twitter-follow-button" data-show-count="false">@DrFrazerNoble</a>
<script src="http://platform.twitter.com/widgets.js" type="text/javascript"></script>