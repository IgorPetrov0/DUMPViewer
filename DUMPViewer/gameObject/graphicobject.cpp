#include "graphicobject.h"

graphicObject::graphicObject()
{   
    visible=true;
    lightSorces=NULL;
    bonesArray=NULL;
    rootNode=NULL;
    emptyNodes=NULL;
    animationsArray=NULL;
}
///////////////////////////////////////////////////////////
graphicObject::~graphicObject(){
    if(lightSorces!=NULL){
        lightSorces->deletePointers();
        delete lightSorces;
    }
    if(bonesArray!=NULL){
        bonesArray->deletePointers();
        delete bonesArray;
    }
    if(emptyNodes!=NULL){
        emptyNodes->deletePointers();
        delete emptyNodes;
    }
    if(animationsArray!=NULL){
        animationsArray->deletePointers();
        delete animationsArray;
    }
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
////////////////////////////////////////////////////////////////////////////////
unsigned int graphicObject::numLights(){
    return lightSorces->getSize();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
string graphicObject::getVertexShaderFileName() const{
    return vertexShader;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
string graphicObject::getFragmentShaderFileName() const{
    return fragmentShader;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
GLuint graphicObject::getGLShaderProgram() const{
    return GLShaderProgram;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void graphicObject::setGLShaderProgram(const GLuint &value){
    GLShaderProgram = value;
}



