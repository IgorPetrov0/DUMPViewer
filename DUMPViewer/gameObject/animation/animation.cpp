#include "animation.h"

animation::animation()
{
    channels=NULL;
}
////////////////////////////////////////////////////////////////////////////////
animation::~animation(){
    if(channels!=NULL){
        channels->deletePointers();
        delete channels;
    }
}
///////////////////////////////////////////////////////////////////////////////
void animation::setChannels(dArray<animChannel *> *value){
    channels = value;
}
///////////////////////////////////////////////////////////////////////////////
string animation::getName() const{
    return name;
}
///////////////////////////////////////////////////////////////////////////////
void animation::setName(const string &value){
    name = value;
}
///////////////////////////////////////////////////////////////////////////////
int animation::getTickPerSecond() const{
    return tickPerSecond;
}
///////////////////////////////////////////////////////////////////////////////
void animation::setTickPerSecond(int value){
    tickPerSecond = value;
}
///////////////////////////////////////////////////////////////////////////////
int animation::getDuration() const{
    return duration;
}
///////////////////////////////////////////////////////////////////////////////
void animation::setDuration(int value){
    duration = value;
}
///////////////////////////////////////////////////////////////////////////////
unsigned int animation::getNumChannels(){
    return channels->getSize();
}
///////////////////////////////////////////////////////////////////////////////
