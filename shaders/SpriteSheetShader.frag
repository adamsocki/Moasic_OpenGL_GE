
#version 330 core

in vec2 texcoord;

uniform sampler2D texture0;
uniform float index_x;
uniform float index_y;
uniform float texture_width;
uniform float texture_height;
uniform float time;

out vec4 color;

void main() {

  // texcoord.x = 10;

    vec2 uv = texcoord;

   // uv.x += (128.0 + time) / 2560.0;
   // uv.y += cos(time);
    uv.x *= (128.0) / 2560.0;
    uv.x += (index_x * 128.0) / 2560.0;
    //uv.x
    //uv.x = 128.0 / 2560.0;
    //uv.x = (1.0 * 128.0) / 2560.0;
   
  //  uv.x += (index_x * 128.0) / 2560.0;
    
   uv.y *= 128.0 / 1664.0;
    uv.y +=  (index_y * 128.0) / 1664.0;
    //uv.y = 1.0;
    //uv.y += (index_y * 128.0) / 1664.0;
    //uv.x *= (188.0) / texture_width.x;
    //uv.x += (index_x * 128.0) / texture_width.x;
   // uv.x *= 0.5;
    //uv.y *= (128.0) / texture_width.y;
    //uv.y += (index_y * 128.0) / texture_width.y;
  // uv.y *= (10.0 * 128.0) / 1664.0;
   //double x = 1280/2560;
   //float x2 = 5.0 / 10.0;
   //uv.x *= x2;
  // uv.y *= 0.1;
   // 
  //  textureContrib.r = 1 - textureContrib.r;
   // textureContrib.g = 1 - textureContrib.g;
   // textureContrib.b = 1 - textureContrib.b;
   // textureContrib.r = 1 - textureContrib.r;
   // uv.x *= number;
   // uv.y *= number;

     // uv *= vec2(0.5, 0.5);
      //uv.x = ; 
      //uv.y += 0.5;
      //texcoord = vec2(0.5, 0.5);
     //Write a custom shader that outputs a blend of two textures.
     // uv.x *= atan(uv.x, uv.y) * time;
     //uv += vec2(0.5 , 0.5);
     vec4 textureContrib = texture(texture0, uv).rgba;
     color.rgba = textureContrib;

    // vec2 uvCenter = vec2(0.5, 0.5);
     //vec2 uvFromCenter = uv - uvCenter;

     //vec2 uvDir = normalize(uvFromCenter);
    //float d = dot(uvDir, vec2(0, -1));

    // float angle = acos(d) * 0.5;
    // vec2 testTexcoord = vec2(0.5, 0.5);
    // vec3 textureContrib = texture(texture0, testTexcoord).rgb;

    //

    // uv *= ((1 + sin(time)) * 0.5);
     

    // uv.x = (1 + cos(uv.y * 3.14)) * 0.5;
    // uv.y = (1 + sin(uv.x * 3.14)) * 0.5;
    
    
    //vec2 uvCenter = vec2(0.5, 0.5) + (0.1 * vec2(cos(time), sin(time)));
    // uv.x += ((1 + sin((time + (uv.y * 8)))) * 0.5);
    // uv.y += time * 0.1;
    // uv.y += time * 0.2 + ((1 + cos((time + (uv.x * 2)))) * 0.5);

    // uv.x += cos(time);
    // uv.y += sin(time);

    // uv = uvFromCenter;
    // uv.x += (1 + cos(uvFromCenter.x * uvFromCenter.y * 8 + time)) * 0.5;
    // uv.y += (1 + sin(uvFromCenter.x * uvFromCenter.y * 8 + time)) * 0.5;

    //uv += vec2(0eff.5, -0.5);

    // uv = vec2(cos(angle) * (uv.x - 0.5) - sin(angle) * (uv.y - 0.5) + 0.5,
    //           cos(angle) * (uv.y - 0.5) + sin(angle) * (uv.x - 0.5) + 0.5);

    //uv += d;
    //uv *= d;

    
    // uv.y *= atan(uv.x, uv.y) * time;
    
    

    //color.rgb = vec3((1 + d) / 2);

    // color.rgb = vec3(0, 0, 0);
    // color.rgb = vec3(uv.x, uv.y, 0);

    //color.rgba = vec4(texcoord.x, texcoord.y, 0, 1);
}
