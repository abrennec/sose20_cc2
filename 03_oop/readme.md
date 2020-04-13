<!-- ---  
title: Creative Coding II
author: Angela Brennecke
affiliation: Film University Babelsberg KONRAD WOLF
date: Summer term 20
---   -->
**Creative Coding II - Summerterm 20**

Prof. Dr. Angela Brennecke | a.brennecke@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*

---

--- 

# Object-oriented Programming

- oop
  - abstraction
    - concept
    - level of abstraction
  - encapsulation
    - access levels
    - header and definiton
  - inheritance
    - grouping of functionality
    - hierarchy
  - polymorphism
    - object management
- oop & cpp class design
  - constructor
  - destructor
  - member variables
  - member functions
  - access levels
  - base classes
  - virtual constructor


### Further Considerations

The [separation of header and definition files](http://www.cppforschool.com/tutorial/separate-header-and-implementation-files.html) clearly supports to distinguish between 

- **the what** - software interfaces (e.g., like declarations) from 
- **the how** - implementation details (e.g., like definitions)

... on a software design level. 

Software interfaces describe **what** kind of functionality is available whereas implementation details describe **how** the functionality is implemented. It makes sense to separate both aspects, for example, when you think of OpenGL which provides a common software interface (API) and at the same time comes with different OpenGL implementations (OpenGL libraries/drivers) per platform and graphics card. The same is true in the context of the openFrameworks SDK.

- stl

- fbo

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


