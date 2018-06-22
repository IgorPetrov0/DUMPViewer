#include "meshobject.h"

meshObject::meshObject()
{
    vertexAtributesArray=NULL;
    indicesObjectsArray=NULL;
    move=glm::vec3(0,0,0);
    scale=glm::vec3(1,1,1);
    rotate=glm::vec3(0,0,0);
}
//////////////////////////////////////////////////////////////////
meshObject::meshObject(meshObject *mesh){
    vertexAtributesArray = new dArray<vertexCoordinates>(*mesh->getVertexAtributesArray());
    boundBox=mesh->getBoundBox();
}
//////////////////////////////////////////////////////////////////
meshObject::~meshObject(){
    delete vertexAtributesArray;
    indicesObjectsArray->deletePointers();
    delete indicesObjectsArray;
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
    for(int n=0;n!=size;n++){
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
    glm::mat4 mScale = glm::scale(glm::mat4(1.0f),scale);
    glm::mat4 mRotateX = glm::rotate(mScale,glm::radians(rotate.x),glm::vec3(1.0f,0.0f,0.0f));
    glm::mat4 mRotateY = glm::rotate(mRotateX,glm::radians(rotate.y),glm::vec3(0.0f,1.0f,0.0f));
    glm::mat4 mRotateZ = glm::rotate(mRotateY,glm::radians(rotate.z),glm::vec3(0.0f,0.0f,1.0f));
    glm::mat4 mModel = glm::translate(mRotateZ,move);
    return mModel;
}
///////////////////////////////////////////////////////////////////////////////////
void meshObject::setModelMatrix(const glm::mat4 &value){
    modelMatrix = value;
}
////////////////////////////////////////////////////////////////////////////////
unsigned int meshObject::getNumIndicesObjects(){
    return indicesObjectsArray->getSize();
}
////////////////////////////////////////////////////////////////////////////////
gameIndexObject *meshObject::getIndexObject(unsigned int index){
    return indicesObjectsArray->operator [](index);
}
