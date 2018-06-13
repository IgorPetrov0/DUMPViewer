#include "gameindexobject.h"

gameIndexObject::gameIndexObject()
{
    indices=NULL;
    materialPointer=NULL;
}
//////////////////////////////////////////////////////////////////////
gameIndexObject::~gameIndexObject(){
    materialPointer->release();
    delete indices;
}
///////////////////////////////////////////////////////////////////////////
void gameIndexObject::addMaterialPointer(gameObjectMaterial *pointer){
    materialPointer=pointer;
    pointer->addOwner();
}
///////////////////////////////////////////////////////////////////////////
void gameIndexObject::addIndicesArray(dArray<unsigned int> *indices){
    if(this->indices!=NULL){
        delete this->indices;
    }
    this->indices=indices;
}
////////////////////////////////////////////////////////////////////////////
gameObjectMaterial *gameIndexObject::getMaterial(){
    return materialPointer;
}
//////////////////////////////////////////////////////////////////////////////
dArray<unsigned int> *gameIndexObject::getIndices(){
    return indices;
}
//////////////////////////////////////////////////////////////////////////////
unsigned int gameIndexObject::getNumFaces(){
    return indices->getSize();
}
