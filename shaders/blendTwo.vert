#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 in_texcoord;

uniform mat4 model;
uniform mat4 viewProjection;

//uniform vec3 lightDir;

out vec2 texcoord;

void main() {
    gl_Position =  vec4(vertexPosition_modelspace, 1.0);

    texcoord = in_texcoord;
}

