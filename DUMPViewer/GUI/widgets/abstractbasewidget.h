#ifndef ABSTRACTBASEWIDGET_H
#define ABSTRACTBASEWIDGET_H

#include <QWidget>

class abstractBaseWidget : public QWidget
{
    Q_OBJECT

public:
    abstractBaseWidget(QWidget *parent):QWidget(parent){}
    virtual void updateContent()=0;
    virtual void resizeWidget(QRect rect)=0;





};

#endif // ABSTRACTBASEWIDGET_H
