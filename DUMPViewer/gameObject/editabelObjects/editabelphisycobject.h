#ifndef editabelPhisycObject_H
#define editabelPhisycObject_H

#include <QVector>
#include "gameObject/phisycobject.h"
#include "editabelrigidbody.h"

class editabelPhisycObject : public phisycObject
{
public:
    editabelPhisycObject();
    editabelPhisycObject(phisycObject *object);
    virtual ~editabelPhisycObject();
    void addRigidBody(editabelRigidBody *body);
    void removeRigidBody(rigidBody *body);
    editabelRigidBody *getRigitBody(int index);
    void compilePhisicObject();

    int rigidBodyesCount();
    int constraintsCount();

    bool isExist();

protected:
    QVector<editabelRigidBody*> rigidBodiesVector;
    QVector<constraint*> constraintsVector;//массив шарниров


};

#endif // editabelPhisycObject_H
