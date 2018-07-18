#version 330 core

#define LIGHT_UNDEFINED 0
#define LIGHT_DIRECTIONAL 1
#define LIGHT_POINT 2
#define LIGHT_SPOT 3
#define LIGHT_AMBIENT 4


     in vec2 tC;
     in vec3 fragmentPos;
     in vec3 fragmentNormal;

     uniform sampler2D tex;
     out vec4 color;


     layout(std140) uniform materialParams{
         vec3 ambient;
         vec3 diffuse;
         vec3 specular;
         vec3 emission;
         float shines;
     };

     layout(std140) uniform lightSource{
         float angleInnerCone;//0
         float angleOuterCone;//4
         float attenuationConstant;//8
         float attenuationLinear;//12
         float attenuationQuadratic;//16
         vec3 cAmbient;//32
         vec3 cDiffuse;//48
         vec3 cSpecular;//64
         vec3 direction;//80
         vec3 position;//96
     };

     vec3 ads(){
         vec3 n = normalize(fragmentNormal);
         vec3 s = normalize(position-fragmentPos);
         vec3 v = normalize(-fragmentPos);
         vec3 r = reflect(-s,n);
         return cDiffuse*(ambient + diffuse*max(dot(s,n),1.0) + specular*pow(max(dot(r,v),1.0),shines));
     }


     void main(void)
     {
         //color=texture2D(tex,tC);
         //color=texture(tex,tC);
         //color=vec4(ads(),1.0);//+texture2D(tex,tC);
         float cosTheta= dot(fragmentNormal,vec3(1));
         color=vec4(cDiffuse*cosTheta+diffuse,1.0)+texture2D(tex,tC);
        //color=vec4(emission,1.0)+texture2D(tex,tC);
     }
