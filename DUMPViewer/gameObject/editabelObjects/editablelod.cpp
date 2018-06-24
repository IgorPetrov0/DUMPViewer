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
//////////////////////////////////////////////////////////
editableLOD::editableLOD(editabelGraphicObject *object, float distance){

    unsigned int size=object->getVertexAtributesArray()->getSize();
    this->vertexAtributesArray = new dArray<vertexCoordinates>(size);
    for(unsigned int n=0;n!=size;n++){
        this->vertexAtributesArray->addElement(n,object->getVertexAtributesArray()->operator [](n));
    }
    size=object->getNumIndicesObjects();
    this->indicesObjectsArray = new dArray<gameIndexObject*>(size);
    for(unsigned int n=0;n!=size;n++){
        gameIndexObject *io = new gameIndexObject(object->getIndexObject(n));
        this->indicesObjectsArray->addElement(n,io);
    }
    this->boundBox=object->getBoundBox();
    this->vboName=object->getVboName();
    setMoveVector(object->getMoveVector());
    setScaleVector(object->getScaleVector());
    setRotateVector(object->getRotateVector());//модельная матрица должна сгенериться автоматически
    this->visible=object->isVisible();
    this->ego_type=object->getViewType();
    this->name=object->getName();
    this->LODDistance=distance;
}
