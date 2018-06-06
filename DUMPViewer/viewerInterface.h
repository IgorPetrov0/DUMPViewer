#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>

class viewerInterface : public QObject
{
    Q_OBJECT
public:
    explicit viewerInterface(QObject *parent = 0);

signals:

public slots:
};

#endif // INTERFACE_H
