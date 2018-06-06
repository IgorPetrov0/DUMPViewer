#ifndef PHISYCOBJECT_H
#define PHISYCOBJECT_H

#include "gameObject/rigidbody.h"
#include "gameObject/constraint.h"

class phisycObject
{
public:
    phisycObject();
    ~phisycObject();
    phisycObject &operator=(phisycObject &pObject);
    bool operator ==(phisycObject &pObject);
    bool operator !=(phisycObject &pObject);
    dArray<rigidBody*> *getRigidBodiesPointer();
    dArray<constraint*> *getConstraintsPointer();
    void setRigidBodyArray(dArray<rigidBody*> *dArray);
    void setConstraintsArray(dArray<constraint*> *dArray);
    unsigned int getSizeInBytes();

    arraySize constraintsCount();
    arraySize rigidBodyesCount();

protected:
    dArray<rigidBody*> *rigidBodiesArray;//массив твердых тел
    dArray<constraint*> *constraintsArray;//массив шарниров

};

#endif // PHISYCOBJECT_H
