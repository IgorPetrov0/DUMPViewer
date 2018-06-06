#ifndef EDITABLELOD_H
#define EDITABLELOD_H

#include "gameObject/lod.h"
#include "editabelgraphicobject.h"

class editableLOD : public editabelGraphicObject, public LOD
{
public:
    editableLOD();    
    editableLOD(LOD *lod);

};

#endif // EDITABLELOD_H
