#include "gameindexobject.h"

gameIndexObject::gameIndexObject()
{
    indices=NULL;
    materialPointer=NULL;
    size=0;
}
//////////////////////////////////////////////////////////////////////
gameIndexObject::~gameIndexObject(){
    materialPointer->release();//материал только отпускается, но не уничтожается т.к. им еще может кто-то пользоваться
    if(!materialPointer->isUsed()){
        delete materialPointer;
    }
    if(indices!=NULL){
        delete indices;
    }
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
    size=this->indices->getSize();
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
    return size/3;
}
////////////////////////////////////////////////////////////////////////////////
unsigned int gameIndexObject::getIndicesCount(){
    return indices->getSize();
}
///////////////////////////////////////////////////////////////////////////////////
unsigned int gameIndexObject::getEbo() const{
    return ebo;
}
////////////////////////////////////////////////////////////////////////////////
void gameIndexObject::setEbo(unsigned int value){
    ebo = value;
}
////////////////////////////////////////////////////////////////////////////////
void gameIndexObject::clear(){
    if(indices!=NULL){
        delete indices;
        indices=NULL;
    }



    materialPointer->clear();
}
