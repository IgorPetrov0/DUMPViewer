#version 330 core

    layout(location=1) in vec3 position;
    layout(location=2) in vec2 texCoord;
    layout(location=3) in vec3 normal;

    uniform mat4 MVPMatrix;

    layout(std140) uniform modelMatrices{
        mat4 modelMatrix;
        mat4 normalMatrix;
    };


    out vec2 tC;
    out vec3 fragmentPos;
    out vec3 fragmentNormal;




    void main(void)
    {
        tC=texCoord;
        fragmentPos = normalize(modelMatrix * vec4(position,1.0)).xyz;
        fragmentNormal = normalize(normalMatrix * vec4(normal,0.0)).xyz;
        gl_Position = MVPMatrix * vec4(position, 1.0);
    }
