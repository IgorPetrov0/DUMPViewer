#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include "gameObject/dArray.h"
#include "gameObject/animation/animchannel.h"


class animation
{
public:
    animation();
    ~animation();
    void setChannels(dArray<animChannel *> *value);
    string getName() const;
    void setName(const string &value);
    int getTickPerSecond() const;
    void setTickPerSecond(int value);
    int getDuration() const;
    void setDuration(int value);
    unsigned int getNumChannels();

protected:
    string name;
    int tickPerSecond;
    int duration;
    dArray<animChannel*> *channels;

};

#endif // ANIMATION_H
