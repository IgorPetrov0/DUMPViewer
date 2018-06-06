#include "sceneobject.h"

sceneObject::sceneObject()
{

    vertexArray=NULL;
    texturesArray=NULL;
    normalsArray=NULL;
    vertexArraySize=0;
    normalsArraySize=0;
    texturesArraySize=0;

}
/////////////////////////////////////
sceneObject::~sceneObject()
{
    deleteArrays();
    for(int n=0;n!=materialsArray.size();n++){
        delete materialsArray.at(n);
    }
    materialsArray.clear();
}
//////////////////////////////////////////
void sceneObject::addMaterial(material *mat){
    materialsArray.append(mat);
}
//////////////////////////////////////////////////
int sceneObject::getMaterialsSize(){
    return materialsArray.size();
}
///////////////////////////////////////////////////
material *sceneObject::getMaterial(int index){
    if((index>=0)&(index<materialsArray.size())){
        return materialsArray.at(index);
    }
    return NULL;
}
///////////////////////////////////////////////////
void sceneObject::clear(){
    deleteArrays();
    for(int n=0;n!=materialsArray.size();n++){
        materialsArray[n]->clear();
    }
}
//////////////////////////////////////////////////////////////
int sceneObject::getTexturesArraySize(){
    return texturesArraySize;
}
//////////////////////////////////////////////////////////////
int sceneObject::getVertexSize(){
    return vertexArraySize;
}
//////////////////////////////////////////////////////////////////
float const *sceneObject::getVertexArrayPointer(){
    return vertexArray;
}
//////////////////////////////////////////////////////////////////
float const *sceneObject::getTexturesArrayPointer(){
    return texturesArray;
}
//////////////////////////////////////////////////////////////////
void sceneObject::setVertexArray(float *array,int size){
    deleteArrays(DEL_VERTEXES);//сначала удаляем массив.
    //иначе будет утекать память
    vertexArray=array;
    vertexArraySize=size;
}
/////////////////////////////////////////////////////////////////
void sceneObject::setNormalsArray(float *array, int size){
    deleteArrays(DEL_NORMALS);//сначала удаляем массив.
    //иначе будет утекать память
    normalsArray=array;
    normalsArraySize=size;
}
////////////////////////////////////////////////////////////////////
void sceneObject::setTexturesArray(float *array,int size){
    deleteArrays(DEL_TEXTURES);//сначала удаляем массив.
    //иначе будет утекать память
    texturesArray=array;
    texturesArraySize=size;
}
////////////////////////////////////////////////////////////////////
int sceneObject::getFaces(){
    int count;
    for(int n=0;n!=materialsArray.size();n++){
        count+=materialsArray.at(n)->getFacesCount();
    }
    return count;
}
////////////////////////////////////////////////////////////////////
void sceneObject::deleteArrays(int target){

    switch(target){
        case(DEL_ALL):{

        }
        case(DEL_VERTEXES):{
            if(vertexArray!=NULL){
                delete []vertexArray;
                vertexArray=NULL;
            }
            vertexArraySize=0;
            if(target!=DEL_ALL){
                break;
            }
        }
        case(DEL_NORMALS):{
            if(normalsArray!=NULL){
                delete []normalsArray;
                normalsArray=NULL;
            }
            normalsArraySize=0;
            if(target!=DEL_ALL){
                break;
            }
        }
        case(DEL_TEXTURES):{
            if(texturesArray!=NULL){
                delete []texturesArray;
                texturesArray=NULL;
            }
            texturesArraySize=0;
            if(target!=DEL_ALL){
                break;
            }
        }
        case(DEL_GRAPHIC_OBJECT):{
            gObject->deleteArrays();
            if(target!=DEL_ALL){
                break;
            }
        }
    }
}
