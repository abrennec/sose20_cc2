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

### 1 Shader Mask Implementation 8 pts

In the code example screen_grab_tex_shader in the CGObjectManager class, implement the function 

- void createSpotlightTexture(const ofImage& screenImg)

Checkout the function for more details and make sure that you understand the code to accomplish this task.


### 2 Shader fixes 4 pts

Once you process the textures with the shader program, you will notice that the result looks different from the image manipulation solution. Try to fix the mask calculation in the shader.

### 3 Refactoring 3 pts

The application sketch is ok, but not too good of a code design. Come up with 3 or more improvements that will increase the readability and comprehensibility of the code. Implement at least one improvement. Feel free to add additional improvements as comments to the code.

--- 

> NOTE: Always keep reference types in mind, in particular in conjunction with the keyword **const**.
> What does **constexpr** mean in this context?
