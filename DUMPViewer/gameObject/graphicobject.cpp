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
//////////////////////////////////////////////////////////////////////////////////////////////////////
void graphicObject::setAnimationsArray(dArray<animation *> *value){
    animationsArray = value;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int graphicObject::numAnimations(){
    if(animationsArray!=NULL){
        return animationsArray->getSize();
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
animation *graphicObject::getAnimation(unsigned int index){
    if(animationsArray!=NULL){
        return animationsArray->operator [](index);
    }
    return NULL;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
animation *graphicObject::getAnimation(string name){
    if(animationsArray!=NULL){
        unsigned int size=animationsArray->getSize();
        for(unsigned int n=0;n!=size;n++){
            animation *tmp=animationsArray->operator [](n);
            if(tmp->getName()==name){
                return tmp;
            }
        }
    }
    return NULL;
}
////////////////////////////////////////////////////////////////////////////////////////////////////


