<!-- ---  
title: Creative Coding II
author: Angela Brennecke
affiliation: Film University Babelsberg KONRAD WOLF
date: Summer term 20
---   -->
**Creative Coding II - Summerterm 20**

Prof. Dr. Angela Brennecke | a.brennecke@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*

---

- [Overview of the Course](#overview-of-the-course)
  - [Organization](#organization)
  - [Course Description](#course-description)
  - [Method of Instruction](#method-of-instruction)
  - [Syllabus](#syllabus)
  - [Learning Objectives](#learning-objectives)
  - [Grading](#grading)
- [Communication & Materials](#communication--materials)
  - [Assignments & Uploads](#assignments--uploads)
- [Further Readings](#further-readings)
  - [Books](#books)
    - [Creative Coding](#creative-coding)
    - [C/C++](#cc)
    - [Software Design](#software-design)
  - [Online Resources](#online-resources)
    - [openFrameworks Courses](#openframeworks-courses)

---


# Overview of the Course

## Organization 

- Mondays and Wednesdays 11:30 h - 13 h
- Module 5 | 3 SWS | 4 ECTS
- 18 sessions in total

**NOTE**: The course will be held online until further notice. During the time of online lectures, we will use the lecture hours for updates, discussions and consultation times.

## Course Description 

This course builds on the concepts presented in ‘Creative Coding I’ and introduces the software development toolkit [openFrameworks](http://openframeworks.cc). openFrameworks is a creative coding toolkit dedicated to realtime development written in C++. We will specifically use it

- to introduce the C++ programming language & corresponding build processes
- to explore object-orientation and realtime development with C++
- to get familiar with using a software development kits

Moreover, the course will present different techniques and technologies of graphics, image and audio processing. They will gradually be incorporated into the artistic programming exercises.

openFrameworks is comprised of a huge body of example projects as well as additional functionality (ofxAddons) that we will explore during the course.

We will get to know the overarching topic of the course **interaction and interfaces** in larger and smaller projects. As an artistic starting point, we will deal with imagery or music and develop a digital representation and/or interpretation using openFrameworks.

## Method of Instruction

This course will start as an online course which requires an increased amount of personal work and participation in the development of problem solutions. You will have to work through materials and assignments on your own. There will be slots for discussions twice a week. Make sure that you are prepared when bringing your questions to those slots. 

Make use of the **Github team** as well as openFrameworks forum when you are stuck and post your questions there. If you cannot find a solution, get in touch with your tutors.

On **Mondays**, new learning material and assignments will be published. We will meet online to check-in briefly and discuss open questions. 

On **Wednesdays**, we will have a check-in meeting for questions. All assignments will be given a dedicated deadline. In general, please upload any code assignments to the assignment's folder on GitHub and put your research solutions to the GitHub Wiki. 

**Note**: Group work is encouraged but might not be applicable due to the current situation. This will be a point for discussion in the first online session.



## Syllabus

1. Introduction, Technical Setup, and Build Process (2)
2. C++ development basics: Building a first ofApp (1)
3. Object-oriented Programming Concepts with C++: Animated objects (2)
4. Image represenations (2)
5. Memory management and user interaction (2)
6. Audio processing and interactive sound objects (2)
7. OpenCV (2)
8. Final Exercise (2)
9. Final Exercise (1)
10. Wrap-up (2)


## Learning Objectives

- Understanding and working with a complex SDK like openFrameworks
- Developing, compiling and building your own C++ applications
- Object-oriented software design with C++
- Applying different computational techniques in an artistic sketch
- Expressing and reflecting on your artistic ideas with openFrameworks


## Grading

### Breakdown <!-- omit in toc -->

* 30% - Homework assignments
  * Programming exercises
  * Wiki updates and critiques
* 70% - Final exercise
  * The final exercise will be a programming exercise of an openFrameworks application. The type of application can be chosen individually. However, the application must include/address:
    * Object-oriented design
    * At least two different topics from the course
    * An artistic idea that can be freely chosen 

Team work (2 persons per team) and pair programming is encouraged.
  
### Grading criteria <!-- omit in toc -->

* An application sketch that can be build, launched, and run
* Engineering effort, clarity of code organization and code quality
* Technical and creative reflection


---

# Communication & Materials

As a communication platform, we will use [GitHub.com](https://github.com/) to share code, lecture materials, comments, and submit homework and project assignments.

- [GitHub repository (public)](https://github.com/ctechfilmuniversity/sose20_cc2)
- [GitHub Wiki (public)](https://github.com/ctechfilmuniversity/sose20_cc2/wiki)
- [GitHub team (public)](https://github.com/orgs/ctechfilmuniversity/teams/sose20_cc2)

The repository will be used to share scripts (usually as readme.md) and slides, coding examples, homework and project materials. The Wiki will be maintained by the students to share information that might be useful for everyone, for example, dos and don'ts, useful links, and so on. The team will be used for discussion, comments, notes and any important announcements.

To stay tuned with the materials, clone the main repo:

```
git clone https://github.com/ctechfilmuniversity/sose20_cc2

```


## Assignments & Uploads

Please upload your assignments and exercise results to the assignments folder of the corresponding session, i.e., "01_intro". To do so, go to the assignments folder and create a folder. Name it <my_last_name> and put your results into that folder, for example, like so:

```
01_intro/assignments/brennecke/mySketch
                                bin/
                                src/
                                readme.md
                                addons.make
                                config.make
```

Make sure that you do not upload any IDE-based project files. To do so, add a **.gitignore** file to your local sose20_cc2 repository. This should not be uploaded. An example configuration might look like this:

```
# Example .gitignore file
# Configuration for C++ development

# Prerequisites
*.d
*~

/*/.DS_Store
.DS_Store
.gitignore

# Compiled Object files
*.slo
*.lo
*.o
*.obj

# Precompiled Headers
*.gch
*.pch

# Compiled Dynamic libraries
*.so
*.dylib
*.dll

# Compiled Static libraries
*.lai
*.la
*.a
*.lib

# Executables
*.exe
*.out
*.app

# Directories
obj/
.vs/

# IDE project files
*.sln
*.vcxproj*
*.xcodeproj/
*.code-workspace
*.xcconfig
*.vscode
*.plist

```


---

# Further Readings

## Books 

### Creative Coding 

- Denis Perevalov, Igor Tatrnikov (2015): openFrameworks Essentials. Packt Publishing. Birmingham, UK.
- Denis Perevalov (2013): Mastering openFrameworks: Creative Coding Demystified. Packt Publishing. Birmingham, UK.
- Joshua Noble (2009): Programming Interactivity. A Designer’s Guide to Processing, Arduino & openFrameworks. Sebastopol, CA: O’Reilly Media Inc.
- Ira Greenberg (2007): Processing: Creative Coding & Computational Art. Berkley, CA: Friends of ED/Apress Press.
- Bill Manaris & Andrews R. Brown (2014): Making Music with Computers. New York, NY: Chapman & Hall / CRC Press.

### C/C++  

- Bjarne Stroustrup (2013): The C++ Programming Language. Upper Saddle River, NJ: Pearson Education, Inc.
- Bjarne Stroustrup (2014): Programming. Principles & Practices Using C++. Upper Saddle River, NJ: Addison-Wesley.
- Scott Meyers („Effective C++“ series, advanced)
- Herb Sutter („Exceptional C++“ series, really advanced)

### Software Design 

- Grady Booch (1994): Object-oriented Analysis and Design. Addison-Wesley. NY, USA.
- Robert C. Martin (2009): Clean Code. Prentice Hall. NY, USA.
- Robert C. Martin (2017): Clean Architecture. Prentice Hall. NY, USA.


## Online Resources

### References, Tutorials, Community <!-- omit in toc -->
- [learncpp](http://www.learncpp.com) -- Very good resource for beginners and experienced developers!
- [cplusplus](http://www.cplusplus.com/) -- Very good reference site with many examples.
- [cppreference](http://www.cppreference.com/) -- Advanced, very good reference site.
- [fluentcpp](https://www.fluentcpp.com) -- Very good website with a focus on programming design (advanced!).
- [ofBook](https://github.com/openframeworks/ofBook/tree/master/chapters) -- Very good starting point for openFrameworks.
- [openFrameworks](https://openframeworks.cc/) -- All about openFrameworks.
- [openFrameworks Forum](http://forum.openframeworks.cc/) -- Communication tool for openFrameworks.

### openFrameworks Courses 
There are several excellent openFrameworks courses available on GitHub, for example:

- Zach Lieberman: https://github.com/ofZach/RTP_SFPC_FALL19
- Tyler Henry: https://github.com/tyhenry/dt_openframeworks_2018
- Dan Wilcox: https://github.com/danomatika/CreativeCodingExamples
- We are no Computer: https://github.com/wearenocomputer/workshop