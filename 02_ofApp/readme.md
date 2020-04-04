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
- [Learning Objectives](#learning-objectives)
- [C++ Basics](#c-basics)
  - [General Language Aspects](#general-language-aspects)
  - [Types](#types)
    - [Built-in Types](#built-in-types)
    - [User-defined Types](#user-defined-types)
  - [Variables](#variables)
    - [Initialization & Assignment](#initialization--assignment)
  - [Statically vs Dynamically Typed](#statically-vs-dynamically-typed)
  - [Functions](#functions)
    - [Sequential Execution](#sequential-execution)
    - [Declaration vs Definition](#declaration-vs-definition)
    - [The main Function](#the-main-function)
  - [Header and Definition Files](#header-and-definition-files)
- [Building an ofApp](#building-an-ofapp)
  - [ProjectGenerator](#projectgenerator)
  - [The ofApp](#the-ofapp)
- [Reading Material](#reading-material)
  - [Recap](#recap)
  - [Precap](#precap)

--- 

# Learning Objectives

- Getting started C++ language and syntax aspects
- Understanding header and definition files and their relationship
- Getting to know openFramework's ProjectGenerator
- Developing a first ofApp


# C++ Basics

C++ is a high-level programming language with a rich set of
syntactic and semantic elements that support developers in translating and expressing software concepts and ideas directly in code. C++ has a long history and has undergone several improvements in recent years. It is still one of the languages most used today due to the fact that it supports  low-level ( == close to the hardware) as well as a high-level programming (== close to the human) programming at the same time. 

Of course, there are also several critical voices arguing that C++ is hard to learn, not state-of-the-art, and carries along too many concepts due to its long history. Beware that it will be challenging to understand C++ concepts. However, it will allow you to develop a deeper understanding of 

- how software and hardware interconnect
- the craft of software development 
- where modern programming concepts come from.

To put it short, why C++?

- Improve & expand on general knowledge

C++ is particularly well-known for its support of
- writing very efficient (real-time) 
- programs object-oriented programming
- generic programming


## General Language Aspects

Remember from the previous lesson, C++ is a **compiled programming language**. It requires to be translated into machine code before it can actually be executed on a computer in the form of a C++ application binary. This translation was introduced as **C++ build process**. 

In addition to this C++ is also a **statically typed programming language** which means that all data types  provided by the language (and that an be used in a C++ program) have to be defined at compile time. This means that

- variables have to be associated with a specific data type and
- the type of the variable cannot change during the program's life time.

To better understand what is a statically typed language, let's take a look at C++ types first.

## Types

### Built-in Types
 - basic built-in types:
 	- **int**:  "integers" represent a whole number like 0, 1, 2, 3, 884675, -2075, etc.
 	- **float**:  "floats" represent numbers with decimal points like 1.0, 1.1, 1974239.08236, -300.75, etc.
 	- **bool**:  a "boolean" value can be either **true** or **false**  

 	```c++
 	int i 	= -100;
 	float f = 12345.6789;
    bool b 	= true;
 	```

### User-defined Types

The possibility to specify user-defined types allows
to create completely new data types
to specifically match the application and/or user needs to translate complex concepts into software code
to improve the readability of complex systems

The enumeration type is a user- defined data type that allows to group a list of symbolic constant of type integer
A variable of type Color functions like a constant integer variable

```c++
enum Color {

    red,
    yellow,
    green
};
```

The structure type allows to   combine different kinds of data types inside of one struct
The keyword struct is required to define the data type

```c++
struct Point {

    int x;
    int y;
    bool isVisible;
    Color aColor;
};
```


Typical class interface of an openFrameworks application class
The class prototype is usually defined in the header file *.h whereas the actual implementation 
is defined in the   definition file *.cpp

```c++

```

## Variables 

### Initialization & Assignment

Variables are associated with a certain data type in the code

```c++
float grade {5.0}; int years = 4 + 3; bool test;
auto grade {5.0}; auto years = 4 + 3; auto test;
// uniform initialization
// copy initialization (slower)
// declaration (better do initialization)
// error
```

The newly introduced type auto allows for automatic type deduction — this only works for initializing variables upon
creation 

https://www.learncpp.com/cpp-tutorial/4-8-the-auto-keyword/

## Statically vs Dynamically Typed

```c++
int myIntVar = 10;  // the variable myIntVar is now associated
                    // with the data type "int" 
                    // (representing an integer)
float myFloatVar = 25.765;  // the variable myFloatVar is now associated
                            // with the data type "float" 
                            // (representing a floating point)

myIntVar = myFloatVar;  // copying the value stored in myFloatVar
                        // into myIntVar will result in a "type cast";
                        // as a result, myIntVar will store "25" or "26" 
```


Type checking is executed at compile time
To identify type errors early in the development cycle 

To allocate the required memory at compile time
To ensure faster program execution

In contrast, dynamically typed languages do not associate data types with variables — data types are dynamically defined and checked at run time and variable type associations can change
This is another reason for why interpreted languages are usually slower in execution than statically typed languages 
Examples: python, javascript


<!-- ### Loops

 - _for_ loops run code a set number of times

	```c++
   	for (int i=0; i<10; i++) { 
   		// this will run 10 times
   	}
	```

 - _while_ loops run code until a condition is false

 	```c++
    bool runLoop = true;
 	while (runLoop){
 		// we need to set runLoop false to exit loop
 		// otherwise, we create an "infinite loop"
        runLoop = false;
 	}
 	``` -->

## Functions

Functions are central building blocks of a program that   group statements in logical units & organize the code
Every C++ program requires a main function for program start Main functions are usually stored in main.cpp

Function name — int add (int x, int y) { ... } 
Return type — int add (int x, int y) { ... } 
Parameter (list) — int add (int x, int y) { ... } 
Function body — int add (int x, int y) { ... }

 - _functions_ are blocks of code that can be _called_ later on to run
 	- functions can take _arguments_ (also called _parameters_) as input -  
 		these are values you supply the function when you _call_ it
 	- functions can also _return_ values (or not - its up to you)

```c++

```

### Sequential Execution

### Declaration vs Definition

A function declaration informs the compiler about the existence of the function in the code
It uses a function prototype that includes function name, return type, parameter list & semicolon but no function body
The function definition includes the function body and can be specified at a later point

The separation of declaration and definition is an essential aspect of software design as it supports separating interface design and implementation details
The separation of code into header and definition files applies this approach to source code management and deployment


### The main Function

```c++
#include <iostream>

int main () {

    std::cout << "Hello, CTech World" << std::endl;
    return 0;
}
```


## Header and Definition Files

The job of the header file is to declare all of the functionality that is being implemented in the definition file. This has several advantages such as 
- separating a concept from a specific implementation (where might this be useful?)
- organizing the source code 
- categorizing and abstracting functionality
- what else?

![header_source_01](assets/header_cpp_01.png)  
*Source: https://www.learncpp.com/cpp-tutorial/header-files/*

This is a more complex example that shows how to add functionality to a main.cpp file by including two different header files. The corresponding definition files are not affected by the inclusion. Including different header files will affect the compilation as the additional information will be compiled into the object files. Then, in a next step during linking, the implementation / definition of additional functionality will be linked into the final executable as an additional object file. Compiled languages support the combination and use of different functionalities into one final software program.

![header_source_02](assets/header_cpp_02.png)  
*Source: https://www.learncpp.com/cpp-tutorial/header-files/*



# Building an ofApp

## ProjectGenerator

The Project Generator 
allows you to create your own empty


## The ofApp

Every ofApp is by default comprised of three files

- main.cpp -- This is the starting point for every C++ program!
- ofApp.h -- The header file
- ofApp.cpp -- The definition file (also simply called Cpp file)



# Reading Material

## Recap 

Revise and Review

- [openFrameworks folder structure](https://openframeworks.cc/ofBook/chapters/setup_and_project_structure.html)
- [C++ build process](https://www.learncpp.com/cpp-tutorial/introduction-to-the-compiler-linker-and-libraries/)

## Precap

Prepare and Preview

- [C++ basics](https://openframeworks.cc/ofBook/chapters/cplusplus_basics.html) 
- [cpplearn.com](https://www.learncpp.com): Skim through chapters 1 & 2, read sections 1.1 to 1.4 and 2.1 to 2.3 carefully.
- [openFrameworks functions: setup, update, and draw](https://openframeworks.cc/ofBook/chapters/how_of_works.html)
