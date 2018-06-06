#ifndef APPLICATION_H
#define APPLICATION_H

#include <QString>
#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QObject>
#include <QVector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/mesh.h>
#include <assimp/types.h>
#include <assimp/postprocess.h>
#include "gameObject/editabelObjects/editabelgameobject.h"
#include "gameObject/stream.h"
#include "viewwindow.h"
#include "objectCompiller/loader.h"


class application
{
public:
    application();
    QString modelFilter();
    QString defaultObjectName();
    QString programmName();
    QWidget *mainWindowPointer();
    QString currentPath();
    editabelGameObject *currentObject();
    viewWindow *view();
    void setMainWindowPointer(QWidget *pointer);
    void setViewWindowPointer(viewWindow *pointer);
    void setCurrentObject(editabelGameObject *object);
    void setCurrentPath(QString path);
    void setLastDistance(float distance);
    float lastDistance();
    void deleteCurrentObject();
    bool loadCurrentObject(QString fileName);
    bool loadGraphicObject(QString fileName, editabelGraphicObject *object);
    bool saveCurrentObject(QString fileName);
    QString getLastError();


protected:
    QString a_modelFilter;//TODO фильтр файлов моделей. добавлять здесь по мере расширения парсеров
    QString a_defaultObjectName;
    QString a_programName;
    QString a_currentPath;                    //путь к текущему каталогу
    QWidget *a_mainWindowPointer;
    editabelGameObject *a_currentObject;
    viewWindow *a_view;
    float a_lastDistance;
    QVector<gameObjectTexture*> texturesArray;
    QString a_error;

    bool loadTextures(graphicObject *object);
};

#endif // APPLICATION_H
