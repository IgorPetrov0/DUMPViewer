#ifndef GAMEOBJECTTEXTURE_H
#define GAMEOBJECTTEXTURE_H

#include <string>
#include <QDataStream>
#include "gameObject/dArray.h"

using namespace std;

class gameObjectTexture
{
public:
    gameObjectTexture();
    gameObjectTexture(gameObjectTexture *texture);
    void setName(string tName);
    void setTexturePointer(dArray<unsigned char> *dArray);
    void setWidth(int value);
    void setHeight(int value);
    dArray<unsigned char> *getTexturePointer();
    int width();
    int height();
    gameObjectTexture &operator =(gameObjectTexture &texture);
    bool operator ==(gameObjectTexture &texture);
    bool operator !=(gameObjectTexture &texture);
    string getName();
    unsigned int getOglName();
    void setOglName(unsigned int n);
    void clear();
    unsigned int getSizeInBytes();
    bool isUsed();
    void addOuner();
    void deleteTexture();
    unsigned int getOunerCounter();

protected:
    ~gameObjectTexture();
    dArray<unsigned char> *textureArray;//указатель на массив текстуры
    string name;
    unsigned int oglName;//имя, присваеваемое OpenGL при создании текстуры
    int tWidth,tHeigth;
    unsigned int ounerCounter;//для того, что-бы не удалить, если есть хоть один владелец
};

#endif // GAMEOBJECTTEXTURE_H
