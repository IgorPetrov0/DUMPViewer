#ifndef VECTOR3_H
#define VECTOR3_H

#include "vector2.h"

class vector3: public vector2
{
public:
    vector3();
    void setZ(float z);
    float z();
    bool operator ==(vector3 v);
    bool operator !=(vector3 v);

protected:
    float zCoord;


};

#endif // VECTOR3_H
