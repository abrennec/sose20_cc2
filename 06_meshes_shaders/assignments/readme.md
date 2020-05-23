<!-- ---  
title: Creative Coding II
author: Angela Brennecke
affiliation: Film University Babelsberg KONRAD WOLF
date: Summer term 20
---   -->
**Creative Coding II - Summerterm 20**

Prof. Dr. Angela Brennecke | a.brennecke@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*


# Assignments

_Meaningful_ bullet points are sufficient to answer the questions - if necessary.

NOTE: The programming part of task 2 (2.3) from the last work sheet will be integrated into this worksheet.

### 1 Interaction | 1 pts

Please read the first section of the script on interaction. With your team, review your findings and identify potential correspondences and differences. Highlight them in the WIKI.

### 2 Memory Allocation | 4 pts

Please watch the screencasts and additional material on memory allocation in C++. The first two screencasts will be ready at the beginnig of session 05. They focus on automatic memory allocation and local variables as well as reference and pointer data type. The second two screencasts focus on pointers and dynamic memory allocation. This is more advanced topic that we will review when we look into audio programming in particular. The screencasts will be published on Wednesday. Focus on the first two topics first of all.

### 3 Screen Grab Img Balls Revisited | 20 pts

The programming exercise 2.3 from the last session will become part of this programming exercise. The exercise is intended to have you practically recap most of the topics that we have touched on so far. In particular, the subsequent programming exercises are intended for you to practice the following aspects:

- Turn an existing code base (screen grab example) into your own project by
  - Reviewing and refactoring the ofApp design
  - Abstracting from the concrete code base and functionality and applying your object oriented programming skills to re-structuring the code where/if necessary and to introducing new objects that reflect the underyling concepts
- Embrace the graphics rendering and image processing theory practically and get an understanding of how you can actually use and apply the concepts by working with ofImage and/or ofVideoGrabber, ofTexture and ofPixels
- Understand the fundamentals of memory allcoation and recapping what is actually meant by statically typed language as well as 
  - developing an intuition for handling data (in the form of your variables and objects)
  - developing an intuition for how to design your functions and data transfer routines.

#### 2.1 Abstraction and Application Design | 2

Recap the classroom discussion on the different abstract concepts that can be found in the screen grab application example. Reflect on how the code base could look like in order to reflect the different concepts:

- What kind of objects would you introduce?
- How would these objects interact with each other? What would be the "public interface" of the objects?

Draw a simply system diagram of components that indicates how the components relate to each other.

#### 2.2 Function Parameters | 2

As a warm-up exercise:

- Remove the member variable "screenImage" and turn it into a local variable in the draw() function.
- How do you have to change the subsequent functions "takeAPicture()" and "drawPixelOverlay()"?
- How would you have to change the code if "takeAPicture" was specified so that it returns an ofImage?

#### 2.3 Pass by reference, pass by value | 2

Pass by reference and pass by value are two approaches to defining the handing over of an argument to a function. This is achieved by specifying the function parameters either to support pass by reference or pass by value. What is meant by each approach? When would you use either of them?

#### 2.4 Image to Object Mapping | 4

In the code, an ofPrimitvePlane, a computer generated geometry, is being rotated. Map the webCam image or any other image onto the geometry. How could you achieve this? What kind of graphics representation is used for mapping images to a geometry? Is this related to graphics rendering or image processing? Reconsider the rendering pipeline which is used to render 2d or 3d objects and allows for a specific form of mapping images to a geometry.

 Checkout [this section on textures in the ofBook](https://openframeworks.cc/ofBook/chapters/openGL.html#textures) to learn more about how to stick an image to a geometry and review the code example for more hints on how to proceed.

#### 2.5 Image Manipulation & Display | 6

In the application retrieve two images: One image is the screenGrab image that captures the latest position of the ball objects. Another image is either captured from the webCam or an ofImage of your liking. 

Use the screenGrab image as an input to your image manipulation routine. For example, every pixel that is not black indicates where the brightness of the webCam image (or your chosen image) is going to be highlighted or emphasized. Create a resulting image that you can add to the finally rendering image you put on display.

Think about whether you want to display it in the form of a blending operation, on an individual disply or with the help of an fbo. What would be the benefit of using an fbo?

#### 2.6 Object Orientation | 4

Review the first task 2.1 and start to re-factor the code. Based on your concept, new classes to the code. For instance, one class could be intended to handle all the image manipulation operations. Another class could be intended to manage all of the computer generated objects, i.e., the balls as well as the plane object. Consider the ofApp class as an application interface only. As such, the interface receives information from the user or from the operating system and hands it over to the specialized objects.

--- 

> NOTE: Always keep reference types in mind, in particular in conjunction with the keyword **const**.
> What does **constexpr** mean in this context?
