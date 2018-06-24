#ifndef EDITABELRIGIDBODY_H
#define EDITABELRIGIDBODY_H

#include "gameObject/rigidbody.h"
#include "gameObject/editabelObjects/editabelgraphicobject.h"


class editabelRigidBody : public rigidBody
{
public:
    editabelRigidBody();
    editabelRigidBody(editabelGraphicObject *gObject, meshType source);
    editabelRigidBody(rigidBody *body);
    ~editabelRigidBody();
    void setTexture(gameObjectTexture *texture);
    void compileObject();

    virtual meshObject *getMeshPointer();

protected:
    editabelGraphicObject *erbMesh;


};

#endif // EDITABELRIGIDBODY_H
