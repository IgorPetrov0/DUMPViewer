#ifndef MESHOBJECT_H
#define MESHOBJECT_H

#include <string>
#include "gameObject/dArray.h"
#include "gameindexobject.h"
#include "mathPrimitives/vector3.h"
#include "defines.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "gameObject/animation/nodeobject.h"
#include "gameObject/animation/bone.h"
#include "gameObject/animation/nodeobject.h"
#include "gameObject/animation/animation.h"


using namespace std;

class meshObject : public nodeObject
{
public:
    meshObject();
    meshObject(meshObject *mesh);
    virtual ~meshObject();
    void setVertexAtributes(dArray<vertexCoordinates> *array);
    dArray<vertexCoordinates> *getVertexAtributesArray();
    const vertexCoordinates *getVertexesPointer();
    arraySize getVertexseSize();
    vector3 getBoundBox();
    unsigned int getNumIndicesObjects();
    gameIndexObject *getIndexObject(unsigned int index);
    void setBoundBox(vector3 box);
    bool isEmpty();
    void clear();//очистка данных меша, которые переносятся в видеопамять
    meshObject *operator =(meshObject &mesh);
    bool operator ==(meshObject &mesh);
    bool operator !=(meshObject &mesh);
    virtual unsigned int getSizeInBytes();
    void setVaoName(unsigned int value);
    unsigned int getVboName() const;
    void setVboName(unsigned int value);
    glm::mat4 getModelMatrix() const;
    bool isVisible();
    void setVisible(bool visible);
    bool getMatricesArray(int size, int *offsets, unsigned char *array);//возвращает указатель на массив, содержащий матрицы модели и нормалей
    void setAnimationsArray(dArray<animation *> *value);
    unsigned int numAnimations();
    animation *getAnimation(unsigned int index);
    animation *getAnimation(string name);
    void playCurrentAnimation(float time);
    void setCurrentAnimation(string name);


protected:
    dArray<vertexCoordinates> *vertexAtributesArray;//массив вершин
    dArray<gameIndexObject*> *indicesObjectsArray;//массив индексных объектов.
    dArray<bone*>*bonesArray;
    vector3 boundBox;
    unsigned int vboName;//храним имя vbo для возможности удаления буфера из видеопамяти
    glm::mat4 modelMatrix;
    glm::mat4 normalMatrix;
    glm::vec3 move;
    glm::vec3 scale;
    glm::vec3 rotate;
    bool visible;
    int matricesCount;
    nodeObject *rootNode;//указатель на корневой узел/ так же хранится первым в массиве пустых узлов
    dArray<nodeObject*> *emptyNodes;//массив пустых узлов, не связанных с объектами, но присутствующими в иерархии
    dArray<animation*> *animationsArray;
    animation *currentAnimation;
    void readHierarchy(float time, nodeObject *node, glm::mat4 parentTransform);




};

#endif // MESHOBJECT_H
