// Compared to version GLSL v1.2, GLSL v1.5 brings in more flexibility
// and supports a slightly different use of built-in variables
// than v1.2. Check the openFrameworks examples in the shaders folder.
// All examples support OpenGL v2 and OpenGL v3.

// OpenGL v3.0 supports GLSL v1.5
// #version 150

// OpenGL 2.0 supports GLSL 1.2
#version 120

// Main task of the fragment shader is to set the fragment value, i.e.,
// specify the gl_FragColor variable that represents the pixel color per vertex.
// In older GLSL versions, the color value can be
// accessed through the built-in variable gl_Color.

void main()
{
    //gl_FragColor = gl_Color;                        // use the built-in variable as "defined" in the app
    gl_FragColor = vec4( 1.0, 0.0, 0.0, 1.0 );    // explicitly set a pixel color;
}
