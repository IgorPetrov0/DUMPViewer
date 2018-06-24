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
    gameIndexObject(gameIndexObject *object);
    ~gameIndexObject();
    void addMaterialPointer(gameObjectMaterial *pointer);
    void addIndicesArray(dArray<unsigned int> *indices);
    gameObjectMaterial *getMaterial();
    dArray<unsigned int> *getIndices();
    unsigned int getIndicesCount();
    unsigned int getEbo() const;
    void setEbo(unsigned int value);
    void clear();//очистка данных, загруженных в видеопамять

protected:
    dArray<unsigned int> *indices;//индексы
    gameObjectMaterial *materialPointer;//указатель на материал
    unsigned int ebo;
    unsigned int size;//размер храним отдельно т.к. при загрузке в видеопамять массив индексов очищается


};

#endif // GAMEINDEXOBJECT_H
