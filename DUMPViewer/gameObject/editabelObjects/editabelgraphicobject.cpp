#include "editabelgraphicobject.h"

editabelGraphicObject::editabelGraphicObject()
{
    ego_type=VIEW_TEXTURED;
    calculateModelMatrix();
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

    unsigned int size=0;
    unsigned int lastIndex=0;
    unsigned int c=0;
    unsigned int offset=8;
    unsigned int beginIndex=0;
    unsigned int bonesSize=0;


    //вершины
    //подсчитываем общее кол-во вершин в сцене
    aiMesh **meshes=scene->mMeshes;
    for(unsigned int n=0;n!=scene->mNumMeshes;n++){
        size+=meshes[n]->mNumVertices;
        if(meshes[n]->HasBones()){//если хоть один меш в сцене имеет кости, то меняем смещение
            offset=8+NUM_BONES_PER_VERTEX*2;
            bonesSize+=meshes[n]->mNumBones;//заодно считаем общее количество костей
        }
        //собираем имена мешей. Нужно для построения иерархии
        meshNames.append(meshes[n]->mName);
    }
    //создаем массив вершинных атрибутов для объекта и заполняем его
    //массив один на объект
    //формат: vX,vY,vZ,tX,tY,nX,nY,nZ, -для объектов без костей
    //формат: vX,vY,vZ,tX,tY,nX,nY,nZ,boneIndex1,w1,boneIndex2,w2,boneIndex3,w3,boneIndex4,w4 -для объектов с костями
    if(vertexAtributesArray!=NULL){
        delete vertexAtributesArray;
    }
    if(offset>8){//если с костями
        vertexAtributesArray = new dArray<vertexCoordinates>(size*3+size*2+size*3+size*NUM_BONES_PER_VERTEX*2);//количество координат вершин+количество текстурных координат+кол-во нормалей+кости
        bonesArray = new dArray<bone*>(bonesSize);
    }
    else{//если без костей
        vertexAtributesArray = new dArray<vertexCoordinates>(size*3+size*2+size*3);//количество координат вершин+количество текстурных координат+кол-во нормалей
    }

    this->setName(meshes[0]->mName.C_Str());//имя меша = имя первого по счету меша в aiScene
    //проходим по всем мешам сцены собираем вершины, текстурные координаты и нормали
    for(unsigned int n=0;n!=scene->mNumMeshes;n++){
        aiMesh *mesh=meshes[n];
        aiVector3D *vertexes=mesh->mVertices;
        aiVector3D *texCoords=mesh->mTextureCoords[0];
        aiVector3D *normals=mesh->mNormals; 
        unsigned int m=0;
        for(m=0;m!=mesh->mNumVertices;m++){
            unsigned int cm=c+m;
            vertexAtributesArray->addElement(cm*offset,vertexes[m].x);
            vertexAtributesArray->addElement(cm*offset+1,vertexes[m].y);
            vertexAtributesArray->addElement(cm*offset+2,vertexes[m].z);
            if(mesh->HasTextureCoords(0)){
                vertexAtributesArray->addElement(cm*offset+3,texCoords[m].x);
                vertexAtributesArray->addElement(cm*offset+4,texCoords[m].y);
            }
            else{
                vertexAtributesArray->addElement(cm*offset+3,0);
                vertexAtributesArray->addElement(cm*offset+4,0);
            }
            if(mesh->HasNormals()){
                vertexAtributesArray->addElement(cm*offset+5,normals[m].x);
                vertexAtributesArray->addElement(cm*offset+6,normals[m].y);
                vertexAtributesArray->addElement(cm*offset+7,normals[m].z);
            }
            else{
                vertexAtributesArray->addElement(cm*offset+5,0);
                vertexAtributesArray->addElement(cm*offset+6,0);
                vertexAtributesArray->addElement(cm*offset+7,0);
            }
            if(offset>8){//если есть кости хотя-бы в одном меше сцены, то резервируем место под них
                for(unsigned int cc=0;cc!=NUM_BONES_PER_VERTEX*2;cc++){
                    vertexAtributesArray->addElement(cm*offset+8+cc,0);
                }
            }
        }
        c+=m;
    }
    //создаем массив индексных объектов
    if(indicesObjectsArray!=NULL){
        indicesObjectsArray->deletePointers();
        delete indicesObjectsArray;
    }
    indicesObjectsArray = new dArray<gameIndexObject*>(scene->mNumMeshes);
    beginIndex=lastIndex;
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
        if(mesh->HasBones()){//если данный меш имеет кости, то собираем их. Иначе места в массиве остаются нулевыми
            loadBones(mesh,beginIndex);
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
    //собираем источники света
    if(scene->HasLights()){
        loadLights(scene);
    }
    //строим иерархию
    rootNode=createHierarhi(scene->mRootNode);
    size=emptyNodesVector.size();
    if(size!=0){//если вектор пустых нодов не пустой, то создаем массив
        emptyNodes = new dArray<nodeObject*>(size);
        for(unsigned int n=0;n!=size;n++){//заполняем его
            emptyNodes->addElement(n,emptyNodesVector[n]);
        }
        emptyNodesVector.clear();//а вектор очищаем
    }
    meshNames.clear();//имена мешей больше не нужны

    //собираем анимации
    loadAnimations(scene);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void editabelGraphicObject::setMoveVector(const glm::vec3 vector){
    move=vector;
    calculateModelMatrix();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void editabelGraphicObject::setRotateVector(const glm::vec3 vector){
    rotate=vector;
    calculateModelMatrix();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void editabelGraphicObject::setScaleVector(const glm::vec3 vector){
    scale=vector;
    calculateModelMatrix();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
glm::vec3 editabelGraphicObject::getMoveVector()const{
    return move;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
glm::vec3 editabelGraphicObject::getRotateVector()const{
    return rotate;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
glm::vec3 editabelGraphicObject::getScaleVector()const{
    return scale;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void editabelGraphicObject::setVertexShaderFileName(QString name){
    vertexShader=name.toStdString();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void editabelGraphicObject::setFragmentShaderFileName(QString name){
    fragmentShader=name.toStdString();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void editabelGraphicObject::calculateModelMatrix(){
    glm::mat4 mScale = glm::scale(glm::mat4(1.0f),scale);
    glm::mat4 mRotateX = glm::rotate(mScale,glm::radians(rotate.x),glm::vec3(1.0f,0.0f,0.0f));
    glm::mat4 mRotateY = glm::rotate(mRotateX,glm::radians(rotate.y),glm::vec3(0.0f,1.0f,0.0f));
    glm::mat4 mRotateZ = glm::rotate(mRotateY,glm::radians(rotate.z),glm::vec3(0.0f,0.0f,1.0f));
    modelMatrix = glm::translate(mRotateZ,move);
    normalMatrix=glm::transpose(glm::inverse(normalMatrix));
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void editabelGraphicObject::loadLights(const aiScene *scene){
    unsigned int size=scene->mNumLights;
    lightSorces = new dArray<gameObjectLight*>(size);
    for(unsigned int n=0;n!=size;n++){
        lightPropetries prop;
        aiLight *light=scene->mLights[n];
        prop.angleInnerCone=light->mAngleInnerCone;
        prop.angleOuterCone=light->mAngleOuterCone;
        prop.attenuationConstant=light->mAttenuationConstant;
        prop.attenuationLinear=light->mAttenuationLinear;
        prop.attenuationQuadratic=light->mAttenuationQuadratic;
        prop.cAmbient=glm::vec4(light->mColorAmbient.r,light->mColorAmbient.g,light->mColorAmbient.b,0.0);
        prop.cDiffuse=glm::vec4(light->mColorDiffuse.r,light->mColorDiffuse.g,light->mColorDiffuse.b,0.0);
        prop.cSpecular=glm::vec4(light->mColorSpecular.r,light->mColorSpecular.g,light->mColorSpecular.b,0.0);
        prop.direction=glm::vec4(light->mDirection.x,light->mDirection.y,light->mDirection.z,0.0);
        prop.position=glm::vec4(light->mPosition.x,light->mPosition.y,light->mPosition.z,0.0);
        gameObjectLight *gLight = new gameObjectLight;
        gLight->setProperties(prop);
        switch (light->mType) {
            case(aiLightSource_DIRECTIONAL):{
                gLight->setType(LIGHT_DIRECTIONAL);
                break;
            }
            case(aiLightSource_POINT):{
                gLight->setType(LIGHT_POINT);
                break;
            }
            case(aiLightSource_SPOT):{
                gLight->setType(LIGHT_SPOT);
                break;
            }
            case(aiLightSource_AMBIENT):{
                gLight->setType(LIGHT_AMBIENT);
                break;
            }
            default:{
                gLight->setType(LIGHT_UNDEFINED);
                break;
            }
        }
        gLight->setName(light->mName.C_Str());
        lightSorces->addElement(n,gLight);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void editabelGraphicObject::loadBones(const aiMesh *mesh, unsigned int beginIndex){
    //формат: vX,vY,vZ,tX,tY,nX,nY,nZ,boneIndex1,w1,boneIndex2,w2,boneIndex3,w3,boneIndex4,w4 -для объектов с костями
    unsigned int size=mesh->mNumBones;
    static unsigned int boneIndex=0;

    unsigned int n=0;
    for(n=0;n!=size;n++){
        bone *B = new bone;
        aiBone *bone=mesh->mBones[n];
        B->setOffsetMatrix(convertMatrix(bone->mOffsetMatrix));
        B->setName(bone->mName.C_Str());
        bonesArray->addElement(boneIndex+n,B);
        for(unsigned int m=0;m!=bone->mNumWeights;m++){
            aiVertexWeight weight=bone->mWeights[m];
            unsigned int offset=(weight.mVertexId+beginIndex)*(8+NUM_BONES_PER_VERTEX*2)+8;//смещение для вершины в массиве - индекс+смещение меша+8 флоатов (вершинные атрибуты)
            for(unsigned int c=0;c!=NUM_BONES_PER_VERTEX;c++){
                if(vertexAtributesArray->operator [](offset+c)==(float)0 && vertexAtributesArray->operator [](offset+c+1)==(float)0){//если позиция кости =0, то пишем в нее
                    vertexAtributesArray->operator [](offset+c)=boneIndex+n;//индекс кости
                    vertexAtributesArray->operator [](offset+c+1)=weight.mWeight;//вес
                    break;
                }//иначе проверяем следующую позицию
                //если все позиции заняты, то кость не записывается
            }
        }
    }
    boneIndex+=n;
    if(boneIndex==bonesArray->getSize()){
        boneIndex=0;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void editabelGraphicObject::loadAnimations(const aiScene *scene){
    unsigned int size=scene->mNumAnimations;
    animationsArray = new dArray<animation*>(size);

    for(unsigned int n=0;n!=size;n++){
        aiAnimation *tmpAnim=scene->mAnimations[n];
        animation *tmpAnimation = new animation;
        tmpAnimation->setName(tmpAnim->mName.C_Str());
        tmpAnimation->setDuration(tmpAnim->mDuration);
        tmpAnimation->setTickPerSecond(tmpAnim->mTicksPerSecond);

        unsigned int nChanels=tmpAnim->mNumChannels;
        dArray<animChannel*> *tmpChannelsArray = new dArray<animChannel*>(nChanels);
        for(unsigned int m=0;m!=nChanels;m++){
            dArray<animKey*> *tmpKeys=NULL;

            //ключи позиций
            animChannel *tmpChannel = new animChannel;
            tmpChannel->setNodeName(tmpAnim->mChannels[n]->mNodeName.C_Str());

            unsigned int keySize=tmpAnim->mChannels[m]->mNumPositionKeys;
            tmpKeys = new dArray<animKey*>(keySize);
            for(unsigned int nm=0;nm!=keySize;nm++){
                animKey *tmpKey = new animKey;
                aiVectorKey key=tmpAnim->mChannels[m]->mPositionKeys[nm];
                tmpKey->setTime(key.mTime);
                tmpKey->setValue(glm::vec3(key.mValue.x,key.mValue.y,key.mValue.z));
                tmpKeys->addElement(nm,tmpKey);
            }
            tmpChannel->setPositionKeys(tmpKeys);

            //ключи поворотов
            dArray<animQuatKey*>*tmpQuatKeys = new dArray<animQuatKey*>(keySize);
            keySize=tmpAnim->mChannels[m]->mNumRotationKeys;
            for(unsigned int nm=0;nm!=keySize;nm++){
                animQuatKey *tmpQuatKey = new animQuatKey;
                aiQuatKey key=tmpAnim->mChannels[m]->mRotationKeys[nm];
                tmpQuatKey->setTime(key.mTime);
                tmpQuatKey->setValue(glm::quat(key.mValue.w,key.mValue.x,key.mValue.y,key.mValue.z));
                tmpQuatKeys->addElement(nm,tmpQuatKey);
            }
            tmpChannel->setRotationKeys(tmpQuatKeys);

            //ключи масштабирования
            keySize=tmpAnim->mChannels[m]->mNumScalingKeys;
            tmpKeys = new dArray<animKey*>(keySize);
            for(unsigned int nm=0;nm!=keySize;nm++){
                animKey *tmpKey = new animKey;
                aiVectorKey key=tmpAnim->mChannels[m]->mScalingKeys[nm];
                tmpKey->setTime(key.mTime);
                tmpKey->setValue(glm::vec3(key.mValue.x,key.mValue.y,key.mValue.z));
                tmpKeys->addElement(nm,tmpKey);
            }
            tmpChannel->setScaleKeys(tmpKeys);
            tmpChannelsArray->addElement(m,tmpChannel);
        }
        animationsArray->addElement(n,tmpAnimation);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
nodeObject *editabelGraphicObject::createHierarhi(const aiNode *node){
    nodeObject *no=findNode(node->mName);
    if(no==NULL){
        no = new nodeObject;
        emptyNodesVector.append(no);
    }
    no->setTransformMatrix(convertMatrix(node->mTransformation));
    if(node->mParent!=NULL){
        no->setParent(findNode(node->mParent->mName));
    }
    no->setName(node->mName.C_Str());
    unsigned int size=node->mNumChildren;
    if(size!=0){
        dArray<nodeObject*>*nodes = new dArray<nodeObject*>(size);
        for(unsigned int n=0;n!=size;n++){
            nodes->addElement(n,createHierarhi(node->mChildren[n]));
        }
        no->setChildsArray(nodes);
    }
    return no;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
nodeObject *editabelGraphicObject::findNode(aiString name){

    string nodeName=name.C_Str();
    nodeObject *node;
    //проверяем, по массиву имен мешей
    unsigned int size=meshNames.size();
    for(unsigned int n=0;n!=size;n++){
        if(meshNames[n]==name){
            return this;
        }
    }
    //проверяем по массиву костей
    if(bonesArray!=NULL){
        size=bonesArray->getSize();
        for(unsigned int n=0;n!=size;n++){
            node=bonesArray->operator [](n);
            if(node->getName()==nodeName){
                return node;
            }
        }
    }
    //проверяем по массиву источников света
    if(lightSorces!=NULL){
        size=lightSorces->getSize();
        for(unsigned int n=0;n!=size;n++){
            node=lightSorces->operator [](n);
            if(node->getName()==nodeName){
                return node;
            }
        }
    }
    //проверяем по массиву пустых нодов
    size=emptyNodesVector.size();
    for(unsigned int n=0;n!=size;n++){
        node=emptyNodesVector[n];
        if(node->getName()==nodeName){
            return node;
        }
    }

    return NULL;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
glm::mat4 editabelGraphicObject::convertMatrix(aiMatrix4x4 matrix){
    glm::mat4 mat;
    mat[0][0]=matrix.a1; mat[0][1]=matrix.a2; mat[0][2]=matrix.a3; mat[0][3]=matrix.a4;
    mat[1][0]=matrix.b1; mat[1][1]=matrix.b2; mat[1][2]=matrix.b3; mat[1][3]=matrix.b4;
    mat[2][0]=matrix.c1; mat[2][1]=matrix.c2; mat[2][2]=matrix.c3; mat[2][3]=matrix.c4;
    mat[3][0]=matrix.d1; mat[3][1]=matrix.d2; mat[3][2]=matrix.d3; mat[3][3]=matrix.d4;
    return mat;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////




















