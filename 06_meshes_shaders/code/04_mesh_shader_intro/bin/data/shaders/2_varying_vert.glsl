
#version 120


uniform vec4 scale;
uniform float appWidth;
uniform float appHeight;

// Varying variables allow to exchange internal information between
// vertex and fragment shaders.
varying vec4 vertex_color;


void main()
{
    // Scale the vertex in world space.
    vec4 pos = gl_Vertex * scale;

    // Translate the scaled position.
    pos += vec4(5.0, 0.0, 0.0, 1.0);

    // Calculate the projected position in clip space.
    gl_Position = gl_ModelViewProjectionMatrix * pos;
    
    // Set the varying variable which is going to be evaluated
    // in the fragment shader in the next step.
    float x = pos.x / appWidth;  // 
    float y = pos.y / appHeight;
    vertex_color = vec4(x, y, 0.0, 1.0);
}
