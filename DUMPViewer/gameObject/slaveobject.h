#ifndef SLAVEOBJECT_H
#define SLAVEOBJECT_H

//класс подчиненных объектов. Обеспечивает функционал счетчика владельцев

class slaveObject
{
public:
    slaveObject();
    void addOwner();
    void release();
    bool isUsed();


protected:
    unsigned int ownerCounter;


};

#endif // SLAVEOBJECT_H
