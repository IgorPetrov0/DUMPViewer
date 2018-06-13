#include "gameobjectmaterial.h"

gameObjectMaterial::gameObjectMaterial()
{
    VAOname=0;   
    diffuseTexture=NULL;
}
/////////////////////////////////////////////////////////////////////
gameObjectMaterial::gameObjectMaterial(gameObjectMaterial *material){
    if(material==this){
        return;
    }
    diffuseTexture = new gameObjectTexture(material->getDiffuseTexture());
    VAOname=material->getVAOName();
}
/////////////////////////////////////////////////////////////////////
gameObjectMaterial::~gameObjectMaterial(){
    clear();
}
/////////////////////////////////////////////////////////////////////
unsigned int gameObjectMaterial::getOGLTextureName(){
    return diffuseTexture->getOglName();
}
/////////////////////////////////////////////////////////////////////
gameObjectTexture *gameObjectMaterial::getDiffuseTexture(){
    return diffuseTexture;
}
/////////////////////////////////////////////////////////////////////
void gameObjectMaterial::setVAOName(unsigned int name){
    VAOname=name;
}
/////////////////////////////////////////////////////////////////////
void gameObjectMaterial::addTexture(gameObjectTexture *tex){
    tex->addOwner();
    diffuseTexture=tex;
}
/////////////////////////////////////////////////////////////////////
unsigned int gameObjectMaterial::getVAOName(){
    return VAOname;
}
/////////////////////////////////////////////////////////////////////
void gameObjectMaterial::clear(){
    diffuseTexture->release();
}
/////////////////////////////////////////////////////////////////////
gameObjectMaterial &gameObjectMaterial::operator =(gameObjectMaterial *material){
    *diffuseTexture=*material->getDiffuseTexture();
    return *this;
}
/////////////////////////////////////////////////////////////////////
bool gameObjectMaterial::operator ==(gameObjectMaterial &material){
    if(*diffuseTexture!=*material.getDiffuseTexture()){
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
    size+=sizeof(arraySize);//запас под количество
    size+=diffuseTexture->getSizeInBytes();
    return size;
}
//////////////////////////////////////////////////////////////////////////////////
void gameObjectMaterial::setName(string name){
    this->name=name;
}
//////////////////////////////////////////////////////////////////////////////////
string gameObjectMaterial::getName(){
    return name;
}
