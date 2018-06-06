#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "gameObject/rigidbody.h"
#include "mathPrimitives/vector3.h"
#include "bulletengine/LinearMath/btTransform.h"

enum constraintType{//TODO возможно придется делать отдельные классы. Пока так
    CONSTRAINT_POINT_TO_POINT,
    CONSTRAINT_HINGE,
    CONSTRAINT_SLIDER,
    CONSTRAINT_CONE_TWIST,
    CONSTRAINT_GENERIC_6_DOF
};

class constraint
{
public:
    constraint();
    ~constraint();
    constraint* operator =(constraint &constr);
    bool operator ==(constraint &constr);
    bool operator !=(constraint &constr);
    rigidBody *getRigitBodyA();
    rigidBody *getRigitBodyB();    
    vector3 *getPivotA();
    vector3 *getPivotB();
    btTransform *getTransformA();
    btTransform *getTransformB();
    constraintType getType();
    void setRigidBodyA(rigidBody *rb);
    void setRigidBodyB(rigidBody *rb);
    void setPivotA(vector3 *pivot);
    void setPivotB(vector3 *pivot);
    void setTransformA(btTransform *transform);
    void setTransformB(btTransform *transform);
    void setType(constraintType type);
    unsigned int getSizeInBytes();

    string getPointerA();
    string getPointerB();
    void setPointerA(string name);
    void setPointerB(string name);

protected:
   rigidBody *rigitBodyA;
   rigidBody *rigitBodyB;
   string *pointerA;//временные указатели на rigidBodies. Существуют только на время загрузки
   string *pointerB;
   vector3 *pivotA;
   vector3 *pivotB;
   btTransform *transformA;
   btTransform *transformB;
   constraintType type;

};

#endif // CONSTRAINT_H
