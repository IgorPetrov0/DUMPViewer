#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include "gameObject/dArray.h"
#include "gameObject/animation/animchannel.h"


class animation
{
public:
    animation();



protected:
    string name;
    int tickPerSecond;
    int duration;
    dArray<animChannel*> channels;

};

#endif // ANIMATION_H
