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
    VAOname=material->getVAOName();
}
/////////////////////////////////////////////////////////////////////
gameObjectMaterial::~gameObjectMaterial(){
    clear();
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
    texture->deleteTexture();
    texture=NULL;
}
/////////////////////////////////////////////////////////////////////
gameObjectMaterial &gameObjectMaterial::operator =(gameObjectMaterial *material){
    *texture=*material->getTexture();
    return *this;
}
/////////////////////////////////////////////////////////////////////
bool gameObjectMaterial::operator ==(gameObjectMaterial &material){
    if(*texture!=*material.getTexture()){
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
    size+=texture->getSizeInBytes();
    return size;
}

