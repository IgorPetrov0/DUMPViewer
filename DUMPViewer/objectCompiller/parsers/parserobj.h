#ifndef PARSEROBJ_H
#define PARSEROBJ_H

#include <QFile>
#include <QFileInfo>
#include <QVector>
#include <QObject>
#include <QImage>
#include "abstractparser.h"




class parserOBJ : public abstractParser
{
    Q_OBJECT

public:
    parserOBJ();
    ~parserOBJ();
    virtual bool readFile(QString fileName);
    void getAllMaterials(QVector<material*> *matArray);//выдает все материалы, которые есть в списке



protected:
    bool parsObj(QFile *file);
    //bool readNumSring(QString *string, unsigned char n,QVector<QString> *outVector);
    bool readNumbers(QString *string, QVector<float> *outVector);//чтение чисел из строки
    bool readVector3(QString *string, QVector3D *target);//читает числа из строки в вектор
    bool readFloat(QString *string, float *target);//читает из строки в переменную
    bool readMaterial(material *mat);//чтение материала из файла библиотеки
    bool readString(QString *string, QString *target);//чтение строки из заданной строки
    void deleteObject();//удаление объекта с проверкой
    QString path;//путь к файлу объекта
    QString mtLib;//имя файла .mtl



};

#endif // PARSEROBJ_H
