#include "gameobjecttexture.h"

gameObjectTexture::gameObjectTexture()
{
    name="defaultTexture";
    oglName=0;
    tWidth=24;
    tHeigth=24;
    //создаем дефолтную текстуру на случай, если назначенная материалу структура не загрузилась
    unsigned int size=tWidth*tHeigth*4*sizeof(char);
    textureArray=new dArray<unsigned char>(size);
    for(unsigned int n=0;n!=size;n++){
        textureArray->addElement(n,255);
    }
    ounerCounter=0;
}
//////////////////////////////////////////////////
gameObjectTexture::gameObjectTexture(gameObjectTexture *texture){
    if(texture==this){
        return;
    }
    textureArray = new dArray<unsigned char>(texture->getTexturePointer());
    name=texture->getName();
    oglName=texture->getOglName();
    tWidth=texture->width();
    tHeigth=texture->height();
    ounerCounter=texture->getOunerCounter();
}
/////////////////////////////////////////////////
gameObjectTexture::~gameObjectTexture(){
    delete textureArray;
}
///////////////////////////////////////////////
void gameObjectTexture::setName(string tName){
    name=tName;
}
/////////////////////////////////////////////////////
void gameObjectTexture::setHeight(int value){
    tHeigth=value;
}
/////////////////////////////////////////////////////
void gameObjectTexture::setWidth(int value){
    tWidth=value;
}
////////////////////////////////////////////////
void gameObjectTexture::setTexturePointer(dArray<unsigned char> *array){
    if(array!=NULL){
        delete textureArray;
        textureArray=array;
    }
}
///////////////////////////////////////////////////////////////////////////
string gameObjectTexture::getName(){
    return name;
}
///////////////////////////////////////////////////////////////////////////
int gameObjectTexture::width(){
    return tWidth;
}
///////////////////////////////////////////////////////////////////////////
int gameObjectTexture::height(){
    return tHeigth;
}
////////////////////////////////////////////////////////////////////////////
dArray<unsigned char> *gameObjectTexture::getTexturePointer(){
    return textureArray;
}
////////////////////////////////////////////////////////////////////////////
unsigned int gameObjectTexture::getOglName(){
    return oglName;
}
////////////////////////////////////////////////////////////////////////////
void gameObjectTexture::setOglName(unsigned int n){
    oglName=n;
}
//////////////////////////////////////////////////////////////////////////////
gameObjectTexture &gameObjectTexture::operator =(gameObjectTexture &texture){
    name=texture.getName();
    tWidth=texture.width();
    tHeigth=texture.height();
    *textureArray=*texture.getTexturePointer();
    return *this;
}
//////////////////////////////////////////////////////////////////////////////
bool gameObjectTexture::operator ==(gameObjectTexture &texture){
    if(name!=texture.getName()){
        return false;
    }
    if(tWidth!=texture.width()){
        return false;
    }
    if(tHeigth!=texture.height()){
        return false;
    }
    if(*textureArray!=*texture.getTexturePointer()){
        return false;
    }
    return true;
}
//////////////////////////////////////////////////////////////////////////////
bool gameObjectTexture::operator !=(gameObjectTexture &texture){
    return !operator ==(texture);
}
//////////////////////////////////////////////////////////////////////////////
void gameObjectTexture::clear(){
    delete textureArray;
}
////////////////////////////////////////////////////////////////////////////////
unsigned int gameObjectTexture::getSizeInBytes(){
    unsigned int size=0;
    size+=name.capacity();
    size+=sizeof(unsigned int);//под размер

    return size;
}
////////////////////////////////////////////////////////////////////////////////////////
void gameObjectTexture::addOuner(){
    ounerCounter++;
}
/////////////////////////////////////////////////////////////////////////////////////////
bool gameObjectTexture::isUsed(){
    if(ounerCounter>1){
        return true;
    }
    return false;
}
///////////////////////////////////////////////////////////////////////////////////////
void gameObjectTexture::deleteTexture(){
    if(ounerCounter>1){
        ounerCounter--;
        return;
    }
    delete this;
}
/////////////////////////////////////////////////////////////////////////////////////////////
unsigned int gameObjectTexture::getOunerCounter(){
    return ounerCounter;
}



