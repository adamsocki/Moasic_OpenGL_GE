#version 330 core

layout(location = 0) in vec2 vertexPosition_modelspace;
layout(location = 1) in vec2 in_texcoord;

out vec2 TexCoords;
uniform float time;
void main()
{
    TexCoords = in_texcoord;
    //TexCoords.x += cos(time);

    gl_Position = vec4(vertexPosition_modelspace.x * cos(time), vertexPosition_modelspace.y, 0.0, 1.0); 
}  