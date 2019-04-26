# Timing with Boost

Welcome to my tutorial on timers using Boost's Asio library.

## Section 1: Introduction

Considering the following situation: you're an engineer working at a large factory. There is a machine in the factory you are responsible for. Your employer requires regular measurements of the machine's state to ensure its safe operation. What do you do?

Here are some potential solutions:

1. You walk over to the machine and manually make a measurement. You record the machine's state on a computer.
1. You develop an embedded system to automatically make a measurement and save the machine's state to a memory card. You walk over to the system at the end of the day and copy the day's log from the memory card.
1. You develop an embedded system and PC application to automatically make a measurement and save the machine's state on a computer. You walk over to the system at the end of the day and copy the day's log from the computer.

Given the desired number and frequency of measurements, there's a number of issues with the first two options: the measurement period might be too short; you can only make measurements when your at work; you may want to change the embedded system's timing; changing the embedded system's requires machine down time, etc. A more satisfactory solution is the last option: an embedded system consisting of a sensor, amplifier, microcontroller, power supply, and PC-interface that will allow for a PC application to prompt it for a measurement. The PC application's timing can be changed on the fly, with no change to the embedded system.

The problem is, how can we control the PC application's timing? Fortunately, there are a number of software frameworks and libraries, e.g. [Qt](https://www.qt.io/) and [Boost](https://www.boost.org/), which have been developed to faciliate this. Qt provides its core module and Boost provides the Asio library, which both provide time-based functionality.

In this tutorial, I will show you how to use Boost's Asio library to perform syncrhonous and asynchronous time-based operations. Sample 1 shows you how to syncrhonously wait for a fixed period of time; Sample 2 shows you how to asyncrhonously wait for a fixed period of time; Sample 3 shows you how to asynchronously wait for a fixed period of time and pass a value to a wait handler; Sample 4 shows you how to asyncrhonously wait for a fixed period of time and pass a value to a class's member function; and Sample 5 shows you how to asyncrhonously wait for a fixed period in a separate thread.

The remainder of this tutorial is structured as follows: Section 2 describes the tutorial's requirements; Section 3 describes how to build the tutorial's samples; Section 4 presents and describes Sample 1's source code; Section 5 presents and describes Sample 2's source code; Section 6 presents and describes Sample 3's source code; Section 7 presents an activity for you to complete; Section 8 presents and describes Sample 4's source code; Section 9 presents and describes Sample 5's source code; Section 10 presents an activity for you to complete; and Section 11 concludes the tutorial.

## Section 2: Requirements

### Windows

You need the following programs and libraries installed on your computer to build the tutorial's samples and activities:

1. [CMake](https://cmake.org/).
1. [Boost](https://www.boost.org/).
1. [Visual Studio IDE](https://visualstudio.microsoft.com/).

This tutorial has been validated using the following software versions and hardware:

1. CMake 3.14
1. Boost 1.70.0
1. Visual Studio IDE 2019, Community Edition

If you haven't got these installed, click on each link to go to the program's respective website. To install CMake and Visual Studio IDE, run the respective installer. Most Boost libraries are header-only, i.e. they consist entirely of header files containing templates and inline functions, and require no separately-compiled library binaries or special treatment when linking. However, some libraries, e.g. Boost.Chrono, must be built separately. More information about getting started with Boost can be found [here](https://www.boost.org/doc/libs/1_70_0/more/getting_started/windows.html).

If you'd like to use an alternative to Microsoft's Visual Studio Integrated Development Environment (IDE), consider Microsoft's [Visual Studio Code](https://code.visualstudio.com/). It's a light-weight, flexible alternative to Visual Studio IDE.

Once you've CMake, Boost, and an IDE installed, you're ready to get started.

## Section 3: Build Instructions

This tutorial contains the following files:

1. [./README.md](./README.md)
1. [./activity_1/client/CMakeLists.txt](./activity_1/CMakeLists.txt)
1. [./activity_1/main.cpp](./activity_1/main.cpp)
1. [./activity_1/main.hpp](./activity_1/main.hpp)
1. [./activity_2/client/CMakeLists.txt](./activity_2/CMakeLists.txt)
1. [./activity_2/main.cpp](./activity_2/main.cpp)
1. [./activity_2/main.hpp](./activity_2/main.hpp)
1. [./sample_1/CMakeLists.txt](./sample_1/CMakeLists.txt)
1. [./sample_1/main.cpp](./sample_1/main.cpp)
1. [./sample_1/main.hpp](./sample_1/main.hpp)
1. [./sample_2/CMakeLists.txt](./sample_2/CMakeLists.txt)
1. [./sample_2/main.cpp](./sample_2/main.cpp)
1. [./sample_2/main.hpp](./sample_2/main.hpp)
1. [./sample_3/CMakeLists.txt](./sample_3/CMakeLists.txt)
1. [./sample_3/main.cpp](./sample_3/main.cpp)
1. [./sample_3/main.hpp](./sample_3/main.hpp)
1. [./sample_4/CMakeLists.txt](./sample_4/CMakeLists.txt)
1. [./sample_4/main.cpp](./sample_4/main.cpp)
1. [./sample_4/main.hpp](./sample_4/main.hpp)
1. [./sample_5/CMakeLists.txt](./sample_5/CMakeLists.txt)
1. [./sample_5/main.cpp](./sample_5/main.cpp)
1. [./sample_5/main.hpp](./sample_5/main.hpp)

The sample_1 sub-directory contains source code that shows you how to syncrhonously wait. The sample_2 sub-directory contains source code that shows you how to asynchronously wait. The sample_3 sub-directory contains source code that shows you how to pass a value to an asynchronous wait handler. The sample_4 sub-directory contains source code that shows you how to use a class's member function as an asyncrhonous wait handler. The sample_5 sub-directory contains source code that shows you how to how to asyncrhonously wait in a new thread. The activity_1 and activity_2 sub-directories contain projects set-up for you to complete the tutorial's actvitities. 

### Windows

The following describe how to build the tutorial's sample and activity using either: 1) console commands, or 2) Visual Studio IDE.

### Console Commands

To build a Debug version of a sample or activity, browse to its directory via the command line and use the following commands:

    mkdir build
    cd build
    cmake -G "Visual Studio 16 2019" ..
    cmake --build . --config Debug --target install

To run the built binary, browse to the bin sub-directory and use the following commands:

    cd ..
    cd bin
    .\project.exe

To build a Release version of a sample or activity, browse to its directory via the command line and use the following commands:

    mkdir build
    cd build
    cmake -G "Visual Studio 16 2019" ..
    cmake --build . --config Release --target install

To run the built binary, browse to the bin sub-directory and use the following commands:

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

To run the built binary:

1. Click 'Debug > Start'

To change the build configuration:

1. Click 'Project > Change CMake Settings for project'
1. Select the build configuration

To build a 64-bit, debug application, select 'x64-Debug'; to build a 64-bit, release application, select 'x64-Release'. CMake's default is a 64-bit, debug configuration.

## Section 4: Sample 1

## Section 5: Activity 1

## Section 10: Conclusion

In this tutorial, I have shown you how to [...].

You have used [...].

I hope this tutorial has been useful.

## Credit

Dr Frazer K. Noble  
Department of Mechanical and Electrical Engineering  
School of Food and Advanced Technology  
Massey University  
New Zealand  

Follow me on Twitter <a href="http://twitter.com/DrFrazerNoble" class="twitter-follow-button" data-show-count="false">@DrFrazerNoble</a>
