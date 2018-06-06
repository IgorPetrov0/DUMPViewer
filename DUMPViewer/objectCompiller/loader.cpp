#include "loader.h"

loader::loader()
{
    l_texturesVector=NULL;
}
/////////////////////////////////////////////////////////////////////
bool loader::loadGraphicObject(graphicObject *gObject, QString fileName){

    Importer importer;

    const aiScene *scene=importer.ReadFile(fileName.toStdString(),aiProcess_Triangulate|aiProcess_JoinIdenticalVertices);
    if(scene==NULL){
        error=QObject::tr("File ")+fileName+QObject::tr(" is not open.");
        return false;
    }
    if(!scene->HasMeshes()){
        error=QObject::tr("Model ")+fileName+QObject::tr(" has no meshes.");
    }

    //вершины
    //подсчитываем общее кол-во вершин в сцене
    unsigned int numVertices=0;
    aiMesh **meshes=scene->mMeshes;
    for(unsigned int n=0;n!=scene->mNumMeshes;n++){
        aiString s=meshes[n]->mName;
        numVertices+=meshes[n]->mNumVertices;
    }
    //создаем массив вершин для объекта и заполняем его
    //массив вершин один на объект
    dArray<vertexCoordinates> *vertices = new dArray<vertexCoordinates>(numVertices*3);
    unsigned int counter=0;
    for(unsigned int n=0;n!=scene->mNumMeshes;n++){
        for(unsigned int m=0;m!=meshes[n]->mNumVertices;m++){
            aiVector3D v=meshes[n]->mVertices[m];
            vertices->addElement(counter,v.x);
            vertices->addElement(counter+1,v.y);
            vertices->addElement(counter+2,v.z);
            counter+=3;
        }
    }
    gObject->setVertexes(vertices);

    //создаем массив индексов для объекта и заполняем его



//при использовании assimp не требуется
//    sceneObject *graphicSceneObject=NULL;

//    if(!parseMeshFile(fileName, &graphicSceneObject)){
//        return false;
//    }
//    gObject->setBoundBox(calculateBoundBox(graphicSceneObject));
//    gObject->setTrianglesCount(graphicSceneObject->getFaces());
//    //теперь готовим графический объект
//    if(!compileGraphicObject(graphicSceneObject, gObject)){//в качестве параметра передаем графику текущего объекта
//        delete graphicSceneObject;//кто получает объект, тот и удалаляет. парсер про него уже забыл
//        return false;
//    }
//    delete graphicSceneObject;//кто получает объект, тот и удалаляет. парсер про него уже забыл
//    QFileInfo fi(fileName);//присваиваем имя из имени файла
//    gObject->setName(fi.baseName().toStdString());

//    return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool loader::compileGraphicObject(sceneObject *sObject, graphicObject *gObject){

    vector3 v3;
    vector2 v2;

    vector<vertex*> *vertexArray=new vector<vertex*>;//временный массив вершин
    vector<unsigned int> *indicesArray=new vector<unsigned int>;//временный массив индексов
    vector<gameObjectMaterial*> *materialsArray=new vector<gameObjectMaterial*>;//массив материалов

    if(l_texturesVector==NULL){
        error=QObject::tr("Textures vector is not defined. Use setTexturesVector() function.");
        return false;
    }

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
            if((index>=0)&(index < sObject->getVertexSize())){//если индекс не вылезает за пределы массива
                v3.setX(sObject->getVertexArrayPointer()[index]);
                v3.setY(sObject->getVertexArrayPointer()[index+1]);
                v3.setZ(sObject->getVertexArrayPointer()[index+2]);
            }
            else{//иначе обнуляем вершину
                v3.setX(0);
                v3.setY(0);
                v3.setZ(0);
            }
            v->setPos(v3);

            //получаем по этому индексу текстурные координаты
            index=tmpMat->getTextureIndicesArrayPointer()[m]*2;
            if((index>=0)&(index < sObject->getTexturesArraySize())){//если индекс не вылезает за пределы массива
                v2.setX(sObject->getTexturesArrayPointer()[index]);
                v2.setY(sObject->getTexturesArrayPointer()[index+1]);
            }
            else{//иначе обнуляем вершину
                v2.setX(0);
                v2.setY(0);
            }
            v->setTexCoord(v2);

            //получаем по этому индексу нормаль
            index=tmpMat->getNormalsIndicesArrayPointer()[m]*3;
            if((index>=0)&(index < sObject->getNormalsArraySize())){
                v3.setX(sObject->getNormalsArrayPointer()[index]);
                v3.setY(sObject->getNormalsArrayPointer()[index+1]);
                v3.setZ(sObject->getNormalsArrayPointer()[index+2]);
            }
            else{
                v3.setX(0);
                v3.setY(0);
                v3.setZ(0);
            }
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
        int i=0;
        int tSize=l_texturesVector->size();
        for(i=0;i!=tSize;i++){
            if(tmpMat->getTexureFileName().toStdString()==l_texturesVector->at(i)->getName()){//если нашли
                newMat->setTexture(l_texturesVector->at(i));//передаем указатель на текстуру
                break;
            }
        }
        if(i==l_texturesVector->size()){//если не нашли
            //создаем текстуру
            gameObjectTexture *tmpTexture=new gameObjectTexture;
            tmpTexture->setName(tmpMat->getTexureFileName().toStdString());
            loadTexture(tmpTexture);//текстура могла и не загрузиться. значит отображаем без нее
            l_texturesVector->push_back(tmpTexture);
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
    return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////
bool loader::parseMeshFile(QString fileName, sceneObject **object){
    QFileInfo fi(fileName);
    path=fi.absolutePath();
    QString suf=fi.suffix();
    abstractParser *parser=NULL;
    bool result=false;

    //вызываем парсеры в зависимости от типа файла
    if(suf=="obj"){//если файл .obj
        parser = new parserOBJ;
    }
    else if(suf=="dae"){//если файл .dae
        parser = new parserDAE;
    }
    //TODO тут будут другие парсеры
    //
    //

    if(parser!=NULL){
        if(!parser->readFile(fileName)){
            error=parser->getLastError();
        }
        else{
            *object=parser->getSceneObject();
            result=true;
        }
        delete parser;
    }
    return result;
}
////////////////////////////////////////////////////////////////////////////////////////////////
bool loader::loadTexture(gameObjectTexture *texture){

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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int loader::findVertex(vertex *ver, vector<vertex *> *array){
    unsigned int size=array->size();
    for(unsigned int n=0;n!=size;n++){
        if(*ver==*array->at(n)){
            return n;
        }
    }
    return size;
}
////////////////////////////////////////////////////////////////////////////////
vector3 loader::calculateBoundBox(sceneObject *object){
    const float *vertexesArray=object->getVertexArrayPointer();
    float minX=vertexesArray[0];
    float maxX=vertexesArray[0];
    float minY=vertexesArray[1];
    float maxY=vertexesArray[1];
    float minZ=vertexesArray[2];
    float maxZ=vertexesArray[2];

    for(int n=0;n!=object->getVertexSize();n=n+3){
        float v=vertexesArray[n];
        if(v<minX){
            minX=vertexesArray[n];
        }
        if(v>maxX){
            maxX=v;
        }
        v=vertexesArray[n+1];
        if(v<minY){
            minY=vertexesArray[n];
        }
        if(v>maxY){
            maxY=v;
        }
        v=vertexesArray[n+2];
        if(v<minZ){
            minZ=vertexesArray[n];
        }
        if(v>maxZ){
            maxZ=v;
        }
    }
    vector3 tv;
    tv.setX(maxX-minX);
    tv.setY(maxY-minY);
    tv.setZ(maxZ-minZ);
    return tv;
}
//////////////////////////////////////////////////////////////////////////////////////
QString loader::getLastError(){
    QString tmp=error;
    error.clear();
    return tmp;
}
///////////////////////////////////////////////////////////////////////////////////////////
void loader::setTexturesVector(QVector<gameObjectTexture *> *texturesVector){
    l_texturesVector=texturesVector;
}
