#ifndef GAMEOBJECTLIGHT_H
#define GAMEOBJECTLIGHT_H

#include <string>
#include "glm/glm.hpp"


enum lightType{
    LIGHT_UNDEFINED,
    LIGHT_DIRECTIONAL,
    LIGHT_POINT,
    LIGHT_SPOT,
    LIGHT_AMBIENT
};



struct lightPropetries{
    float angleInnerCone;
    float angleOuterCone;
    float attenuationConstant;
    float attenuationLinear;
    float attenuationQuadratic;
    glm::vec3 cAmbient;
    glm::vec3 cDiffuse;
    glm::vec3 cSpecular;
    glm::vec3 direction;
    glm::vec3 position;
};

class gameObjectLight
{
public:
    gameObjectLight();
    lightType getType() const;
    void setType(const lightType &value);
    const lightPropetries *getProperties() const;
    void setProperties(const lightPropetries &value);
    bool getArray(int size, int *offsets, unsigned char *array);


protected:
    lightType type;
    lightPropetries properties;
    int propertiesCount;




};

#endif // GAMEOBJECTLIGHT_H
