#ifndef ANIMCHANNEL_H
#define ANIMCHANNEL_H

#include <string.h>
#include <iostream>
#include "gameObject/animation/animkey.h"
#include "gameObject/animation/animquatkey.h"
#include "gameObject/dArray.h"


using namespace std;

class animChannel
{
public:
    animChannel();
    void setPositionKeys(dArray<animKey *> *value);
    void setRotationKeys(dArray<animQuatKey *> *value);
    void setScaleKeys(dArray<animKey *> *value);
    string getNodeName() const;
    void setNodeName(const string &value);

protected:
    string nodeName;
    dArray<animKey*> *positionKeys;
    dArray<animQuatKey*> *rotationKeys;
    dArray<animKey*> *scaleKeys;
};

#endif // ANIMCHANNEL_H
