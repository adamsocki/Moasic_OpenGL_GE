#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 in_texcoord;

out vec2 TexCoords;

void main()
{
    TexCoords = in_texcoord;
    gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0); 
}  