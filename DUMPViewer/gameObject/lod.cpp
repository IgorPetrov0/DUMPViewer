#include "lod.h"

LOD::LOD()
{

}
///////////////////////////////////////////////////////
LOD::LOD(graphicObject *gObject, float distance)
{
    //this=gObject;
}
//////////////////////////////////////////////////////
void LOD::setDistance(float value){
    LODDistance=value;
}
/////////////////////////////////////////////////////
float LOD::getDistance(){
    return LODDistance;
}
/////////////////////////////////////////////////////
graphicObject *LOD::getGraphicObject(){
    return this;
}
/////////////////////////////////////////////////////
LOD &LOD::operator =(LOD &lod){
    LODDistance=lod.getDistance();
    graphicObject::operator =(*lod.getGraphicObject());
    return *this;
}
/////////////////////////////////////////////////////
bool LOD::operator ==(LOD &lod){
    if(LODDistance!=lod.getDistance()){
        return false;
    }
    if(graphicObject::operator !=(*lod.getGraphicObject())){
        return false;
    }
    return true;
}
/////////////////////////////////////////////////////
bool LOD::operator !=(LOD &lod){
    return !operator ==(lod);
}
/////////////////////////////////////////////////////
unsigned int LOD::getSizeInBytes(){
    return graphicObject::getSizeInBytes()+sizeof(float);//графика+дистанция
}
