#include "vertex.h"

vertex::vertex()
{

}
//////////////////////////////////////////////
vector3 vertex::getPos(){
    return pos;
}
///////////////////////////////////////////////
vector2 vertex::getTexCoord(){
    return texCoord;
}
//////////////////////////////////////////////
vector3 vertex::getNormal(){
    return normal;
}
//////////////////////////////////////////////
void vertex::setPos(vector3 pos){
    this->pos=pos;
}
//////////////////////////////////////////////
void vertex::setTexCoord(vector2 coord){
    texCoord=coord;
}
//////////////////////////////////////////////
void vertex::setNormal(vector3 normal){
    this->normal=normal;
}
/////////////////////////////////////////////
bool vertex::operator ==(vertex v){
    if(v.normal!=this->normal){
        return false;
    }
    if(v.pos!=this->pos){
        return false;
    }
    if(v.texCoord!=this->texCoord){
        return false;
    }
    return true;
}
/////////////////////////////////////////////
bool vertex::operator !=(vertex v){
    if(v.normal!=this->normal){
        return true;
    }
    if(v.pos!=this->pos){
        return true;
    }
    if(v.texCoord!=this->texCoord){
        return true;
    }
    return false;
}
//////////////////////////////////////////////
unsigned int vertex::sizeInFloat(){
    return 8;
}
/////////////////////////////////////////////////////////////////////////////////////
unsigned int vertex::getSizeInBytes(){
    unsigned int size=0;
    size+=pos.getSizeInBytes();
    size+=texCoord.getSizeInBytes();
    size+=normal.getSizeInBytes();
    return size;
}





