#include "editabelgameobject.h"

editabelGameObject::editabelGameObject()
{
    epObject=NULL;
    objectSaved=false;
    eMainMesh=NULL;
}
/////////////////////////////////////////////////////////////////////////////
editabelGameObject::editabelGameObject(QString name)
{
    this->name=name.toStdString();
    epObject=NULL;
    eMainMesh=NULL;
    objectSaved=false;
}
////////////////////////////////////////////////////////////////////////////
editabelGameObject::editabelGameObject(gameObject *object){

    name=object->getName();
    dArray<LOD*> *la=object->getLODsArray();
    if(la!=NULL){//лодов у объекта может и не быть. Если есть, то загружаем
        unsigned int LODsSize=la->getSize();
        for(unsigned int n=0;n!=LODsSize;n++){
            editableLOD *eLod = new editableLOD((*la)[n]);
            LODsVector.push_back(eLod);
        }
    }
    graphicObject *oMainMesh=object->getMainMesh();
    if(oMainMesh!=NULL){
        eMainMesh = new editabelGraphicObject(oMainMesh);
    }
    else{
        eMainMesh=NULL;
    }
    phisycObject *oPhisycObject=object->getPhisycObject();
    if(oPhisycObject!=NULL){
        epObject = new editabelPhisycObject(oPhisycObject);
    }
    else{
        epObject=NULL;
    }
    objectSaved=false;
}
////////////////////////////////////////////////////////////////////////////
editabelGameObject::~editabelGameObject(){
    compileGameObject();
    //объект скомпилирован, т.е. ЛОД-ы будут удаляться  gameObject-ом
    if(epObject!=NULL){
        delete epObject;
        epObject=NULL;
        pObject=NULL;
    }
}
////////////////////////////////////////////////////////////////////////////////////////
void editabelGameObject::setPhisycObject(phisycObject *object){
    if(epObject!=NULL){
        delete epObject;
    }
    epObject = new editabelPhisycObject(object);
    objectSaved=false;
}
/////////////////////////////////////////////////////////////////////////////
void editabelGameObject::addLOD(editableLOD *lod, unsigned int index){
    if(index>=LODsVector.size()){
        LODsVector.push_back(lod);
    }
    else{
        delete LODsVector.at(index);
        LODsVector.at(index)=lod;
    }
    objectSaved=false;
}
//////////////////////////////////////////////////////////////////////////
void editabelGameObject::deleteLOD(unsigned int index){
    LODsVector.erase(LODsVector.begin()+index);
    objectSaved=false;
}
//////////////////////////////////////////////////////////////////////////
editableLOD *editabelGameObject::getLod(unsigned int LODNumber){
    if(LODNumber < (unsigned int)LODsVector.size()){
        return LODsVector.at(LODNumber);
    }
    return NULL;
}
//////////////////////////////////////////////////////////////////////////
editabelPhisycObject *editabelGameObject::getPhisycObject(){
    return epObject;
}
/////////////////////////////////////////////////////////////////////////
bool editabelGameObject::LODExsist(unsigned int LODNumber){
    if(LODNumber < (unsigned int)LODsVector.size()){
        return true;
    }
    return false;
}
///////////////////////////////////////////////////////////////////////////
unsigned int editabelGameObject::LODsSize(){
    return LODsVector.size();
}
/////////////////////////////////////////////////////////////////////////////
void editabelGameObject::deleteMainMesh(){
    if(eMainMesh!=NULL){
        delete eMainMesh;
        eMainMesh=NULL;
        objectSaved=false;
    }
}
///////////////////////////////////////////////////////////////////////////////////
void editabelGameObject::showMainMesh(bool show){

    unsigned int size=LODsVector.size();
    for(unsigned int n=0;n!=size;n++){
        LODsVector.at(n)->setVisible(false);
    }

    if(eMainMesh!=NULL){
        eMainMesh->setVisible(show);
    }
    objectSaved=false;
}
///////////////////////////////////////////////////////////////////////////////////
void editabelGameObject::showLOD(unsigned int index, bool show){
    unsigned int size=LODsVector.size();
    for(unsigned int n=0;n!=size;n++){//делаем все остальное невидимым
        LODsVector.at(n)->setVisible(false);
    }
    if(eMainMesh!=NULL){
        eMainMesh->setVisible(false);
    }
    if(index < size){//если индекс корректный
        LODsVector.at(index)->setVisible(show);//то делаем LOD видимым
    }
    objectSaved=false;
}
///////////////////////////////////////////////////////////////////////////////////
void editabelGameObject::showRigitBody(bool show){
    objectSaved=false;
}
///////////////////////////////////////////////////////////////////////////////////
void editabelGameObject::showConstraints(bool show){
    objectSaved=false;
}
////////////////////////////////////////////////////////////////////////////////////
void editabelGameObject::setSave(){
    objectSaved=true;
}
//////////////////////////////////////////////////////////////////////////////////////
bool editabelGameObject::isSaved(){
    return objectSaved;
}
//////////////////////////////////////////////////////////////////////////////////////
void editabelGameObject::compileGameObject(){
    if(eMainMesh==NULL){
        mainMesh=(graphicObject*)eMainMesh;
    }

    if(LODs!=NULL){//удаляем, даже если ЛОД-ов нет совсем, т.к. тогда не должно их быть и у родителя
        delete LODs;
        LODs=NULL;
    }

    int size=LODsVector.size();
    if(size!=0){
        LODs=new dArray<LOD*>(size);
        for(int n=0;n!=size;n++){//заполняем массив ЛОД-ов указателями из вектора
            LODs->addElement(n,(LOD*)LODsVector.at(n));
        }
    }
    if(epObject!=NULL){
        epObject->compilePhisicObject();
        if(pObject!=NULL){
            pObject=(phisycObject*)epObject;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
void editabelGameObject::setLodsArray(dArray<LOD *> *array){
    //скорее всего будет не нужно
//    arraySize size=LODs->getSize();
//    for(arraySize n=0;n!=size;n++){
//        LODsVector.push_back(LODs->operator [](n));
//    }

}
//////////////////////////////////////////////////////////////////////////////////////////////////
void editabelGameObject::addRigiBody(editabelRigidBody *rBody){
    if(epObject==NULL){
        epObject = new editabelPhisycObject;
    }
    epObject->addRigidBody(rBody);
}
///////////////////////////////////////////////////////////////////////////////////
int editabelGameObject::rigidBodyesCount(){
    if(epObject!=NULL){
        return epObject->rigidBodyesCount();
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////
int editabelGameObject::constraintsCount(){
    if(epObject!=NULL){
        return epObject->constraintsCount();
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
editabelGraphicObject *editabelGameObject::getMainMesh(){
    return eMainMesh;
}
/////////////////////////////////////////////////////////////
void editabelGameObject::setMainMesh(editabelGraphicObject *object){
    if(eMainMesh!=NULL){
        delete eMainMesh;
    }
    eMainMesh=object;
}
////////////////////////////////////////////////////////////////////////
bool editabelGameObject::mainMeshExsist(){
    if(eMainMesh!=NULL){
        return true;
    }
    return false;
}
