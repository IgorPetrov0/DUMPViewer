#include "constraint.h"

constraint::constraint()
{
    type=CONSTRAINT_POINT_TO_POINT;
    pivotA=NULL;
    pivotB=NULL;
    rigitBodyA=NULL;
    rigitBodyB=NULL;
    transformA=NULL;
    transformB=NULL;
    pointerA=NULL;
    pointerB=NULL;
}
///////////////////////////////////////////////////
constraint::~constraint(){
    delete pivotA;
    delete pivotB;
    delete rigitBodyA;
    delete rigitBodyB;
    delete transformA;
    delete transformB;
    delete pointerA;
    delete pointerB;
}
///////////////////////////////////////////////
bool constraint::operator ==(constraint &constr){
    if(constr.getType()!=type){
        return false;
    }
    if(*constr.getPivotA()!=*pivotA){
        return false;
    }
    if(*constr.getPivotB()!=*pivotB){
        return false;
    }
    if(*constr.getRigitBodyA()!=*rigitBodyA){
        return false;
    }
    if(*constr.getRigitBodyB()!=*rigitBodyB){
        return false;
    }
    if(! (*constr.getTransformA()==*transformA)){
        return false;
    }
    if(! (*constr.getTransformB()==*transformB)){
        return false;
    }
    return true;
}
////////////////////////////////////////////////////////////
bool constraint::operator !=(constraint &constr){
    return !operator ==(constr);
}
/////////////////////////////////////////////////
constraint *constraint::operator =(constraint &constr){
    type=constr.getType();
    *rigitBodyA=*constr.getRigitBodyA();
    *rigitBodyB=*constr.getRigitBodyB();
    *pivotA=*constr.getPivotA();
    *pivotB=*constr.getPivotB();
    *transformA=*constr.getTransformA();
    *transformB=*constr.getTransformB();
    return this;
}
////////////////////////////////////////////////////////////
rigidBody *constraint::getRigitBodyA(){
    return rigitBodyA;
}
////////////////////////////////////////////////////////////
rigidBody *constraint::getRigitBodyB(){
    return rigitBodyB;
}
////////////////////////////////////////////////////////////
vector3 *constraint::getPivotA(){
    return pivotA;
}
////////////////////////////////////////////////////////////
vector3 *constraint::getPivotB(){
    return pivotB;
}
////////////////////////////////////////////////////////////
btTransform *constraint::getTransformA(){
    return transformA;
}
////////////////////////////////////////////////////////////
btTransform *constraint::getTransformB(){
    return transformB;
}
////////////////////////////////////////////////////////////
constraintType constraint::getType(){
    return type;
}
////////////////////////////////////////////////////////////
string constraint::getPointerA(){
    string tmp;
    if(pointerA!=NULL){
        tmp=*pointerA;
        delete pointerA;
        pointerA=NULL;
    }
    return tmp;
}
////////////////////////////////////////////////////////////
string constraint::getPointerB(){
    string tmp;
    if(pointerB!=NULL){
        tmp=*pointerB;
        delete pointerB;
        pointerB=NULL;
    }
    return tmp;
}
////////////////////////////////////////////////////////////
void constraint::setPointerA(string name){
    if(pointerA==NULL){
        pointerA = new string;
    }
    *pointerA=name;
}
////////////////////////////////////////////////////////////
void constraint::setPointerB(string name){
    if(pointerB==NULL){
        pointerB = new string;
    }
    *pointerB=name;
}
////////////////////////////////////////////////////////////
void constraint::setRigidBodyA(rigidBody *rb){
    rigitBodyA=rb;
}
////////////////////////////////////////////////////////////
void constraint::setRigidBodyB(rigidBody *rb){
    rigitBodyB=rb;
}
////////////////////////////////////////////////////////////
void constraint::setPivotA(vector3 *pivot){
    pivotA=pivot;
}
////////////////////////////////////////////////////////////
void constraint::setPivotB(vector3 *pivot){
    pivotB=pivot;
}
////////////////////////////////////////////////////////////
void constraint::setTransformA(btTransform *transform){
    transformA=transform;
}
////////////////////////////////////////////////////////////
void constraint::setTransformB(btTransform *transform){
    transformB=transform;
}
////////////////////////////////////////////////////////////
void constraint::setType(constraintType type){
    this->type=type;
}
///////////////////////////////////////////////////////////////
unsigned int constraint::getSizeInBytes(){
    unsigned int size=0;
    size+=rigitBodyA->getSizeInBytes();
    size+=rigitBodyB->getSizeInBytes();
    size+=pivotA->getSizeInBytes();
    size+=pivotB->getSizeInBytes();
    size+=32;//размер 2-х btTransform-ов
    return size;
}
