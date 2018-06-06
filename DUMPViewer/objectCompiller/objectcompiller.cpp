#include "objectcompiller.h"

objectCompiller::objectCompiller()
{
    currentObject=NULL;
}
///////////////////////////////////////////////////////////////
void objectCompiller::createEmptyObject(QString objectName){
    currentObject=new editabelGameObject(objectName);
    currentObject->setName(objectName.toStdString());
}
///////////////////////////////////////////////////////////////
bool objectCompiller::addGraphicMesh(QString fileName){
    CHECK_EXIST_OBJECT
    sceneObject *graphicSceneObject;

    if(!parseMeshFile(fileName, graphicSceneObject)){
        return false;
    }
    //теперь готовим графический объект
    compileGraphicObject(graphicSceneObject, currentObject->getMainMesh());//в качестве параметра передаем графику текущего объекта


    delete graphicSceneObject;//кто получает объект, тот и удалаляет. парсер по него уже забыл
    return true;
}
///////////////////////////////////////////////////////////////////////
bool objectCompiller::addPhisicMesh(QString fileName){
    CHECK_EXIST_OBJECT
    sceneObject *phisycSceneObject;

    if(!parseMeshFile(fileName, phisycSceneObject)){
        return false;
    }
    compilePhisycObject(phisycSceneObject, currentObject->getPhisycObject());//в качестве параметра передаем физическю модель текущего объекта

    delete phisycSceneObject;//кто получает объект, тот и удалаляет. парсер по него уже забыл
    return true;
}
///////////////////////////////////////////////////////////////////////
bool objectCompiller::parseMeshFile(QString fileName, sceneObject *object){
    QFileInfo fi(fileName);
    path=fi.absolutePath();
    QString suf=fi.suffix();

    //вызываем парсеры в зависимости от типа файла
    if(suf=="obj"){//если файл .obj
        parserOBJ parser;
        if(!parser.readFile(fileName)){
            error=parser.getLastError();
            return false;
        }
        object=parser.getSceneObject();
    }
    //TODO тут будут другие парсеры
    //
    //
    return true;
}
//////////////////////////////////////////////////////////////////
editabelGameObject *objectCompiller::getCurrentObject(){
    return currentObject;
}
//////////////////////////////////////////////////////////////////
bool objectCompiller::compileGraphicObject(sceneObject *sObject, graphicObject* gObject){
    CHECK_EXIST_OBJECT
    vector3 v3;
    vector2 v2;

    vector<vertex*> *vertexArray=new vector<vertex*>;//временный массив вершин
    vector<unsigned int> *indicesArray=new vector<unsigned int>;//временный массив индексов
    vector<gameObjectMaterial*> *materialsArray=new vector<gameObjectMaterial*>;//массив материалов
    vector<gameObjectTexture*> *textures=new vector<gameObjectTexture*>;//уже загруженные текстуры

    //проходим по всем материалам объекта
    unsigned int mSize=sObject->getMaterialsSize();
    for(unsigned int n=0;n!=mSize;n++){
        material *tmpMat=sObject->getMaterial(n);
        gameObjectMaterial *newMat= new gameObjectMaterial;
        unsigned int vSize=tmpMat->getVertexesCount();
        for(unsigned int m=0;m!=vSize;m++){
            //строим вершину
            vertex *v=new vertex;

            //получаем по индексу вершину
            int index=tmpMat->getVertexIndicesArrayPointer()[m]*3;//получаем позицию в массиве = индекс*3
            v3.setX(sObject->getVertexArrayPointer()[index]);
            v3.setY(sObject->getVertexArrayPointer()[index+1]);
            v3.setZ(sObject->getVertexArrayPointer()[index+2]);
            v->setPos(v3);

            //получаем по этому индексу текстурные координаты
            index=tmpMat->getTextureIndicesArrayPointer()[m]*2;
            v2.setX(sObject->getTexturesArrayPointer()[index]);
            v2.setY(sObject->getTexturesArrayPointer()[index+1]);
            v->setTexCoord(v2);

            //получаем по этому индексу нормаль
            index=tmpMat->getNormalsIndicesArrayPointer()[m]*3;
            v3.setX(sObject->getNormalsArrayPointer()[index]);
            v3.setY(sObject->getNormalsArrayPointer()[index+1]);
            v3.setZ(sObject->getNormalsArrayPointer()[index+2]);
            v->setNormal(v3);

            //ишем получившуюся вершину в массиве
            unsigned int newIndex=findVertex(v,vertexArray);//если функция нашла вершину она вернет ее позицию
            if(newIndex==vertexArray->size()){//если не нашла, то вернет следующую, еще не существующую позицию в массиве
                vertexArray->push_back(v);//тогда пихаем вершину в массив и эта позиция становится существующей
            }
            else{//если такая вершина уже есть
                delete v;//то временную удаляем
            }
            indicesArray->push_back(newIndex);
        }
        //когда прошли по материалу формируем массив для gameObjectMaterial
        dArray<unsigned int> *indArray=new dArray<unsigned int>(indicesArray->size());//создаем массив индексов
        indArray->fillArray(indicesArray);
        newMat->setIndicesArray(indArray);//передаем указатель материалу
        indicesArray->clear();//очищаем вектор для следующего материала

        //ищем текстуру среди ранее загруженных
        unsigned int i=0;
        unsigned int tSize=textures->size();
        for(i=0;i!=tSize;i++){
            if(tmpMat->getTexureFileName().toStdString()==textures->at(i)->getName()){//если нашли
                newMat->setTexture(textures->at(i));//передаем указатель на текстуру
                break;
            }
        }
        if(i==textures->size()){//если не нашли
            //создаем текстуру
            gameObjectTexture *tmpTexture=new gameObjectTexture;
            tmpTexture->setName(tmpMat->getTexureFileName().toStdString());
            loadTexture(tmpTexture);//текстура могла и не загрузиться. значит отображаем без нее
            textures->push_back(tmpTexture);
            newMat->setTexture(tmpTexture);
        }
        //тут скопировать остальные св-ва материала
        //
        //материал готов
        materialsArray->push_back(newMat);
    }
    //когда все материалы готовы
    //формируем массивы для graphicObject

    //вершины
    dArray<float>*vA=new dArray<float>(vertexArray->size()*vertex::sizeInFloat());
    unsigned int size=vertexArray->size();
    for(unsigned int n=0;n!=size;n++){
        vertex *v=vertexArray->at(n);
        //структура вершины в массиве
        unsigned int offset=n*v->sizeInFloat();//получаем смещение в целевом массиве
        //позиция
        vA->addElement(offset,v->getPos().x());//float pos.x
        vA->addElement(offset+1,v->getPos().y());//float pos.y
        vA->addElement(offset+2,v->getPos().z());//float pos.z

        //текстура
        vA->addElement(offset+3,v->getTexCoord().x());//float texCoord.x
        vA->addElement(offset+4,v->getTexCoord().y());//float texCoord.y

        //нормаль
        vA->addElement(offset+5,v->getNormal().x());//float normal.x
        vA->addElement(offset+6,v->getNormal().y());//float normal.y
        vA->addElement(offset+7,v->getNormal().z());//float normal.z
    }

    gObject->setVertexes(vA);//задаем объекту вершины
    //удаляем массив
    delete vertexArray;

    //материалы
    dArray<gameObjectMaterial*>*mA=new dArray<gameObjectMaterial*>(materialsArray->size());
    mA->fillArray(materialsArray);
    gObject->setMaterials(mA);
    //удаляем массив
    delete materialsArray;

    //удаляем массив индексов
    delete indicesArray;
    return 1;
}
///////////////////////////////////////////////////////////////////////////////////////
bool objectCompiller::compilePhisycObject(sceneObject *sObject, editabelPhisycObject *pObject){

}
////////////////////////////////////////////////////////////////////////
unsigned int objectCompiller::findVertex(vertex *ver, vector<vertex *> *array){
    unsigned int size=array->size();
    for(unsigned int n=0;n!=size;n++){
        if(*ver==*array->at(n)){
            return n;
        }
    }
    return size;
}
//////////////////////////////////////////////////////////////////////////////////
QString objectCompiller::getLastError(){
    QString e=QObject::tr("Object compiller error:   ")+error;
    error=QObject::tr("No error.");
    return e;
}
////////////////////////////////////////////////////////////////////////////////
bool objectCompiller::loadTexture(gameObjectTexture *texture){
    //пока предполагаем, что текстуры лежат вместе с файлом
    QImage tex(TEXTURES_DIR+"/"+QString::fromStdString(texture->getName()));
    if(tex.isNull()){
        error=QObject::tr("Can't open texture file ")+QString::fromStdString(texture->getName())+QObject::tr(" .");
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
    return true;
}
///////////////////////////////////////////////////////////////////////////////////////////
