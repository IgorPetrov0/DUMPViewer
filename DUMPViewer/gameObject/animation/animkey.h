#ifndef ANIMKEY_H
#define ANIMKEY_H

#include "glm/glm.hpp"


class animKey
{
public:
    animKey();
    double getTime() const;
    void setTime(double value);
    glm::vec3 getValue() const;
    void setValue(const glm::vec3 &value);

protected:
    double time;
    glm::vec3 value;


};

#endif // ANIMKEY_H
