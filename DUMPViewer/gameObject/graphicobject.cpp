#include "graphicobject.h"

graphicObject::graphicObject()
{   
    visible=true;
}
///////////////////////////////////////////////////////////
graphicObject::~graphicObject(){

}
///////////////////////////////////////////////////////////////////////////////
graphicObject &graphicObject::operator =(graphicObject &gObject){
    return *this;
}
///////////////////////////////////////////////////////////////////////////////
bool graphicObject::operator ==(graphicObject &gObject){
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
////////////////////////////////////////////////////////////////////////////////
unsigned int graphicObject::getSizeInBytes(){
    unsigned int size=0;
    unsigned int arSize=0;

    size+=meshObject::getSizeInBytes();

    size+=sizeof(arraySize);//место под размер массива


    size+=sizeof(arraySize);//место под размер массива
    size+=sizeof(bool);//запас под visible
    return size;
}
///////////////////////////////////////////////////////////////////////////////////
void graphicObject::reloadVideoData(){





}
//////////////////////////////////////////////////////////////////////////////////////////
arraySize graphicObject::getTexCoordsSize(){
    return 0;
}

