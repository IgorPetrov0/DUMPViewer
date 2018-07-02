#include "gameobjectlight.h"

gameObjectLight::gameObjectLight()
{
    properties.angleInnerCone=6.28;
    properties.angleOuterCone=6.28;
    properties.attenuationConstant=0;
    properties.attenuationLinear=1;
    properties.attenuationQuadratic=0;
    properties.cAmbient=glm::vec3(1,1,1);
    properties.cDiffuse=glm::vec3(1,1,1);
    properties.cSpecular=glm::vec3(1,1,1);
    properties.direction=glm::vec3(0,0,-1);
    properties.position=glm::vec3(0,0,0);
    type=LIGHT_DIRECTIONAL;
}
////////////////////////////////////////////////////////////////////////
lightType gameObjectLight::getType() const{
    return type;
}
//////////////////////////////////////////////////////////////////////////
void gameObjectLight::setType(const lightType &value){
    type = value;
}
//////////////////////////////////////////////////////////////////////////
const lightPropetries *gameObjectLight::getProperties() const{
    return &properties;
}
//////////////////////////////////////////////////////////////////////////
void gameObjectLight::setProperties(const lightPropetries &value){
    properties = value;
}
//////////////////////////////////////////////////////////////////////////
