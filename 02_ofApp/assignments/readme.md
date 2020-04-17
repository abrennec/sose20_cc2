<!-- ---  
title: Creative Coding II
author: Angela Brennecke
affiliation: Film University Babelsberg KONRAD WOLF
date: Summer term 20
---   -->
**Creative Coding II - Summerterm 20**

Prof. Dr. Angela Brennecke | a.brennecke@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*


# Assignments

_Meaningful_ bullet points are sufficient to answer the questions.

## 1) Artistic (2 pts)
### 1.1 Creative Coding

- What does creative coding mean to you?
- What kind of Art pieces does really appeal to you? Pick one piece and share it with the group through the Wiki at the [Art-Pieces Page](https://github.com/ctechfilmuniversity/lecture_creative_coding_2/wiki/Art-Pieces)

Here is also some inspiration: Zach Lieberman is one of the creators and developers of openFrameworks. He works as an artist, developer, educator and posts new sketches on his Instagram on a regular basis. Check out [this talk](https://www.youtube.com/watch?v=xx1eeoo_xnY) of Zach Lieberman to learn more about his work. 

<!-- - [Interview with Zach Lieberman](https://www.theverge.com/2019/5/10/18564182/zach-lieberman-interactive-art-animation-movement-openframeworks-art-club)
- [Talk of Zach Lieberman](https://www.youtube.com/watch?v=bmztlO9_Wvo) -->

## 2) Recap (4 pts)

Check out the code folder in the repository. Inside of it, you'll find two erroneous sketches

- **myRomanticSketch**, which got broken after the screencast and needs fixing; building results in 3 linker errors and 1 compiler issue.
- **myStridePatternSketch**, which is even worse and contains several compile-time (4 issues need to be fixed) and linker errors (1 issue needs to be fixed).

Your task is to:

- Import the projects using ProjectGenerator.
- Build the projects and understand what causes the compiler and linker errors.
- Fix the issues and run the applications.

In your assignment folder, push back the fixed source files. Note down in an *.md file what were the issues that needed to be fixed.

## 3) Programming (4 pts)
### 3.1 Sine Waves

Check out the code folder in the repository. Inside of it, you'll find openFramworks apps by Zach Liebermann from one of his classes: 01_sine to 04_sine.

- Build and run the examples, create the project files with the help of the ProjectGenerator. Review and understand the code.
  - What is ofGetElapsedTimef() function doing?
  - What is ofMap(..) function doing?
- Pick at least one of the examples that appeals to you most and change it to your liking. Try some of these modifications:
  - Work with changes of timing and size.
  - Change the sin functions.
  - Add color to the piece and use the sin function to change the color values.
  - Mix ideas from the examples.
- Add interaction
  - Use ofGetMouseX() and / or ofGetMouseY() to integrate mouse feedback into the piece.

## Bonus (5 pts)

This is an advanced exercise if you feel bored with the rest. Integrate all the different sine wave visualizations from 2.2 into one ofApp. 
- Create a drawing function for each visualization.
- Make use of ofKeyPressed(..) to switch between the visualizations (refer to the blendingExample from the previous session for more details on how to achieve this).
- Would it be possible to blend between the visualizations? 
  - If so, how could you do this?



## Discussion Points

- What is pragma once used for?
- What is an API ? How is the setup / components in your own words?
- What is OpenGL ? How is it related to graphics hardware?