
#version 120

// Introduce some newer features to the older GLSL version.
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable


// This line declares that the shader will use some kind of texture.
// In this case, tex0 indicates this is the texture bound to the
// shader by default in openFrameworks via bind() function call.
// You can also process additional textures with the shader. To do
// so, every texture has to be explicitly set as a uniform texture
// in openFrameworks.
uniform sampler2DRect tex0;


void main()
{
    // Retrieve the texture coord of the pixel currently being
    // processed by the shader. This coordinat is stored in
    // the built-in texture array variable gl_TexCoord[] unless
    // specified differently (in a uniform variable, f.e.).
    
    vec4 color = texture2DRect(tex0, gl_TexCoord[0].st);
    
    color.r = 1.0 - color.r;
    color.g = 1.0 - color.g;
    color.b = 1.0 - color.b;
    
    //color.rg = color.gr;
    
    // Retrieve the color of texture at position "pos" and set
    // the built-in fragment variable.
    gl_FragColor = color;
}
