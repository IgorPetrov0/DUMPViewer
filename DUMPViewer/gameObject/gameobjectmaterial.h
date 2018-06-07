#ifndef GAMEOBJECTMATERIAL_H
#define GAMEOBJECTMATERIAL_H

#include <iostream>
#include <string>
#include "gameObject/dArray.h"
#include "gameObject/gameobjecttexture.h"


using namespace std;

class gameObjectMaterial
{
public:
    gameObjectMaterial();
    gameObjectMaterial(gameObjectMaterial *material);
    ~gameObjectMaterial();
    dArray<unsigned int> *getIndices();
    unsigned int getIndecesSize();
    unsigned int getVAOName();
    unsigned int getOGLTextureName();
    gameObjectTexture *getTexture();
    void setVAOName(unsigned int name);
    void setTexture(gameObjectTexture *tex);
    void clear();
    void setIndicesArray(dArray<unsigned int> *indices);
    gameObjectMaterial &operator =(gameObjectMaterial *material);
    bool operator ==(gameObjectMaterial &material);
    bool operator !=(gameObjectMaterial &material);
    unsigned int getSizeInBytes();

protected:
    gameObjectTexture *texture;
    unsigned int VAOname;
};

#endif // GAMEOBJECTMATERIAL_H
