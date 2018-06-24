#include "editorCore.h"

editorCore::editorCore()
{
    a_mainWindowPointer=NULL;
    a_currentObject=NULL;
    a_modelFilter="Object files (*.obj *.dae *.blend)";
    a_defaultObjectName="defaultObject";
    a_lastDistance=-5;
    a_programName="DUMPViewer";

}
////////////////////////////////////////////////////////////////////////
editorCore::~editorCore(){
    int t=0;
}
////////////////////////////////////////////////////////////////////////
QString editorCore::modelFilter(){
    return a_modelFilter;
}
////////////////////////////////////////////////////////////////////////
QString editorCore::defaultObjectName(){
    return a_defaultObjectName;
}
////////////////////////////////////////////////////////////////////////
QString editorCore::programmName(){
    return a_programName;
}
///////////////////////////////////////////////////////////////////////
QString editorCore::currentPath(){
    return a_currentPath;
}
////////////////////////////////////////////////////////////////////////
QWidget *editorCore::mainWindowPointer(){
    return a_mainWindowPointer;
}
////////////////////////////////////////////////////////////////////////
editabelGameObject *editorCore::currentObject(){
    return a_currentObject;
}
////////////////////////////////////////////////////////////////////////
void editorCore::setMainWindowPointer(QWidget *pointer){
    a_mainWindowPointer=pointer;
}
////////////////////////////////////////////////////////////////////////
void editorCore::setCurrentObject(editabelGameObject *object){
    a_currentObject=object;
}
////////////////////////////////////////////////////////////////////////
void editorCore::setCurrentPath(QString path){
    if(!path.isEmpty()){
        a_currentPath=path;
    }
}
//////////////////////////////////////////////////////////////////////////////
void editorCore::setViewWindowPointer(viewWindow *pointer){
    a_view=pointer;
    pointer->setTexturesVector(&globalTexturesArray);
}
////////////////////////////////////////////////////////////////////////////
void editorCore::setLastDistance(float distance){
    a_lastDistance=distance;
}
//////////////////////////////////////////////////////////////////////////
float editorCore::lastDistance(){
    return a_lastDistance;
}
////////////////////////////////////////////////////////////////////////////////
void editorCore::deleteCurrentObject(){
    if(a_currentObject!=NULL){
        a_view->deleteAll();
        delete a_currentObject;
        a_currentObject=NULL;
        a_view->update();
    }
}
////////////////////////////////////////////////////////////////////////////////
bool editorCore::loadCurrentGameObject(QString fileName){
    if(fileName.isEmpty()){
        return false;
    }
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly)){
        unsigned int size=file.size();
        if(size!=0){
            unsigned char *arr=new unsigned char[size];
            QDataStream fStr(&file);
            fStr.readRawData((char*)arr,size);
            stream str(arr,size);
            deleteCurrentObject();
            gameObject *tmpObject=new gameObject;
            str.in(tmpObject);//читаем объект
            //создаем редактируемый объект
            editabelGameObject *newObject = new editabelGameObject(tmpObject);
            delete tmpObject;//временный объект убиваем
            newObject->compileGameObject();

            //очищаем массив текстур
            for(int n=0;n!=globalTexturesArray.size();n++){
                globalTexturesArray[n]->deleteTexture();
            }
            globalTexturesArray.clear();
            //грузим текстуры
            if(newObject->mainMeshExsist()){
                //loadTextures(newObject->getMainMesh());
            }
            for(unsigned int n=0;n!=newObject->LODsSize();n++){
                //loadTextures(newObject->getLod(n));
            }
            setCurrentObject(newObject);
            file.close();
            return true;
        }
    }
    QMessageBox box(a_mainWindowPointer);
    box.setText(QObject::tr("Error load game object \n")+fileName);
    box.setStandardButtons(QMessageBox::Ok);
    box.setIcon(QMessageBox::Critical);
    box.exec();
    return false;
}

/////////////////////////////////////////////////////////////////////////////////////
bool editorCore::saveCurrentGameObject(QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox box(a_mainWindowPointer);
        box.setWindowTitle(QObject::tr("Save current object error!"));
        box.setIcon(QMessageBox::Critical);
        box.setText(QObject::tr("Save current object error! \n Can not open file \n")+fileName);
        box.setDefaultButton(QMessageBox::Ok);
        box.exec();
        return false;
    }
    currentObject()->compileGameObject();
    unsigned int size=currentObject()->getSizeInBytes();
    unsigned char *arr=new unsigned char[size];
    stream str(arr,size);
    str.out(a_currentObject);
    QDataStream fStr(&file);
    fStr.writeRawData((const char*)arr,size);
    file.close();
    delete []arr;
    a_currentObject->setSave();
    return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
bool editorCore::loadGraphicObject(QString fileName, editabelGraphicObject *object){
    Importer importer;

    const aiScene *scene=importer.ReadFile(fileName.toStdString(),aiProcess_Triangulate|aiProcess_JoinIdenticalVertices);
    if(scene==NULL){
        a_error=QObject::tr("File ")+fileName+QObject::tr(" is not open.");
        return false;
    }
    if(!scene->HasMeshes()){
        a_error=QObject::tr("Model ")+fileName+QObject::tr(" has no meshes.");
        return false;
    }
    if(scene->HasTextures()){//для форматов, которые хранят текстуры внутри файла
        if(!addTextures(scene,QFileInfo(fileName).absolutePath())){
            return false;
        }
    }
    if(scene->HasMaterials()){//собираем материалы, если они есть
        if(!addMaterials(scene,QFileInfo(fileName).absolutePath())){
            return false;
        }
    }

    object->loadFromAiScene(scene,&globalMaterialsArray);
    return true;
}
/////////////////////////////////////////////////////////////////////////////////
QString editorCore::getLastError(){
    QString tmp=a_error;
    a_error.clear();
    return tmp;
}
///////////////////////////////////////////////////////////////////////////////////
gameObjectMaterial *editorCore::addMaterials(const aiScene *scene, QString objectPath){

    gameObjectMaterial *material=NULL;
    unsigned int size=scene->mNumMaterials;
    for(unsigned int n=0;n!=size;n++){
        aiMaterial *mat=scene->mMaterials[n];
        aiString name;
        mat->Get(AI_MATKEY_NAME,name);
        unsigned int size=globalMaterialsArray.size();
        for(unsigned int n=0;n!=size;n++){//ищем материал в глобальном массиве по имени
            material=globalMaterialsArray[n];
            if(material->getName()==name.C_Str()){
                return material;
            }
        }
        material = new gameObjectMaterial;
        unsigned int texCount=mat->GetTextureCount(aiTextureType_DIFFUSE);//добавляем диффузные текстуры
        for(unsigned int m=0;m!=texCount;m++){
            gameObjectTexture *newTexture=addTexturesFromFiles(mat,aiTextureType_DIFFUSE,m,objectPath);
            if(newTexture!=NULL){
                material->addTexture(newTexture);
            }
            else{
                delete material;
                return NULL;
            }
        }
        material->setName(name.C_Str());
        globalMaterialsArray.append(material);
    }
    return material;
}
///////////////////////////////////////////////////////////////////////////////////
bool editorCore::addTextures(const aiScene *scene, QString objectPath){
    return false;
}
////////////////////////////////////////////////////////////////////////////////////
gameObjectTexture *editorCore::addTexturesFromFiles(aiMaterial *material, aiTextureType type, unsigned int index, QString objectPath){
    gameObjectTexture *newTexture=NULL;
    aiString filePath;

    aiReturn r=material->GetTexture(type,index,&filePath,NULL,NULL,NULL,NULL,NULL);
    if(r==aiReturn_SUCCESS){
        QString fullPath=objectPath+"/"+QString::fromLatin1(filePath.data,filePath.length);
        QFileInfo fi(fullPath);
        //ищем название в хранилище
        unsigned int size=globalTexturesArray.size();
        for(unsigned int n=0;n!=size;n++){
            gameObjectTexture *tex=globalTexturesArray[n];
            if(tex->getName()==fi.fileName().toStdString()){//если текстура найдена, то выходим и ничего не делаем
                return tex;//возвращаем существующую текстуру
            }
        }

        QFile file(fullPath);
        if(!file.exists()){
            a_error=tr("Texture file ")+fi.absoluteFilePath()+tr(" not found.");
            return NULL;
        }

        //строим текстуру
        newTexture = new gameObjectTexture;
        if(newTexture->loadFromFile(fi.fileName().toStdString(),fi.absoluteFilePath().toStdString())){
            globalTexturesArray.append(newTexture);
            return newTexture;
        }
        else{
            delete newTexture;
            a_error=tr("Texture ")+fi.absoluteFilePath()+tr(" not loaded. Used default texture.");
            return NULL;
        }
    }
    else{
        a_error==tr("Error read diffuse texture from material.");
        return NULL;
    }
}
/////////////////////////////////////////////////////////////////////////////
void editorCore::checkMaterials(){
    unsigned int size=globalMaterialsArray.size();
    unsigned int n=0;
    //такой порядок важен. Сначала удаляем материалы. Материалы освобождают текстуры.
    while(n!=size){//проходим по глобальному массиву текстур и удаляем неиспользуемые
        if(!globalMaterialsArray.at(n)->isUsed()){
            delete globalMaterialsArray.at(n);
            globalMaterialsArray.remove(n);//если удалили элемент вектора,
            size=globalMaterialsArray.size();//то обновляем информацию о размере
            n=0;//и начинаем цикл заново
        }
        else{
            n++;
        }
    }
    n=0;
    size=globalTexturesArray.size();
    while(n!=size){//проходим по глобальному массиву текстур и удаляем неиспользуемые
        if(!globalTexturesArray.at(n)->isUsed()){
            delete globalTexturesArray.at(n);
            globalTexturesArray.remove(n);//если удалили элемент вектора,
            size=globalTexturesArray.size();//то обновляем информацию о размере
            n=0;//и начинаем цикл заново
        }
        else{
            n++;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void editorCore::addMainMesh(editabelGraphicObject *mesh){
    a_currentObject->setMainMesh(mesh);
    a_view->addModel(mesh);
    a_view->update();
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void editorCore::addLOD(unsigned int number, editableLOD *lod){
    a_currentObject->addLOD(lod,number);
    a_view->addModel((editabelGraphicObject*)lod);
    a_view->update();
}
////////////////////////////////////////////////////////////////////////////////////////////////
void editorCore::deleteMesh(meshType type){
    switch(type){
        case(MESH_MAIN_MESH):{
            a_view->removeModel(currentObject()->getMainMesh());
            a_currentObject->deleteMainMesh();
            checkMaterials();
            a_view->update();
            break;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
void editorCore::setViewDistance(float value){
    a_view->setDistance(value);
    a_view->update();
}
////////////////////////////////////////////////////////////////////////////////////////////////
float editorCore::getViewDistance(){
    return a_view->getDistance();
}
////////////////////////////////////////////////////////////////////////////////////////////////
void editorCore::updateView(){
    a_view->update();
}
