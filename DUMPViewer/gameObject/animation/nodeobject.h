#ifndef NODEOBJECT_H
#define NODEOBJECT_H

#include <string>
#include "glm/glm.hpp"
#include "gameObject/dArray.h"


class nodeObject
{
public:
    nodeObject();
    string getName();
    void setName(string name);
    nodeObject *getParent() const;
    void setParent(nodeObject *value);
    glm::mat4 getTransformMatrix() const;
    void setTransformMatrix(const glm::mat4 &value);
    unsigned int numChildren();
    nodeObject *getChild(unsigned int index);
    void setChildsArray(dArray<nodeObject*> *childsArray);

protected:
    string name;
    nodeObject *parent;
    dArray<nodeObject*> *childs;
    glm::mat4 transformMatrix;


};

#endif // NODEOBJECT_H
