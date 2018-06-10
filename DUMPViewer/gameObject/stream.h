#ifndef STREAM_H
#define STREAM_H

#include <string.h>
//#include <mem.h>
#include "mathPrimitives/vector2.h"
#include "mathPrimitives/vector3.h"
#include "mathPrimitives/vertex.h"
#include "gameObject/gameobject.h"
#include "gameObject/editabelgameobject.h"
#include "gameObject/rigidbody.h"
#include "gameObject/phisycobject.h"
#include "gameObject/meshobject.h"
#include "gameObject/graphicobject.h"
#include "gameObject/lod.h"
#include "gameObject/gameobjecttexture.h"
#include "gameObject/gameobjectmaterial.h"
#include "gameObject/constraint.h"
#include "gameObject/gameobject.h"


enum streamMode{
    MODE_READ,
    MODE_WRITE
};

#define VAR_NOT_NULL if(var==NULL)return;

class stream
{
public:
    stream(unsigned char *dArray, unsigned int size);
    void out(int var);
    void out(float var);
    void out(bool var);
    void out(double var);
    void out(std::string var);
    void out(const unsigned char *dArray, unsigned int size);
    void out(const unsigned int *dArray, unsigned int size);
    void out(const float *dArray, unsigned int size);
    void out(vector2 *var);
    void out(vector3 *var);
    void out(vertex *var);
    void out(rigidBody *var);
    void out(phisycObject *var);
    void out(meshObject *var);
    void out(LOD *var);
    void out(graphicObject *var);
    void out(gameObjectTexture *var);
    void out(gameObjectMaterial *var);
    void out(constraint *var);
    void out(btTransform *var);
    void out(gameObject *var);
    void outPtr(void *ptr);//сериализация указателя. нет, не маразм. значение указателя = уникальное имя

    void in(int *var);
    void in(unsigned int *var);
    void in(float *var);
    void in(bool *var);
    void in(double *var);
    void in(std::string *var);
    void in(unsigned char **dArray, unsigned int &size);
    void in(unsigned int **dArray, unsigned int &size);
    void in(float **dArray, unsigned int &size);
    void in(vector2 *var);
    void in(vector3 *var);
    void in(vertex *var);
    void in(rigidBody *var);
    void in(phisycObject *var);
    void in(meshObject *var);
    void in(LOD *var);
    void in(graphicObject *var);
    void in(gameObjectTexture *var);
    void in(gameObjectMaterial *var);
    void in(constraint *var);
    void in(btTransform *var);
    void in(editabelGameObject *var);
    void in(gameObject *var);
    void inPtr(string *name);//десериализация указателя. нет, не маразм. значение указателя = уникальное имя



protected:
    unsigned char *s_array;
    unsigned int s_pos;
    unsigned int s_arraySize;
    
    void add(const unsigned char *dArray, unsigned int size);
    void take(unsigned char *dArray, unsigned int size);


};

#endif // STREAM_H
