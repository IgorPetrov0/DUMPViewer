#include "gameobjectlight.h"

gameObjectLight::gameObjectLight()
{
    properties.angleInnerCone=6.28;
    properties.angleOuterCone=6.28;
    properties.attenuationConstant=0.0;
    properties.attenuationLinear=0.0;
    properties.attenuationQuadratic=0.0;
    properties.cAmbient=glm::vec3(0.5,0.5,0.5);
    properties.cDiffuse=glm::vec3(1.0,1.0,1.0);
    properties.cSpecular=glm::vec3(0.0,0.0,1.0);
    properties.direction=glm::vec3(0.0,-1.0,0.0);
    properties.position=glm::vec3(0.0,5.0,0.0);
    float *d=(float*)&properties;
    type=LIGHT_DIRECTIONAL;
    propertiesCount=10;//устанавливать вручную.
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
bool gameObjectLight::getArray(int size, int *offsets, unsigned char *array){
    if(size!=propertiesCount){
        return false;
    }
    memcpy(array+offsets[0],(void*)&properties.angleInnerCone,sizeof(float));
    memcpy(array+offsets[1],(void*)&properties.angleOuterCone,sizeof(float));
    memcpy(array+offsets[2],(void*)&properties.attenuationConstant,sizeof(float));
    memcpy(array+offsets[3],(void*)&properties.attenuationLinear,sizeof(float));
    memcpy(array+offsets[4],(void*)&properties.attenuationQuadratic,sizeof(float));
    memcpy(array+offsets[5],(void*)&properties.cAmbient,sizeof(glm::vec3));
    memcpy(array+offsets[6],(void*)&properties.cDiffuse,sizeof(glm::vec3));
    memcpy(array+offsets[7],(void*)&properties.cSpecular,sizeof(glm::vec3));
    memcpy(array+offsets[8],(void*)&properties.direction,sizeof(glm::vec3));
    memcpy(array+offsets[9],(void*)&properties.position,sizeof(glm::vec3));
    return true;
}
//////////////////////////////////////////////////////////////////////////
