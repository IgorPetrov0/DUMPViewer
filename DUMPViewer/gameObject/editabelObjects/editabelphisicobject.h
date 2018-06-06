#ifndef EDITABELPHISICOBJECT_H
#define EDITABELPHISICOBJECT_H

#include <QVector>
#include "gameObject/phisycobject.h"

class editabelPhisicObject : public phisycObject
{
public:
    editabelPhisicObject();

protected:
    QVector<rigidBody*> *rigidBodiesArray;
    QVector<constraint*> *constraintsArray;//массив шарниров


};

#endif // EDITABELPHISICOBJECT_H
