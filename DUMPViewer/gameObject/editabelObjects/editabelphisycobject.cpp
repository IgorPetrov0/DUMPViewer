#include "editabelphisycobject.h"

editabelPhisycObject::editabelPhisycObject()
{

}
///////////////////////////////////////////////////////
editabelPhisycObject::editabelPhisycObject(phisycObject *object){
    unsigned int rigidBodiesSize=0;
    unsigned int constraintSize=0;
    if(object->getRigidBodiesPointer()!=NULL){
        rigidBodiesSize=object->getRigidBodiesPointer()->getSize();
    }
    if(object->getConstraintsPointer()!=NULL){
        constraintSize=object->getConstraintsPointer()->getSize();
    }
    for(unsigned int n=0;n!=rigidBodiesSize;n++){
        editabelRigidBody *body = new editabelRigidBody((*object->getRigidBodiesPointer())[n]);
        rigidBodiesVector.append(body);
    }
    for(unsigned int n=0;n!=constraintSize;n++){
      //  constraintsVector.append((*object->getConstraintsPointer())[n]);
    }
}
////////////////////////////////////////////////////////////////////////////////////
editabelPhisycObject::~editabelPhisycObject(){

}
////////////////////////////////////////////////////////////////////////////////////
void editabelPhisycObject::addRigidBody(editabelRigidBody *body){
    if(body!=NULL){
        rigidBodiesVector.append(body);
    }
}
//////////////////////////////////////////////////////////////////////////////////////
void editabelPhisycObject::removeRigidBody(rigidBody *body){
   int size=rigidBodiesVector.size();
   for(int n=0;n!=size;n++){
       if(rigidBodiesVector.at(n)==body){
           delete rigidBodiesVector.at(n);
           rigidBodiesVector.remove(n,1);
           break;
       }
   }
}
//////////////////////////////////////////////////////////////////////////////////////
int editabelPhisycObject::rigidBodyesCount(){
    return rigidBodiesVector.size();
}
//////////////////////////////////////////////////////////////////////////////////////
int editabelPhisycObject::constraintsCount(){
    return constraintsVector.size();
}
//////////////////////////////////////////////////////////////////////////////////////
editabelRigidBody *editabelPhisycObject::getRigitBody(int index){
    if(index<rigidBodiesVector.size()){
        return rigidBodiesVector.at(index);
    }
    return NULL;
}
/////////////////////////////////////////////////////////////////////////////////////
void editabelPhisycObject::compilePhisicObject(){

    unsigned int size=rigidBodiesVector.size();

    if(rigidBodiesArray!=NULL){
        delete rigidBodiesArray;
        rigidBodiesArray=NULL;
    }
    if(size!=0){//если твердых тел нет, то и не создаем массив
        rigidBodiesArray=new dArray<rigidBody*>(size);
        for(unsigned int n=0;n!=size;n++){
            rigidBodiesVector.at(n)->compileObject();
            rigidBodiesArray->addElement(n,rigidBodiesVector.at(n));
        }
    }

    size=constraintsVector.size();
    if(constraintsArray!=NULL){
        delete constraintsArray;
        constraintsArray=NULL;
    }
    if(size!=0){//если шарниров нет, то и не создаем массив
        constraintsArray=new dArray<constraint*>(size);
        for(unsigned int n=0;n!=size;n++){
            phisycObject::constraintsArray->addElement(n,constraintsVector.at(n));
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////
bool editabelPhisycObject::isExist(){
    if(rigidBodiesArray!=NULL){
        return true;
    }
    if(constraintsArray!=NULL){
        return true;
    }
    return false;
}
