
#version 120

// Common variable type qualifiers in shaders are
// attributes, uniform and varying. These can be built-in or
// user defined values.

// Uniform variables are set for the entire primitive and make up
// a communication between the application and the shader program.
uniform vec4 scale;


void main()
{
    // Scale the vertex in world space.
    vec4 pos = gl_Vertex * scale;
    
    // Translate the scaled position.
    //pos += vec4(5.0, 0.0, 0.0, 1.0);
    
    // Calculate the projected position in clip space.
    gl_Position = gl_ModelViewProjectionMatrix * pos;
}
