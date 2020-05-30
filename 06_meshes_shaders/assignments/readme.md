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

This task is assigned in two alternativ formats, 1.1 complex coding task, 1.2 concept and coding mix. Do not hesitate to mix both approaches!

#### 1.1 Spotlight Texture Shader Implementation (8 pts)

##### 1.1.1 App-side Implementation

In the code example screen_grab_tex_shader in the CGObjectManager class, implement the function 

- void createSpotlightTexture(const ofImage& screenImg)

> Alternative wording: I the code example screen_grab_tex_shader you can find the CGObjectManager class. It contains pseudocode for a function called

> - void createSpotlightTexture(const ofImage& screenImg).

> Checkout the function for more details and make sure that you understand the code to accomplish this task.

> Subsequently implement the function. 

> ein vorher/nachher Bild, je achdem wie die lösung aussehen soll wäre super 

##### 1.1.2 Shader Fix

Once you process the textures with the shader program, you will notice that the result looks different from the image manipulation solution.

> das müsste vielleicht schon in 1.1.1. erwähnt werden?

Try to fix the calculation of the shader mask in the fragment shader. 

If you cannot solve the issue, comment the code: What goes wrong and what needs to be done theoretically to fix the issue?

#### 1.2 Shader Concept & Shader Exercise (8 pts)

##### 1.2.1 Spotlight Texture Shader Concept

If task 1.1 is too complex and you cannot solve the implementation, 
> unglückliche Formulierung
comment the code in function *void createSpotlightTexture(const ofImage& screenImg)*:
- What needs to be done inside of the function in order to create the spotlight texture? Give a rough outline.
>  für mich sieht es so aus als gäbe es die  spotlight texture schon
- Which objects and functions will you have to use therefore? 
- At which point exactly have you been stuck in the implementation?
> Verständnis der Aufgabenstellung

#### 1.2.2 Shader Texture Tests

Select the code example 04_mesh_shader_intro and play around with it. Understand the code and adapt the application to your liking. For example, change the image, change the texture, change the shader, change the mesh, and change the interaction. Try to move the mesh as a whole. Turn the application into an individual creative coding sketch.

> ok, das habe ich nicht gemacht, vielleicht hätte ich erst alle codebeispiele lesen müssen um die Aufgaben zu verstehen

### Bonus - Refactoring 5 pts

Review the screen_grab_tex_shader application in terms of code design. Come up with up to 5 improvements that will increase the readability and comprehensibility of the code. Add your code improvement requests as comments to the code and implement one improvement.

--- 

> NOTE: Always keep reference types in mind, in particular in conjunction with the keyword **const**.
> What does **constexpr** mean in this context?
