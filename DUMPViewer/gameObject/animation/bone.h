#ifndef BONE_H
#define BONE_H

#include <glm/glm.hpp>
#include <gameObject/animation/nodeobject.h>


class bone : public nodeObject
{
public:
    bone();
    glm::mat4 getOffsetMatrix() const;
    void setOffsetMatrix(const glm::mat4 &value);

protected:
    glm::mat4 offsetMatrix;



};

#endif // BONE_H
