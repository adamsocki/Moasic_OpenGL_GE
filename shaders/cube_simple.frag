#version 330 core

in vec4 fs_color;
out vec4 fragColor;
//in vec3 fs_normal;
//in vec3 frag_pos;

//out vec4 color_;

void main(void){



    // diffuse 
//    vec3 norm = normalize(fs_normal);
//    vec3 lightDir = normalize(lightPos - frag_pos);
//    float diff = max(dot(norm, lightDir), 0.0);
//
//    vec3 diffuse = diff * vec3(lightColor);
//
//  //  vec3 ambient = vec3(lightColor) * ambientStrength;
//           
//    // specular
//    float specularStrength = 0.5;
//    vec3 viewDir = normalize(camPos - frag_pos);
//    vec3 reflectDir = reflect(-lightDir, norm);
//    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
//    vec3 specular = specularStrength * spec * vec3(lightColor);  
//
//
//    vec3 ambientVal;
//    ambientVal.x = ambientStrength;
//    ambientVal.y = ambientStrength;
//    ambientVal.z = ambientStrength;
//
//    vec3 ambient = vec3(lightColor) * ambientVal;
//    
//    
//    vec3 result = (ambient + diffuse + specular) * vec3(fs_color);
//
//    //fragColor = vec4(result, 1.0);
//    fragColor = vec4(result, 1.0);

    fragColor = fs_color;
    
    
   // vec3 ambient = lightColor * ambientStrength;
   // fragColor = fs_color * ambient;
}

