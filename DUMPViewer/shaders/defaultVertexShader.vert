#version 330 core

       layout(location=1) in vec3 position;
       layout(location=2) in vec2 texCoord;
       layout(location=3) in vec3 normal;


       #define LIGHT_UNDEFINED 0
       #define LIGHT_DIRECTIONAL 1
       #define LIGHT_POINT 2
       #define LIGHT_SPOT 3
       #define LIGHT_AMBIENT 4

       struct lightSource{
           float angleInnerCone;
           float angleOuterCone;
           float attenuationConstant;
           float attenuationLinear;
           float attenuationQuadratic;
           vec3 cAmbient;
           vec3 cDiffuse;
           vec3 cSpecular;
           vec3 direction;
           vec3 position;
       };

       uniform lightSource light;

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
