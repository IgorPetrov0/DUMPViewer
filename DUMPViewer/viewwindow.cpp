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
}
////////////////////////////////////////////////////////////
viewWindow::~viewWindow(){

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void viewWindow::addModel(editabelGraphicObject *model){
    if(model==NULL){
        return;
    }
    if(model->isEmpty()){
        return;
    }
    modelsArray.append(model);

    makeCurrent();//делаем контекст OpenGL текущим
    for(unsigned int n=0;n!=modelsArray.size();n++){
        GLuint vaoName;
        glGenBuffers(1,&vaoName);
        glBindBuffer(GL_ARRAY_BUFFER,vaoName);
        glBufferData(GL_ARRAY_BUFFER,modelsArray[n]->getVertexseSize()*sizeof(float),modelsArray[n]->getVertexesPointer(),GL_STATIC_DRAW);
        modelsArray[n]->setVaoName(static_cast<unsigned int>(vaoName));
        unsigned int size=modelsArray[n]->getNumIndicesObjects();
        for(unsigned int m=0;m!=size;n++){//создаем текстуры из материалов
            gameObjectTexture tex=modelsArray[n]->getIndexObject(m)->getMaterial()->getDiffuseTexture();
            GLuint texName;




        }


    }








//    //создаем общий буфер атрибутов вершин. В нем все и вертексы и нормали и текстурные координаты. см.: loader::compileGraphicObject
//    QOpenGLBuffer vBuf(QOpenGLBuffer::VertexBuffer);
//    vBuf.create();
//    vBuf.bind();
//    vBuf.setUsagePattern(QOpenGLBuffer::DynamicDraw);
//    vBuf.allocate(model->getVertexesPointer(),model->getVertexseSize()*sizeof(float));
//    vBuf.release();
//    //создаем все текстуры, задействованные в сцене
//    unsigned int size=texturesVector->size();
//    for(unsigned int n=0;n!=size;n++){
//        GLuint tName;
//        glGenTextures(1,&tName);
//        glBindTexture(GL_TEXTURE_2D,tName);
//        glPixelStorei(GL_UNPACK_ALIGNMENT,1);
//        gameObjectTexture *tex=texturesVector->at(n);
//        tex->setOglName(tName);
//        glTexImage2D(GL_TEXTURE_2D, 0, tex->getOGLFormat(), tex->width(),tex->height(),0,tex->getOGLFormat(),tex->getDataType(),tex->getTexturePointer()->getArrayPointer());
//        //параметры фильтрации - линейная
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        glBindTexture(GL_TEXTURE_2D,0);
//    }



//    //создаем свой массив индексов на каждый материал
//    size=model->getNumIndicesObjects();
//    for(unsigned int n=0;n!=size;n++){
//        GLuint oglTmpName=0;
//        gameObjectMaterial *mPointer=model->getIndexObject(n)->getMaterial();

//        glGenVertexArrays(1,&oglTmpName);//получаем свободный идентификатор
//        mPointer->setVAOName(oglTmpName);//передаем идентификатор материалу
//        glBindVertexArray(oglTmpName);//биндим VAO

//        vBuf.bind();//биндим буфер атрибутов

//        int stride=8*sizeof(float);
//        sProgram->enableAttributeArray("position");
//        sProgram->setAttributeBuffer("position",GL_FLOAT,0,3,stride);

//        sProgram->enableAttributeArray("texCoord");
//        sProgram->setAttributeBuffer("texCoord",GL_FLOAT,5*sizeof(float),2,stride);

//        QOpenGLBuffer iBuf(QOpenGLBuffer::IndexBuffer);//создаем буфер вершинных индексов
//        iBuf.create();
//        iBuf.bind();
//        dArray<unsigned int> *indArray=model->getIndexObject(n)->getIndices();
//        iBuf.allocate(indArray->getArrayPointer(),indArray->getSize()*sizeof(unsigned int));

//        glBindVertexArray(0);//отсоединяем VAO

//        iBuf.release();
//        vBuf.release();

//    }

}
////////////////////////////////////////////////////
void viewWindow::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    sProgram=new QOpenGLShaderProgram(this);

    QString vertexShaderSource =
        "#version 330 core\n"

        "in vec3 position;\n"
        "in vec2 texCoord;\n"
        "out vec2 tC;\n"
        "uniform mat4 projectionMatrix;\n"

        "void main(void)\n"
        "{\n"
        "        // перевод вершинных координат в однородные\n"
        "        gl_Position   = projectionMatrix * vec4(position, 1.0);\n"
        "        tC=texCoord;\n"
        "}\n";

    QString fragmentShaderSource =
        "#version 330 core\n"
        "in vec2 tC;\n"
        "uniform sampler2D tex;\n"
        "out vec4 color;\n"

        "void main(void)\n"
        "{\n"
        "        // цвет пикселя определяется текстурой\n"
        "        color=vec4(0.5f, 0.0f, 0.0f, 1.0f);//texture(tex,tC);\n"
        "}\n";

    //создаем шейдеры и шейдерную программу
    sProgram->addShaderFromSourceCode(QOpenGLShader::Vertex,vertexShaderSource);
    sProgram->addShaderFromSourceCode(QOpenGLShader::Fragment,fragmentShaderSource);
    sProgram->link();
    sProgram->bind();

}
/////////////////////////////////////////////////////
void viewWindow::resizeGL(){
    glViewport(0,0,200,200);
}
//////////////////////////////////////////////////////
void viewWindow::paintGL(){

    if(modelsArray.size()!=0){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        sProgram->bind();
        GLint shaderMatrix=sProgram->uniformLocation("projectionMatrix");
        QMatrix4x4 matrix;
        matrix.perspective(60.0f, 4.0f/3.0f, 0.1f, 100.0f);
        matrix.translate(moveX, moveY, distance);
        matrix.rotate(angleX,1,0,0);
        matrix.rotate(angleY,0,1,0);
        sProgram->setUniformValue(shaderMatrix,matrix);
        int mSize=modelsArray.size();
        for(int n=0;n!=mSize;n++){
            if(modelsArray[n]->isVisible()){
               unsigned int matSize=modelsArray[n]->getNumIndicesObjects();
               for(unsigned int m=0;m!=matSize;m++){
                    gameObjectMaterial *tmpMat=modelsArray[n]->getIndexObject(m)->getMaterial();
                    if(tmpMat->getDiffuseTexture()!=NULL){//если у материала есть текстура(текстуры может и не быть.)
                        //биндим текстуру
                        glBindTexture(GL_TEXTURE_2D,tmpMat->getOGLTextureName());
                    }
                    glBindVertexArray((GLuint)tmpMat->getVAOName());
                    glDrawElements(GL_TRIANGLES,(GLsizei)modelsArray[n]->getIndexObject(m)->getNumFaces(),GL_UNSIGNED_INT,NULL);
                    glBindVertexArray(0);
                    glBindTexture(GL_TEXTURE_2D,0);
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
            update();
            break;
        }
        case(Qt::MidButton):{
            moveX=moveX-(mPosX-event->pos().x())*0.01;
            moveY=moveY+(mPosY-event->pos().y())*0.01;
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
    update();
}
//////////////////////////////////////////////////////////////////////////////////
void viewWindow::updateView(){




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
        for(int n=0;n!=mSize;n++){
//            if(modelsArray[n]==model){
//                unsigned int f=0;
//                //удаляем VAO
//                unsigned int mSize=model->getMaterialsSize();
//                for(unsigned int n1=0;n1!=mSize;n1++){
//                    gameObjectTexture *tex=model->getMaterialPointer(n1)->getTexture();
//                    if(!tex->isUsed()){
//                        f=tex->getOglName();
//                        glDeleteTextures(1,&f);
//                    }
//                }
//                //удаляем все текстуры из видеопамяти
//                unsigned int matSize=model->getMaterialsSize();
//                for(unsigned int n2=0;n2!=matSize;n2++){
//                    f=model->getMaterialPointer(n2)->getOGLTextureName();
//                    glDeleteVertexArrays(1,&f);
//                }
//                modelsArray.remove(n);
//                break;
//            }
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
