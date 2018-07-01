#version 330 core

       layout(location=1) in vec3 position;
       layout(location=2) in vec2 texCoord;
       layout(location=3) in vec3 normal;


       uniform mat4 MVPMatrix;
       uniform mat4 modelMatrix;
       uniform mat4 normalMatrix;
       uniform vec3 cameraPos;

       out vec2 tC;
       out vec3 fragmentPos;
       out vec3 fragmentNormal;




       void main(void)
       {
           tC=texCoord;
           fragmentPos = (modelMatrix * vec4(position,1.0)).xyz;
           fragmentNormal = (modelMatrix * vec4(normal,0.0)).xyz;
           gl_Position = MVPMatrix * vec4(position, 1.0);
       }
