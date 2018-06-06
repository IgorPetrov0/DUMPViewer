#include "vector3.h"

vector3::vector3():vector2()
{

    zCoord=0;
}
////////////////////////////////////////
vector3::~vector3(){

}
////////////////////////////////////////
void vector3::setZ(float z){
    zCoord=z;
}
////////////////////////////////////////
float vector3::z(){
    return zCoord;
}
/////////////////////////////////////////
bool vector3::operator ==(vector3 &v){
    if(vector2::operator !=(v)){
        return false;
    }
    if(v.zCoord!=this->zCoord){
        return false;
    }
    return true;
}
/////////////////////////////////////////
bool vector3::operator !=(vector3 &v){
    if(vector2::operator !=(v)){
        return true;
    }
    if(v.zCoord!=this->zCoord){
        return true;
    }
    return false;
}
//////////////////////////////////////////
vector3 &vector3::operator =(vector3 v){
    zCoord=v.z();
    vector2::operator =(v);
    return *this;
}
/////////////////////////////////////////////////
unsigned int vector3::getSizeInBytes(){
    return vector2::getSizeInBytes()+sizeof(float);
}
