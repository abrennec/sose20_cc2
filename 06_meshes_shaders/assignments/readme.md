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

#### 1 Shader and Meshes | 6 pts

Review the shader intro example and understand the code. 

- Play around with the fragment shader values to create a different visual result.
- Play around with the vertex shader and create a different outline of the mesh.
- Change the mesh and by adding one or more coordinates. Adjust the texture coordinates appropriately. 
- Add another form of interaction to the application, i.e., move the whole mesh around instead of only its vertices.


#### 2 Shader Mask in screen_grab | 4 pts

Now apply your knowledge to the CGObjectManager class in the screen_grab_tex_shader project. In this class you will find the function

- *void createSpotlightTexture(const ofImage& screenImg)*

This function is intended to calculate the spotlight image with the help of a shader similarly to what the *createSpotlighImage* function is doing on a pixel by pixel basis in the ImgManipulation class. Now based on your knowledge from the mesh_shader_intro example, please review the comments inside of th function and add comments that describe what exactly needs to be done in order to implement the generation of the spotlight image with two textures and a shader. In particular, explain the following:

- What needs to be done inside of the function in order to create the spotlight texture? Give a rough outline.
- Which objects and functions will you have to use therefore? 


#### Bonus | 5 pts

#### Alternative A - Implement the Shader Mask in screen_grab_tex_shader

Implement the function following your comments / concept above. 
 
Once you process the textures with the shader program, you will notice that the result looks different from the image manipulation solution. Try to fix the calculation of the shader mask in the fragment shader. 

If you cannot finalize the implementation, comment the code: What goes wrong and what needs to be done theoretically to fix the issue?


#### Alternativ B - Refactor the screen_grab_tex_shader Project

Review the screen_grab_tex_shader application in terms of code design. Come up with up to 5 improvements that will increase the readability and comprehensibility of the code. Add your code improvement requests as comments to the code and implement one improvement.

--- 

> NOTE: Always keep reference types in mind, in particular in conjunction with the keyword **const**.
> What does **constexpr** mean in this context?
