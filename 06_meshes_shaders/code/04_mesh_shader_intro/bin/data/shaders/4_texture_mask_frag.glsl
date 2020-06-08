
#version 120

// Introduce some newer features to the older GLSL version.
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable


uniform sampler2DRect tex0;     // "bound" texture
uniform sampler2DRect texture1;     // Second texture

void main()
{
    
    // Retrieve the texture coord of the pixel currently being
    // processed by the shader.
    vec2 pos = gl_TexCoord[0].xy;
    
    // Retrieve the color value of the textures at position "pos".
    vec4 texel0 = texture2DRect( tex0, pos );   // lion texture
    vec4 texel1 = texture2DRect( texture1, pos ); // mask texture
    
    //Compute resulted color
    vec4 outputColor;
    outputColor.rgb = texel0.rgb;       // lion's image
    outputColor.a = texel1.r;           // mask
    
    //Output of the shader
    gl_FragColor = outputColor;
}
