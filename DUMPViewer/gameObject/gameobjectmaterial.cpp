#include "gameobjectmaterial.h"

gameObjectMaterial::gameObjectMaterial()
{
    VAOname=0;   
    diffuseTexture=NULL;
    propertiesCount=5;
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
    if(diffuseTexture!=NULL){
        diffuseTexture->release();//текстура только освобождается, но не уничтожается т.к. ей еще кто-то может пользоваться
    }
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
    if(diffuseTexture!=NULL){
        diffuseTexture->clear();
    }
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
const MatProperties *gameObjectMaterial::getMatProperties() const{
    return &matProp;
}
//////////////////////////////////////////////////////////////////////////////////
void gameObjectMaterial::setMatProperties(const MatProperties &value){
    matProp = value;
}
//////////////////////////////////////////////////////////////////////////////////
bool gameObjectMaterial::getArray(int size, int *offsets, unsigned char *array){
    if(size!=propertiesCount){
        return false;
    }
    memcpy(array+offsets[0],(void*)&matProp.ambient,sizeof(glm::vec3));
    memcpy(array+offsets[1],(void*)&matProp.diffuse,sizeof(glm::vec3));
    memcpy(array+offsets[2],(void*)&matProp.specular,sizeof(glm::vec3));
    memcpy(array+offsets[3],(void*)&matProp.emission,sizeof(glm::vec3));
    memcpy(array+offsets[4],(void*)&matProp.shines,sizeof(float));
    return true;
}
//////////////////////////////////////////////////////////////////////////////////
void gameObjectMaterial::setName(string name){
    this->name=name;
}
//////////////////////////////////////////////////////////////////////////////////
string gameObjectMaterial::getName(){
    return name;
}
