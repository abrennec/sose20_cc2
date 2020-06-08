
#version 120

// Introduce some newer features to the older GLSL version.
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable


uniform vec4 scale;
//varying vec4 vertex_color;


void main()
{
    // Scale the vertex in world space.
    //glm::vec4 scale{1.0, 0.75, 0.75, 1.0};
    vec4 scale2 = scale + vec4(0.75, 1.0, 0.0, 0.0);
    vec4 pos = gl_Vertex * scale2;

    // Translate the scaled position.
    pos += vec4(650.0, 200.0, 0.0, 1.0);

    // Calculate the projected position in clip space.
    gl_Position = gl_ModelViewProjectionMatrix * pos;
    

    // Set the texture coordinates by specifying the built-in vertex
    // attribute gl_TexCoord[0] with the texture coordinate of the
    // bound texture. By default, the texture coordinate of the bound
    // texture is held in the built-in variable gl_MultiTexCoord0.
    // The texture coordinates are interpolated per pixel based on the
    // initally specified texture coordinates held in gl_MultiTexCoord0.
    gl_TexCoord[0] = gl_MultiTexCoord0;
    //gl_FrontColor = gl_Color;
}


// Note from "Mastering openFrameworks" on texture coords:
// "Such an interpolation is one of the most important things in the
// shaders' technology, so let's look at it more closely. In our case,
// we will draw an image on the screen with shaders. Drawing an image
// technically means that openFrameworks renders a textured rectangle
// using OpenGL. The rectangle is drawn by specifying the four vertices'
// coordinates and texture coordinates and binding the corresponding
// image texture. The vertex shader processes these four vertices,
// and OpenGL rasterizes the rectangle as a number of pixels. Then
// each pixel is processed by our fragment shader and the texture
// coordinates for each pixel gl_TexCoord[0] are the result of
// interpolation of texture coordinates of vertices in correspondence
// to the relation between the pixel's position and the position of
//the four vertices."

// Note from "Mastering openFrameworks" on color variables:
// "The last line of the vertex shader gl_FrontColor = gl_Color is not
// necessary for this example, but can be effective for your future use
// of the shader. gl_Color is a built-in variable that is equal to the
// color you set by calling the ofSetColor() function in openFrameworks
// code. gl_FrontColor is a built-in variable that assigns a color for
// the frontal faces of 3D and 2D objects. We draw 2D images using these
// frontal sides, so this value is passed to the fragment shader as a
// built-in gl_Color variable. So you can make the result of the fragment
// shader responsive to ofSetColor() callings by changing its last line
//gl_FragColor = color to gl_FragColor = color * gl_Color."
