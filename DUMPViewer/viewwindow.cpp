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
        GLsizei strade=(8+NUM_BONES_PER_VERTEX*2)*sizeof(float);
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
        unsigned int mSize=modelsArray.size();   
        for(unsigned int n=0;n!=mSize;n++){
            if(modelsArray[n]->isVisible()){
                GLuint program=modelsArray[n]->getGLShaderProgram();
                glUseProgram(program);
                //переписываем матрицы модели
                GLint size=0;
                GLint sizeArray=0;
                GLuint blockIndex=glGetUniformBlockIndex(program,"modelMatrices");
                GLint *offsets=getUniformBlockOffsets(program,"modelMatrices",&size);
                glGetActiveUniformBlockiv(program,blockIndex,GL_UNIFORM_BLOCK_DATA_SIZE,&sizeArray);
                unsigned char *array = new unsigned char[sizeArray];
                if(!modelsArray[n]->getMatricesArray(size,offsets,array)){
                    qWarning("The number of activ uniforms in shader and in gameLightObject does not much.");
                }
                glBindBuffer(GL_UNIFORM_BUFFER,matrixBuffer);
                glBufferData(GL_UNIFORM_BUFFER,MODEL_MATRIX_BUFFER_SIZE,(GLvoid*)array,GL_STATIC_DRAW);
                glBindBuffer(GL_UNIFORM_BUFFER,0);

                unsigned int matSize=modelsArray[n]->getNumIndicesObjects();
                for(unsigned int m=0;m!=matSize;m++){
                    gameIndexObject *indObject=modelsArray[n]->getIndexObject(m);
                    gameObjectMaterial *tmpMat=indObject->getMaterial();

                    //переписываем параметры материала для каждого материала
                    blockIndex=glGetUniformBlockIndex(program,"materialParams");
                    GLint *offsets=getUniformBlockOffsets(program,"materialParams",&size);
                    glGetActiveUniformBlockiv(program,blockIndex,GL_UNIFORM_BLOCK_DATA_SIZE,&sizeArray);
                    unsigned char *array = new unsigned char[sizeArray];
                    if(!tmpMat->getArray(size,offsets,array)){
                        qWarning("The number of activ uniforms in shader and in gameLightObject does not much.");
                    }
                    glBindBuffer(GL_UNIFORM_BUFFER,materialBuffer);
                    glBufferData(GL_UNIFORM_BUFFER,MODEL_MATRIX_BUFFER_SIZE,(GLvoid*)array,GL_STATIC_DRAW);
                    glBindBuffer(GL_UNIFORM_BUFFER,0);

                    //переподключаем буферы после выполнения glBindBuffer
                    glBindBufferBase(GL_UNIFORM_BUFFER,0,matrixBuffer);
                    glBindBufferBase(GL_UNIFORM_BUFFER,1,materialBuffer);
                    glBindBufferBase(GL_UNIFORM_BUFFER,2,lightBuffer);

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
                    glUniformMatrix4fv(MVPMatrixLocation,1,false,(GLfloat*)&MVP);
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
                glDeleteProgram(model->getGLShaderProgram());
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
bool viewWindow::compileShader(QByteArray *shaderText, GLuint &shader, GLenum type){

    GLint param=1;
    GLint ret=0;

    const GLchar *shaderSource = shaderText->data();
    //shaderSource=shaderText->data();

    shader=glCreateShader(type);
    glShaderSource(shader,1,&shaderSource,0);
    glCompileShader(shader);

    glGetShaderiv(shader,GL_COMPILE_STATUS,&param);
    if(param!=GL_TRUE){
        glGetShaderiv(shader,GL_INFO_LOG_LENGTH,&param);
        GLchar *log = new GLchar[param];
        glGetShaderInfoLog(shader,param,&ret,log);
        switch(type){
            case(GL_VERTEX_SHADER):{
                a_error=tr("Vertex shader errors:\n")+QString::fromLatin1(log,param);
                break;
            }
            case(GL_FRAGMENT_SHADER):{
                a_error=tr("Fragment shader errors:\n")+QString::fromLatin1(log,param);
                break;
            }
            //TODO дописать остальные шейдеры
        }
        delete log;
        glDeleteShader(shader);
        return false;
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////
bool viewWindow::compileShaderProgramm(GLuint *shadersArray, unsigned int arraySize, GLuint &program){
    GLint param=1;
    GLint ret=0;

    program=glCreateProgram();
    for(unsigned int n=0;n!=arraySize;n++){
        glAttachShader(program,shadersArray[n]);
        if(glGetError()!=GL_NO_ERROR){
            glDeleteProgram(program);
            a_error=tr("Attach shader error.");
            return false;
        }
    }

    glLinkProgram(program);
    glGetProgramiv(program,GL_LINK_STATUS,&param);
    if(param!=GL_TRUE){
        glGetProgramiv(program,GL_INFO_LOG_LENGTH,&param);
        GLchar *log=new GLchar[param];
        glGetProgramInfoLog(program,param,&ret,log);
        a_error=tr("Link shader programm errors:")+QString::fromLatin1(log,param);
        delete log;
        glDeleteProgram(program);
        return false;
    }

    bindUniforms(program);

    for(unsigned int n=0;n!=arraySize;n++){
        glDeleteShader(shadersArray[n]);
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////
void viewWindow::bindUniforms(GLuint program){

    glUseProgram(program);
    //буфер модельных матриц
   GLuint blockIndex=glGetUniformBlockIndex(program,"modelMatrices");
    glUniformBlockBinding(program,blockIndex,0);//привязываем буфер к точке 0 по его индексу
    glGenBuffers(1,&matrixBuffer);
    glBindBuffer(GL_UNIFORM_BUFFER,matrixBuffer);
    glBufferData(GL_UNIFORM_BUFFER,MODEL_MATRIX_BUFFER_SIZE,NULL,GL_STATIC_DRAW);//создаем пустой буфер в видеопамяти
    glBindBuffer(GL_UNIFORM_BUFFER,0);
    glBindBufferBase(GL_UNIFORM_BUFFER,0,matrixBuffer);

    //буффер свойств материала
    blockIndex=glGetUniformBlockIndex(program,"materialParams");
    glUniformBlockBinding(program,blockIndex,1);//привязываем буфер к точке 1 по его индексу
    glGenBuffers(1,&materialBuffer);
    glBindBuffer(GL_UNIFORM_BUFFER,materialBuffer);
    glBufferData(GL_UNIFORM_BUFFER,MAT_BUFFER_SIZE,NULL,GL_STATIC_DRAW);//создаем пустой буфер в видеопамяти
    glBindBuffer(GL_UNIFORM_BUFFER,0);
    glBindBufferBase(GL_UNIFORM_BUFFER,1,materialBuffer);


    //буффер источника света
    blockIndex=glGetUniformBlockIndex(program,"lightSource");
    glUniformBlockBinding(program,blockIndex,2);//привязываем буфер к точке 2 по его индексу
    glGenBuffers(1,&lightBuffer);
    glBindBuffer(GL_UNIFORM_BUFFER,lightBuffer);

    GLint size=0;
    GLint *offsets=getUniformBlockOffsets(program,"lightSource",&size);
    GLint sizeArray=0;
    glGetActiveUniformBlockiv(program,blockIndex,GL_UNIFORM_BLOCK_DATA_SIZE,&sizeArray);
    unsigned char *array = new unsigned char[sizeArray];
    if(!defaultLight.getArray(size,offsets,array)){
        qWarning("The number of activ uniforms in shader and in gameLightObject does not much.");
    }

    glBufferData(GL_UNIFORM_BUFFER,LIGHT_BUFFER_SIZE,(GLvoid*)array,GL_STATIC_DRAW);//создаем буфер в видеопамяти
    glBindBuffer(GL_UNIFORM_BUFFER,0);
    delete []offsets;
    delete []array;
    glBindBufferBase(GL_UNIFORM_BUFFER,2,lightBuffer);

    MVPMatrixLocation=glGetUniformLocation(program,"MVPMatrix");
}
////////////////////////////////////////////////////////////////////////////////////////////////
GLint *viewWindow::getUniformBlockOffsets(GLint program, const char *blockName, GLint *size){
    GLuint blockIndex=glGetUniformBlockIndex(program,blockName);
    glGetActiveUniformBlockiv(program,blockIndex,GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS,size);
    GLint *array = new GLint[*size];
    GLuint *indices = new GLuint[*size];
    glGetActiveUniformBlockiv(program,blockIndex,GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES,(GLint*)indices);
    glGetActiveUniformsiv(program,*size,indices,GL_UNIFORM_OFFSET,array);
    delete []indices;
    return array;
}
////////////////////////////////////////////////////////////////////////////////////////////////
QString viewWindow::getLastError(){
    QString tmp=a_error;
    a_error.clear();
    return tmp;
}



















