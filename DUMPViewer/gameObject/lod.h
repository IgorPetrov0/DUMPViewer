#ifndef LOD_H
#define LOD_H

#include "gameObject/graphicobject.h"

class LOD : public virtual graphicObject
{
public:
    LOD();
    void setDistance(float value);
    float getDistance();
    graphicObject *getGraphicObject();
    LOD &operator =(LOD &lod);
    bool operator ==(LOD &lod);
    bool operator !=(LOD &lod);
    virtual unsigned int getSizeInBytes();


protected:
    float LODDistance;


};

#endif // LOD_H
