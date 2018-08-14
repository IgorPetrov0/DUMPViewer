#include "meshobject.h"

meshObject::meshObject()
{
    vertexAtributesArray=NULL;
    indicesObjectsArray=NULL;
    move=glm::vec3(0,0,0);
    scale=glm::vec3(1,1,1);
    rotate=glm::vec3(0,0,0);
    modelMatrix=glm::mat4(1.0f);
    normalMatrix=glm::transpose(glm::inverse(modelMatrix));
    matricesCount=2;
    currentAnimation=NULL;
}
//////////////////////////////////////////////////////////////////
meshObject::meshObject(meshObject *mesh){
    vertexAtributesArray = new dArray<vertexCoordinates>(*mesh->getVertexAtributesArray());
    boundBox=mesh->getBoundBox();
}
//////////////////////////////////////////////////////////////////
meshObject::~meshObject(){
    if(vertexAtributesArray!=NULL){
        indicesObjectsArray->deletePointers();
        delete vertexAtributesArray;
    }
    if(indicesObjectsArray!=NULL){
        delete indicesObjectsArray;
    }
}
//////////////////////////////////////////////////////////////////////
void meshObject::setVertexAtributes(dArray<vertexCoordinates> *array){
    if(array!=NULL){
        vertexAtributesArray=array;
    }
}
//////////////////////////////////////////////////////////////////////
const vertexCoordinates *meshObject::getVertexesPointer(){
    return vertexAtributesArray->getArrayPointer();
}
//////////////////////////////////////////////////////////////////////
arraySize meshObject::getVertexseSize(){
    return vertexAtributesArray->getSize();
}
//////////////////////////////////////////////////////////////////////
void meshObject::clear(){
    delete vertexAtributesArray;
    vertexAtributesArray=NULL;
    unsigned int size=indicesObjectsArray->getSize();
    for(unsigned int n=0;n!=size;n++){
        indicesObjectsArray->operator [](n)->clear();
    }
}
//////////////////////////////////////////////////////////////////////
meshObject *meshObject::operator =(meshObject &mesh){

    if(vertexAtributesArray!=NULL){
        delete vertexAtributesArray;
    }
    vertexAtributesArray=new dArray<float>(*mesh.getVertexAtributesArray());
    return this;
}
//////////////////////////////////////////////////////////////////////
bool meshObject::operator ==(meshObject &mesh){
    if(vertexAtributesArray->operator !=(*mesh.getVertexAtributesArray())){
        return false;
    }
    return true;
}
///////////////////////////////////////////////////////////////////////
bool meshObject::operator !=(meshObject &mesh){
    return !operator ==(mesh);
}
////////////////////////////////////////////////////////////////
bool meshObject::isEmpty(){
    if(vertexAtributesArray!=NULL){
        if(vertexAtributesArray->getSize()){
            return false;
        }
    }
    return true;
}
/////////////////////////////////////////////////////////////////////
dArray<vertexCoordinates> *meshObject::getVertexAtributesArray(){
    return vertexAtributesArray;
}
/////////////////////////////////////////////////////////////////////
vector3 meshObject::getBoundBox(){
    return boundBox;
}
////////////////////////////////////////////////////////////////////////
void meshObject::setBoundBox(vector3 box){
    boundBox=box;
}
/////////////////////////////////////////////////////////////////////////
unsigned int meshObject::getSizeInBytes(){
    unsigned int size=0;
    size+=vertexAtributesArray->getSize()*sizeof(vertexCoordinates);
    size+=sizeof(unsigned int);//под размер
    size+=boundBox.getSizeInBytes();
    return size;
}
//////////////////////////////////////////////////////////////////////////////
unsigned int meshObject::getVboName() const{
    return vboName;
}
//////////////////////////////////////////////////////////////////////////////
void meshObject::setVboName(unsigned int value){
    vboName = value;
}
/////////////////////////////////////////////////////////////////////////////
glm::mat4 meshObject::getModelMatrix() const{
    return modelMatrix;
}
////////////////////////////////////////////////////////////////////////////////
unsigned int meshObject::getNumIndicesObjects(){
    return indicesObjectsArray->getSize();
}
////////////////////////////////////////////////////////////////////////////////
gameIndexObject *meshObject::getIndexObject(unsigned int index){
    return indicesObjectsArray->operator [](index);
}
////////////////////////////////////////////////////////////////////////////////
bool meshObject::isVisible(){
   return visible;
}
///////////////////////////////////////////////////////////////////////////////
void meshObject::setVisible(bool visible){
    this->visible=visible;
}
///////////////////////////////////////////////////////////////////////////////
bool meshObject::getMatricesArray(int size, int *offsets, unsigned char *array){
    if(size!=matricesCount){
        return false;
    }
    memcpy(array+offsets[0],(void*)&modelMatrix,sizeof(glm::mat4));
    memcpy(array+offsets[1],(void*)&normalMatrix,sizeof(glm::mat4));
    return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void meshObject::setAnimationsArray(dArray<animation *> *value){
    animationsArray = value;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int meshObject::numAnimations(){
    if(animationsArray!=NULL){
        return animationsArray->getSize();
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
animation *meshObject::getAnimation(unsigned int index){
    if(animationsArray!=NULL){
        return animationsArray->operator [](index);
    }
    return NULL;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
animation *meshObject::getAnimation(string name){
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
//////////////////////////////////////////////////////////////////////////////////////////////
void meshObject::playCurrentAnimation(float time){
    glm::mat4 mat = glm::mat4(1.0f);
    float timeInTicks=time*currentAnimation->getTickPerSecond();
    float animTime=fmod(timeInTicks,currentAnimation->getDuration());
    readHierarchy(animTime,rootNode,mat);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void meshObject::setCurrentAnimation(string name){
    unsigned int size=animationsArray->getSize();
    for(unsigned int n=0;n!=size;n++){
        if(animationsArray->operator [](n)->getName()==name){
            currentAnimation=animationsArray->operator [](n);
            return;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void meshObject::readHierarchy(float time, nodeObject *node, glm::mat4 parentTransform){
    //сначала ищем данный узел по всем каналам анимации
    //затем рекурсивно вызываем эту функцию для всех его потомков
    animChannel *currentChannel=NULL;
    glm::mat4 nodeTransform=node->getTransformMatrix();
    unsigned int size=currentAnimation->getNumChannels();


    for(unsigned int n=0;n!=size;n++){
        if(animationsArray->operator [](n)->getName()==node->getName()){//TODO пока ищем по имени. По указателям искать будет быстрее
            currentChannel=animationsArray->operator [](n);
            break;
        }
    }
    if(currentChannel!=NULL){
        //TODO здесь интерполируем и трансформируем
    }

    glm::mat4 globalTransform=parentTransform*nodeTransform;



}
////////////////////////////////////////////////////////////////////////////////////////////////////
