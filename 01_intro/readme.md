<!-- ---  
title: Creative Coding II
author: Angela Brennecke
affiliation: Film University Babelsberg KONRAD WOLF
date: Summer term 20
---   -->
**Creative Coding II - Summerterm 20**

Prof. Dr. Angela Brennecke | a.brennecke@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*

Last Update: 

---

**Table of Contents**
- [What is openFrameworks?](#what-is-openframeworks)
- [Technical Requirements](#technical-requirements)
  - [The IDE](#the-ide)
  - [Setup and Installation](#setup-and-installation)
    - [openFrameworks](#openframeworks)
    - [macOS and XCode](#macos-and-xcode)
    - [Windows and Visual Studio](#windows-and-visual-studio)
    - [More Support](#more-support)
- [Building a First ofExample](#building-a-first-ofexample)
- [The Build Process](#the-build-process)
  - [Source Code and Executable](#source-code-and-executable)
  - [Compiled vs interpreted Languages](#compiled-vs-interpreted-languages)
  - [Components of the Build Process](#components-of-the-build-process)
  - [Compiler and Linker Errors](#compiler-and-linker-errors)
  - [Reading Material](#reading-material)
- [Additional Learning Ressources](#additional-learning-ressources)

---


# What is openFrameworks?

[openFrameworks](https://openframeworks.cc) is free, open source C++ software development toolkit (SDK) that takes a development approach similar to the Processing environment. The SDK targets easy development of **real-time** and **close-to-the-hardware applications** and is primarily designed for use in creative and experimental projects. openFrameworks is cross-platform and supports systems such as OS X, Windows, Linux, iOS, Android & Linux ARM devices such as Raspberry Pi. 

In contrast to Processing, openFrameworks does not come with an integrated development environment. Instead, openFrameworks comes with a set of **C++ source files** (comprised of header *.h and definition *.cpp files) and system-dependent **pre-compiled libraries**. These files  have to be processed as part of a compilation and build process to create a native openFrameworks application -- another key difference between openFrameworks and Processing: 
- In the case of Processing, the resulting application is by default bound to the Processing IDE. It is only recently that a Processing sketch can be exported as **standalone** application. 
- In the case of openFrameworks the resulting application is by default standalone. It can be launched and can be run independently from the development environment.  

This comes to the price of having to use a dedicated system-dependent **integrated development environment (IDE)** to compile, link, and build the application. [openFrameworks supports several IDEs](https://openframeworks.cc/download/). On macOS we will use the standard IDE **XCode**, on Windows we will use **MS Visual Studio Community 2017**. 

One advantage of **platform-dependent development** is the possibility to directly connect with, exploit and manipulate hardware resources and devices. For example, macOS and Apple computers come with a different implementation of how to use and connect with a hardware device than do Microsoft and Windows computers. The same is true for Linux as well as any of the embedded systems. The aforementioned implementation is usually referred to as an **application programmer's interface (API)**. An API allows the application developer, you, to use hardware features provided by the platform you are working on. 

For example, imagine you would like to record some incoming audio from your soundcard. On macOS you could use functionality provided by [Core Audio](https://developer.apple.com/library/archive/documentation/MusicAudio/Conceptual/CoreAudioOverview/WhatisCoreAudio/WhatisCoreAudio.html) which is the standard macOS audio API. On Windows platforms different APIs exist that implement how to connect with soundcards and audio interfaces. Here you could use functionality provided by **Directsound** or **WASAPI** (Windows Audio Session API) which are part of the [Windows Core Audio APIs](https://docs.microsoft.com/en-us/windows/win32/coreaudio/core-audio-apis-in-windows-vista). This is certainly also true for other hardware devices like graphics cards, webcams and so on. Hence, one central aspect of C++ development is optimizing the use of the given hardware resources.

Since it can be rather tedious for an application developer to take care of all of the individual APIs themselves, certain software development toolkits package multiple APIs and useful functionality into a uniform set of functions. This can be considered an abstraction of individual APIs into one higher-level API. openFrameworks does exactly that. It takes care of creating a graphical window, listening for mouse and keyboard events, processes incoming and outgoing audio streams, 3d graphics, image and video processing, and many more. This way, developers can start with expressing their ideas fairly quickly and at the same time work with an optimal connection to their hardware resources. The following diagram illustrates the different soft- and hardware layers and their relationship:

![System_overview_of](assets/diagram_system_overview_of.png)

openFrameworks is also highly extensible and provides a dedicated mechanism to involve additional functionality through the use of [ofxAddons](https://ofxaddons.com/categories). These are usually open source and add specific or custom functionality to the SDK. Addons are generally built and maintained by members of the openFrameworks community. The downside here is that not all of the addons are maintained continuously. Hence, several addons are outdated and no longer compatible with the latest openFrameworks version. Once you understand how C++ and openFrameworks work, you can workaround this and update an outdated ofxAddon yourselves ;-)

One source of support that might help you with this and many other openFrameworks related questions is the [openFrameworks forum](https://forum.openframeworks.cc). openFramework has a very friendly & active community and it is recommended to search the forum for further information or to create an account to ask questions about specific aspects of the software. 

# Technical Requirements

## The IDE

To create an application with openFrameworks/C++, a dedicated development process has to be evoked. This is usually done with a platform-dependent **integrated development environment (IDE)** . An IDE is comprised of three fundamental components that are usually freely customizable by the developer:
1. A **text editor** usually with syntax highlighting.
2. A **debugger** to step through the code during runtime and in order to identify mistakes and bugs.
3. A **build environment** that processes, compiles, and links the source code.

Nowadays IDEs feature more than that, for instance, they often support integration of tools like version control, deployment facilities or additional code optimization tools. In this course, we will focus on the build and debug processes with **XCode** for macOS and **MS Visual Studio Community 2017** ("Visual Studio" or simply "vs") for Windows platforms. See the next section for more details.

*Note: Other IDEs and platforms will work with openFrameworks as well but will require you to take care of the setup and processing yourselves. Visual Studio Code is a very good alternative that works on both platforms, macOS and Windows. However, at the moment it is [not possible to use the latest debugger on macOS Catalina with Visual Studio Code](https://github.com/microsoft/vscode-cpptools/issues/3829).*

## Setup and Installation

openFrameworks provides a detailed description on how to setup your system. 

### openFrameworks 
Download the latest version of openFrameworks for the platform you will be working on, i.e., macOS and Windows, from this website https://openframeworks.cc/download/: 
- "download openFrameworks for osx"
- "download openFrameworks for visual studio (2017)"

Once you have downloaded openFrameworks, extract the zip file to a folder location from where you would like to work. You do not have to install anything in order to work with the SDK except for an IDE. Further documentation on the technical requirements and environment setup is available in these files

- of\_root\_folder/README.md
- of\_root\_folder/INSTALL.md
- of\_root\_folder/docs/

### macOS and XCode
If you are working on **macOS**, you will need to download and install **Xcode**.  
- Follow the instructions here https://openframeworks.cc/setup/xcode/. 
- Checkout [this video to get a first impression of how to work with openFrameworks on MacOSX](https://www.youtube.com/watch?v=rplUouqg8mc)

### Windows and Visual Studio

If you are working on Windows, you will need to install **MS Visual Studio Community 2017**.   
- Follow the instructions here https://openframeworks.cc/setup/vs/. 
- Checkout [this video to get a first impression of how to work with openFrameworks on Windows](https://www.youtube.com/watch?v=DtD007zeztA)

### More Support
If you have questions and problems during the installation, make use of the [openFrameworks forum](ttps://forum.openframeworks.cc) which contains lots of useful hints and discussions.

Once your system is setup, checkout this introduction video on the openFrameworks folder structure:

- *Link to the introduction video*

# Building a First ofExample

Once you have installed the IDE on your platform and unpacked the downloaded openFrameworks SDK to a folder of your liking you can start building the example applications that come with openFrameworks. It is important to understand that you have to build the example applications with the help of the IDE. All of the files required to do so are inside of the openFrameworks folders. This is the reason, why the folder structure is very important and should not be changed. 

The IDE's **project files**, *.xcodeproject for XCode and *.sln for Windows, contain all of the necessary information for this process.

Since the build system is  and will be used during the build process that we will look into more closely soon. For now, check out the examples folder and build your first openFrameworks examples. Checkout this video for more information.


# The Build Process

## Source Code and Executable

The build process takes care of turning **source code** into executable software programs. 

![build_process_intro](assets/build_process_intro.png)  
*Image credit: http://www.learncpp.com | 0.2 — Introduction to programming languages*

These **executables** or **binaries** are sets of instructions that tell the computer how to operate. Therefore, 
the instructions have to be written in machine code. Machine code is a very low-level programming language with each instruction set being composed of bits, binary numbers like, for example, *10110000 01100001*. These instruction sets are different per CPU, i.e., MacOS, Windows, Linux, etc. binaries differ.

Each platform's operating system comes with a small program called **loader**. When executing the binary, i.e., by double-clicking it, the loader loads the binary file into the platform's random access memory (RAM) and the platform's CPU executes the machine code instructions.


## Compiled vs interpreted Languages

Generally, the build process is a **multi-step process** whereas the interpreter abstracts these steps and appears as a **one-step-process**. 

An interpreted language (e.g. Python or Processing) uses an interpreter that
- does not compile source code in machine code 
- is not necessarily optimized for the platform 
- directly executes the instructions itself

Nowadays interpreted language programs can compete often well with compiled languages.  are therefore generally still slower in program execution than compiled language programs that are executed directly by the CPU

## Components of the Build Process

The following diagram illustrates the development and build process for a compiled language like C++:

![build_process_details](assets/build_process_details.png)  
*Image credit: Richard L. Halterman (2017): Fundamentals of C++ Programming. Online print.*

- Preprocessing: Generates enhanced source code
- Compilation: Generates object files
- Linking: links all object files and generates the executable

## Compiler and Linker Errors

**Compiler errors** occur during compilation usually refer to syntax errors in the code
compiler error code is usually very helpful to identify and fix the compiler error.

**Linker errors** occur during linking of the object files and are often much harder to fix
usually refer to missing implementation details of the code   like, i.e., missing function definitions or libraries (path errors).

Examples presented.

## Reading Material

- https://www.learncpp.com/cpp-tutorial/introduction-to-the-compiler-linker-and-libraries/
- https://www.tutorialspoint.com/compiler_design/compiler_design_overview.htm



# Additional Learning Ressources

- https://openframeworks.cc/learning/
- https://github.com/openframeworks/openFrameworks/wiki/Resources-for-Learning
- http://codeliberation.org/CLF-slides/
- http://www.stroustrup.com/C++.html#guidelines