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

### 1 Interaction | 1 pts

Please read the first section of the script on interaction. With your team, review your findings and identify potential correspondences and differences. Highlight them in the WIKI.

### 2 Screen Grab Img Balls Revisited | up to 14 pts

#### 2.1 Understand Function Parameters and References

As a first exercise:

- Remove the member variable "screenImage" and turn it into a local variable in the draw() function.
- How do you have to change the subsequent functions "takeAPicture()" and "drawPixelOverlay()"?
- How would you have to change the code if "takeAPicture" was specified so that it returns an ofImage?

#### 2.2 Pass by reference, pass by value

Pass by reference and pass by value are two approaches to defining the handing over of an argument to a function. This is achieved by specifying the function parameters either to support pass by reference or pass by value. What is meant by each approach? When would you use either of them?

#### 2.3 Image Manipulation

In the application retrieve two images: One image is the screenGrab image that captures the latest position of the ball objects. Another image is either captured from the webCam or an ofImage of your liking. 

Use the screenGrab image as an input to your image manipulation routine. Every pixel that is not black indicates where the brightniess of the webCam image (or individual ofImage) is going to be highlighted or emphasized. Create a resulting image that you display. 

Think about whether you want to display it in the form of a blending operation, on an individual disply or with the help of an fbo.

What would be the benefit of using an fbo?

#### 2.4 Object Orientation

Re-factor the code. Add two new classes to the code. One class is intended to handling all the image manipulation operations. The other class is intended to manage all of the computer generated objects, i.e., the balls as well as the plane object. The ofApp should work as an application interface only that receives information from the user or from the operating system and hands it over to the specialized objects.

Keep reference types in mind, in particular in conjunction with the keyword **const**. What is the difference between **const** and **constexpr** in this context?

#### 2.5 Interaction (bonus like) | 2 additional pts

Identify and note down two ideas for either 

- two interaction concepts or 
- one interaction and one interface concept 

that you would like to implement in the screen grab img example. If you have enough time left, implement your idea. If you have not enough time left, add your idea in the form of comments into the code.