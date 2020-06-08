// On Shader Versions:
// Compared to version GLSL v1.2, GLSL v1.5 brings in more flexibility
// and supports a slightly different use of built-in variables
// than v1.2. Check the openFrameworks examples in the shaders folder.
// All examples support OpenGL v2 and OpenGL v3.

// OpenGL v3.0 supports GLSL v1.5
// #version 150
// OpenGL 2.0 supports GLSL 1.2
#version 120

// Main task of the vertex shader is to set the vertex position
// in clip space, i.e., define the gl_Position variable.
// In older GLSL versions, the vertex could be
// accessed through the built-in variable gl_Vertex.

void main()
{
    // Calculate the projected position in clip space.
    //gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
    gl_Position = ftransform();
    
    // Alternatively, you could use one matrix here only:
    //gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

}
