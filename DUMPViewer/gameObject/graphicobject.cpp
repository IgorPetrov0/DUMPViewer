#include "graphicobject.h"

graphicObject::graphicObject()
{   
    materialsArray=NULL;
    texCoordsArray=NULL;
    visible=true;
}
///////////////////////////////////////////////////////////
graphicObject::~graphicObject(){
    clear();
}
///////////////////////////////////////////////////////////
void graphicObject::clear(){
    meshObject::clear();
    delete texCoordsArray;

    materialsArray->deletePointers();
    delete materialsArray;

    materialsArray=NULL;
    texCoordsArray=NULL;
}
///////////////////////////////////////////////////////////
void graphicObject::setMaterials(dArray<gameObjectMaterial*> *array){
    if(array!=NULL){
        materialsArray=array;
    }
}
//////////////////////////////////////////////////////////////////////
dArray<float> *graphicObject::getTexCoordArrayPointer(){
    return texCoordsArray;
}
//////////////////////////////////////////////////////////////////////
dArray<gameObjectMaterial*> *graphicObject::getMaterialsArrayPointer(){
    return materialsArray;
}
//////////////////////////////////////////////////////////////////////
gameObjectMaterial *graphicObject::getMaterialPointer(unsigned int index){
    return materialsArray->operator [](index);
}
///////////////////////////////////////////////////////////////////////////
unsigned int graphicObject::getMaterialsSize(){
    return materialsArray->getSize();
}
///////////////////////////////////////////////////////////////////////////////
graphicObject &graphicObject::operator =(graphicObject &gObject){
    *texCoordsArray=*gObject.getTexCoordArrayPointer();
    *materialsArray=*gObject.getMaterialsArrayPointer();
    return *this;
}
///////////////////////////////////////////////////////////////////////////////
bool graphicObject::operator ==(graphicObject &gObject){
    if(*texCoordsArray!=*gObject.getTexCoordArrayPointer()){
        return false;
    }
    if(*materialsArray!=*gObject.getMaterialsArrayPointer()){
        return false;
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////
bool graphicObject::operator !=(graphicObject &gObject){
    return !operator ==(gObject);
}
///////////////////////////////////////////////////////////////////////////////
bool graphicObject::isVisible(){
   return visible;
}
///////////////////////////////////////////////////////////////////////////////
void graphicObject::setVisible(bool visible){
    this->visible=visible;
}
///////////////////////////////////////////////////////////////////////////////
void graphicObject::setTexCoordinates(dArray<texCoordinates> *array){
    delete texCoordsArray;
    texCoordsArray=array;
}
////////////////////////////////////////////////////////////////////////////////
unsigned int graphicObject::getSizeInBytes(){
    unsigned int size=0;
    unsigned int arSize=0;

    size+=meshObject::getSizeInBytes();

    size+=sizeof(arraySize);//место под размер массива
    if(texCoordsArray!=NULL){
        size+=texCoordsArray->getSize()*sizeof(texCoordinates);
    }

    size+=sizeof(arraySize);//место под размер массива
    arSize=materialsArray->getSize();
    for(unsigned int n=0;n!=arSize;n++){
        size+=materialsArray->operator [](n)->getSizeInBytes();
    }
    size+=sizeof(bool);//запас под visible
    return size;
}
///////////////////////////////////////////////////////////////////////////////////
void graphicObject::reloadVideoData(){





}
//////////////////////////////////////////////////////////////////////////////////////////
arraySize graphicObject::getTexCoordsSize(){
    return texCoordsArray->getSize();
}
