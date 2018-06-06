#include "application.h"

application::application()
{
    a_mainWindowPointer=NULL;
    a_currentObject=NULL;
    a_modelFilter="Object files (*.obj *.dae *.blend)";
    a_defaultObjectName="defaultObject";
    a_lastDistance=-5;
    a_programName="DUMPViewer";

}
////////////////////////////////////////////////////////////////////////
QString application::modelFilter(){
    return a_modelFilter;
}
////////////////////////////////////////////////////////////////////////
QString application::defaultObjectName(){
    return a_defaultObjectName;
}
////////////////////////////////////////////////////////////////////////
QString application::programmName(){
    return a_programName;
}
///////////////////////////////////////////////////////////////////////
QString application::currentPath(){
    return a_currentPath;
}
////////////////////////////////////////////////////////////////////////
QWidget *application::mainWindowPointer(){
    return a_mainWindowPointer;
}
////////////////////////////////////////////////////////////////////////
editabelGameObject *application::currentObject(){
    return a_currentObject;
}
////////////////////////////////////////////////////////////////////////
void application::setMainWindowPointer(QWidget *pointer){
    a_mainWindowPointer=pointer;
}
////////////////////////////////////////////////////////////////////////
void application::setCurrentObject(editabelGameObject *object){
    a_currentObject=object;
}
////////////////////////////////////////////////////////////////////////
void application::setCurrentPath(QString path){
    if(!path.isEmpty()){
        a_currentPath=path;
    }
}
//////////////////////////////////////////////////////////////////////////////
void application::setViewWindowPointer(viewWindow *pointer){
    a_view=pointer;
    pointer->setTexturesVector(&texturesArray);
}
//////////////////////////////////////////////////////////////////////////
viewWindow *application::view(){
    return a_view;
}
////////////////////////////////////////////////////////////////////////////
void application::setLastDistance(float distance){
    a_lastDistance=distance;
}
//////////////////////////////////////////////////////////////////////////
float application::lastDistance(){
    return a_lastDistance;
}
////////////////////////////////////////////////////////////////////////////////
void application::deleteCurrentObject(){
    if(a_currentObject!=NULL){
        a_view->deleteAll();
        delete a_currentObject;
        a_currentObject=NULL;
        a_view->update();
    }
}
////////////////////////////////////////////////////////////////////////////////
bool application::loadCurrentObject(QString fileName){
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
bool application::loadTextures(graphicObject *object){
    //грузим текстуры для mainMesh
    int mSize=object->getMaterialsSize();
    for(int n=0;n!=mSize;n++){
        gameObjectMaterial *material=object->getMaterialPointer(n);
        QString fileName=QString::fromStdString(material->getTexture()->getName());
        int m=0;
        for(;m!=texturesArray.size();m++){//ищем такую текстуру в массиве
            if(texturesArray.at(m)->getName()==fileName.toStdString()){//если нашли
                material->getTexture()->deleteTexture();//удаляем дефолтную текстуру
                material->setTexture(texturesArray.at(m));//присваиваем указатель на текстуру материалу
                break;
            }
        }
        if(m==texturesArray.size()){
            //если так и не нашли
            //то загружаем или создаем дефолтную
            gameObjectTexture *texture=material->getTexture();
            QString name=QString::fromStdString(material->getTexture()->getName());
            if(!name.isEmpty()){
                QString g=TEXTURES_DIR+"/"+name;
                QImage tex(g);
                if(tex.isNull()){
                    a_error=QObject::tr("Can't open texture file ")+QString::fromStdString(texture->getName())+QObject::tr(" .");
                    return false;
                }
                tex=tex.convertToFormat(QImage::Format_RGBA8888);//конвертим в формат RGBA8888
                tex=tex.mirrored();
                texture->setWidth(tex.width());
                texture->setHeight(tex.height());

                int size=tex.byteCount();
                dArray<unsigned char> *tmp=new dArray<unsigned char>(size);
                //а это ацкий велосипед на костылях потому, что я пока не нашел, как иначе не таскать с собой объекты QImage, но держать в памяти битмап
                for(int n=0;n!=size;n++){
                    tmp->addElement(n,tex.bits()[n]);
                }
                texture->setTexturePointer(tmp);
            }
            texturesArray.append(texture);
        }
        material->getTexture()->addOuner();//добавляем текстуре владельца
    }
    return true;
}
/////////////////////////////////////////////////////////////////////////////////////
bool application::saveCurrentObject(QString fileName){
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
bool application::loadGraphicObject(QString fileName, editabelGraphicObject *object){
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
    object->loadFromAiScene(scene);




    //пробуем обойтись без лоадера
    //    loader lr;
//    lr.setTexturesVector(&texturesArray);
//    if(!lr.loadGraphicObject(object,fileName)){
//        a_error=lr.getLastError();
//        return false;
//    }
//    return true;
}
/////////////////////////////////////////////////////////////////////////////////
QString application::getLastError(){
    QString tmp=a_error;
    a_error.clear();
    return tmp;
}
