#include "editabelgraphicobject.h"

editabelGraphicObject::editabelGraphicObject()
{
    ego_type=VIEW_TEXTURED;
}
////////////////////////////////////////////////////////////////////
editabelGraphicObject::editabelGraphicObject(graphicObject *gObject){
    vertexAtributesArray = new dArray<vertexCoordinates>(gObject->getVertexAtributesArray());
    boundBox=gObject->getBoundBox();
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
void editabelGraphicObject::loadFromAiScene(const aiScene *scene, QVector<gameObjectMaterial*> *materials){

    unsigned int numVertices=0;
    unsigned int lastIndex=0;
    unsigned int c=0;

    //вершины
    //подсчитываем общее кол-во вершин в сцене
    aiMesh **meshes=scene->mMeshes;
    for(unsigned int n=0;n!=scene->mNumMeshes;n++){
        numVertices+=meshes[n]->mNumVertices;
    }
    //создаем массив вершинных атрибутов для объекта и заполняем его
    //массив один на объект
    //формат: vX,vY,vZ,tX,tY,nX,nY,nZ
    if(vertexAtributesArray!=NULL){
        delete vertexAtributesArray;
    }
    vertexAtributesArray = new dArray<vertexCoordinates>(numVertices*3+numVertices*2+numVertices*3);//количество координат вершин+количество текстурных координат+кол-во нормалей

    //проходим по всем мешам сцены собираем вершины, текстурные координаты и нормали
    for(unsigned int n=0;n!=scene->mNumMeshes;n++){
        aiMesh *mesh=meshes[n];
        aiVector3D *vertexes=mesh->mVertices;
        aiVector3D *texCoords=mesh->mTextureCoords[0];
        aiVector3D *normals=mesh->mNormals; 
        unsigned int m=0;
        for(m=0;m!=mesh->mNumVertices;m++){
            unsigned int cm=c+m;
            vertexAtributesArray->addElement(cm*8,vertexes[m].x);
            vertexAtributesArray->addElement(cm*8+1,vertexes[m].y);
            vertexAtributesArray->addElement(cm*8+2,vertexes[m].z);
            if(mesh->HasTextureCoords(0)){
                vertexAtributesArray->addElement(cm*8+3,texCoords[m].x);
                vertexAtributesArray->addElement(cm*8+4,texCoords[m].y);
            }
            else{
                vertexAtributesArray->addElement(cm*8+3,0);
                vertexAtributesArray->addElement(cm*8+4,0);
            }
            if(mesh->HasNormals()){
                vertexAtributesArray->addElement(cm*8+5,normals[m].x);
                vertexAtributesArray->addElement(cm*8+6,normals[m].y);
                vertexAtributesArray->addElement(cm*8+7,normals[m].z);
            }
            else{
                vertexAtributesArray->addElement(cm*8+5,0);
                vertexAtributesArray->addElement(cm*8+6,0);
                vertexAtributesArray->addElement(cm*8+7,0);
            }
        }
        c+=m;
        m=0;
    }

    //создаем массив индексных объектов
    if(indicesObjectsArray!=NULL){
        delete indicesObjectsArray;
    }
    indicesObjectsArray = new dArray<gameIndexObject*>(scene->mNumMeshes);
    for(unsigned int nn=0;nn!=scene->mNumMeshes;nn++){
        aiMesh *mesh=scene->mMeshes[nn];
        dArray<unsigned int> *array = new  dArray<unsigned int>(mesh->mNumFaces*3);
        unsigned int index=0;
        for(unsigned int n=0;n!=mesh->mNumFaces;n++){
            for(unsigned int m=0;m!=mesh->mFaces[n].mNumIndices;m++){
                unsigned int currentIndex=mesh->mFaces[n].mIndices[m]+lastIndex;//сквозная нумерация
                array->addElement(n*3+m,currentIndex);
                if(currentIndex>index){//за одно ищем наибольший индекс
                    index=currentIndex;
                }
            }

        }
        lastIndex=index+1;
        gameIndexObject *indexObject = new gameIndexObject;
        indexObject->addIndicesArray(array);

        //получаем материал из глобального хранилища
        aiMaterial *mat=scene->mMaterials[mesh->mMaterialIndex];
        unsigned int globalArraySize=materials->size();
        aiString matName;
        mat->Get(AI_MATKEY_NAME,matName);
        unsigned int n;
        for(n=0;n!=globalArraySize;n++){
            if(materials->at(n)->getName()==matName.C_Str()){
                indexObject->addMaterialPointer(materials->at(n));
                break;
            }
        }
        if(n==globalArraySize){//если материал не нашли
            indexObject->addMaterialPointer(materials->at(0));//то присваиваем первый из массива. Он должен быть дефолтный.
        }
        indicesObjectsArray->addElement(nn,indexObject);
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////
string editabelGraphicObject::getName(){
    return name;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void editabelGraphicObject::setName(string name){
    this->name=name;
}
///////////////////////////////////////////////////////////////////////////////////

