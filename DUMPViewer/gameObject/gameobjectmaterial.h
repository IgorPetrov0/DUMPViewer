#ifndef GAMEOBJECTMATERIAL_H
#define GAMEOBJECTMATERIAL_H

#include <iostream>
#include <string>
#include "gameObject/dArray.h"
#include "gameObject/gameobjecttexture.h"
#include "gameObject/slaveobject.h"
#include "glm/glm.hpp"

struct MatProperties
{
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    glm::vec3 emission;
    float shines;
};


using namespace std;

class gameObjectMaterial : public slaveObject
{
public:
    gameObjectMaterial();
    gameObjectMaterial(gameObjectMaterial *material);
    ~gameObjectMaterial();
    dArray<unsigned int> *getIndices();
    string getName();
    unsigned int getVAOName();
    unsigned int getOGLTextureName();
    gameObjectTexture *getDiffuseTexture();
    void setName(string name);
    void setVAOName(unsigned int name);
    void addTexture(gameObjectTexture *tex);
    void clear();
    void setIndicesArray(dArray<unsigned int> *indices);
    gameObjectMaterial &operator =(gameObjectMaterial *material);
    bool operator ==(gameObjectMaterial &material);
    bool operator !=(gameObjectMaterial &material);
    unsigned int getSizeInBytes();
    const MatProperties *getMatProperties() const;
    void setMatProperties(const MatProperties &value);
    bool getArray(int size, int *offsets, unsigned char *array);

protected:
    string name;
    gameObjectTexture *diffuseTexture;
    unsigned int VAOname;
    MatProperties matProp;
    int propertiesCount;


};

#endif // GAMEOBJECTMATERIAL_H
