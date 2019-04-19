# Boost ASIO Tutorial 2: Serial Port

Welcome to my tutorial on how to use Boost's ASIO library to communicate over a serial port.

## Introduction

## Requirements

To complete this tutorial, you will need CMake, Boost, and an Integrated Development Environment (IDE).

### Windows

To build the source code listed in this tutorial, you need to have the following installed on your computer:

1. [CMake](https://cmake.org/)
1. [Boost](https://www.boost.org/)
1. [Visual Studio IDE](https://visualstudio.microsoft.com/)

If you haven't got these installed, click on a link to go to the tool's website. Download and install the relevant system installer, e.g. CMake's "cmake-3.14.2-win64-x64.msi"; Boost's "boost_1_69_0.7z"; and Microsoft's Visual Studio 2019 "Community" edition.

This tutorial has been validated using the following software versions:

1. CMake 3.14
1. Boost 1.69.0
1. Visual Studio IDE 2019, Community Edition

If you'd like to use a different IDE, consider Microsoft's [Visual Studio Code](https://code.visualstudio.com/): It's a light-weight, flexible alternative.

Once you've got CMake, Boost, and an IDE installed, you're ready to get started.

## How to Build the Tutorial's Samples and Activity

This tutorial contains the following files:

1. [activity_1/CMakeLists.txt](./activity_1/CMakeLists.txt)
1. [activity_1/main.cpp](./activity_1/main.cpp)
1. [activity_1/main.h](./activity_1/main.h)
1. [sample_1/CMakeLists.txt](./sample_1/CMakeLists.txt)
1. [sample_1/main.cpp](./sample_1/main.cpp)
1. [sample_1/main.hpp](./sample_1/main.hpp)

The sample_1 sub-directory contains source code that creates a timer, which waits for a fixed period. The activity_1 sub-directory contains a project for you to use to complete the tutorial's activity.

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
1. Click 'Build > Build All'

To run the built executable:

1. Click 'Debug > Start'

To change the build configuration:

1. Click 'Project > Change CMake Settings for project'
1. Select the build configuration

To build a 64-bit, debug application, select 'x64-Debug'; to build a 64-bit, release application, select 'x64-Release'. CMake's default is a x64-bin, debug configuration.

## Sample 1: Transmitting and Receiving a String via a COM Port

Browse to the 'sample_1' sub-directory and open each of the sample's files.

Here, I will explain what each file is doing.




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