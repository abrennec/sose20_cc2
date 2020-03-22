<!-- ---  
title: Creative Coding II
author: Angela Brennecke
affiliation: Film University Babelsberg KONRAD WOLF
date: Summer term 20
---   -->
**Creative Coding II - Summerterm 20**

Prof. Dr. Angela Brennecke | a.brennecke@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*


# Assignments


## 1 Resources
Checkout the openFrameworks website and get familiar with the resources provided: https://openframeworks.cc

## 2 Setup
In order to work with openFrameworks, you will have to download and unpack the openFrameworks SDK for your platform (see 2.1). Also, you have to download and install a dedicated integrated development environment (IDE) for your platform (see 2.2) that will allow you to compile, build and run the native applications on your platform. Please note, there are several options to build openFrameworks applications. During this course, only two of them will be primarily supported: macOS together with XCode and MS Windows together with MS Visual Studio Community 2017. If you want to work on a different platform or with a different IDE, you have to check out the openFrameworks forum for further support. 

### 2.1 openFrameworks 
Download the latest version of openFrameworks for the platform you will be working on, i.e., macOS and Windows, from this website https://openframeworks.cc/download/: 
- "download openFrameworks for osx"
- "download openFrameworks for visual studio (2017)"

### 2.2 IDE
If you are working on **macOS**, you will need to download and install the MacOSX IDE **Xcode**.  
- Follow the instructions here https://openframeworks.cc/setup/xcode/. 
Also, checkout this video to get a first impression of how to work with openFrameworks on MacOSX
- https://www.youtube.com/watch?v=rplUouqg8mc

If you are working on **MS Windows**, you will need to install **MS Visual Studio Community 2017**.   
- Follow the instructions here https://openframeworks.cc/setup/vs/. 
Also, checkout this video to get a first impression of how to work with openFrameworks on Windows
- https://www.youtube.com/watch?v=DtD007zeztA

The openFrameworks forum provides more resources if you encounter problems.

### 2.3 C++17

In order to use the nearly latest C++ standard, you have to change the dedicated make file for this. On macOS Go to  
```
of_root_folder/libs/openFrameworksCompiled/project/osx/config.osx.default.mk line 132:
PLATFORM_CXXFLAGS += -std=c++11

change this line to

PLATFORM_CXXFLAGS += -std=c++17 
```
On Windows go to:
```
of_root_folder/libs/openFrameworksCompiled/project/windows/config.windows.default.mk line 132:
PLATFORM_CXXFLAGS += -std=c++11

change this line to

PLATFORM_CXXFLAGS += -std=c++17 
```

## 3 Examples
Once you have installed the IDE on your platform, unpack the downloaded openFrameworks SDK to a folder of your liking. You do not have to install openFrameworks. All of the files required are simply part of the openFrameworks folder and will be used during the build process that we will look into more closely soon. For now, check out the examples folder and build your first openFrameworks examples. Checkout this video for more information.


# Howto

Assignments will be given at the end of each class. If the assignments comprise written or coded homework, please create a folder named <my_last_name>, add your solutions to this folder and upload the folder to the assignments folder of the corresponding session.
