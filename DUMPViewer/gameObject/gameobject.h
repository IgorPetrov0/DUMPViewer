#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string.h>
#include <iostream>
#include <vector>
#include "gameObject/graphicobject.h"
#include "gameObject/phisycobject.h"
#include "gameObject/gameobjectmaterial.h"
#include "gameObject/lod.h"
#include "gameObject/dArray.h"




//объект игрового мира. содержит данные в пригодном для движка виде
//состоит из графической модели, физической модели, шейдеров, конфигов
using namespace std;

class gameObject
{
public:
    gameObject();
    gameObject(string name);
    virtual ~gameObject();
    void setName(string name);
    dArray<LOD *> *getLODsArray();
    string getName();
    bool phisicSubObjectExsist();
    gameObject &operator =(gameObject &object);
    bool operator ==(gameObject &object);
    bool operator !=(gameObject &object);
    unsigned int getSizeInBytes();
    arraySize rigidBodyesCount();
    arraySize constraintsCount();

    virtual void setPhisycObject(phisycObject *pObject = NULL);
    virtual phisycObject *getPhisycObject();
    virtual bool LODExsist(unsigned int LODNumber);
    virtual LOD *getLod(unsigned int LODNumber);
    virtual unsigned int LODsSize();
    virtual void setLodsArray(dArray<LOD*> *dArray);
    virtual graphicObject *getMainMesh();
    virtual void setMainMesh(graphicObject *mesh);
    virtual bool mainMeshExsist();

protected:
    graphicObject *mainMesh;
    dArray<LOD*> *LODs;
    phisycObject *pObject;
    string name;//имя объекта





};

#endif // GAMEOBJECT_H
