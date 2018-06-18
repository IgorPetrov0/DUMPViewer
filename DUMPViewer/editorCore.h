#ifndef EDITORCORE_H
#define EDITORCORE_H

#include <QString>
#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QObject>
#include <QVector>
#include <QObject>
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/mesh.h>
#include <assimp/types.h>
#include <assimp/postprocess.h>
#include "gameObject/editabelObjects/editabelgameobject.h"
#include "gameObject/stream.h"
#include "viewwindow.h"

//класс ядра приложения. В нем должен быть весь основной функционал
//

using namespace Assimp;

class editorCore : public QObject
{
    Q_OBJECT
public:
    editorCore();
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
    bool loadCurrentGameObject(QString fileName);//загрузка скомпилированного gameObject из файла
    bool saveCurrentGameObject(QString fileName);//сохранение скомпилированного gameObject в файл
    bool loadGraphicObject(QString fileName, editabelGraphicObject *object);//загрузка графического объекта через Assimp
    QString getLastError();
    void removeModelFromView(editabelGraphicObject *model);

protected:
    QString a_modelFilter;//TODO фильтр файлов моделей. добавлять здесь по мере расширения парсеров
    QString a_defaultObjectName;
    QString a_programName;
    QString a_currentPath;                    //путь к текущему каталогу
    QWidget *a_mainWindowPointer;
    editabelGameObject *a_currentObject;
    viewWindow *a_view;
    float a_lastDistance;
    QVector<gameObjectTexture*> globalTexturesArray;
    QVector<gameObjectMaterial*> globalMaterialsArray;
    QString a_error;
    gameObjectMaterial *addMaterials(const aiScene *scene, QString objectPath);//собирает все материалы сцены в одно глобальное хранилище
    bool addTextures(const aiScene *scene, QString objectPath);//собираем все текстуры сцены в одно глобальное хранилище
    gameObjectTexture *addTexturesFromFiles(aiMaterial *material, aiTextureType type, unsigned int index, QString objectPath);//Загружает тектуры из файлов и добавляет в глобальное хранилище
};

#endif // EDITORCORE_H
