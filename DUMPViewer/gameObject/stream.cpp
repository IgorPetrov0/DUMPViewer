#include "stream.h"

stream::stream(unsigned char *array, unsigned int size)
{
    s_array=array;
    s_pos=0;
    s_arraySize=size;
}
////////////////////////////////////////////////////
void stream::out(int var){
    int size=sizeof(int);
    unsigned char *p=(unsigned char*)&var;
    add(p,size);
}
///////////////////////////////////////////////////////
void stream::out(bool var){
    int size=sizeof(bool);
    unsigned char *p=(unsigned char*)&var;
    add(p,size);
}
//////////////////////////////////////////////////////
void stream::out(float var){
    int size=sizeof(float);
    unsigned char *p=(unsigned char*)&var;
    add(p,size);
}
///////////////////////////////////////////////////////////////////
void stream::out(double var){
    int size=sizeof(double);
    unsigned char *p=(unsigned char*)&var;
    add(p,size);
}
////////////////////////////////////////////////////
void stream::out(std::string var){
    int size=var.capacity();
    const char *p=var.c_str();
    out(size);
    add((unsigned char*)p,size);
}
/////////////////////////////////////////////////////
void stream::out(const unsigned char *array, unsigned int size){
    add((unsigned char*)&size,sizeof(unsigned int));
    add(array,size);
}
////////////////////////////////////////////////////////////
void stream::out(const unsigned int *array, unsigned int size){
    add((unsigned char*)&size,sizeof(unsigned int));
    add((unsigned char*)array,size*sizeof(unsigned int));
}
/////////////////////////////////////////////////////////////////
void stream::out(const float *array, unsigned int size){
    add((unsigned char*)&size,sizeof(unsigned int));
    add((unsigned char*)array,size*sizeof(float));
}
//////////////////////////////////////////////////////////////////////////
void stream::out(vector2 *var){
    VAR_NOT_NULL
    out(var->x());
    out(var->y());
}
//////////////////////////////////////////////////////////////////////////
void stream::out(vector3 *var){
    VAR_NOT_NULL
    out((vector2*)var);
    out(var->z());
}
//////////////////////////////////////////////////////////////////////////
void stream::out(vertex *var){
    VAR_NOT_NULL
    vector3 pos=var->getPos();
    vector2 texCoord=var->getTexCoord();
    vector3 normal=var->getNormal();
    out(&pos);
    out(&texCoord);
    out(&normal);
}
//////////////////////////////////////////////////////////////////////////
void stream::out(rigidBody *var){
    VAR_NOT_NULL
    out((int)var->getSource());
    if(var->getSource()==MESH_ORIGINAL){
        out(var->getMeshPointer());
    }
    out(var->getIndicesPointer()->getArrayPointer(),var->getIndicesPointer()->getSize());
    out(var->getMass());
    vector3 mCenter=var->getMassCenter();
    out(&mCenter);
    out((int)var->getType());
}
//////////////////////////////////////////////////////////////////////////
void stream::  out(phisycObject *var){
    VAR_NOT_NULL
    int size=var->rigidBodyesCount();
    dArray<rigidBody*> *arr=var->getRigidBodiesPointer();
    out(size);//размер массива
    for(int n=0;n!=size;n++){
        out(arr->operator [](n));
    }

    size=var->constraintsCount();
    dArray<constraint*> *cArr=var->getConstraintsPointer();
    out(size);//размер массива
    for(int n=0;n!=size;n++){
        out(cArr->operator [](n));
    }
}
//////////////////////////////////////////////////////////////////////////
void stream::out(meshObject *var){
    VAR_NOT_NULL
    dArray<float> *vArray=var->getVertexArray();
    out(vArray->getArrayPointer(),vArray->getSize());
    out(var->getName());
    vector3 bb=var->getBoundBox();
    out(&bb);
    out((int)var->getTrianglesCount());
}
//////////////////////////////////////////////////////////////////////////
void stream::out(LOD *var){
    VAR_NOT_NULL
    out((graphicObject*)var);
    out(var->getDistance());
}
//////////////////////////////////////////////////////////////////////////
void stream::out(graphicObject *var){
    VAR_NOT_NULL
    out((meshObject*)var);

    dArray<float> *cArray=var->getTexCoordArrayPointer();
    if(cArray!=NULL){
        out(cArray->getArrayPointer(),cArray->getSize());
    }
    else{
        out((int)0);
    }
    int size=0;

    out(var->isVisible());
}
//////////////////////////////////////////////////////////////////////////
void stream::out(gameObjectTexture *var){
    VAR_NOT_NULL
    out(var->getName());
}
//////////////////////////////////////////////////////////////////////////
void stream::out(gameObjectMaterial *var){
    VAR_NOT_NULL
    out(var->getTexture());
    //out(var->getIndices()->getArrayPointer(),var->getIndecesSize());//индексы
}
//////////////////////////////////////////////////////////////////////////
void stream::out(constraint *var){
    VAR_NOT_NULL
    outPtr(var->getRigitBodyA());
    outPtr(var->getRigitBodyB());
    out(var->getPivotA());
    out(var->getPivotB());
    out(var->getTransformA());
    out(var->getTransformB());
}
/////////////////////////////////////////////////////////////////////////////
void stream::out(btTransform *var){
    VAR_NOT_NULL
    btTransformFloatData data;
    var->serializeFloat(data);
    out((float*)&data,16);
}
//////////////////////////////////////////////////////////////////////////////
void stream::out(gameObject *var){
    VAR_NOT_NULL
    out(var->getName());
    graphicObject *mainMesh=var->getMainMesh();
    if(mainMesh!=NULL){
        out(true);//метка: существует или нет mainMesh
        out(var->getMainMesh());
    }
    else{
        out(false);
    }

    int size=var->LODsSize();
    out(size);
    for(int n=0;n!=size;n++){
        out(var->getLod(n));
    }
    phisycObject *pObject=var->getPhisycObject();
    if(pObject!=NULL){
        out(true);//метка: существует или нет phisycObject
        out(var->getPhisycObject());
    }
    else{
        out(false);
    }

}
/////////////////////////////////////////////////////////////////////////////
void stream::in(int *var){
    take((unsigned char*)var,sizeof(int));
}
///////////////////////////////////////////////////////////////////////////////
void stream::in(unsigned int *var){
    take((unsigned char*)var,sizeof(unsigned int));
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(float *var){
    take((unsigned char*)var,sizeof(float));
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(bool *var){
    take((unsigned char*)var,sizeof(bool));
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(double *var){
    take((unsigned char*)var,sizeof(double));
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(std::string *var){
    int size=0;
    take((unsigned char*)&size,sizeof(int));
    unsigned char *buf=new unsigned char[size+1];
    take(buf,size);
    buf[size]=0;
    *var=(const char*)buf;
    delete buf;
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(unsigned char **array, unsigned int &size){
    unsigned int inSize=0;
    take((unsigned char*)&inSize,sizeof(int));
    *array = new unsigned char[inSize];
    take(*array,inSize);
    size=inSize;
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(unsigned int **array, unsigned int &size){
    unsigned int inSize=0;
    take((unsigned char*)&inSize,sizeof(int));
    *array = new unsigned int[inSize*sizeof(int)];
    take((unsigned char*)*array,inSize*sizeof(int));
    size=inSize;
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(float **array, unsigned int &size){
    unsigned int inSize=0;
    take((unsigned char*)&inSize,sizeof(int));
    *array = new float[inSize];
    take((unsigned char*)*array,inSize*sizeof(float));
    size=inSize;
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(vector2 *var){
    float buf=0;
    take((unsigned char*)&buf,sizeof(float));
    var->setX(buf);
    take((unsigned char*)&buf,sizeof(float));
    var->setY(buf);
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(vector3 *var){
    in((vector2*)var);
    float buf=0;
    take((unsigned char*)&buf,sizeof(float));
    var->setZ(buf);
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(vertex *var){
    vector3 pos, normal;
    vector2 texCoord;
    in(&pos);
    in(&normal);
    in(&texCoord);
    var->setNormal(normal);
    var->setPos(pos);
    var->setTexCoord(texCoord);
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(rigidBody *var){
    unsigned int size=0;
    unsigned int *inArray;
    meshSource source=MESH_NOMESH;
    vector3 mCenter;
    float mass=0;
    int type=0;

    in((int*)&source);
    var->setSource(source);
    if(source==MESH_ORIGINAL){
        meshObject *mObject=new meshObject;
        in(mObject);
        var->setMeshObject(mObject);
    }

    in(&inArray,size);
    dArray<unsigned int> *newArray=new dArray<unsigned int>(inArray,size);
    var->setIndicesArray(newArray);

    in(&mass);
    var->setMass(mass);

    in(&mCenter);
    var->setMassCenter(mCenter);

    in(&type);
    var->setType((rigidBodyType)type);
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(phisycObject *var){
    dArray<rigidBody*> *rigidBodyesArray;
    dArray<constraint*> *constraintsArray;
    int size=0;

    in(&size);
    if(size!=0){
        rigidBodyesArray = new dArray<rigidBody*>(size);
        for(int n=0;n!=size;n++){
            rigidBody *rBody=new rigidBody;
            in(rBody);
            rigidBodyesArray->addElement(n,rBody);
        }
        var->setRigidBodyArray(rigidBodyesArray);
    }

    in(&size);
    if(size!=0){
        constraintsArray = new dArray<constraint*>(size);
        for(int n=0;n!=size;n++){
            constraint *constr=new constraint;
            in(constr);
            constraintsArray->addElement(n,constr);
        }
        var->setConstraintsArray(constraintsArray);
    }
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(meshObject *var){
    dArray<float> *vertexArray=NULL;
    string meshName;
    vector3 boundBox;
    unsigned int trianglesCount;
    unsigned int size;

    float* tmpArray;
    in(&tmpArray,size);
    vertexArray=new dArray<float>(tmpArray,size);
    var->setVertexes(vertexArray);

    in(&meshName);
    var->setName(meshName);

    in(&boundBox);
    var->setBoundBox(boundBox);

    in(&trianglesCount);
    var->setTrianglesCount(trianglesCount);
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(LOD *var){
    float distance=0;

    in((graphicObject*)var);
    in(&distance);
    var->setDistance(distance);
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(graphicObject *var){
    dArray<float> *texCoordsArray;
    dArray<gameObjectMaterial*> *materialsArray;
    bool visible;
    unsigned int size;

    in((meshObject*)var);

    float *tmpArray;
    in(&tmpArray,size);
    texCoordsArray=new dArray<float>(tmpArray,size);
    var->setTexCoordinates(texCoordsArray);

    in((int*)&size);
    materialsArray= new dArray<gameObjectMaterial*>(size);
    for(unsigned int n=0;n!=size;n++){
        gameObjectMaterial *material=new gameObjectMaterial;
        in(material);
        materialsArray->addElement(n,material);
    }

    in(&visible);
    var->setVisible(visible);
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(gameObjectTexture *var){
    string name;

    in(&name);
    var->setName(name);
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(gameObjectMaterial *var){
    dArray<unsigned int> *indicesArray;
    unsigned int size;

    gameObjectTexture *texture = new gameObjectTexture;
    in(texture);
    var->setTexture(texture);

    unsigned int *tmpArray;
    in(&tmpArray,size);
    indicesArray=new dArray<unsigned int>(tmpArray,size);
    //var->setIndicesArray(indicesArray);
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(constraint *var){
    string pointerA;
    string pointerB;
    vector3 *pivotA = new vector3;
    vector3 *pivotB = new vector3;
    btTransform *transformA = new btTransform;
    btTransform *transformB = new btTransform;
    constraintType type;

    inPtr(&pointerA);
    inPtr(&pointerB);
    in(pivotA);
    in(pivotB);
    in(transformA);
    in(transformB);
    in((int*)&type);

    var->setPivotA(pivotA);
    var->setPivotB(pivotB);
    var->setPointerA(pointerA);
    var->setPointerB(pointerB);
    var->setTransformA(transformA);
    var->setTransformB(transformB);
    var->setType(type);
}
/////////////////////////////////////////////////////////////////////////////
void stream::in(btTransform *var){
    btTransformFloatData *data;
    unsigned int size=0;

    in((float**)&data,size);
    var->deSerializeFloat(*data);
}
////////////////////////////////////////////////////////////////////////////
void stream::in(editabelGameObject *var){
    in((gameObject*)var);
}
////////////////////////////////////////////////////////////////////////////
void stream::in(gameObject *var){
    string name;
    bool isExist=false;
    in(&name);
    var->setName(name);

    in(&isExist);
    if(isExist){//если mainMesh существует
        graphicObject *mainMesh=new graphicObject;
        in(mainMesh);
        var->setMainMesh(mainMesh);
    }

    int size=0;
    in(&size);
    if(size!=0){
        dArray<LOD*> *arr=new dArray<LOD*>(size);
        for(int n=0;n!=size;n++){
            LOD *lod=new LOD;
            in(lod);
            arr->operator [](n)=lod;
        }
        var->setLodsArray(arr);
    }

    in(&isExist);//если phisicObject существует
    if(isExist){
        phisycObject *pObject=new phisycObject;
        in(pObject);
        var->setPhisycObject(pObject);
        for(arraySize n=0;n!=pObject->rigidBodyesCount();n++){
            rigidBody *rb=pObject->getRigidBodiesPointer()->operator [](n);
            meshSource source=rb->getSource();
            if(source!=MESH_ORIGINAL){
                switch((int)source){
                    case(MESH_MAIN_MESH):{
                        rb->createMeshObject(var->getMainMesh());
                        break;
                    }
                    case(MESH_LOD1):{
                        rb->createMeshObject(var->getLod(0));
                        break;
                    }
                    case(MESH_LOD2):{
                        rb->createMeshObject(var->getLod(1));
                        break;
                    }
                    case(MESH_LOD3):{
                        rb->createMeshObject(var->getLod(2));
                        break;
                    }
                    case(MESH_LOD4):{
                        rb->createMeshObject(var->getLod(3));
                        break;
                    }
                }
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////
void stream::outPtr(void *ptr){
    typedef int PTR_;//для 64 битных систем тип будет другой!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    PTR_ val=(int)ptr;
    unsigned int size=sizeof(PTR_)+1;
    unsigned char *arr = new unsigned char[size];
    memcpy(arr,&val,size);
    arr[size-1]=0;//добавляем нуль-терминатор т.к. потом читаем указатель в виде строки
    out(arr,size);
}
////////////////////////////////////////////////////////////////////////////////////////
void stream::inPtr(string *name){
    unsigned char *arr;
    unsigned int size;

    in(&arr,size);
    *name=(const char*)arr;
}
//////////////////////////////////////////////////////////////////////////
void stream::add(const unsigned char *array, unsigned int size){
    if(s_arraySize-s_pos>=size){
        unsigned int ptr=(unsigned int)s_array+s_pos;
        memcpy((void*)ptr,array,size);
        s_pos+=size;
    }
}
/////////////////////////////////////////////////////////////////////////////
void stream::take(unsigned char *array, unsigned int size){
    if(s_arraySize-s_pos>=size){
        memcpy(array,s_array+s_pos,size);
        s_pos+=size;
    }
}
///////////////////////////////////////////////////////////////////////////////

