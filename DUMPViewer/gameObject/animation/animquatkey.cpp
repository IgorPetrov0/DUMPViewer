#include "animquatkey.h"

animQuatKey::animQuatKey()
{

}
//////////////////////////////////////////////////////////////
double animQuatKey::getTime() const{
    return time;
}
//////////////////////////////////////////////////////////////
void animQuatKey::setTime(double value){
    time = value;
}
///////////////////////////////////////////////////////////////
glm::quat animQuatKey::getValue() const{
    return value;
}
///////////////////////////////////////////////////////////////
void animQuatKey::setValue(const glm::quat value){
    this->value = value;
}