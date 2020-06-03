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

This work sheet contains two alternative tasks that you can choose, A or B.

### Alternative A:

#### 1 Shader and Meshes | 6 pts

Review the shader intro example and understand the code. 

- Play around with the fragment shader values to create a different visual result.
- Play around with the vertex shader and create a different outline of the mesh.
- Change the mesh and by adding one or more coordinates. Adjust the texture coordinates appropriately. 
- Add another form of interaction to the application, i.e., move the whole mesh around instead of only its vertices.

#### 2 Shader Mask in screen_grab | 4 pts

If task 1.1 is too complex and you cannot solve the implementation, comment the code in function *void createSpotlightTexture(const ofImage& screenImg)*:
- What needs to be done inside of the function in order to create the spotlight texture? Give a rough outline.
- Which objects and functions will you have to use therefore? 
- At which point exactly have you been stuck in the implementation?

--- 

<<<<<<< HEAD
> Alternative wording: I the code example screen_grab_tex_shader you can find the CGObjectManager class. It contains pseudocode for a function called

> - void createSpotlightTexture(const ofImage& screenImg).

> Checkout the function for more details and make sure that you understand the code to accomplish this task.

> Subsequently implement the function. 

> ein vorher/nachher Bild, je achdem wie die lösung aussehen soll wäre super 
=======
### Alternative B: 
>>>>>>> master

#### 1 Spotlight Texture Shader Implementation | 10 pts

<<<<<<< HEAD
Once you process the textures with the shader program, you will notice that the result looks different from the image manipulation solution.

> das müsste vielleicht schon in 1.1.1. erwähnt werden?

Try to fix the calculation of the shader mask in the fragment shader. 
=======
>>>>>>> master

##### 1.1 Spotlight Texture Shader Implementation

In the code example screen_grab_tex_shader in the CGObjectManager class, implement the function 

- void createSpotlightTexture(const ofImage& screenImg)

<<<<<<< HEAD
If task 1.1 is too complex and you cannot solve the implementation, 
> unglückliche Formulierung
comment the code in function *void createSpotlightTexture(const ofImage& screenImg)*:
- What needs to be done inside of the function in order to create the spotlight texture? Give a rough outline.
>  für mich sieht es so aus als gäbe es die  spotlight texture schon
- Which objects and functions will you have to use therefore? 
- At which point exactly have you been stuck in the implementation?
> Verständnis der Aufgabenstellung
=======
Checkout the function for more details and make sure that you understand the code to accomplish this task.
>>>>>>> master

##### 1.2 Shader Fix

Once you process the textures with the shader program, you will notice that the result looks different from the image manipulation solution. Try to fix the calculation of the shader mask in the fragment shader. 

If you cannot solve the issue, comment the code: What goes wrong and what needs to be done theoretically to fix the issue?

<<<<<<< HEAD
> ok, das habe ich nicht gemacht, vielleicht hätte ich erst alle codebeispiele lesen müssen um die Aufgaben zu verstehen
=======
---
>>>>>>> master

### Bonus - Refactoring | 5 pts

Review the screen_grab_tex_shader application in terms of code design. Come up with up to 5 improvements that will increase the readability and comprehensibility of the code. Add your code improvement requests as comments to the code and implement one improvement.

--- 

> NOTE: Always keep reference types in mind, in particular in conjunction with the keyword **const**.
> What does **constexpr** mean in this context?
