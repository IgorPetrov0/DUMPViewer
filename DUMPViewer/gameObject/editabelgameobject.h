#ifndef EDITABELGAMEOBJECT_H
#define EDITABELGAMEOBJECT_H

#include <QVector>
#include "gameObject/gameobject.h"

class editabelGameObject : public gameObject
{
public:
    editabelGameObject();
    editabelGameObject(gameObject *mesh);
    ~editabelGameObject();
    void setMainMesh(graphicObject *mesh);
    void setPhisicSubObject(phisycObject* mesh);
    void addLOD(LOD *mesh);
    void deleteLOD(unsigned int index);

    virtual LOD *getLod(unsigned int LODNumber);
    virtual bool LODExsist(unsigned int LODNumber);
    virtual unsigned int LODsSize();

protected:
    QVector<LOD*> *LODsVector;


};

#endif // EDITABELGAMEOBJECT_H
