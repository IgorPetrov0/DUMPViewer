#ifndef EDITABELGAMEOBJECT_H
#define EDITABELGAMEOBJECT_H

#include <QVector>
#include <vector>
#include "gameObject/gameobject.h"
#include "editabelphisycobject.h"
#include "editabelgraphicobject.h"
#include "editablelod.h"

class editabelGameObject : public gameObject
{
public:
    editabelGameObject();
    editabelGameObject(QString name);
    editabelGameObject(gameObject *object);
    virtual ~editabelGameObject();

    void addLOD(editableLOD *lod, unsigned int index);
    void deleteLOD(unsigned int index);
    void deleteMainMesh();
    void showMainMesh(bool show);
    void showLOD(unsigned int index, bool show);
    void showRigitBody(bool show);
    void showConstraints(bool show);
    void setSave();
    void compileGameObject();
    void addRigiBody(editabelRigidBody *rBody);
    int rigidBodyesCount();
    int constraintsCount();
    bool isSaved();

    virtual void setPhisycObject(phisycObject *object = NULL);
    virtual editabelPhisycObject *getPhisycObject();
    virtual editableLOD *getLod(unsigned int LODNumber);
    virtual bool LODExsist(unsigned int LODNumber);
    virtual unsigned int LODsSize();
    virtual void setLodsArray(dArray<LOD *> *dArray);
    virtual editabelGraphicObject *getMainMesh();
    virtual void setMainMesh(editabelGraphicObject *object);
    virtual bool mainMeshExsist();



protected:
    vector<editableLOD*> LODsVector;
    editabelPhisycObject *epObject;
    bool objectSaved;
    editabelGraphicObject *eMainMesh;

};

#endif // EDITABELGAMEOBJECT_H
