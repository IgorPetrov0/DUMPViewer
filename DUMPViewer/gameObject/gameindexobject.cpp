#include "gameindexobject.h"

gameIndexObject::gameIndexObject()
{
    indices=NULL;
    materialPointer=NULL;
    size=0;
    ebo=0;
}
/////////////////////////////////////////////////////////////////////
gameIndexObject::gameIndexObject(gameIndexObject *object)
{
    unsigned int aSize=object->getIndicesCount();
    this->indices = new dArray<unsigned int>(aSize);
    for(unsigned int n=0;n!=aSize;n++){
        indices->addElement(n,object->getIndices()->operator [](n));
    }
    this->addMaterialPointer(object->getMaterial());//материал нужно именно добавлять, чтобы добавился владелец
    this->ebo=object->getEbo();
    this->size=object->getIndicesCount();
}
//////////////////////////////////////////////////////////////////////
gameIndexObject::~gameIndexObject(){
    materialPointer->release();//материал только отпускается, но не уничтожается т.к. им еще может кто-то пользоваться
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
////////////////////////////////////////////////////////////////////////////////
unsigned int gameIndexObject::getIndicesCount(){
    return size;
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
