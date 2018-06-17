#include "gameobjecttexture.h"

gameObjectTexture::gameObjectTexture()
{
    name="defaultTexture";
    oglName=0;
    tWidth=24;
    tHeigth=24;
    existInOpenGL=false;
    //создаем дефолтную текстуру на случай, если назначенная материалу структура не загрузилась
    unsigned int size=tWidth*tHeigth*4*sizeof(char);
    textureArray=new dArray<unsigned char>(size);
    for(unsigned int n=0;n!=size;n++){
        textureArray->addElement(n,255);
    }
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
    //ounerCounter=texture->getOunerCounter();
}
/////////////////////////////////////////////////
gameObjectTexture::~gameObjectTexture(){
    if(textureArray!=NULL){
        delete textureArray;
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
    existInOpenGL=true;
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
    if(textureArray!=NULL){
        delete textureArray;
        textureArray=NULL;
    }
}
////////////////////////////////////////////////////////////////////////////////
unsigned int gameObjectTexture::getSizeInBytes(){
    unsigned int size=0;
    size+=name.capacity();
    size+=sizeof(unsigned int);//под размер
    return size;
}
///////////////////////////////////////////////////////////////////////////////////////
void gameObjectTexture::deleteTexture(){
    if(ownerCounter>1){
        ownerCounter--;
        return;
    }
    delete this;
}
/////////////////////////////////////////////////////////////////////////////////////
GLint gameObjectTexture::getOGLFormat() const{
    return format;
}
/////////////////////////////////////////////////////////////////////////////////////
GLint gameObjectTexture::getDataType() const
{
    return dataType;
}
////////////////////////////////////////////////////////////////////////////////////
bool gameObjectTexture::loadFromFile(string name, string path ){
    this->name=name;//имя текстуры - это имя файла с расширением без путей
    ILuint id;
    ILinfo imageInfo;
    ilInit();
    iluInit();
    ilGenImages(1,&id);
    ilBindImage(id);
    ilLoadImage(path.data());
    if(ilGetError()!=IL_NO_ERROR){
        ilDeleteImage(id);
        ilShutDown();
        return false;
    }
    iluGetImageInfo(&imageInfo);
    tWidth=imageInfo.Width;
    tHeigth=imageInfo.Height;
    format=imageInfo.Format;
    dataType=imageInfo.Type;
    ILubyte *data = ilGetData();
    if(textureArray!=NULL){
        delete textureArray;
    }
    textureArray=new dArray<unsigned char>(imageInfo.SizeOfData);
    //копируем массив текстуры в свой буфер
    for(unsigned int n=0;n!=imageInfo.SizeOfData;n++){
        textureArray->addElement(n,data[n]);
    }
    ilDeleteImage(id);
    ilShutDown();
}
////////////////////////////////////////////////////////////////////////////////////
bool gameObjectTexture::isExistInOpenGL(){
    return existInOpenGL;
}
