#ifndef VECTOR2_H
#define VECTOR2_H


class vector2
{
public:
    vector2();
    void setX(float value);
    void setY(float value);
    float x();
    float y();
    bool operator ==(vector2 v);
    bool operator !=(vector2 v);


protected:
    float xCoord,yCoord;


};

#endif // VECTOR2_H
