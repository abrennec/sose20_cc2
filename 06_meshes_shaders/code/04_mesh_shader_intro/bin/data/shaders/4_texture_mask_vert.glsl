
#version 120

// Introduce some newer features to the older GLSL version.
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable



void main()
{
    // Calculate the projected position in clip space with built-in function.
    gl_Position = ftransform();
    

    // Set the texture coordinates by specifying the built-in vertex
    // variable gl_TexCoord[0] with the texture coordinate of the
    // bound texture. By default, the texture coordinate of the bound
    // texture is held in the built-in variable gl_MultiTexCoord0.
    // The texture coordinates are interpolated per pixel based on the
    // initally specified texture coordinates held in gl_MultiTexCoord0.
    
    // gl_TexCoord is a varying variable that communicates the texture
    // information to the fragment shader
    // gl_MultiTexCoord0 is an attribute variable that communicates the
    // texture information from the application to the vertex shader
    gl_TexCoord[0] = gl_MultiTexCoord0;
}
