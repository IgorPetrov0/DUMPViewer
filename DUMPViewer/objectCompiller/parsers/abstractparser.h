#ifndef ABSTRACTPARSER_H
#define ABSTRACTPARSER_H

#include <QObject>
#include "objectCompiller/sceneObject/sceneobject.h"

class abstractParser : public QObject
{
    Q_OBJECT
public:
    explicit abstractParser();
    virtual bool readFile(QString fileName);
    virtual sceneObject* getSceneObject();
    QString getLastError();

protected:
    QString error;
    sceneObject *object;



signals:

public slots:



};

#endif // ABSTRACTPARSER_H
