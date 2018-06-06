#include "phisycobject.h"

phisycObject::phisycObject()
{
    rigidBodiesArray=NULL;
    constraintsArray=NULL;
}
//////////////////////////////////////////////////////////////////////////
phisycObject::~phisycObject(){
    if(rigidBodiesArray!=NULL){
        rigidBodiesArray->deletePointers();
        delete rigidBodiesArray;
    }
    if(constraintsArray!=NULL){
        constraintsArray->deletePointers();
        delete constraintsArray;
    }
}
/////////////////////////////////////////////////////////////////////////
phisycObject &phisycObject::operator=(phisycObject &pObject){
    *rigidBodiesArray=*pObject.getRigidBodiesPointer();
    *constraintsArray=*pObject.getConstraintsPointer();
    return *this;
}
/////////////////////////////////////////////////////////////////////////
bool phisycObject::operator ==(phisycObject &pObject){
    if(*rigidBodiesArray!=*pObject.getRigidBodiesPointer()){
        return false;
    }
    if(*constraintsArray!=*pObject.getConstraintsPointer()){
        return false;
    }
    return true;
}
/////////////////////////////////////////////////////////////////////////
bool phisycObject::operator !=(phisycObject &pObject){
    return !operator==(pObject);
}
/////////////////////////////////////////////////////////////////////////
dArray<rigidBody*> *phisycObject::getRigidBodiesPointer(){
    return rigidBodiesArray;
}
/////////////////////////////////////////////////////////////////////////
dArray<constraint*> *phisycObject::getConstraintsPointer(){
    return constraintsArray;
}
/////////////////////////////////////////////////////////////////////////
void phisycObject::setRigidBodyArray(dArray<rigidBody*> *array){
    if(rigidBodiesArray!=NULL){
        rigidBodiesArray->deletePointers();
        delete rigidBodiesArray;
    }
    rigidBodiesArray=array;
}
/////////////////////////////////////////////////////////////////////////
void phisycObject::setConstraintsArray(dArray<constraint*> *array){
    if(constraintsArray!=NULL){
        constraintsArray->deletePointers();
        delete constraintsArray;
    }
    constraintsArray=array;
}
/////////////////////////////////////////////////////////////////////////
unsigned int phisycObject::getSizeInBytes(){
    unsigned int size=0;
    arraySize arSize;
    size+=sizeof(arraySize);
    if(rigidBodiesArray!=NULL){
        arSize=rigidBodiesArray->getSize();
        for(arraySize n=0;n!=arSize;n++){
            size+=rigidBodiesArray->operator [](n)->getSizeInBytes();
        }
    }
    size+=sizeof(arraySize);
    if(constraintsArray!=NULL){
        arSize=constraintsArray->getSize();
        for(arraySize n=0;n!=arSize;n++){
            size+=constraintsArray->operator [](n)->getSizeInBytes();
        }
    }
    return size;
}
/////////////////////////////////////////////////////////////////////////////
arraySize phisycObject::constraintsCount(){
    if(constraintsArray==NULL){
        return 0;
    }
    return constraintsArray->getSize();
}
///////////////////////////////////////////////////////////////////////////////
arraySize phisycObject::rigidBodyesCount(){
    if(rigidBodiesArray==NULL){
        return 0;
    }
    return rigidBodiesArray->getSize();
}
