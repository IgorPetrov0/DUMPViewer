#ifndef ANIMQUATKEY_H
#define ANIMQUATKEY_H

#include "glm/gtc/quaternion.hpp"

class animQuatKey
{
public:
    animQuatKey(); 
    double getTime() const;
    void setTime(double value);
    glm::quat getValue() const;
    void setValue(const glm::quat value);

protected:
    double time;
    glm::quat value;


};

#endif // ANIMQUATKEY_H
