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

     struct materialParams{
         vec3 diffuse;
         vec3 ambient;
         vec3 specular;
         float shines;

     };

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
     uniform materialParams matParam;

     vec3 ads(){
         vec3 n = normalize(fragmentNormal);
         vec3 s = normalize(light.position-fragmentPos);
         vec3 v = normalize(-fragmentPos);
         vec3 r = reflect(-s,n);
         return light.cDiffuse*(matParam.ambient + matParam.diffuse*max(dot(s,n),0.0) + matParam.specular*pow(max(dot(r,v),0.0),matParam.shines));
     }




     void main(void)
     {
         //color=texture2D(tex,tC);
         //color=texture(tex,tC);
         color=vec4(ads(),1.0);
     }
