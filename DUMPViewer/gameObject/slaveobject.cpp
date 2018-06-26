#include "slaveobject.h"

slaveObject::slaveObject()
{
    ownerCounter=0;
}
////////////////////////////////////////////////////////////////////////
void slaveObject::addOwner(){
    ownerCounter++;
}
/////////////////////////////////////////////////////////////////////////
void slaveObject::release(){
    if(ownerCounter==0){
        return;
    }
    ownerCounter--;
}
////////////////////////////////////////////////////////////////////////
bool slaveObject::isUsed(){
    if(ownerCounter>0){
        return true;
    }
    return false;
}
