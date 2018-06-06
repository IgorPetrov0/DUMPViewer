#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "gameObject/meshobject.h"
#include "gameObject/graphicobject.h"
#include "mathPrimitives/vector3.h"


enum rigidBodyType{
    RIGID_BODY_MOVABLE,
    RIGID_BODY_STATIC
};

enum meshSource{
    MESH_NOMESH,
    MESH_ORIGINAL,
    MESH_MAIN_MESH,
    MESH_LOD1,
    MESH_LOD2,
    MESH_LOD3,
    MESH_LOD4
};

class rigidBody
{
public:
    rigidBody();
    rigidBody(graphicObject *object, meshSource source);
    ~rigidBody();
    rigidBody& operator = (rigidBody &body);
    bool operator ==(rigidBody &body);
    bool operator !=(rigidBody &body);
    vector3 &getMassCenter();
    float getMass();
    dArray<unsigned int> *getIndicesPointer();
    void setIndicesArray(dArray<unsigned int> *iArray);
    void createMeshObject(graphicObject *object);
    void setMeshObject(meshObject *object);
    void setMassCenter(vector3 mCenter);
    void setMass(float mass);
    unsigned int getSizeInBytes();
    meshSource getSource();
    void setSource(meshSource source);
    void setType(rigidBodyType type);
    rigidBodyType getType();

    virtual meshObject *getMeshPointer();

protected:
    void createIndicesArray(graphicObject *object);

    meshObject *rbMesh;//указатель на меш
    meshSource rbSource;//источник меша для твердого тела
    dArray<unsigned int> *indicesArray;
    float mass;
    vector3 massCenter;
    rigidBodyType rbType;

};

#endif // RIGIDBODY_H
