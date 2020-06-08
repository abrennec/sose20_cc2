
#version 120


// This variable is not used in the example. Feel free to play around with it here.
uniform vec4 color;

// Varying variables allow to exchange internal information between
// vertex and fragment shaders.
varying vec4 vertex_color;


void main()
{
    // Now set the vertex_color that has been defined in the vertex shader.
    
    gl_FragColor = vertex_color;
    //gl_FragColor = vec4( 1.0, 0.0, 0.0, 1.0 ); //vertex_color;
    //gl_FragColor = gl_Color;

}
