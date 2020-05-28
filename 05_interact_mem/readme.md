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
- [Interaction \& Interfaces](#interaction--interfaces)
- [C++ Memory Management](#c-memory-management)
  - [Local Variables & Memory](#local-variables--memory)
  - [References & Pointers](#references--pointers)
  - [Pointers & Memory](#pointers--memory)
  - [Smart Pointers](#smart-pointers)
- [How to Approach Object Oriented Development](#how-to-approach-object-oriented-development)
  - [How to start development?](#how-to-start-development)
  - [How to start actual coding?](#how-to-start-actual-coding)
- [Reading Material](#reading-material)
  - [Recap](#recap)
  - [Precap](#precap)
  - [References](#references)

--- 

# Learning Objectives

- Interaction and interfaces


Time Estimate: This session will approximately take 6-8 hours of time in total including script and assignments. It compensates slightly for the last session that might have taken less than 8 hours. Please send me a note how much time you took for the las


# Interaction \& Interfaces

In his book **Programming Interactivity** [JNoble2009], [Joshua Noble](http://thefactoryfactory.com/#aboutme) discusses several forms of interaction from the perspective of interaction design and interactive digital art programs. According to him, 

> Interaction could be defined as the exchange of information between two or more active participants. The writer and video game designer Chris Crawford describes interaction as “an iterative process of listening, thinking, and speaking between two or more actors.”  Generally, when we’re talking about interaction and programming it’s because one element in the interaction is a computer system of some sort or some control element that a person is trying to get to do something. The person for whom the computer or mechanical system is being designed is called the user, and what the user is using is called the system. There are many different terms floating around today, such as *human computer interaction*, *computer human interaction*, or *experience design*. All mean more or less the same thing: designing a system of some sort that a person can interact with in a way that is meaningful to them. **[JNoble2009, p. 5]**


Moreover, the following excerpt is part of Noble's discussion of the term **interface**:
> The interface is the medium of the communication between the user and the system. It drives a lot of what is possible and what is not possible, what is efficient and what isn’t, and what the tone of the interaction is. If you think about how you talk to someone on the phone versus how you talk to them in person, you’re probably using more hand gestures, facial expressions, and other forms of nonverbal communication in person and being more direct and using your tone of voice more when you are on the phone. What we use to do something affects a lot of how we do that thing. Having a functional, expressive, and attractive interface is very important in creating the means for an interaction to occur. The attractiveness of an interface is an important part of making an interaction pleasant to a use; the colors, text, symmetry, sounds, and graphics are important and are communicative elements that shape a great deal about what a user thinks about your system. **[JNoble2009, p. 9]**

Hence, interaction and interface are closely related concepts. Another essential aspect of the above mentioned discussions on interaction and interface is the term **communication** which could be described as the transfer and exchange of information. 

When reconsidering these concepts and the citations above, what are the main aspects of either interaction and interface? Could you, for example, understand an **interaction** as a formal process description on a technical level? If so, how would you define it?

In contrast, could you, for example, understand an **interface** as a clear specification of how the interaction has to be executed in the first place? What is your take on this interpretation? 


<!-- https://braitsch.github.io/ofxDatGui/ -->


# C++ Memory Management

One of the fundamental strengths of C++ is the way the language deals with data and the associated data types:

- On a design level, data types can be considered as **representations of a concept** with a certain kind of feature set. 
- On a hardware level, the data type determines a **piece of memory** that is allocated at compile-time as well as during run-time.

Remember, C++ is a statically typed language. Data types have to be specified and associated with variables at compile-time  and the variable's type cannot change during run-time.

In the context of memory management, it is important to understand that 
Type checking is executed at compile time 
- To identify type errors early in the development cycle
- To allocate the required memory per variable/object at compile time
- To ensure faster program execution

The following four screencasts will present you with background information required to understand how memory allocation and memory management are handled with C++. In this context, two fundamental data types will be introduced in depth

- **The reference type**
- **The pointer type**

Both are relevant when it comes to efficient data handling as well as manipulation of memory and allocation of memory during run-time.

## Local Variables & Memory

Check out this screencast to get started with object-oriented programming with C++:

*Attention: The video may take a couple of minutes to load.*

[![variables_memory](assets/screencast.png)](https://owncloud.gwdg.de/index.php/s/kUHhYq7tWW0hg6i)

You'll find the [corresponding slides](additional_material/01_local_variables_memory.pdf) in the additional_material folder.


## References & Pointers

Check out this screencast to get started with object-oriented programming with C++:

*Attention: The video may take a couple of minutes to load.*

[![refs ptrs](assets/screencast.png)](https://owncloud.gwdg.de/index.php/s/8phkTrdnzZYeiaA)

You'll find the [corresponding slides](additional_material/02_references_pointers.pdf) in the additional_material folder.


## Pointers & Memory

Check out this screencast to get started with object-oriented programming with C++:

*Attention: The video may take a couple of minutes to load.*

[![ptrs memory](assets/screencast.png)](https://owncloud.gwdg.de/index.php/s/E1OWRTpvxdwnirS)

You'll find the [corresponding slides](additional_material/03_pointers_and_memory.pdf) in the additional_material folder.



## Smart Pointers

Check out this screencast to get started with object-oriented programming with C++:

*Attention: The video may take a couple of minutes to load.*

[![smart pointers](assets/screencast.png)](https://owncloud.gwdg.de/index.php/s/2R4H1MWn7Veiwe7)

You'll find the [corresponding slides](additional_material/04_smart_pointers.pdf) in the additional_material folder.

# How to Approach Object Oriented Development

In correspondence with assignment *3 Screen Grab Img Balls Revisited*, you can watch and work along two screencasts on how to approach the assignment and object oriented programming with C++ in general on a conceptual level as well as on a more practical level starting from scratch:

## How to start development?

*Attention: The videos may take a couple of minutes to load.*
[![howto start concept](assets/screencast.png)](https://owncloud.gwdg.de/index.php/s/Og7McR59CmUxPAx)

You'll find the [corresponding notes](additional_material/howto_start_dev.pdf) in the additional_material folder.

## How to start actual coding?

*Attention: The videos may take a couple of minutes to load.*

[![howto start code](assets/screencast.png)](https://owncloud.gwdg.de/index.php/s/9Y6ftlHQhp3H22J)

You'll find the corresponding code example in the **code/03_screen_grab_from_scratch/** folder.


# Reading Material

## Recap 

Revise and Review

- [Memory in C++](https://openframeworks.cc/ofBook/chapters/memory.html)
- [C++ Pointers](http://www.cplusplus.com/doc/tutorial/pointers/)
- [C++ Pointers and References](https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html)
- [Graphics, Textures, CG Objects in openFrameworks](https://openframeworks.cc/ofBook/chapters/openGL.html)

## Precap

Prepare and Preview

> TBD how we proceed

- [Shaders](https://openframeworks.cc/ofBook/chapters/shaders.html)
- [OOP Inheritance](https://openframeworks.cc/ofBook/chapters/OOPs!.html)

## References

- [JNoble2009] Joshua Noble (2009): Programming Interactivity. A Designer’s Guide to Processing, Arduino & openFrameworks. Sebastopol, CA: O’Reilly Media Inc.
- [DPIT2015] Denis Perevalov, Igor Tatrnikov (2015): openFrameworks Essentials. Packt Publishing. Birmingham, UK.
- [DPere2013] Denis Perevalov (2013): Mastering openFrameworks: Creative Coding Demystified. Packt Publishing. Birmingham, UK.