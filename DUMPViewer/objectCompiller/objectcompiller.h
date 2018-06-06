#ifndef OBJECTCOMPILLER_H
#define OBJECTCOMPILLER_H

#include <string.h>
#include "objectCompiller/parsers/parserobj.h"
#include "gameObject/editabelObjects/editabelgameobject.h"
#include "gameObject/gameobjecttexture.h"
#include "mathPrimitives/vertex.h"
#include "gameObject/dArray.h"
#include "defines.h"

#define CHECK_EXIST_OBJECT if(currentObject==NULL){error=QObject::tr("No object.");return false;} //макрос проверки на существование текущего объекта

//класс компилятора объекта. собирает готовый gameObject из графики, конфига и всего остального
//в нем будут все алгоритмы для преобразования данных

using namespace std;

class objectCompiller
{
public:
    objectCompiller();
    void createEmptyObject(QString objectName);//создает пустой объект
    bool addGraphicMesh(QString fileName);
    bool addPhisicMesh(QString fileName);
    editabelGameObject *getCurrentObject();//возвращает указатель на графический объект
    QString getLastError();

protected:
    editabelGameObject *currentObject;
    QString path;//текущий путь, с которым работаем
    bool compileGraphicObject(sceneObject *sObject, graphicObject *gObject);
    bool compilePhisycObject(sceneObject *sObject, editabelPhisycObject *pObject);
    unsigned int findVertex(vertex *ver, vector<vertex *> *dArray);//ишет вершину в массиве вершин, возвращает ее позицию в массиве
    bool loadTexture(gameObjectTexture *texture);//читает текстуру из файла
    bool parseMeshFile(QString fileName, sceneObject *object);
    QString error;

};

#endif // OBJECTCOMPILLER_H
