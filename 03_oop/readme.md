<!-- ---  
title: Creative Coding II
author: Angela Brennecke
affiliation: Film University Babelsberg KONRAD WOLF
date: Summer term 20
---   -->

**Creative Coding II - Summerterm 20**

Prof. Dr. Angela Brennecke | a.brennecke@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*

---

**Table of Contents**

---

# Object-oriented Programming (OOP)

## General Concepts

Object-oriented programming (OOP) is a programming paradigm that is based on the idea of creating objects — well defined code entities that represent real-world concepts and translate them into the digital world.

properties and functionality

relationships between objects expressed by, f.e.,
- inheritance -> is-a
- composition -> has-a



Objects are user-defined data structures by variables & functions called member variables & member functions

In C++, the design of an object is done by a class

To create an object, you have to define its properties and methods in a corresponding Class

Classes are the blueprint for the actual objects

Based on the class definition various  different object instances can be created. 

Classes are user-defined data structures that allow to translate a theoretical concept into a piece of reusable code

Technically, classes consist of 
* a class name
* constructor & destructor
* member functions
* member variables 
* specification of access levels (private, public,…) 
* specification of relationships to other classes


## Classes and Objects
Declaration of the Class

Definition of the Class

Object instantiations




Class definitions consist of 

Member functions are defined inside of the class definition to represent all of the functionality to access and manipulate the data members

Member variables are defined inside of the class definition to represent the actual data members  and / or data structures required by the class

## Constructor and Destructor


## Access Levels


## General Concepts
  - abstraction
    - concept
    - level of abstraction
  - encapsulation
    - access levels
    - header and definiton

## Inheritance 

  - inheritance
    - grouping of functionality
    - hierarchy

## Polymorphism 

  - polymorphism
    - object management



## Design Considerations

The [separation of header and definition files](http://www.cppforschool.com/tutorial/separate-header-and-implementation-files.html) clearly supports to distinguish between 

- **The what** - software interfaces, e.g., like class design and declarations  
- **The how** - implementation details, e.g., like object instanciations and definitions in general

... on a software design level. 

Software interfaces describe **what** kind of functionality is available whereas implementation details describe **how** the functionality is implemented. It makes sense to separate both aspects, for example, when you think of OpenGL which provides a common software interface (API) and at the same time comes with different OpenGL implementations (OpenGL libraries/drivers) per platform and graphics card. The same is true in the context of the openFrameworks SDK.

# The C++ Standard Library



# opfenFrameworks - The Frame Buffer Object

openFrameworks Essentials:

"Redirecting drawing to the offscreen buffer
The offscreen buffer is a virtual screen in video memory, where we can draw anything just as we can on a real screen. The resultant picture can be used as an image or texture. We can draw it on a real screen, process with shader, or use to texture 3D objects.
In the OpenGL library, which is used by openFrameworks for drawing, the offscreen
buffer is called Frame Buffer Object (FBO). Naturally, in openFrameworks, this buffer is maintained by the ofFbo class."

- Animation
- https://openframeworks.cc/ofBook/chapters/animation.html
- Easing 
- https://github.com/tyhenry/dt_openframeworks_2018/tree/master/week05
- http://www.flong.com/texts/code/shapers_exp/
- https://easings.net
- https://github.com/jesusgollonet/ofpennereasing


# Type Conversion

-> Homework
-> slides


# Reading Material

## Recap 

Revise and Review

- [Object-oriented Programming (OOP) & openFrameworks/C++](https://openframeworks.cc/ofBook/chapters/OOPs!.html)
  - Note that this introduction is not flawless but it gives you a good idea about how OOP works with openFrameworks
- Abstraction and Design Aspects
  - FluentCpp
  - Clean Code
- [C++ Standard Library](http://www.cppforschool.com/tutorial/libraryfunc.html)
  - Additional Material
  - learncpp

- [Separation of header and definition files](http://www.cppforschool.com/tutorial/separate-header-and-implementation-files.html)

## Precap

Prepare and Preview


