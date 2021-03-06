#ifndef MESHOBJECT_H
#define MESHOBJECT_H

#include <string>
#include "gameObject/dArray.h"
#include "mathPrimitives/vector3.h"
#include "defines.h"

using namespace std;

class meshObject
{
public:
    meshObject();
    meshObject(meshObject *mesh);
    virtual ~meshObject();
    void setVertexes(dArray<vertexCoordinates> *dArray);
    dArray<vertexCoordinates> *getVertexArray();
    const vertexCoordinates *getVertexesPointer();
    arraySize getVertexseSize();
    string getName();
    vector3 getBoundBox();
    unsigned int getTrianglesCount();
    void setBoundBox(vector3 box);
    void setTrianglesCount(unsigned int count);
    void setName(string name);
    bool isEmpty();
    void clear();
    meshObject *operator =(meshObject &mesh);
    bool operator ==(meshObject &mesh);
    bool operator !=(meshObject &mesh);
    virtual unsigned int getSizeInBytes();

protected:
    dArray<vertexCoordinates> *vertexesArray;//массив вершин
    string *meshName;//имя нужно только для редактора и создается в функции setName
    unsigned int *trianglesCount;//аналогично имени
    vector3 boundBox;


};

#endif // MESHOBJECT_H
