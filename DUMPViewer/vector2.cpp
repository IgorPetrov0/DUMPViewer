#include "vector2.h"

vector2::vector2()
{
    xCoord=0;
    yCoord=0;
}
////////////////////////////////////////
void vector2::setX(float value){
    xCoord=value;
}
////////////////////////////////////////
void vector2::setY(float value){
    yCoord=value;
}
/////////////////////////////////////////
float vector2::x(){
    return xCoord;
}
/////////////////////////////////////////
float vector2::y(){
    return yCoord;
}
//////////////////////////////////////////
bool vector2::operator ==(vector2 v){
    if(v.xCoord!=this->xCoord){
        return false;
    }
    if(v.yCoord!=this->yCoord){
        return false;
    }
    return true;
}
//////////////////////////////////////////
bool vector2::operator !=(vector2 v){
    if(v.xCoord!=this->xCoord){
        return true;
    }
    if(v.yCoord!=this->yCoord){
        return true;
    }
    return false;
}
/////////////////////////////////////////////////

