<!-- ---  
title: Creative Coding II
author: Angela Brennecke
affiliation: Film University Babelsberg KONRAD WOLF
date: Summer term 20
---   -->
**Creative Coding II - Summerterm 20**

Prof. Dr. Angela Brennecke | a.brennecke@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*


# Assignments | optional!

_Meaningful_ bullet points are sufficient to answer the questions - if necessary.


### Creative Concept | 3 pts

Read the script on sound and audio processing with openFrameworks. Think about the scree grab example. How would the integration of sound add to the current application? What would you like to implement? Let your ideas flow.

### Inheritance | 4 pts

Find two examples of class inheritance in the openFrameworks SDK. As a starting point, you could review the relationship between ofApp and ofBaseApp class. Furthermore, find out to what class the audioIn and audioOut functions belong to. Why can these be used inside of ofApp?

### Final Exercise | 3 pts

Start thinking about a final exercise. The requirements are listed in the script. Feel free to come up with an individual idea. Please note that I really would like you to use this exercise as an option to experiment and explore what you have learned in this course. Do not worry if you think your ideas are too small or too big. With the final exercise, I would like you to enjoy the development. So, find some **suggestions** below and please wrap your head around them as well as the content we have addressed throughout the course. Come up with your own idea and interests.

---

# Final Exercise | not optional!

The scope of the final exercise should be similar to the screenGrab refactoring and image processing task; it should not exceed this assignment! Rather, part of the final exercise should also be a phase of inspiration and concept design. 

Find my suggestions below as a starting point.

**Also please note: The final exercise should ideally be presented on the CTech github pages or in your personal portfolios. Therefore, please provide an animated GIF or MP4 screencapture of the result together with a short documentation (based on the documentation template).**

#### Suggestion #1 - Screengrab Continued

Review the screengrab example another time. The current implementation is rather cluttered and combines several different techniques. How would you turn this into an aesthetically pleasing application sketch? What would you remove, what would you add? Here are some ideas.

Add another CG object to the scene which can be interacted with by the user. Re-think the current CG objects and create an object hierarchy - if this makes sense. Ideas for objects:
- Design the object such that it generates audio (see the final_ex_insp_soundBufferExample) and such that the interaction changes the visual form and the generated audio.
- Design the object such that it implements different blending modes (multiplying, colour, hard light, soft light, negative, luminance, ...). Whenever two objects cross each other, the visualization changes based on the set blending mode. (See the initally used blending example for technical details)
- Design an object that leaves a fading trail behind it when animated and think about how this trail could be implemented. Think about a class "trail" and how this could be combined with the CG object(s).
- Design an object that brings collision detection to the application and have it trigger an audio playback whenever two objects hit each other.

Feel free to come up with your own ideas.

#### Suggestion #2 - New Application

Create a new ofApp.

##### 2.1

Combine image processing with computer graphics and explore how you can analyze an image and turn it into a mesh structure for further processing; for instance, think about detecting specific color values, changes in color or brightness, etc. that you could use to create a mesh. Explore the ofPath and ofPolyline objects and their functionalities. The generated mesh should be interacted with.

- reference: https://openframeworks.cc/documentation/graphics/
- code example: final_ex_insp_polyline_brushes

##### 2.2

Visualize audio signals by reading in audio and analyzing the parameters, i.e., loudness. Create a simple mesh-based object and render it using shader technology. Use the audio parameters to specifiy how the object is being rendered. For instance, change the vertices or the colors or both. Have the audio interact with the shader.
- reference: https://openframeworks.cc/documentation/sound/
- code example: final_ex_insp_soundBufferExample


#### Suggestion #3 - Freestyle

Explore the openFrameworks examples and documentation for any kind of further inspiration. Come up with an idea to figure out the scope for the final exercise. Also, check the ofxAddons in the case you would like to use or explore additional functionality. In the examples folder of openFrameworks you will also find examples for most ofxAddons that come with openFrameworks by default. 

##### 3.1 

- For example, you might want to explore the ofxGUI addon and think about improving the style of one of the GUI elements. Check out the examples/gui folder for an example.

- In this context you might also want to explore the ofxOpenCV and ofxCv addons and their examples for a first glance at developing something with openCV. Feel free to explore the examples for an inspiration. 

- In order to explore AR develpoment, checkout the ofxARKit addon. You will need an iPhone to work with this kit.

##### 3.2

Let yourselves be inspired by the simplicity of the code example
  - code example: final_ex_insp_timeExample

How would you turn this example into an audio-visual Arts piece using, i.e., shaders, audio, meshes, images, ..?

