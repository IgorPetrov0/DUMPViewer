#version 330 core

           layout(location=1) in vec3 position;
           layout(location=2) in vec2 texCoord;
           out vec2 tC;
           uniform mat4 projectionMatrix;

           void main(void)
           {
                   gl_Position   = projectionMatrix * vec4(position, 1.0);
                   tC=texCoord;
           }