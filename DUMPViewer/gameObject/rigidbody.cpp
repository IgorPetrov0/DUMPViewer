#include "rigidbody.h"

rigidBody::rigidBody()
{
    mass=0;
    indicesArray=NULL;
    rbMesh=NULL;
    rbSource=MESH_ORIGINAL;
    rbType=RIGID_BODY_MOVABLE;
}
/////////////////////////////////////////////////////////////////////////
rigidBody::rigidBody(graphicObject *object, meshSource source){
    mass=0;
    indicesArray=NULL;
    rbSource=source;

    if(source==MESH_ORIGINAL){
        rbMesh=new meshObject(((meshObject*)object));
    }
    else{
        rbMesh=(meshObject*)object;
    }
    createIndicesArray(object);

}
////////////////////////////////////////////////////
rigidBody::~rigidBody(){
    delete indicesArray;
    if(rbSource==MESH_ORIGINAL){
        delete rbMesh;
    }
}
/////////////////////////////////////////////////
rigidBody& rigidBody::operator = (rigidBody &body){
    delete indicesArray;
    indicesArray=new dArray<unsigned int>(*body.getIndicesPointer());
    mass=body.getMass();
    massCenter=body.getMassCenter();
    rbMesh=body.getMeshPointer();
    return *this;
}
/////////////////////////////////////////////////
bool rigidBody::operator ==(rigidBody &body){
    if(mass!=body.getMass()){
        return false;
    }
    if(massCenter!=body.massCenter){
        return false;
    }
    if(*indicesArray!=*body.getIndicesPointer()){
        return false;
    }
    if(rbMesh != body.getMeshPointer()){
        return false;
    }
    return true;
}
/////////////////////////////////////////////////
bool rigidBody::operator !=(rigidBody &body){
    return !operator ==(body);
}
////////////////////////////////////////////////////
meshObject *rigidBody::getMeshPointer(){
    return rbMesh;
}
/////////////////////////////////////////////////
vector3 &rigidBody::getMassCenter(){
    return massCenter;
}
/////////////////////////////////////////////////
float rigidBody::getMass(){
    return mass;
}
////////////////////////////////////////////////////
dArray<unsigned int> *rigidBody::getIndicesPointer(){
    return indicesArray;
}
///////////////////////////////////////////////////////
void rigidBody::setIndicesArray(dArray<unsigned int> *iArray){
    if(indicesArray!=NULL){
        delete indicesArray;
    }
    indicesArray=iArray;
}
//////////////////////////////////////////////////////////////////
void rigidBody::setMassCenter(vector3 mCenter){
    massCenter=mCenter;
}
//////////////////////////////////////////////////////////////////
void rigidBody::setMass(float mass){
    this->mass=mass;
}
//////////////////////////////////////////////////////////////////
unsigned int rigidBody::getSizeInBytes(){
    unsigned int size=0;
    if(rbSource==MESH_ORIGINAL){//если меш оригинальный, то
        size+=rbMesh->getSizeInBytes();//вписываем размер меша
    }
    size+=sizeof(meshSource);
    size+=sizeof(arraySize);//размер массива индексов
    size+=indicesArray->getSize()*sizeof(unsigned int);
    size+=sizeof(float);//масса
    size+=massCenter.getSizeInBytes();
    size+=sizeof(int);//тип
    return size;
}
///////////////////////////////////////////////////////////////////////
meshSource rigidBody::getSource(){
    return rbSource;
}
///////////////////////////////////////////////////////////////////////
void rigidBody::setSource(meshSource source){
    rbSource=source;
}
///////////////////////////////////////////////////////////////////////
void rigidBody::setType(rigidBodyType type){
    rbType=type;
}
////////////////////////////////////////////////////////////////////////
rigidBodyType rigidBody::getType(){
    return rbType;
}
////////////////////////////////////////////////////////////////////////
void rigidBody::createMeshObject(graphicObject *object){
    rbMesh=(meshObject*)object;
    createIndicesArray(object);
}
/////////////////////////////////////////////////////////////////////////
void rigidBody::setMeshObject(meshObject *object){
    rbMesh=object;
}
//////////////////////////////////////////////////////////////////////////
void rigidBody::createIndicesArray(graphicObject *object){
    unsigned int indicesCount=0;

    if(indicesArray!=NULL){
        delete indicesArray;
    }
    indicesArray=new dArray<unsigned int>(indicesCount);

    arraySize pos=0;
}
