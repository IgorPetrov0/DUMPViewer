#ifndef ABSTRACTWIDGET_H
#define ABSTRACTWIDGET_H

#include <QWidget>


class abstractWidget : public QWidget
{
    Q_OBJECT
public:
    abstractWidget(QWidget *parent):QWidget(parent){}//если есть реализация, то она должна быть в этом же файле
    virtual void updateInfo()=0;
};

#endif // ABSTRACTWIDGET_H
