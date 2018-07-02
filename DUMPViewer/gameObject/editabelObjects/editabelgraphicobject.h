#ifndef EDITABBELGRAPHICOBJECT_H
#define EDITABBELGRAPHICOBJECT_H

#include <QVector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/mesh.h>
#include <assimp/types.h>
#include "gameObject/graphicobject.h"

enum viewType{
    VIEW_TEXTURED,
    VIEW_CARCAS
};

//класс редактируемого графического объекта

class editabelGraphicObject : public virtual graphicObject
{
public:
    editabelGraphicObject();
    editabelGraphicObject(graphicObject *gObject);
    void loadFromAiScene(const aiScene *scene, QVector<gameObjectMaterial*> *materials);//загрузка графического объекта из aiScene assimp
    void setViewType(viewType type);
    viewType getViewType();
    void compileObject();
    string getName();
    void setName(string name);
    void setMoveVector(const glm::vec3 vector);
    void setRotateVector(const glm::vec3 vector);
    void setScaleVector(const glm::vec3 vector);
    glm::vec3 getMoveVector()const;
    glm::vec3 getRotateVector()const;
    glm::vec3 getScaleVector()const;


protected:
    viewType ego_type;
    string name;

    void calculateModelMatrix();
    void loadLights(const aiScene *scene);


};

#endif // EDITABBELGRAPHICOBJECT_H
