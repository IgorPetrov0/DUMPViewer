#include "graphicobject.h"

graphicObject::graphicObject()
{   
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
    texCoordsArray=NULL;
}
/////////////////////////////////////////////////////////////////////////
dArray<float> *graphicObject::getTexCoordArrayPointer(){
    return texCoordsArray;
}
///////////////////////////////////////////////////////////////////////////////
graphicObject &graphicObject::operator =(graphicObject &gObject){
    *texCoordsArray=*gObject.getTexCoordArrayPointer();
    return *this;
}
///////////////////////////////////////////////////////////////////////////////
bool graphicObject::operator ==(graphicObject &gObject){
    if(*texCoordsArray!=*gObject.getTexCoordArrayPointer()){
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
