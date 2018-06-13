#ifndef GAMEINDEXOBJECT_H
#define GAMEINDEXOBJECT_H

#include "gameObject/gameobjectmaterial.h"
#include "dArray.h"


//класс для хранения индексов материалов. Свойства материала хранятся отдельно т.к.
//нет смысла хранить материалы для каждого объекта

class gameIndexObject
{
public:
    gameIndexObject();
    ~gameIndexObject();
    void addMaterialPointer(gameObjectMaterial *pointer);
    void addIndicesArray(dArray<unsigned int> *indices);
    gameObjectMaterial *getMaterial();
    dArray<unsigned int> *getIndices();
    unsigned int getNumFaces();

protected:
    dArray<unsigned int> *indices;//индексы
    gameObjectMaterial *materialPointer;//указатель на материал

};

#endif // GAMEINDEXOBJECT_H
