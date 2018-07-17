#ifndef ANIMCHANNEL_H
#define ANIMCHANNEL_H

#include <string.h>
#include <iostream>
#include "gameObject/animation/animkey.h"
#include "gameObject/dArray.h"


using namespace std;

class animChannel
{
public:
    animChannel();


protected:
    string nodeName;
    dArray<animKey*>positionKeys;
    dArray<animKey*>rotationKeys;
    dArray<animKey*>scaleKeys;
};

#endif // ANIMCHANNEL_H
