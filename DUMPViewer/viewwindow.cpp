#include "viewwindow.h"

viewWindow::viewWindow(QWidget *parent)
    : QOpenGLWidget(parent)
{
    QSurfaceFormat format;
      format.setDepthBufferSize(24);
      format.setMajorVersion(4);
      format.setMinorVersion(5);
      format.setSamples(4);
      format.setProfile(QSurfaceFormat::CoreProfile);
      setFormat(format);
      loaded=false;
      this->parent=parent;
      angleX=0;
      angleY=0;
      mPosX=0;
      mPosY=0;
      moveX=0;
      moveY=0;
      distance=-1;
      MVPMatrixLocation=0;
      projection = glm::perspective(glm::radians(60.0f),4.0f/3.0f,0.1f,100.0f);
}
////////////////////////////////////////////////////////////
viewWindow::~viewWindow(){

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void viewWindow::addModel(editabelGraphicObject *model){
    GLsizei arSize=0;

    if(model==NULL){
        return;
    }
    if(model->isEmpty()){
        return;
    }
    modelsArray.append(model);
    makeCurrent();//делаем контекст OpenGL текущим
    GLuint vboName,  vaoName, indBuffer;
    //сначала создаем VBO и заполняем его данными
    glGenBuffers(1,&vboName);
    glBindBuffer(GL_ARRAY_BUFFER,vboName);
    arSize=model->getVertexseSize()*sizeof(float);
    const vertexCoordinates *arr=model->getVertexesPointer();
    glBufferData(GL_ARRAY_BUFFER,arSize,arr,GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    model->setVboName(vboName);

    unsigned int size=model->getNumIndicesObjects();
    for(unsigned int m=0;m!=size;m++){//проходим по всем индексным объектам
        gameIndexObject *indObject = model->getIndexObject(m);
        gameObjectTexture *tex=indObject->getMaterial()->getDiffuseTexture();
        if(tex!=NULL){
            if(!tex->isExistInOpenGL()){//создаем текстуру, если она еще не создана
                GLuint tName;
                glGenTextures(1,&tName);
                glBindTexture(GL_TEXTURE_2D,tName);
                glPixelStorei(GL_UNPACK_ALIGNMENT,1);
                tex->setOglName(tName);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex->width(),tex->height(),0,tex->getOGLFormat(),tex->getDataType(),tex->getTexturePointer()->getArrayPointer());
                //параметры фильтрации - линейная
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glBindTexture(GL_TEXTURE_2D,0);
            }
        }
        //создаем буферы индексов
        glGenBuffers(1,&indBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,indBuffer);
        const unsigned int *indArray=indObject->getIndices()->getArrayPointer();
        GLsizeiptr indSize=indObject->getIndicesCount();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,indSize*sizeof(unsigned int),indArray,GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
        indObject->setEbo(indBuffer);

        //создаем VAO
        glGenVertexArrays(1,&vaoName);
        glBindVertexArray(vaoName);
        glBindBuffer(GL_ARRAY_BUFFER,vboName);//биндим к нему VBO
        GLsizei strade=8*sizeof(float);
        glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,strade,NULL);//координаты вершины
        glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,strade,(GLvoid*)(3*sizeof(float)));//текстурные координаты
        glVertexAttribPointer(3,3,GL_FLOAT,GL_FALSE,strade,(GLvoid*)(5*sizeof(float)));//нормаль
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);
        glEnableVertexAttribArray(3);
        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER,0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
        indObject->getMaterial()->setVAOName(vaoName);
    }
    model->clear();//удаление из ОЗУ данных, которые загружены в видеопамять
    calculateViewMatrix();
    update();
}
////////////////////////////////////////////////////
void viewWindow::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(0.0,0.0,0,0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}
/////////////////////////////////////////////////////
void viewWindow::resizeGL(){
    glViewport(0,0,200,200);
}
//////////////////////////////////////////////////////
void viewWindow::paintGL(){
    if(modelsArray.size()!=0){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(sProgram);
        unsigned int mSize=modelsArray.size();
        for(unsigned int n=0;n!=mSize;n++){
            if(modelsArray[n]->isVisible()){
                unsigned int matSize=modelsArray[n]->getNumIndicesObjects();
                for(unsigned int m=0;m!=matSize;m++){
                    gameIndexObject *indObject=modelsArray[n]->getIndexObject(m);
                    gameObjectMaterial *tmpMat=indObject->getMaterial();
                    if(tmpMat->getDiffuseTexture()!=NULL){//если у материала есть текстура(текстуры может и не быть.)
                        //биндим текстуру
                        glBindTexture(GL_TEXTURE_2D,tmpMat->getOGLTextureName());
                    }
                    GLuint vao=indObject->getMaterial()->getVAOName();
                    GLint ebo=indObject->getEbo();
                    glBindVertexArray(vao);
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
                    GLsizei indices=(GLsizei)indObject->getIndicesCount();
                    glm::mat4 MVP = projection*view*modelsArray[n]->getModelMatrix();
                    glUniformMatrix4fv(MVPMatrixLocation,1,false,glm::value_ptr(MVP));
                    glUniformMatrix4fv(modelMatrixLocation,1,false,glm::value_ptr(modelsArray[n]->getModelMatrix()));
                    glUniformMatrix4fv(normalMatrixLocation,1,false,glm::value_ptr(modelsArray[n]->getNormalMatrix()));
                    float cp[3]={moveX,moveY,distance};
                    glUniform3fv(cameraPosLocation,1,cp);
                    glUniform1fv(defaultLightLocation,1,(float*)defaultLight.getProperties());
                    glUniform1fv(materialParamsLocation,1,(float*)tmpMat->getMatProperties());
                    glDrawElements(GL_TRIANGLES,indices,GL_UNSIGNED_INT,NULL);
                    glBindTexture(GL_TEXTURE_2D,0);
                    glBindVertexArray(0);
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
                }
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////////
void viewWindow::mouseMoveEvent(QMouseEvent *event){
    switch(event->buttons()){
        case(Qt::LeftButton):{
            angleYInc(mPosX-event->pos().x());
            mPosX=event->pos().x();
            angleXInc(mPosY-event->pos().y());
            mPosY=event->pos().y();
            calculateViewMatrix();
            update();
            break;
        }
        case(Qt::MidButton):{
            moveX=moveX-(mPosX-event->pos().x())*0.01;
            moveY=moveY+(mPosY-event->pos().y())*0.01;
            calculateViewMatrix();
            update();
            break;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////
void viewWindow::keyPressed(int key){
    switch(key){
        case(Qt::Key_Up):{
            angleXInc(1);
            break;
        }
        case(Qt::Key_Down):{
            angleXInc(-1);
            break;
        }
        case(Qt::Key_Left):{
            angleYInc(1);
            break;
        }
        case(Qt::Key_Right):{
            angleYInc(-1);
            break;
        }
    }
    calculateViewMatrix();
    update();
}
//////////////////////////////////////////////////////////////////////////////
void viewWindow::angleXInc(int dir){
    angleX-=dir;
    if(angleX>=360){//если вывалились за 360 градусов(потом подумать, что будет, если вывалились за 2*360
        angleX=angleX-360;//то смотрим, на сколько вывалились
    }
    if(angleX<=0){//если вывалились за ноль
        angleX=360-angleX;//то смотрим, на сколько вывалились
    }
}
///////////////////////////////////////////////////////////////////////////////
void viewWindow::angleYInc(int dir){
    angleY-=dir;
    if(angleY>=360){//если вывалились за 360 градусов(потом подумать, что будет, если вывалились за 2*360
        angleY=angleY-360;//то смотрим, на сколько вывалились
    }
    if(angleY<=0){//если вывалились за ноль
        angleY=360-angleY;//то смотрим, на сколько вывалились
    }
}
///////////////////////////////////////////////////////////////////////////////
void viewWindow::calculateViewMatrix(){
    glm::mat4 viewTranslate = glm::translate(glm::mat4(1.0f),glm::vec3(moveX,moveY,distance));
    glm::mat4 viewRotateX = glm::rotate(viewTranslate,glm::radians(angleX),glm::vec3(-1.0f,0.0f,0.0f));
    view = glm::rotate(viewRotateX,glm::radians(angleY),glm::vec3(0.0f,1.0f,0.0f));
}
////////////////////////////////////////////////////////////////////////////////
void viewWindow::mousePressEvent(QMouseEvent *event){
    //при каждом нажатии запоминаем позицию. при движении считаем от нее
    mPosX=event->pos().x();
    mPosY=event->pos().y();
}
//////////////////////////////////////////////////////////////////////////////////
void viewWindow::wheelEvent(QWheelEvent *event){
    //обработка ролика мыши
    if(event->delta()>0){
        distance+=0.1;
    }
    else if(event->delta()<0){
        distance-=0.1;
    }
    calculateViewMatrix();
    update();
}
//////////////////////////////////////////////////////////////////////////////////
void viewWindow::deleteAll(){

//    while(modelsArray.size()!=0){
//        graphicObject *model=modelsArray[0];
//        unsigned int f=0;
//        //удаляем VAO
//        unsigned int mSize=model->getMaterialsSize();
//        for(unsigned int n1=0;n1!=mSize;n1++){
//            f=model->getMaterialPointer(n1)->getTexture()->getOglName();
//            glDeleteTextures(1,&f);
//        }
//        //удаляем все текстуры из видеопамяти
//        unsigned int matSize=model->getMaterialsSize();
//        for(unsigned int n2=0;n2!=matSize;n2++){
//            f=model->getMaterialPointer(n2)->getOGLTextureName();
//            glDeleteVertexArrays(1,&f);
//        }
//        modelsArray.remove(0);
//    }
}
///////////////////////////////////////////////////////////////////////////////////
void viewWindow::removeModel(editabelGraphicObject *model){
    if(model!=NULL){
        int mSize=modelsArray.size();
        for(int n=0;n!=mSize;n++){//ищем модель в контейнере
            if(modelsArray[n]==model){//если нашли
                GLuint f=0;
                f=model->getVboName();
                glDeleteBuffers(1,&f);//удаляем VBO

                //удаляем текстуры
                unsigned int size=model->getNumIndicesObjects();
                for(unsigned int m=0;m!=size;m++){
                    //удаляем текстуры
                    gameIndexObject *indObject=model->getIndexObject(m);
                    gameObjectTexture *tex=indObject->getMaterial()->getDiffuseTexture();
                    if(tex!=NULL){
                        if(!tex->isUsed()){
                            f=tex->getOglName();
                            glDeleteTextures(1,&f);
                        }
                    }
                    //удаляем EBO
                    f=indObject->getEbo();
                    glDeleteBuffers(1,&f);
                }
                modelsArray.remove(n);
                break;
            }
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////
void viewWindow::setDistance(float distance){
    this->distance=distance;
}
/////////////////////////////////////////////////////////////////////////////////////
float viewWindow::getDistance(){
    return distance;
}
///////////////////////////////////////////////////////
void viewWindow::setTexturesVector(QVector<gameObjectTexture *> *vector){
    texturesVector=vector;
}
///////////////////////////////////////////////////////////////////////////////////////
bool viewWindow::setVertexShader(QByteArray *shaderText){

    GLint param=1;
    GLint ret=0;

    const GLchar *vertexShaderSource = new GLchar[shaderText->size()];
    vertexShaderSource=shaderText->data();

    vertexShader=glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexShaderSource,0);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&param);
    if(param!=GL_TRUE){
        glGetShaderiv(vertexShader,GL_INFO_LOG_LENGTH,&param);
        GLchar *log = new GLchar[param];
        glGetShaderInfoLog(vertexShader,param,&ret,log);
        a_error=tr("Vertex shader errors:\n")+QString::fromLatin1(log,param);
        delete log;
        glDeleteShader(vertexShader);
        return false;
    }
    delete vertexShaderSource;
    return true;
}
///////////////////////////////////////////////////////////////////////////////////////
bool viewWindow::setFragmentShader(QByteArray *shaderText){

    GLint param=1;
    GLint ret=0;

    const GLchar *fragmentShaderSource = new GLchar[shaderText->size()];
    fragmentShaderSource=(GLchar*)shaderText->data();

    fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentShaderSource,0);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&param);
    if(param!=GL_TRUE){
        glGetShaderiv(fragmentShader,GL_INFO_LOG_LENGTH,&param);
        GLchar *log = new GLchar[param];
        glGetShaderInfoLog(fragmentShader,param,&ret,log);
        a_error=tr("Fragment shader errors:\n")+QString::fromLatin1(log,param);
        delete log;
        glDeleteShader(fragmentShader);
        return false;
    }

    delete fragmentShaderSource;
    return true;
}
///////////////////////////////////////////////////////////////////////////////
bool viewWindow::compileShaderProgramm(){
    GLint param=1;
    GLint ret=0;

    sProgram=glCreateProgram();
    glAttachShader(sProgram,vertexShader);
    glAttachShader(sProgram,fragmentShader);

    glLinkProgram(sProgram);
    glGetProgramiv(sProgram,GL_LINK_STATUS,&param);
    if(param!=GL_TRUE){
        glGetProgramiv(sProgram,GL_INFO_LOG_LENGTH,&param);
        GLchar *log=new GLchar[param];
        glGetProgramInfoLog(sProgram,param,&ret,log);
        a_error=tr("Link shader programm errors:")+QString::fromLatin1(log,param);
        delete log;
        return false;
    }
    MVPMatrixLocation=glGetUniformLocation(sProgram,"MVPMatrix");
    modelMatrixLocation=glGetUniformLocation(sProgram,"modelMatrix");
    normalMatrixLocation=glGetUniformLocation(sProgram,"normalMatrix");
    //cameraPosLocation=glGetUniformLocation(sProgram,"cameraPos");
    defaultLightLocation=glGetUniformLocation(sProgram,"light");
    materialParamsLocation=glGetUniformLocation(sProgram,"matParam");
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////
QString viewWindow::getLastError(){
    QString tmp=a_error;
    a_error.clear();
    return tmp;
}
