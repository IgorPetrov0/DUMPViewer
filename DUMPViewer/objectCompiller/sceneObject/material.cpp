#include "material.h"

material::material()
{
    vertexIndicesArray=NULL;
    textureIndicesArray=NULL;
    normalsIndicesArray=NULL;
    Ns=0;
    Ni=0;
    d=0;
    illum=0;
    vertexesCount=0;
    VAOname=0;

}
//////////////////////////////////////
material::~material()
{
    name.clear();
    deleteArrays();
}
////////////////////////////////////////
void material::setName(QString name){
    this->name=name;
}
/////////////////////////////////////////////////////
void material::setVertexIndicesArray(int *array){
    if(vertexIndicesArray!=NULL){
        delete []vertexIndicesArray;
    }
    vertexIndicesArray=array;
}
////////////////////////////////////////////////////////
void material::setTextureIndicesArray(int *array){
    if(textureIndicesArray!=NULL){
        delete []textureIndicesArray;
    }
    textureIndicesArray=array;
}
//////////////////////////////////////////////////////////
void material::setNormalsIndicesArray(int *array){
    if(normalsIndicesArray!=NULL){
        delete []normalsIndicesArray;
    }
    normalsIndicesArray=array;
}
////////////////////////////////////////////////////////////
void material::setVertexesCount(int count){
    vertexesCount=count;
}
////////////////////////////////////////////////////////////
void material::setVAOName(int name){
    VAOname=name;
}
/////////////////////////////////////////////////////////////
unsigned int material::getVertexesCount(){
    return vertexesCount;
}
///////////////////////////////////////////////////////////////////////////////////
int const *material::getNormalsIndicesArrayPointer(){
    return normalsIndicesArray;
}
///////////////////////////////////////////////////////////////////////////////////
int const *material::getVertexIndicesArrayPointer(){
    return vertexIndicesArray;
}
///////////////////////////////////////////////////////////////////////////////////
int const *material::getTextureIndicesArrayPointer(){
    return textureIndicesArray;
}
//////////////////////////////////////////////////////////////////////////////////
QString material::getName(){
    return name;
}
//////////////////////////////////////////////////////////////////////////////////
QString material::getTexureFileName(){
    return mapKd;
}
///////////////////////////////////////////////////////////////////////////////////
int material::getVAOName(){
    return VAOname;
}
//////////////////////////////////////////////////////////////////////////////////
void material::setNs(float value){
    Ns=value;
}
//////////////////////////////////////////////////////////////////////////////////
void material::setKaRGB(QVector3D value){
    KaRGB=value;
}
//////////////////////////////////////////////////////////////////////////////////
void material::setKdRGB(QVector3D value){
    KdRGB=value;
}
//////////////////////////////////////////////////////////////////////////////////
void material::setKsRGB(QVector3D value){
    KsRGB=value;
}
//////////////////////////////////////////////////////////////////////////////////
void material::setNi(float value){
    Ni=value;
}
//////////////////////////////////////////////////////////////////////////////////
void material::setD(float value){
    d=value;
}
//////////////////////////////////////////////////////////////////////////////////
void material::setIllum(float value){
    illum=value;
}
//////////////////////////////////////////////////////////////////////////////////
void material::setMapKd(QString fileName){
    mapKd=fileName;
}
/////////////////////////////////////////////////////////////////////////////////////
void material::clear(){
    deleteArrays();
}
/////////////////////////////////////////////////////////////////////////////////////
void material::deleteArrays(){
    if(vertexIndicesArray!=NULL){
        delete []vertexIndicesArray;
        vertexIndicesArray=NULL;
    }
    if(textureIndicesArray!=NULL){
        delete []textureIndicesArray;
        textureIndicesArray=NULL;
    }
    if(normalsIndicesArray!=NULL){
        delete []normalsIndicesArray;
        normalsIndicesArray=NULL;
    }
}
//////////////////////////////////////////////////////////////////////////////////////
void material::setTextureBitmap(int *array, int size){
    textureBitMap=array;
    textureSize=size;
}
/////////////////////////////////////////////////////////////////////////////////////////
