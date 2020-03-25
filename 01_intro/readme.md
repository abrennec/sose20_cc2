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
- [openFrameworks Tour](#openframeworks-tour)
- [Technical Setup](#technical-setup)
  - [Integrated Development Environments](#integrated-development-environments)
  - [openFrameworks](#openframeworks)

---


# openFrameworks Tour

[openFrameworks](https://openframeworks.cc) is free, open source C++ software development toolkit (SDK) that takes a development approach similar to the Processing environment. The SDK targets easy development of **real-time** and **close-to-the-hardware applications** and is primarily designed for use in creative and experimental projects. openFrameworks is cross-platform and supports systems such as OS X, Windows, Linux, iOS, Android & Linux ARM devices such as Raspberry Pi. 

In contrast to Processing, openFrameworks does not come with an integrated development environment. Instead, openFrameworks comes with a set of **C++ source files** (comprised of header *.h and definition *.cpp files) and system-dependent **pre-compiled libraries**. These files  have to be processed manually during the compilation and build process to create a native openFrameworks application -- another key difference between openFrameworks and Processing. In the case of Processing, the resulting application is by default bound to the Processing IDE. It is only recently that you can exploit a Processing sketch as a **standalone** application. In the case of openFrameworks the resulting application is by default standalone and independent from the development environment. This comes to the price of having to use a dedicated system-dependent **integrated development environment (IDE)** to compile, link, and build the application. [openFrameworks supports several IDEs](https://openframeworks.cc/download/). On macOS we will use the standard IDE **XCode**, on windows we will use **MS Visual Studio Community 2017**. 

One advantage of **platform-dependent development** is the possibility to directly connect with, exploit and manipulate hardware resources and devices. For example, macOS and Apple computers come with a different implementation of how to use and connect with a hardware device than do Microsoft and windows computers. The same is true for Linux as well as any of the embedded systems. The aforementioned implementation is usually referred to as an **application programmer's interface (API)**. An API allows the application developer, you, to use hardware features provided by the platform you are working on. 

For example, imagine you would like to record some incoming audio from your soundcard. On macOS you could use functionality provided by [Core Audio](https://developer.apple.com/library/archive/documentation/MusicAudio/Conceptual/CoreAudioOverview/WhatisCoreAudio/WhatisCoreAudio.html) which is the standard macOS audio API. On windows platforms different APIs exist that implement how to connect with soundcards and audio interfaces. Here you could use functionality provided by the [Windows Core Audio APIs](https://docs.microsoft.com/en-us/windows/win32/coreaudio/core-audio-apis-in-windows-vista). This is certainly also true for other hardware devices like graphics cards, webcams and so on. Hence, one central aspect of C++ development is the attempt and possibility to optimize how to exlpoit the given hardware resources.

Since it can be rather tedious for an application developer to take care of all of the individual APIs themselves, certain software development toolkits wrap multiple APIs and useful functionality into a streamlined set of functions. This can be considered an abstraction of individual APIs into one consistent API. openFrameworks takes care of creating a graphical window, listening for mouse and keyboard events, processes incoming and outgoing audio streams, 3d graphics, image and video processing, and many more. This way, developers can start with expressing their ideas fairly quickly and at the same time work with an optimal connection to their hardware resources. The following diagram illustrates the different soft- and hardware layers and their relationship:

![System_overview_of](assets/diagram_system_overview_of.png)

openFrameworks is also highly extensible and provides a dedicated mechanism to involve additional functionality through the use of [ofxAddons](https://ofxaddons.com/categories). These are usually open source and add specific or custom functionality to the SDK. Addons are generally built and maintained by members of the openFrameworks community. The downside here is that several addons are outdated software versions that are no longer compatible with the latest openFrameworks version, however.

Finally, it has a very friendly & active community and it is recommended to search the [openFrameworks forum](https://forum.openframeworks.cc) for further information or to create an account to ask questions about specific aspects of the software. 

Let's check out the SDK folders and files with some examples.

Processing vs openFrameworks -- differences

Zach Lieberman
- https://www.theverge.com/2019/5/10/18564182/zach-lieberman-interactive-art-animation-movement-openframeworks-art-club
- https://www.youtube.com/watch?v=bmztlO9_Wvo


# Technical Setup

## Integrated Development Environments

To create an application with openFrameworks/C++, a dedicated development process has to be evoked. This is usually done with a platform-dependent integrated development environment (IDE) . An IDE is comprised of three fundamental components that are usually freely customizable by the developer:
1. A text editor usually with syntax highlighting.
2. A debugger to step through the code during runtime and in order to identify mistakes and bugs.
3. A compiler, linker, and build environment.

Nowadays IDEs feature more than that, for instance, they often support integration of tools like version control, deployment facilities, etc.

In this course, XCode and Visual Studio Community 2017 will be supported. Other IDEs and platforms will work with openFrameworks as well but will require an independent setup.

### Windows Users <!-- omit in toc -->

If you are using a Windows machine, most prominent IDEs are:
- MS Visual Studio Community
- VSCode with MSYS2 or MS Visual Studio Community

### MacOSX Users <!-- omit in toc -->

If you are using a MacOS machine, most prominent IDEs are:
- XCode including the "command line tools"
- VSCode (command line tools are also required)

## openFrameworks

Go to [openFrameworks.cc/download](http://openframeworks.cc/download/) and download the right version for your platform. Check out the tutorials that cover the installation process per platform. 

- Windows and Visual Studio Community: https://openframeworks.cc/setup/vs/
- MacOSX and XCode: https://openframeworks.cc/setup/xcode/
- Linux: https://openframeworks.cc/setup/linux-install/

Once you have downloaded openFrameworks, extract the zip file to a folder from where you would like to work from. Further documentation on the technical requirements and environment setup is available in 

- of\_root/README.md
- of\_root/INSTALL.md
- of\_root/docs/

If you have questions and problems during the installation, make use of the openFrameworks forum which contains lots of useful hints and discussions as well as serve as an independent help and learning channel:
- https://forum.openframeworks.cc

### Additional Learning Ressources <!-- omit in toc -->

- https://openframeworks.cc/learning/
- https://github.com/openframeworks/openFrameworks/wiki/Resources-for-Learning
- http://codeliberation.org/CLF-slides/
