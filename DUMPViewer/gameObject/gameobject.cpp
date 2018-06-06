
#include "gameobject.h"


gameObject::gameObject()
{
    mainMesh=NULL;
    pObject=NULL;
    LODs=NULL;
}
////////////////////////////////////////////////////////
gameObject::gameObject(string name){
    mainMesh=NULL;
    pObject=NULL;
    LODs=NULL;
    this->name=name;
}
//////////////////////////////////////////////
gameObject::~gameObject(){
    if(mainMesh!=NULL){
        delete mainMesh;
    }
    if(pObject!=NULL){
        delete pObject;
    }
    if(LODs!=NULL){
        LODs->deletePointers();
        delete LODs;
    }
}
////////////////////////////////////////////
void gameObject::setName(string name){
    this->name=name;
}
///////////////////////////////////////////////
graphicObject *gameObject::getMainMesh(){
    return mainMesh;
}
////////////////////////////////////////////////////////////////////////////
LOD *gameObject::getLod(unsigned int LODNumber){
    if(LODNumber < LODs->getSize()){
        return (*LODs)[LODNumber];
    }
    return NULL;
}
///////////////////////////////////////////////
phisycObject *gameObject::getPhisycObject(){
    return pObject;
}
///////////////////////////////////////////////////
dArray<LOD*> *gameObject::getLODsArray(){
    return LODs;
}
////////////////////////////////////////////////////
string gameObject::getName(){
    return name;
}
////////////////////////////////////////////////
bool gameObject::mainMeshExsist(){
    if(mainMesh!=NULL){
        return true;
    }
    return false;
}
/////////////////////////////////////////////////////////////////////////////
bool gameObject::LODExsist(unsigned int LODNumber){
    if((*LODs)[LODNumber]!=NULL){
        return true;
    }
    return false;
}
//////////////////////////////////////////////////////////////////////////
bool gameObject::phisicSubObjectExsist(){
    if(pObject!=NULL){
        return true;
    }
    return false;
}
//////////////////////////////////////////////////////////////////////////////
unsigned int gameObject::LODsSize(){
    return LODs->getSize();
}
//////////////////////////////////////////////////////////////////////////////
gameObject &gameObject::operator =(gameObject &object){
    mainMesh=object.getMainMesh();
    LODs=object.getLODsArray();
    pObject=object.getPhisycObject();
    name=object.getName();
    return *this;
}
//////////////////////////////////////////////////////////////////////////////
bool gameObject::operator ==(gameObject &object){
    if(*mainMesh!=*object.getMainMesh()){
        return false;
    }
    if(*LODs!=*object.getLODsArray()){
        return false;
    }
    if(*pObject!=*object.getPhisycObject()){
        return false;
    }
    if(name!=object.getName()){
        return false;
    }
    return true;
}
//////////////////////////////////////////////////////////////////////////////
bool gameObject::operator !=(gameObject &object){
    return !operator==(object);
}
//////////////////////////////////////////////////////////////////////////////
unsigned int gameObject::getSizeInBytes(){
    unsigned int size=0;

    size+=name.capacity()+sizeof(int);//строка + количество байт в ней

    if(mainMesh!=NULL){
        size+=mainMesh->getSizeInBytes();
        size+=sizeof(bool);//размер под метку существования mainMesh-а
    }
    size+=sizeof(unsigned int);//под размер ЛОДов
    if(LODs!=NULL){
        unsigned int arSize=LODs->getSize();
        for(unsigned int n=0;n!=arSize;n++){
            size+=LODs->operator [](n)->getSizeInBytes();
        }
    }
    size+=sizeof(bool);//размер под метку существования phisicObject-а
    if(pObject!=NULL){
        size+=pObject->getSizeInBytes();
    }
    return size;
}
////////////////////////////////////////////////////////////////////////////////////
void gameObject::setLodsArray(dArray<LOD *> *array){
    if(LODs!=NULL){
        LODs->deletePointers();
        delete LODs;
    }
    LODs=array;
}
////////////////////////////////////////////////////////////////////////////////////
void gameObject::setPhisycObject(phisycObject *pObject){
    if(this->pObject!=NULL){
        delete this->pObject;
    }
    this->pObject=pObject;
}
//////////////////////////////////////////////////////////////////////////////////////
void gameObject::setMainMesh(graphicObject *mesh){
    if(mainMesh!=NULL){
        delete mainMesh;
    }
    mainMesh=mesh;
}
///////////////////////////////////////////////////////////////////////////////////
arraySize gameObject::rigidBodyesCount(){
    if(pObject!=NULL){
        return pObject->rigidBodyesCount();
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////
arraySize gameObject::constraintsCount(){
    if(pObject!=NULL){
        return pObject->constraintsCount();
    }
    return 0;
}




