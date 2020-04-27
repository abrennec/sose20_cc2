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
- [Review \& Preview](#review--preview)
- [Interaction \& Interfaces](#interaction--interfaces)
- [Image Representations with openFrameworks](#image-representations-with-openframeworks)
  - [ofImage](#ofimage)
  - [ofPixel](#ofpixel)
  - [ofTexture](#oftexture)
  - [Frame Buffer Objects](#frame-buffer-objects)
- [Rendering Pipeline Revisited](#rendering-pipeline-revisited)
- [Reading Material](#reading-material)
  - [Recap](#recap)
  - [Precap](#precap)
  - [References](#references)

--- 

# Learning Objectives

- Interaction and interfaces
- Image representations
- Frame buffer objects

Time Estimate: This session will approximately take 6-8 hours of time in total including script and assignments. It compensates slightly for the last session that might have taken less than 8 hours. Please send me a note how much time you took for the las

# Review \& Preview

In the last three sessions, we covered three fundamental topics required to get started with C++/openFrameworks based development:

- We looked into the different abstraction layers of hardware, driver software, APIs, SDKs, and finally custom application development to get a better understanding of how the technical components are related and depend on each other.
- We looked into the basics of the C++ programming language, the platform dependent build process, and how we can actually debug an application and dig into the underlying technological structures. 
- We looked into the basics of object-oriented programming to get started with reconsidering the development process from the perspective of objects and components in order to improve our code base and system design in terms of structure and abstraction.

From now on, we will look into **specific topics of openFrameworks** such as image representations and manipulations, audio programming, a glance into shader development and the image processing library openCV that can be integrated into openFrameworks in the form of an addon. We will also take a look at memory management with C++ and continuously review the object-oriented programming paradigms. All of these topics, we will review in the light of **interaction and interfaces**, the main theme of this lecture. 

# Interaction \& Interfaces

Interaction and interfaces  is what we have already touched upon with the first exercises on interactive sine wave drawings as well as with the technical application programming interfaces (APIs) that we briefly discussed. Moreover, we saw a couple of interactive artistic pieces by some of your favorite artists.

In the context of creative coding and creative technologies, we will now start to involve and invite aspects of interaction and interfaces into the practical exercises and we will aim for developing **our own understanding of interaction and interfaces** during the remainder of this course.


In his book "Programming Interactivity", 2009, Joshua Noble discusses several forms of interaction from the perspective of interaction design and interactive digital art programs. According to him, 

> Interaction could be defined as the exchange of information between two or more active participants. The writer and video game designer Chris Crawford describes interaction as “an iterative process of listening, thinking, and speaking between two or more actors.”  Generally, when we’re talking about interaction and programming it’s because one element in the interaction is a computer system of some sort or some control element that a person is trying to get to do something. The person for whom the computer or mechanical system is being designed is called the user, and what the user is using is called the system. There are many different terms floating around today, such as *human computer interaction*, *computer human interaction*, or *experience design*. All mean more or less the same thing: designing a system of some sort that a person can interact with in a way that is meaningful to them. **[JNoble2009, p. 5]**


Moreover, the following excerpt is part of Noble's discussion of the term **interface**:
> The interface is the medium of the communication between the user and the system. It drives a lot of what is possible and what is not possible, what is efficient and what isn’t, and what the tone of the interaction is. If you think about how you talk to someone on the phone versus how you talk to them in person, you’re probably using more hand gestures, facial expressions, and other forms of nonverbal communication in person and being more direct and using your tone of voice more when you are on the phone. What we use to do something affects a lot of how we do that thing. Having a functional, expressive, and attractive interface is very important in creating the means for an interaction to occur. The attractiveness of an interface is an important part of making an interaction pleasant to a use; the colors, text, symmetry, sounds, and graphics are important and are communicative elements that shape a great deal about what a user thinks about your system. **[JNoble2009, p. 9]**

Hence, interaction and interface are closely related concepts. Another essential aspect of the above mentioned discussions on interaction and interface is the term **communication** which could be described as the transfer and exchange of information. 

When reconsidering these concepts and the citations above, what are the main aspects of either interaction and interface? Could you, for example, understand an **interaction** as a formal process description on a technical level? If so, how would you define it?

In contrast, could you, for example, understand an **interface** as a clear specification of how the interaction has to be executed in the first place? What is your take on this interpretation? 

 Considering creative coding and (interactive) digital art, the first part of the homework assignments will revolve around these definitions and terms. Central task will be to come up with an individual or personal definition of interaction, interfaces and communication seen through the eyes of 

- a creative technologist and how you would like to develop/design an application
- an artist and how you would like to interact with an audience
- an audience and how do you perceive interaction in an artistic piece, e.g., made by your favorite artists

Based on that, we will continue finetuning the definitions and will discuss them against the background of the upcoming topics.

# Image Representations with openFrameworks

In openFrameworks, three main classes have been introduced that represent the handling of image data on different levels of abstraction. In particular, these levels of abstraction could be referred to as user level, data level, and graphics or GPU level. The corresponding classes are 

- **ofImage** - user level
- **ofPixels** - data level
- **ofTexture** - graphics or GPU level


openFrameworks essentials:
> There are three classes for working with images:
> • ofImage: This is intended for manipulating the pixel values and drawing an image
> • ofPixels: This is intended for manipulating the pixels values only
> • ofTexture: This is intended for drawing images only


[creative coding 1](https://github.com/ctechfilmuniversity/ws1920_cc1/blob/master/04_processing/cc1_ws1920_04_processing_script.md#images)

The following paragraphs are taken from the "Mastering openFrameworks", Chapter 4, pp. 105).

> The architecture of a computer assumes all images, vector graphics, and 3D objects that will be depicted on the screen should be loaded at first into the video memory. Images in the video memory are called textures. By default, openFrameworks's class ofImage holds two same images. These are the pixel array in RAM that can be accessed by image.getPixels() and its clone, the texture in the video memory that can be accessed by image.getTextureReference().
> 
> So, when you change the pixel array of image, you need to call image.update() in order to apply the changes to the corresponding texture. 
> 
> You may ask why is such a double representation needed? Yes, indeed, it is possible to discard the texture (using the image.setUseTexture( false ) function) and to render the pixel array directly on the screen. But this operation needs to load the pixel array into the video memory anyway, which is a fast but nevertheless time-consuming operation. So, if we did not change the image or wish to draw it several times on the screen, it is better to have a texture for it.
> 
> You can discard a pixel array too. Pixel arrays are just tools for writing images to disks and a convenient way of changing it using CPUs. So, if you do not want to change your image, it is good idea to use only textures, without having pixel arrays in the RAM. To do so, use ofTexture instead of ofImage. In case you are using ofTexture, your image will lie in the video memory only and will not occupy any RAM. So you obtain memory optimization, which is crucial for large projects.

## ofImage 

The first class, **ofImage**, is intended to represent high-level image manipulations such as

- image loading
- image 
- access to pixel object
- access to texture object

According to the ofBook, ofImage is defined as follows:

> The ofImage is the most common object for loading, saving and displaying static images in openFrameworks. Loading a file into the ofImage **allocates an internal ofPixels object** to store the image data. ofImage objects are not merely containers, but also include internal methods and objects (such as an ofTexture) for displaying their pixel data to the screen.


## ofPixel

> This is an openFrameworks container for pixel data which lives inside each ofImage, as well as other classes like ofVideoGrabber. It's a wrapper around a buffer that includes additional information like width and height.

Classically, pixel data is stored in an array of type **unsigned char** that represents positive 8 bit numbers ranging from 0 to 255:

EXAMPLE

In such an array, grayscale data is simply stored as one-channel of 8-bit numbers whereas RGB (red, green, blue) data is stored as three-channels of 8-bit numbers. To do so, the array is simply extended and a corresponding reading and writing paradigm, usually interleaved, is being introduced:

EXAMPLE

## ofTexture

ofBook:
>  This container stores image data in the texture memory of your computer's graphics card (GPU). Many other classes, including ofImage, ofxCvImage, ofVideoPlayer, ofVideoGrabber, ofFbo, and ofKinect, maintain an internal ofTexture object to render their data to the screen.

## Frame Buffer Objects

Frame buffer objects are additional buffer objects that can be used for drawing images. The are also referred to as off-screen buffers as they allow you to draw inside of them and not directly draw to the screen.

ofBook:

>  This is a GPU "frame buffer object", a container for textures and an optional depth buffer. It can be loosely understood as another renderer—a canvas to which you can draw 3D or 2D scenes—whose resulting pixels can themselves be treated like an image. Ultimately the ofFBO is an object stored on the graphics card that represents a rendered drawing pass.

openFrameworks esssentials, p 71:

> The offscreen buffer is a virtual screen in video memory, where we can draw anything just as we can on a real screen. The resultant picture can be used as an image or texture. We can draw it on a real screen, process with shader, or use to texture 3D objects.
>
> In the OpenGL library, which is used by openFrameworks for drawing, the offscreen buffer is called Frame Buffer Object (FBO). Naturally, in openFrameworks, this buffer is maintained by the ofFbo class.

Mastering openframeworks, pp. 48,49:

> FBO in computer graphics stands for frame buffer object. This is an offscreen raster buffer where openFrameworks can draw just like on the screen. You can draw something in this buffer, and then draw the buffer contents on the screen. The picture in the buffer is not cleared with each testApp::draw() calling, so you can use FBO for accumulated drawings.
> fbo has texture of the type ofTexture, which holds its current picture. The texture can be accessed using fbo.getTextureReference(). 

# Rendering Pipeline Revisited



# Reading Material

## Recap 

Revise and Review

- [Preliminaries to Image Processing](https://openframeworks.cc/ofBook/chapters/image_processing_computer_vision.html#preliminariestoimageprocessing)


## Precap

Prepare and Preview

- [Graphics](https://openframeworks.cc/ofBook/chapters/openGL.html)
- Memory Allocation

## References

- [JNoble2009] Joshua Noble (2009): Programming Interactivity. A Designer’s Guide to Processing, Arduino & openFrameworks. Sebastopol, CA: O’Reilly Media Inc.
- [DPIT2015] Denis Perevalov, Igor Tatrnikov (2015): openFrameworks Essentials. Packt Publishing. Birmingham, UK.
- [DPere2013] Denis Perevalov (2013): Mastering openFrameworks: Creative Coding Demystified. Packt Publishing. Birmingham, UK.