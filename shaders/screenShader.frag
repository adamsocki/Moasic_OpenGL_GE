#version 330 core


out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D screenTexture;
uniform float time;

void main()
{
   
   
   vec2 uv = TexCoords;

    
    
    vec3 col = texture(screenTexture, uv).rgb;
     col.r += cos(time) * 0.4;
     uv.y += sin(time);
    //scol.r += ((1 + sin(time)) * 0.5);
    FragColor = vec4(col, 1.0);


//    FragColor = texture(screenTexture, TexCoords);
//    float average = 0.2126 * FragColor.r + 0.7152 * FragColor.g + 0.0722 * FragColor.b;
//    FragColor = vec4(average, average, average, 1.0);
} 
