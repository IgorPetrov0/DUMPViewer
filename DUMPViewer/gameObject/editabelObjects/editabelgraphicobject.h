#ifndef EDITABBELGRAPHICOBJECT_H
#define EDITABBELGRAPHICOBJECT_H

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
    void loadFromAiScene(const aiScene *scene);//загрузка графического объекта из aiScene assimp
    void setViewType(viewType type);
    viewType getViewType();
    void compileObject();

protected:
    viewType ego_type;



};

#endif // EDITABBELGRAPHICOBJECT_H
