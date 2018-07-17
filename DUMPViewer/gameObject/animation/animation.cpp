#include "animation.h"

animation::animation()
{

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

