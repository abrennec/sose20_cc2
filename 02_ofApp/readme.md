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

# Learning Objectives

- sine wave examples
- move something around
- get used to the documentation
- find out about a function inside of the code

# C++ Basics

## C++ Syntax

### Types

 - basic built-in types:
 	- **int**:  "integers" represent a whole number like 0, 1, 2, 3, 884675, -2075, etc.
 	- **float**:  "floats" represent numbers with decimal points like 1.0, 1.1, 1974239.08236, -300.75, etc.
 	- **bool**:  a "boolean" value can be either **true** or **false**  

 	```c++
 	int i 	= -100;
 	float f = 12345.6789;
    bool b 	= true;
 	```

### Variables


### Loops

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
 	```

 - _functions_ are blocks of code that can be _called_ later on to run
 	- functions can take _arguments_ (also called _parameters_) as input -  
 		these are values you supply the function when you _call_ it
 	- functions can also _return_ values (or not - its up to you)

 	```c++
    // examples:
    
 	// return an integer
 	int add2Plus2(){
 		return 2 + 2;
 	}
    // use parameters
    int add(int first, int second){
    	return first + second;
    }
    // return nothing
    void emptyFunction(){
    	// this function does nothing
    }
    
 	// call the functions
    int result1 = add2Plus2();
    int result2 = add(2,2);
    emptyFunction();
 	```

- we can print text to the "console" like this:  
	```c++
    cout << "hello world" << endl;
    ```
	 - we can print text ("strings") or numbers like _ints_ and _floats_ 
	 - always start with `cout << ` then the message.  
	 - ` << endl;` adds a new line at the end.  this is optional but keeps your console log

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

- project files


## The ofApp

Every ofApp is by default comprised of three files

- main.cpp -- This is the starting point for every C++ program!
- ofApp.h -- The header file
- ofApp.cpp -- The definition file (also simply called Cpp file)


