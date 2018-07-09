#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QOpenGLWidget>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QMouseEvent>
#include <QPoint>
#include <QVector3D>
#include <QQuaternion>
#include <QtGui/QOpenGLFunctions_3_3_Core>
#include <math.h>
#include <QMessageBox>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "gameObject/graphicobject.h"
#include "mathPrimitives/vertex.h"
#include "gameObject/editabelObjects/editabelgameobject.h"
#include "gameObject/editabelObjects/editabelgraphicobject.h"



class viewWindow: public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
     Q_OBJECT
public:
    viewWindow(QWidget *parent=0);
    ~viewWindow();
    void addModel(editabelGraphicObject *model);
    void removeModel(editabelGraphicObject *model);
    void keyPressed(int key);
    void setDistance(float distance);
    float getDistance();
    void deleteAll();
    void setTexturesVector(QVector<gameObjectTexture *> *vector);
    bool compileShader(QByteArray *shaderText, GLuint &shader, GLenum type);
    bool compileShaderProgramm(GLuint *shadersArray, unsigned int arraySize, GLuint &program);
    QString getLastError();

protected:
    void initializeGL();
    void resizeGL();
    void paintGL();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void angleXInc(int dir);
    void angleYInc(int dir);
    void calculateViewMatrix();
    void bindUniforms(GLuint program);
    GLint *getUniformBlockOffsets(GLint program, const char *blockName, GLint *size);


    QWidget *parent;//указатель на родителя
    //GLuint sProgram;
    GLuint vertexArray,textureArray,indicesArray;//массивы координат вершин, текстурных координат и индексов
    GLint MVPMatrixLocation;
    GLuint matrixBuffer;
    GLuint materialBuffer;
    GLuint lightBuffer;



    bool loaded;
    float angleX,angleY;//углы вращения
    int mPosX,mPosY;//предыдущая позиция курсора мыши
    float distance;
    float moveX,moveY;//смещения
    QVector<editabelGraphicObject*> modelsArray;
    QVector<gameObjectTexture*> *texturesVector;
    static const GLchar *vertexShaderSource[];
    static const GLchar *fragmentShaderSource[];
    QString a_error;
    glm::mat4 view;//видовая матрица
    glm::mat4 projection;//проекционная матрица
    gameObjectLight defaultLight;

};

#endif // VIEWWINDOW_H
