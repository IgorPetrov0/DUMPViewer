#ifndef PARSERDAE_H
#define PARSERDAE_H


#include <QDomDocument>
#include <QFile>
#include <QMessageBox>
#include "objectCompiller/parsers/abstractparser.h"

class parserDAE : public abstractParser
{
    Q_OBJECT

public:
    parserDAE();
    ~parserDAE();
    virtual bool readFile(QString fileName);


protected:
    void parsDAE(QDomElement *root);
    void parsGeometry(QDomNode *geometry);

    QDomDocument *xmlDocument;

    //имена массивов в XML файле
    QString vertexArrayName;
    QString normalsArrayName;
    QString texCoordArrayName;

    //смещения индексов
    unsigned char vOffset;
    unsigned char nOffset;
    unsigned char texCoordOffset;


};

#endif // PARSERDAE_H
