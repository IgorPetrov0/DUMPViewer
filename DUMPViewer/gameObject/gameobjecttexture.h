#ifndef GAMEOBJECTTEXTURE_H
#define GAMEOBJECTTEXTURE_H

#include <string>
#include <QDataStream>
#include <QtGui/QOpenGLFunctions_3_3_Core>
#include "gameObject/dArray.h"
#include "gameObject/slaveobject.h"
#include "DevIL/include/il.h"
#include "DevIL/include/ilu.h"


using namespace std;

class gameObjectTexture : public slaveObject
{
public:
    gameObjectTexture();
    gameObjectTexture(gameObjectTexture *texture);
    ~gameObjectTexture();
    dArray<unsigned char> *getTexturePointer();
    bool loadFromFile(string name, string path);
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
    void addOuner();
    void deleteTexture();
    GLint getOGLFormat() const;
    GLint getDataType() const;
    bool isExistInOpenGL();

protected:
    dArray<unsigned char> *textureArray;//указатель на массив текстуры
    string name;
    unsigned int oglName;//имя, присваеваемое OpenGL при создании текстуры
    int tWidth,tHeigth;
    GLint format;
    GLint dataType;
    void convertFormat();
    bool existInOpenGL;//маркер существования текстуры. Присваивается, когда текстура создается в видеопамяти. TODO:предусмотреть отключение маркера
};

#endif // GAMEOBJECTTEXTURE_H
