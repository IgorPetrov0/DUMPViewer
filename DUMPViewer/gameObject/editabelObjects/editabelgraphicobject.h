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

protected:
    viewType ego_type;
    string name;



};

#endif // EDITABBELGRAPHICOBJECT_H
