#include "editabelgraphicobject.h"

editabelGraphicObject::editabelGraphicObject()
{
    ego_type=VIEW_TEXTURED;
}
////////////////////////////////////////////////////////////////////
editabelGraphicObject::editabelGraphicObject(graphicObject *gObject){

    vertexesArray = new dArray<vertexCoordinates>(gObject->getVertexArray());

    meshName = new string(gObject->getName());

    trianglesCount = new unsigned int(gObject->getTrianglesCount());
    boundBox=gObject->getBoundBox();

    dArray<float> *texCooordsArray=gObject->getTexCoordArrayPointer();
    if(texCooordsArray!=NULL){
        texCoordsArray = new dArray<texCoordinates>(texCooordsArray);
    }

    arraySize size=gObject->getMaterialsSize();
    materialsArray = new dArray<gameObjectMaterial *>(size);
    for(arraySize n=0;n!=size;n++){
        materialsArray->addElement(n,new gameObjectMaterial(gObject->getMaterialPointer(n)));
    }

    visible=gObject->isVisible();

    ego_type=VIEW_TEXTURED;
}
////////////////////////////////////////////////////////////////////
void editabelGraphicObject::setViewType(viewType type){
    ego_type=type;
}
//////////////////////////////////////////////////////////////////////
viewType editabelGraphicObject::getViewType(){
    return ego_type;
}
//////////////////////////////////////////////////////////////////////////
void editabelGraphicObject::compileObject(){

}
//////////////////////////////////////////////////////////////////////////
void editabelGraphicObject::loadFromAiScene(const aiScene *scene){

    unsigned int counter=0;
    unsigned int lastVertexNumber=0;
    unsigned int numVertices=0;

    //вершины
    //подсчитываем общее кол-во вершин в сцене
    aiMesh **meshes=scene->mMeshes;
    for(unsigned int n=0;n!=scene->mNumMeshes;n++){
        numVertices+=meshes[n]->mNumVertices;
    }
    //создаем массив вершин для объекта и заполняем его
    //массив вершин один на объект
    if(vertexesArray!=NULL){
        delete vertexesArray;
    }
    vertexesArray = new dArray<vertexCoordinates>(numVertices*3);

    if(materialsArray!=NULL){
        materialsArray->deletePointers();
        delete materialsArray;
    }
    materialsArray = new dArray<gameObjectMaterial*>(scene->mNumMeshes);//количество материалов соответствует количеству
    //мешей в сцене assimp-а т.к. там мешу соответствует только один материал

    for(unsigned int n=0;n!=scene->mNumMeshes;n++){
        lastVertexNumber=counter;
        for(unsigned int m=0;m!=meshes[n]->mNumVertices;m++){
            aiVector3D v=meshes[n]->mVertices[m];
            vertexesArray->addElement(counter,v.x);
            vertexesArray->addElement(counter+1,v.y);
            vertexesArray->addElement(counter+2,v.z);
            counter+=3;
        }
        //создаем материал
        gameObjectMaterial *material = new gameObjectMaterial;
        unsigned int size=meshes[n]->mNumFaces;//на 3 потому, что делаем триангуляцию в постпроцессе
        unsigned int indCounter=0;
        dArray<unsigned int> *indices = new dArray<unsigned int>(size*3);//общий массив индексов

        aiFace *faces=meshes[n]->mFaces;
        for(unsigned int m=0;m!=size;m++){//берем индексы со всех поверхностей
            //меняем значение идексов в соответствии со сквозной индексацией
            indices->addElement(indCounter,faces[m].mIndices[0]+lastVertexNumber);
            indices->addElement(indCounter+1,faces[m].mIndices[1]+lastVertexNumber);
            indices->addElement(indCounter+2,faces[m].mIndices[2]+lastVertexNumber);
            indCounter+=3;
        }
        material->setIndicesArray(indices);

        //получаем диффузные текстуры
        aiMaterial *mat=scene->mMaterials[meshes[n]->mMaterialIndex];
        unsigned int numTex=mat->GetTextureCount(aiTextureType_DIFFUSE);
        aiString path;
        aiReturn rez=mat->GetTexture(aiTextureType_DIFFUSE,meshes[n]->mMaterialIndex,&path);


        materialsArray->addElement(n,material);
    }
}
