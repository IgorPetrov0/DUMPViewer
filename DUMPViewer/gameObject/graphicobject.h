#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include <string.h>
#include "gameObject/meshobject.h"
#include "gameObject/dArray.h"
#include "gameObject/gameobjectmaterial.h"
#include "mathPrimitives/vector3.h"
#include "gameObject/gameobjecttexture.h"
#include "defines.h"


using namespace std;

class graphicObject : public meshObject
{
public:
    graphicObject();
    virtual ~graphicObject();
    void setMaterials(dArray<gameObjectMaterial*> *dArray);
    void setTexCoordinates(dArray<texCoordinates> *dArray);
    dArray<float> *getTexCoordArrayPointer();
    arraySize getTexCoordsSize();
    dArray<gameObjectMaterial*> *getMaterialsArrayPointer();
    gameObjectMaterial* getMaterialPointer(unsigned int index);
    unsigned int getMaterialsSize();
    void clear();
    graphicObject &operator =(graphicObject &gObject);
    bool operator ==(graphicObject &gObject);
    bool operator !=(graphicObject &gObject);
    bool isVisible();
    void setVisible(bool visible);
    unsigned int getSizeInBytes();
    void reloadVideoData();


protected:
    dArray<texCoordinates> *texCoordsArray;//массив текстурных координат
    dArray<gameObjectMaterial*> *materialsArray;//массив материалов
    bool visible;

};

#endif // GRAPHICOBJECT_H
