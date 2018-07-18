#ifndef EDITABLELOD_H
#define EDITABLELOD_H

#include "gameObject/lod.h"
#include "editabelgraphicobject.h"

class editableLOD : public editabelGraphicObject, public LOD
{
public:
    editableLOD();    
    editableLOD(LOD *lod);
    editableLOD(editabelGraphicObject *object,float distance);


};

#endif // EDITABLELOD_H
