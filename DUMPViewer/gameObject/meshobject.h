#ifndef MESHOBJECT_H
#define MESHOBJECT_H

#include <string>
#include "gameObject/dArray.h"
#include "gameindexobject.h"
#include "mathPrimitives/vector3.h"
#include "defines.h"

using namespace std;

class meshObject
{
public:
    meshObject();
    meshObject(meshObject *mesh);
    virtual ~meshObject();
    void setVertexAtributes(dArray<vertexCoordinates> *array);
    dArray<vertexCoordinates> *getVertexAtributesArray();
    const vertexCoordinates *getVertexesPointer();
    arraySize getVertexseSize();
    vector3 getBoundBox();
    unsigned int getNumIndicesObjects();
    gameIndexObject *getIndexObject(unsigned int index);
    void setBoundBox(vector3 box);
    bool isEmpty();
    void clear();//очистка данных меша, которые переносятся в видеопамять
    meshObject *operator =(meshObject &mesh);
    bool operator ==(meshObject &mesh);
    bool operator !=(meshObject &mesh);
    virtual unsigned int getSizeInBytes();
    void setVaoName(unsigned int value);
    unsigned int getVboName() const;
    void setVboName(unsigned int value);

protected:
    dArray<vertexCoordinates> *vertexAtributesArray;//массив вершин
    dArray<gameIndexObject*> *indicesObjectsArray;//массив индексных объектов.
    vector3 boundBox;
    unsigned int vboName;//храним имя vbo для возможности удаления буфера из видеопамяти


};

#endif // MESHOBJECT_H
