#include "meshobject.h"

meshObject::meshObject()
{
    vertexAtributesArray=NULL;
    meshName=NULL;
    trianglesCount=NULL;
    indicesObjectsArray=NULL;
}
//////////////////////////////////////////////////////////////////
meshObject::meshObject(meshObject *mesh){
    vertexAtributesArray = new dArray<vertexCoordinates>(*mesh->getVertexAtributesArray());
    meshName = new string(mesh->getName());
    trianglesCount = new unsigned int(mesh->getTrianglesCount());
    boundBox=mesh->getBoundBox();
}
//////////////////////////////////////////////////////////////////
meshObject::~meshObject(){
    clear();
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
string meshObject::getName(){
    string name;
    if(meshName!=NULL){
        name=*meshName;
    }
    return name;
}
//////////////////////////////////////////////////////////////////////
void meshObject::clear(){
    delete meshName;
    meshName=NULL;

    delete vertexAtributesArray;
    vertexAtributesArray=NULL;

    delete trianglesCount;
    trianglesCount=NULL;
}
//////////////////////////////////////////////////////////////////////
void meshObject::setName(string name){
    if(meshName==NULL){
        meshName=new string;
    }
    *meshName=name;
}
//////////////////////////////////////////////////////////////////////
meshObject *meshObject::operator =(meshObject &mesh){

    if(!mesh.getName().empty()){
        setName(mesh.getName());
    }
    if(vertexAtributesArray!=NULL){
        delete vertexAtributesArray;
    }
    vertexAtributesArray=new dArray<float>(*mesh.getVertexAtributesArray());
    return this;
}
//////////////////////////////////////////////////////////////////////
bool meshObject::operator ==(meshObject &mesh){
    if(meshName!=NULL){
        if(*meshName!=mesh.getName()){
            return false;
        }
    }
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
////////////////////////////////////////////////////////////////////////
void meshObject::setTrianglesCount(unsigned int count){
    if(trianglesCount==NULL){
        trianglesCount=new unsigned int;
    }
    *trianglesCount=count;
}
//////////////////////////////////////////////////////////////////////////
unsigned int meshObject::getTrianglesCount(){
    if(trianglesCount!=NULL){
        return *trianglesCount;
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////////
unsigned int meshObject::getSizeInBytes(){
    unsigned int size=0;
    size+=vertexAtributesArray->getSize()*sizeof(vertexCoordinates);
    size+=sizeof(unsigned int);//под размер
    if(meshName!=NULL){
        size+=(unsigned int)meshName->capacity()+sizeof(int);
    }
    if(trianglesCount!=NULL){
        size+=sizeof(int);
    }
    size+=boundBox.getSizeInBytes();
    return size;
}
////////////////////////////////////////////////////////////////////////////////
unsigned int meshObject::getVaoName() const
{
    return vaoName;
}
////////////////////////////////////////////////////////////////////////////////
void meshObject::setVaoName(unsigned int value)
{
    vaoName = value;
}
////////////////////////////////////////////////////////////////////////////////
unsigned int meshObject::getNumIndicesObjects(){
    return indicesObjectsArray->getSize();
}
////////////////////////////////////////////////////////////////////////////////
gameIndexObject *meshObject::getIndexObject(unsigned int index){
    return indicesObjectsArray->operator [](index);
}
