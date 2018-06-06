#include "editablelod.h"

editableLOD::editableLOD()
{

}
///////////////////////////////////////////////
editableLOD::editableLOD(LOD *lod) :
    editabelGraphicObject((graphicObject *)lod)
{
    LODDistance=lod->getDistance();
}
