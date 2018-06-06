#include "editabelgameobject.h"

editabelGameObject::editabelGameObject()
{

}
////////////////////////////////////////////////////////////////////////////
editabelGameObject::editabelGameObject(gameObject *mesh){
    LODsVector=new QVector<LOD*>;
    unsigned int LODsSize=mesh->getLODsArray()->getSize();
    for(unsigned int n=0;n!=LODsSize;n++){
        LODsVector->append((*mesh->getLODsArray())[n]);
    }
    gameObject::operator =(*mesh);
}
////////////////////////////////////////////////////////////////////////////
editabelGameObject::~editabelGameObject(){
    delete LODsVector;
}
////////////////////////////////////////////////////////////////////////////
void editabelGameObject::setMainMesh(graphicObject *mesh){
    mainMesh=mesh;
}
////////////////////////////////////////////////////////////////////////////////////////
void editabelGameObject::setPhisicSubObject(phisycObject* mesh){
    pObject=mesh;
}
/////////////////////////////////////////////////////////////////////////////
void editabelGameObject::addLOD(LOD *mesh){
    if(mesh!=NULL){
        LODsVector->append(mesh);
    }
}
//////////////////////////////////////////////////////////////////////////
void editabelGameObject::deleteLOD(unsigned int index){
    LODsVector->remove(index);
}
//////////////////////////////////////////////////////////////////////////
LOD *editabelGameObject::getLod(unsigned int LODNumber){
    if(LODNumber < (unsigned int)LODsVector->size()){
        return LODsVector->at(LODNumber);
    }
    return NULL;
}
/////////////////////////////////////////////////////////////////////////
bool editabelGameObject::LODExsist(unsigned int LODNumber){
    if(LODNumber < (unsigned int)LODsVector->size()){
        return true;
    }
    return false;
}
///////////////////////////////////////////////////////////////////////////
unsigned int editabelGameObject::LODsSize(){
    return LODsVector->size();
}
/////////////////////////////////////////////////////////////////////////////
