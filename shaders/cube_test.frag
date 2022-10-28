#version 330 core

in vec4 fs_color;
out vec4 fragColor;
in vec3 fs_normal;
in vec3 frag_pos;

uniform vec4 lightColor;
uniform float ambientStrength;
uniform vec3 lightPos;

//out vec4 color_;

void main(void){



    // diffuse 
    vec3 norm = normalize(fs_normal);
    vec3 lightDir = normalize(lightPos - frag_pos);
    float diff = max(dot(norm, lightDir), 0.0);

    vec3 diffuse = diff * vec3(lightColor);

  //  vec3 ambient = vec3(lightColor) * ambientStrength;
    vec3 ambientVal;
    ambientVal.x = ambientStrength;
    ambientVal.y = ambientStrength;
    ambientVal.z = ambientStrength;

    vec3 ambient = vec3(lightColor) * ambientVal;
    
    
    vec3 result = (ambient + diffuse) * vec3(fs_color);

    //fragColor = vec4(result, 1.0);
    fragColor = vec4(result, 1.0);
    
    
   // vec3 ambient = lightColor * ambientStrength;
   // fragColor = fs_color * ambient;
}

