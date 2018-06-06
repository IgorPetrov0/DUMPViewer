#ifndef VECTOR2_H
#define VECTOR2_H


class vector2
{
public:
    vector2();
    ~vector2();
    void setX(float value);
    void setY(float value);
    float x();
    float y();
    bool operator ==(vector2 &v);
    bool operator !=(vector2 &v);
    vector2 &operator =(vector2 &v);
    virtual unsigned int getSizeInBytes();

protected:
    float xCoord,yCoord;


};

#endif // VECTOR2_H
