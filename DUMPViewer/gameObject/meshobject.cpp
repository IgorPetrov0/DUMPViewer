#include "meshobject.h"

meshObject::meshObject()
{
    vertexesArray=NULL;
    meshName=NULL;
    trianglesCount=NULL;
}
//////////////////////////////////////////////////////////////////
meshObject::meshObject(meshObject *mesh){
    vertexesArray = new dArray<vertexCoordinates>(*mesh->getVertexArray());
    meshName = new string(mesh->getName());
    trianglesCount = new unsigned int(mesh->getTrianglesCount());
    boundBox=mesh->getBoundBox();
}
//////////////////////////////////////////////////////////////////
meshObject::~meshObject(){
    clear();
}
//////////////////////////////////////////////////////////////////////
void meshObject::setVertexes(dArray<vertexCoordinates> *array){
    if(array!=NULL){
        vertexesArray=array;
    }
}
//////////////////////////////////////////////////////////////////////
const vertexCoordinates *meshObject::getVertexesPointer(){
    return vertexesArray->getArrayPointer();
}
//////////////////////////////////////////////////////////////////////
arraySize meshObject::getVertexseSize(){
    return vertexesArray->getSize();
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

    delete vertexesArray;
    vertexesArray=NULL;

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
    if(vertexesArray!=NULL){
        delete vertexesArray;
    }
    vertexesArray=new dArray<float>(*mesh.getVertexArray());
    return this;
}
//////////////////////////////////////////////////////////////////////
bool meshObject::operator ==(meshObject &mesh){
    if(meshName!=NULL){
        if(*meshName!=mesh.getName()){
            return false;
        }
    }
    if(vertexesArray->operator !=(*mesh.getVertexArray())){
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
    if(vertexesArray!=NULL){
        if(vertexesArray->getSize()){
            return false;
        }
    }
    return true;
}
/////////////////////////////////////////////////////////////////////
dArray<vertexCoordinates> *meshObject::getVertexArray(){
    return vertexesArray;
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
    size+=vertexesArray->getSize()*sizeof(vertexCoordinates);
    size+=sizeof(unsigned int);//под размер
    if(meshName!=NULL){
        size+=meshName->capacity()+sizeof(int);
    }
    if(trianglesCount!=NULL){
        size+=sizeof(int);
    }
    size+=boundBox.getSizeInBytes();
    return size;
}
////////////////////////////////////////////////////////////////////////////////

