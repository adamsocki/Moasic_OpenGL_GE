
#version 330 core

in vec2 texcoord;

uniform sampler2D texture0;
uniform sampler2D texture1;
uniform float time;

out vec4 color;

void main() {

    //svec2 uv = texcoord;
   /// texture0.g += texture1.g;
    //vec4 textureContrib0 = texture(texture0, uv).rgba;
   // vec4 textureContrib1 = texture(texture1, uv).rgba;
    //textureContrib0.g += textureContrib1.r;

     //vec4 textureContrib = texture(texture0, uv).rgba;

    color.rgba = mix(texture(texture0, texcoord), texture(texture1, texcoord), 0.65);
    //color.r *= 0.5;
    
    //color.r *= textureContrib1.g;
    //color.rgba = textureContrib;

}
