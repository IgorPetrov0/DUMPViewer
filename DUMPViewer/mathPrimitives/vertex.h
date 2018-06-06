#ifndef VERTEX_H
#define VERTEX_H

#include "vector3.h"
#include "vector2.h"

class vertex
{
public:
    vertex();
    vector3 getPos();
    vector2 getTexCoord();
    vector3 getNormal();
    void setPos(vector3 pos);
    void setTexCoord(vector2 coord);
    void setNormal(vector3 normal);
    bool operator ==(vertex v);
    bool operator !=(vertex v);
    static unsigned int sizeInFloat();//вовращает размер во float-ах
    unsigned int getSizeInBytes();

protected:
    vector3 pos;//позиция
    vector2 texCoord;//текстурные координаты
    vector3 normal;//нормаль


};

#endif // VERTEX_H
