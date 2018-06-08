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
    pointer->setTexturesVector(&texturesArray);
}
//////////////////////////////////////////////////////////////////////////
viewWindow *editorCore::view(){
    return a_view;
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
            for(int n=0;n!=texturesArray.size();n++){
                texturesArray[n]->deleteTexture();
            }
            texturesArray.clear();
            //грузим текстуры
            if(newObject->mainMeshExsist()){
                loadTextures(newObject->getMainMesh());
            }
            for(unsigned int n=0;n!=newObject->LODsSize();n++){
                loadTextures(newObject->getLod(n));
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
////////////////////////////////////////////////////////////////////////////////////////
bool editorCore::loadTextures(graphicObject *object){
    //грузим текстуры для mainMesh
//    int mSize=object->getMaterialsSize();
//    for(int n=0;n!=mSize;n++){
//        gameObjectMaterial *material=object->getMaterialPointer(n);
//        QString fileName=QString::fromStdString(material->getTexture()->getName());
//        int m=0;
//        for(;m!=texturesArray.size();m++){//ищем такую текстуру в массиве
//            if(texturesArray.at(m)->getName()==fileName.toStdString()){//если нашли
//                material->getTexture()->deleteTexture();//удаляем дефолтную текстуру
//                material->setTexture(texturesArray.at(m));//присваиваем указатель на текстуру материалу
//                break;
//            }
//        }
//        if(m==texturesArray.size()){
//            //если так и не нашли
//            //то загружаем или создаем дефолтную
//            gameObjectTexture *texture=material->getTexture();
//            QString name=QString::fromStdString(material->getTexture()->getName());
//            if(!name.isEmpty()){
//                QString g=TEXTURES_DIR+"/"+name;
//                QImage tex(g);
//                if(tex.isNull()){
//                    a_error=QObject::tr("Can't open texture file ")+QString::fromStdString(texture->getName())+QObject::tr(" .");
//                    return false;
//                }
//                tex=tex.convertToFormat(QImage::Format_RGBA8888);//конвертим в формат RGBA8888
//                tex=tex.mirrored();
//                texture->setWidth(tex.width());
//                texture->setHeight(tex.height());

//                int size=tex.byteCount();
//                dArray<unsigned char> *tmp=new dArray<unsigned char>(size);
//                //а это ацкий велосипед на костылях потому, что я пока не нашел, как иначе не таскать с собой объекты QImage, но держать в памяти битмап
//                for(int n=0;n!=size;n++){
//                    tmp->addElement(n,tex.bits()[n]);
//                }
//                texture->setTexturePointer(tmp);
//            }
//            texturesArray.append(texture);
//        }
//        material->getTexture()->addOuner();//добавляем текстуре владельца
//    }
//    return true;
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

    object->loadFromAiScene(scene);  
    return true;
}
/////////////////////////////////////////////////////////////////////////////////
QString editorCore::getLastError(){
    QString tmp=a_error;
    a_error.clear();
    return tmp;
}
///////////////////////////////////////////////////////////////////////////////////
bool editorCore::addMaterials(const aiScene *scene, QString objectPath){

    gameObjectMaterial *material = new gameObjectMaterial;
    unsigned int size=scene->mNumMaterials;
    for(unsigned int n=0;n!=size;n++){
        aiMaterial *mat=scene->mMaterials[n];
        unsigned int texCount=scene->mMaterials[n]->GetTextureCount(aiTextureType_DIFFUSE);//добавляем диффузные текстуры
        for(unsigned int m=0;m!=texCount;m++){
            gameObjectTexture *newTexture=addTexturesFromFiles(mat,aiTextureType_DIFFUSE,m,objectPath);
            if(newTexture!=NULL){
                material->addTexture(newTexture);
            }
            else{
                return false;
            }
        }
    }




    return true;
}
///////////////////////////////////////////////////////////////////////////////////
bool editorCore::addTextures(const aiScene *scene, QString objectPath){

}
////////////////////////////////////////////////////////////////////////////////////
gameObjectTexture *editorCore::addTexturesFromFiles(aiMaterial *material, aiTextureType type, unsigned int index, QString objectPath){
    gameObjectTexture *newTexture=NULL;
    aiString filePath;

    aiReturn r=material->GetTexture(type,index,&filePath,NULL,NULL,NULL,NULL,NULL);
    if(r==aiReturn_SUCCESS){
        QString fileName=QString::fromLatin1(filePath.data, filePath.length);
        //ищем название в хранилище
        unsigned int size=texturesArray.size();
        for(unsigned int n=0;n!=size;n++){
            gameObjectTexture *tex=texturesArray[n];
            if(tex->getName()==filePath.C_Str()){//если текстура найдена, то выходим и ничего не делаем
                tex->addOuner();//добавляем владельца
                return tex;//возвращаем существующую текстуру
            }
        }
        QString fullPath=objectPath+"/"+QString::fromLatin1(filePath.data,filePath.length);
        QFile file(fullPath);
        if(!file.exists()){
            a_error=tr("Texture file ")+fileName+tr(" not found.");
            return newTexture;
        }
        QFileInfo fi(fullPath);
        newTexture = new gameObjectTexture;
        newTexture->setName(fi.fileName().toStdString());//имя текстуры - это имя файла с расширением без путей
        ILuint id;
        ilInit();
        ilGenImages(1,&id);
        ilBindImage(id);
        ilLoadImage((wchar_t*)fi.absoluteFilePath().data());


        return newTexture;
    }
    else{
        a_error==tr("Error read diffuse texture from material.");
        return NULL;
    }
}
