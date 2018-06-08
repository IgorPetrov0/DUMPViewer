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

protected:
    dArray<unsigned int> *indices;//индексы вперемешку вершины/нормали/текстуры
    gameObjectMaterial *materialPointer;//указатель на материал

};

#endif // GAMEINDEXOBJECT_H
