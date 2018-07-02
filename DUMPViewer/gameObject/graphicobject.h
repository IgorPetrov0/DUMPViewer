#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include <string.h>
#include "gameObject/meshobject.h"
#include "gameObject/dArray.h"
#include "gameObject/gameobjectmaterial.h"
#include "mathPrimitives/vector3.h"
#include "gameObject/gameobjecttexture.h"
#include "defines.h"
#include "gameObject/gameobjectlight.h"
#include "dArray.h"

using namespace std;

class graphicObject : public meshObject
{
public:
    graphicObject();
    virtual ~graphicObject();
    graphicObject &operator =(graphicObject &gObject);
    bool operator ==(graphicObject &gObject);
    bool operator !=(graphicObject &gObject);
    unsigned int getSizeInBytes();
    unsigned int numLights();

protected:
    dArray<gameObjectLight*>*lightSorces;

};

#endif // GRAPHICOBJECT_H
