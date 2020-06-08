
#version 120

// Common variable type qualifiers in shaders are
// attributes, uniform and varying. These can be built-in or
// user defined values.

// Uniform variables are set for the entire primitive and make up
// a communication between the application and the shader program.
uniform vec4 color;


void main()
{
    // The variable that must be set by the fragment shader
    // is gl_FragColor which represents the pixel color of the vertex

    gl_FragColor = color;
    //gl_FragColor = vec4( 1.0, 0.0, 0.0, 1.0 ); //vertex_color;
    //gl_FragColor = gl_Color;
}
