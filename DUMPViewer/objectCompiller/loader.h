#ifndef LOADER_H
#define LOADER_H

#include <QObject>
#include <QFileInfo>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/mesh.h>
#include <assimp/types.h>
#include <assimp/postprocess.h>
#include "objectCompiller/parsers/parserobj.h"
#include "objectCompiller/parsers/parserdae.h"
#include "gameObject/graphicobject.h"
#include "mathPrimitives/vector3.h"
#include "defines.h"

using namespace Assimp;

class loader
{
public:
    loader();
    bool loadGraphicObject(graphicObject *gObject, QString fileName);
    void setTexturesVector(QVector<gameObjectTexture*> *texturesVector);
    QString getLastError();

protected:
    bool compileGraphicObject(sceneObject *sObject, graphicObject *gObject);
    bool parseMeshFile(QString fileName, sceneObject **object);
    bool loadTexture(gameObjectTexture *texture);//читает текстуру из файла
    unsigned int findVertex(vertex *ver, vector<vertex *> *dArray);//ишет вершину в массиве вершин, возвращает ее позицию в массиве
    vector3 calculateBoundBox(sceneObject *object);

    QString error;
    QString path;
    QVector<gameObjectTexture*> *l_texturesVector;
};

#endif // LOADER_H
