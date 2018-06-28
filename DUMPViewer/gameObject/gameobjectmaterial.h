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
    glm::vec4 ambient;
    glm::vec4 diffuse;
    glm::vec4 specular;
    glm::vec4 emission;
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
    MatProperties getMatProperties() const;
    void setMatProperties(const MatProperties &value);

protected:
    string name;
    gameObjectTexture *diffuseTexture;
    unsigned int VAOname;
    MatProperties matProp;



};

#endif // GAMEOBJECTMATERIAL_H
