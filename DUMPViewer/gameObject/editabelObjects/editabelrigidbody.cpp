#include "editabelrigidbody.h"

editabelRigidBody::editabelRigidBody()
{
    erbMesh=NULL;
}
//////////////////////////////////////////////////////////////////////////////////
editabelRigidBody::editabelRigidBody(editabelGraphicObject *gObject, meshSource source){
    if(source==MESH_ORIGINAL){
        erbMesh=new editabelGraphicObject(gObject);
    }
    else{
        erbMesh=gObject;
    }
    rbSource=source;
}
////////////////////////////////////////////////////////////////////////////////
editabelRigidBody::editabelRigidBody(rigidBody *body){
    erbMesh = new editabelGraphicObject;
    //собираем графический объект из меша
    arraySize size=body->getMeshPointer()->getVertexseSize();
    dArray<vertexCoordinates> *vertexesArray = new dArray<vertexCoordinates>(body->getMeshPointer()->getVertexArray());
    erbMesh->setVertexes(vertexesArray);
    erbMesh->setName(body->getMeshPointer()->getName());//имя для editabelRigidBody обязательно
    erbMesh->setTrianglesCount(body->getMeshPointer()->getTrianglesCount());//количество треугольников тоже
    erbMesh->setBoundBox(body->getMeshPointer()->getBoundBox());

    //создаем материал для отображения rigidBody в редакторе
    gameObjectMaterial *material = new gameObjectMaterial;

    size=body->getIndicesPointer()->getSize();
    dArray<unsigned int> *iArray = new dArray<unsigned int>(size);
    for(arraySize n=0;n!=size;n++){
        iArray->addElement(n,(*body->getIndicesPointer())[n]);
    }
    //material->setIndicesArray(iArray);//присваиваем индексы материалу


    rbSource=body->getSource();
    rbType=body->getType();
    erbMesh->setViewType(VIEW_TEXTURED);
    mass=body->getMass();
    massCenter=body->getMassCenter();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
editabelRigidBody::~editabelRigidBody(){
    delete erbMesh;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void editabelRigidBody::setTexture(gameObjectTexture *texture){
    //erbMesh->getMaterialPointer(0)->setTexture(texture);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
meshObject *editabelRigidBody::getMeshPointer(){
    return (meshObject*)erbMesh;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void editabelRigidBody::compileObject(){
    if(rbMesh!=NULL){
        delete rbMesh;
        rbMesh=NULL;
    }
    if(erbMesh!=NULL){
        rbMesh = new meshObject((meshObject*)erbMesh);
    }

    if(indicesArray!=NULL){
        delete indicesArray;
        indicesArray=NULL;
    }
}
