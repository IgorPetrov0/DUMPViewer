#ifndef BOUNDBOX_H
#define BOUNDBOX_H

#include "gameObject/dArray.h"

class boundBox
{
public:
    boundBox(dArray<vertexCoordinates> *array);
    float xMin, xMax;
    float yMin, yMax;
    float zMin, zMax;




};

#endif // BOUNDBOX_H
