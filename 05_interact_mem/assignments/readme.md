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

### 1 Interaction | 2 pts

Please read the first section of the script on interaction. With your team, review your findings and identify potential correspondences and differences. Highlight them in the WIKI.

### 2 Screen Grab Img Balls Revisited | up to 18 pts

#### 2.1 Understand Function Parameters and References

As a first exercise:

- Remove the member variable "screenImage" and turn it into a local variable in the draw() function.
- How do you have to change the subsequent functions "takeAPicture()" and "drawPixelOverlay()"?
- How would you have to change the code if "takeAPicture" was specified so that it returns an ofImage?

#### 2.2 Pass by reference, pass by value

Pass by reference and pass by value are two approaches to defining the handing over of an argument to a function. This is achieved by specifying the function parameters either to support pass by reference or pass by value. What is meant by each approach? When would you use either of them?

#### 2.3 Texture Mapping

In the code, an ofPrimitvePlane, a computer generated geometry, is being rotated. Map the webCam image or any other image onto the geometry. 

Therefore, you have to use an ofTexture object. Texture objects specify how the texture image can actually be drawn onto a geometry by specifying texture coordinates. These coordinates can then be connected with the object coordinates. Checkout [this section on textures in the ofBook](https://openframeworks.cc/ofBook/chapters/openGL.html#textures) to learn more about texture binding and texture mapping and check the code for the corresponding function calls.

#### 2.4 Image Manipulation

In the application retrieve two images: One image is the screenGrab image that captures the latest position of the ball objects. Another image is either captured from the webCam or an ofImage of your liking. 

Use the screenGrab image as an input to your image manipulation routine. Every pixel that is not black indicates where the brightniess of the webCam image (or individual ofImage) is going to be highlighted or emphasized. Create a resulting image that you display. 

Think about whether you want to display it in the form of a blending operation, on an individual disply or with the help of an fbo.

What would be the benefit of using an fbo?

#### 2.5 Object Orientation

Re-factor the code. Add two new classes to the code. One class is intended to handling all the image manipulation operations. The other class is intended to manage all of the computer generated objects, i.e., the balls as well as the plane object. The ofApp should work as an application interface only that receives information from the user or from the operating system and hands it over to the specialized objects.

Keep reference types in mind, in particular in conjunction with the keyword **const**. What is the difference between **const** and **constexpr** in this context?
