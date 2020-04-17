<!-- ---  
title: Creative Coding II
author: Angela Brennecke
affiliation: Film University Babelsberg KONRAD WOLF
date: Summer term 20
---   -->

**Creative Coding II - Summerterm 20**

Prof. Dr. Angela Brennecke | a.brennecke@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*

---- 

**Table of Contents**  
- [Object-oriented Programming (OOP)](#object-oriented-programming-oop)
  - [Theoretical Concepts](#theoretical-concepts)
  - [Classes & Objects](#classes--objects)
    - [Class Members](#class-members)
    - [Constructor & Destructor](#constructor--destructor)
      - [The default constructor](#the-default-constructor)
      - [The user-defined constructor](#the-user-defined-constructor)
      - [Destructor](#destructor)
    - [Access Levels](#access-levels)
      - [Abstraction](#abstraction)
      - [Design Aspects](#design-aspects)
    - [Object Instantiation & Member Access](#object-instantiation--member-access)
    - [Classes, Header, and Definition Files](#classes-header-and-definition-files)
- [The Frame Buffer Object](#the-frame-buffer-object)
- [Additional C++ Specifics](#additional-c-specifics)
  - [C++ Standard Library](#c-standard-library)
  - [Type Conversion](#type-conversion)
- [Reading Material](#reading-material)
  - [Recap](#recap)
  - [Precap](#precap)

---

# Object-oriented Programming (OOP)

Object-oriented programming (OOP) is a programming paradigm that is based on the idea of creating and working with objects. An **object** in OOP is a digital entity which represents a certain concept or idea and, in doing so, which groups all functionality and properties required to represent that concept or idea into a user-defined data type called a **class**. 

For example, imagine you wanted to draw a small character inside of your ofApp. You could go about this task by applying several function calls to ofDrawCircle, ofDrawRectangle, ofDrawTriangle, and so on in order to draw a character onto the screen. Your draw() function would probably become quite large. Now imagine you wanted to draw a small house as well. You would have to add additional function calls to ofDrawRectangle, for example, extending your draw() function further. The readability of your code would probably suffer and any interaction with the small character would probably be rather tedious to implement as well. 

 With OOP you might instead define a user-defined data type, a C++ class, called "myCharacter" and move all of the functionality required to draw and represent your character into the class specification. Then, in ofApp.h, you would simply add a variable of type "myCharacter", instantiate it and call its' drawing routine, for example, like so:

```cpp

class ofApp : ofBaseApp() {

    // ....
    myCharacter happyCreature;      // add a member variable
}

////

void ofApp::draw() {

    happyCreature.draw();   // call the object's drawing routine
}

```
---
Check out this screencast to learn about object-oriented programming with C++:

*Attention: The video may take a couple of minutes to load.*

[![oop intro](assets/screencast.png)]()

---

In its essence, OOP is a very straightforward approach to software development which targets to simplify the development process. On a practical level, object-oriented design will help you to better organize your code, to make it more readable and to better categorize individual elements. 
On a software design level, object-oriented design will help you to reflect on your program from a conceptual point of view and to identify:
  - What kind of elements, components, or simply *objects* do you actually need and use?
  - How do they relate to each other?  
  - What kind of properties and what kind of functionality do they represent?


## Theoretical Concepts

There are four main theoretical concepts related to OOP that we will get to know during the next sessions. These concepts are 

- Abstraction 
- Encapsulation
- Inheritance
- Polymorphism 

**Abstraction** is an approch to abstract from a concrete application scenario or example and to derive a general concept that can be applied to different scenarios. 

**Encapsulation** is an approach to identify and group together all properties and functionalities that belong to and represent a certain concept in one object.

**Inheritance** is an approach to create an object hierarchy in order to share properties and functionality and to specify a hierarchical child-object is-a parent-object relationship. 

**Polymorphism** is an approach to manage hierarchical groups of objects with the help of pointers and to additionally specify the relationships expressed by the hierarchy.

Don't worry if you do not understand all of these theories at this point. We will revisit them during the upcoming sessions again and again.

## Classes & Objects

Following [the explanation at cplusplus.com](http://www.cplusplus.com/doc/tutorial/classes/), *classes are user-defined data types in C++ and objects are instantiations of classes. If you think of variables, a class would be the variable type whereas the object itself would be the actual variable that can be used in the code.* 

Classes are blueprints of objects. Based on **one** **class** definition **various different object instances** can be created. 

### Class Members

As you have already seen in the previous screencast, every class is specified by

* **Class name** (which is used like any other type specifier, e.g., int, float, or bool)
* **Member variables**, 
* **Member functions**.


**Member variables** are defined inside of the class definition to represent the actual data members and / or data structures required and used by the class.

**Member functions** are defined inside of the class definition to represent all of the functionality to access and manipulate the data members and to interact with the object itself.


Additionally, classes consist of 
* **constructor & destructor**, specific member functions
* specification of **access levels** (private, protected, public) 
* potentially, specifications of **relationships** to other classes (e.g., through inheritance, friendships, etc.)


**Please** [refer to this explanation](http://www.cppforschool.com/tutorial/classobject.html) for an example of classes and objects.

### Constructor & Destructor

Every class has two special member functions called 
constructor and destructor. As the name suggests, the constructor is required to **construct** the object and to initialize all of the data members of the class whereas the destructor is required to properly **destroy** the object and its data members when its lifetime ends.

**Please** [refer to this explanation](http://www.cppforschool.com/tutorial/constructor.html) to get a better understanding of the functionality.

Every C++ class must have a constructor as well as a desctructor. This constructor is always called when an object of that class is being instantiated. The destructor is called when the object's lifetime ends.

#### The default constructor

If the class does not specify a constructor, the **compiler generates a default constructor automatically**. This is the case, for example, in the ofApp class. The default constructor initializes all data members to their default values.

```cpp

TODO

```

#### The user-defined constructor

Every class can also **have (additional) user-defined constructors** which can be used to directly initialize member variables to specific values other than the default values. The function prototypes of the constructors must differ from each other! 


```cpp

TODO

```

#### Destructor

Like the constructor, every class must specify a  destructor. If the class does not have an explicit default destructor, **the compiler generates one automatically**. Destructors are particularly important when a class member variable allocates dynamic memory — as we will see soon.


```cpp

TODO

```
---
Check out this screencast to learn about class design with C++:

*Attention: The video may take a couple of minutes to load.*

[![oop intro](assets/screencast.png)]()

---

### Access Levels

Access levels helps you define how you want your object be used and how you want the data members and function members be access **from outside of the class**.

- **Public** Every member variable and/or function defined under public can be accessed from outside of the class. 

- **Protected** Every member variable and/or function defined under protected can be accessed from inside of the class and from inside of the inherited class(es) only — not from outside of the class

- **Private** Every member definition in a class is declared as private by default — if not specified otherwise. Every member variable and/or function defined under private can only be accessed from inside of the class — not from outside of the class

#### Abstraction

Access levels are a C++ mechanism to support abstraction. 
In that regard, 
- The public keyword specifies the interface level of a class
- The protected keyword specifies the inheritance and hierarchical level
- The private keyword specifies the implementation details level, i.e., every 

--- 

Check out this screencast to learn about access levels with C++:

*Attention: The video may take a couple of minutes to load.*

[![oop intro](assets/screencast.png)]()

---

#### Design Aspects

A rule of thumb for good class design is to ensure that  data members are *private* and can be accessed and manipulated by *public* function members. This way, a **solid public interface** can be designed which remains *as is* even when the underlying data members change. Additionally, this way any kind of manipulation of member variable values is restricted to the class only.


### Object Instantiation & Member Access

The advantage of object-oriented programming is

- To translate real-world concepts into digital concepts
- To use several objects of the same class in the ofApp without having to repeat code
- To configure unique objects following the specification defined in the class


### Classes, Header, and Definition Files

On a software design level, the [separation of header and definition files](http://www.cppforschool.com/tutorial/separate-header-and-implementation-files.html) clearly supports to distinguish between 

- **The what** - software interfaces, e.g., like class design and declarations, and
- **The how** - implementation details, e.g., like object instanciations and definitions in general.


Software interfaces describe **what** kind of functionality is available whereas implementation details describe **how** the functionality is implemented. It makes sense to separate both aspects, for example, when you think of OpenGL which provides a common software interface (API) and at the same time comes with different OpenGL implementations (OpenGL libraries/drivers) per platform and graphics card. The same is true in the context of the openFrameworks SDK.

# The Frame Buffer Object

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


# Additional C++ Specifics

## C++ Standard Library 

## Type Conversion

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


