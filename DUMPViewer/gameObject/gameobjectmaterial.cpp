#include "gameobjectmaterial.h"

gameObjectMaterial::gameObjectMaterial()
{
    VAOname=0;   
    texture=NULL;
}
/////////////////////////////////////////////////////////////////////
gameObjectMaterial::gameObjectMaterial(gameObjectMaterial *material){
    if(material==this){
        return;
    }
    texture = new gameObjectTexture(material->getTexture());
    indicesArray = new dArray<unsigned int>(material->getIndices());
    VAOname=material->getVAOName();
}
/////////////////////////////////////////////////////////////////////
gameObjectMaterial::~gameObjectMaterial(){
    clear();
}
/////////////////////////////////////////////////////////////////////
dArray<unsigned int> *gameObjectMaterial::getIndices(){
    return indicesArray;
}
/////////////////////////////////////////////////////////////////////
unsigned int gameObjectMaterial::getIndecesSize(){
    if(indicesArray!=NULL){
        return indicesArray->getSize();
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////
unsigned int gameObjectMaterial::getOGLTextureName(){
    return texture->getOglName();
}
/////////////////////////////////////////////////////////////////////
gameObjectTexture *gameObjectMaterial::getTexture(){
    return texture;
}
/////////////////////////////////////////////////////////////////////
void gameObjectMaterial::setIndicesArray(dArray<unsigned int> *indices){
    indicesArray=indices;
}
/////////////////////////////////////////////////////////////////////
void gameObjectMaterial::setVAOName(unsigned int name){
    VAOname=name;
}
/////////////////////////////////////////////////////////////////////
void gameObjectMaterial::setTexture(gameObjectTexture *tex){
    texture=tex;
}
/////////////////////////////////////////////////////////////////////
unsigned int gameObjectMaterial::getVAOName(){
    return VAOname;
}
/////////////////////////////////////////////////////////////////////
void gameObjectMaterial::clear(){
    delete indicesArray;
    indicesArray=NULL;
    texture->deleteTexture();
    texture=NULL;
}
/////////////////////////////////////////////////////////////////////
gameObjectMaterial &gameObjectMaterial::operator =(gameObjectMaterial *material){
    *texture=*material->getTexture();
    *indicesArray=*material->getIndices();
    return *this;
}
/////////////////////////////////////////////////////////////////////
bool gameObjectMaterial::operator ==(gameObjectMaterial &material){
    if(*texture!=*material.getTexture()){
        return false;
    }
    if(*indicesArray!=*material.getIndices()){
        return false;
    }
    return true;
}
/////////////////////////////////////////////////////////////////////
bool gameObjectMaterial::operator !=(gameObjectMaterial &material){
    return !operator ==(material);
}
/////////////////////////////////////////////////////////////////////
unsigned int gameObjectMaterial::getSizeInBytes(){
    unsigned int size=0;
    size+=indicesArray->getSize()*sizeof(arraySize);
    size+=sizeof(arraySize);//запас под количество
    size+=texture->getSizeInBytes();
    return size;
}

