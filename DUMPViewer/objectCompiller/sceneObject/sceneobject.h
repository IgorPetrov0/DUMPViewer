#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <QString>
#include <QVector>
#include "objectCompiller/sceneObject/material.h"
#include "mathPrimitives/vertex.h"

enum{//перечислитель для функции удаления
    DEL_ALL,//удалить все
    DEL_VERTEXES,
    DEL_NORMALS,
    DEL_TEXTURES,
    DEL_GRAPHIC_OBJECT
};


//класс объекта сцены. Промежуточный класс между файловыми форматами и gameObject -ом. Хранит информацию о модели в рассортированном виде
//из него потом компилируется все остальное
class sceneObject
{
public:
    sceneObject();
    ~sceneObject();
    void addMaterial(material *mat);

    //создание массивов
    void setVertexArray(float *array,int size);
    void setNormalsArray(float *array, int size);
    void setTexturesArray(float *array,int size);

    unsigned int getMaterialsSize();//возвращает количество материалов в объекте
    int getVertexSize();//возвращает количество вершин
    int getTexturesArraySize();//возвращает количество текстурных координат
    int getNormalsArraySize();//возвращает количество нормалей
    int getFaces();//считает количество полигонов во всех материалах

    //получение указателей на массивы
    float const *getVertexArrayPointer();
    float const *getTexturesArrayPointer();
    float const *getNormalsArrayPointer();
    material *getMaterial(int index);//возвращает указатель на материал по индексу

    void clear();//выгрузка данных из памяти

protected:
    QVector<material*>materialsArray;
    float *vertexArray;//массив вершин
    float *normalsArray;//массив нормалей
    float *texturesArray;//массив текстурных координат
    //размеры соответствующих массивов
    int vertexArraySize;
    int normalsArraySize;
    int texturesArraySize;

    void deleteArrays(int target=DEL_ALL);//безопасное удаление массивов








};

#endif // SCENEOBJECT_H
