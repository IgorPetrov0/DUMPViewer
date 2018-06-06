#ifndef MATERIAL_H
#define MATERIAL_H

#include <QString>
#include <QVector>
#include <QVector3D>

class material
{
public:
    material();
    ~material();
    void setName(QString name);
    void setVertexesCount(int count);//устанавливает кол-во вершин
    void setVertexIndicesArray(int *array);
    void setTextureIndicesArray(int *array);
    void setNormalsIndicesArray(int *array);
    void setTextureBitmap(int *array, int size);
    void setVAOName(int name);//задает идентификатор VAO

    ///////////////////////////////
    //задания свойств материала
    void setNs(float value);
    void setKaRGB(QVector3D value);
    void setKdRGB(QVector3D value);
    void setKsRGB(QVector3D value);
    void setNi(float value);
    void setD(float value);
    void setIllum(float value);
    void setMapKd(QString fileName);
    ///////////////////////////////

    unsigned int getVertexesCount();//возвращает количество вершин
    int getVAOName();//возвращает идентификатор VAO
    QString getName();
    QString getTexureFileName();//возвращает имя файла текстуры
    int const *getVertexIndicesArrayPointer();
    int const *getNormalsIndicesArrayPointer();
    int const *getTextureIndicesArrayPointer();

    void clear();//очистка видеоданных

protected:
    QString name;
    int *vertexIndicesArray;//массив вершинных индексов
    int *textureIndicesArray;//массив текстурных индексов
    int *normalsIndicesArray;//массив индексов нормалей
    int *textureBitMap;//текстура в битовом формате
    int textureSize;//количество байт в битмапе текстуры
    int vertexesCount;//количество вершин
    //оптические свойства материала
    float Ns;//блеск материала
    QVector3D KaRGB;//фоновое(ambient)отражение материала в формате RGB
    QVector3D KdRGB;//диффузное отражение материала в формате RGB
    QVector3D KsRGB;//зеркальное отражение материала в формате RGB
    float Ni;//оптическая плотность материала
    float d;//растворение (прозрачность)
    float illum;//собственное свечение материала
    QString mapKd;//путь к файлу текстуры
    int VAOname;//идентификатор VAO

    void deleteArrays();//безопасное удаление массивов

};

#endif // MATERIAL_H
