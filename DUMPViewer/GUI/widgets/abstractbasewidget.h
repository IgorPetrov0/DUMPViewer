#ifndef ABSTRACTBASEWIDGET_H
#define ABSTRACTBASEWIDGET_H

#include <QWidget>
#include "editorCore.h"

class abstractBaseWidget : public QWidget
{
    Q_OBJECT

public:
    abstractBaseWidget(QWidget *parent):QWidget(parent){core=NULL;}
    virtual void resizeWidget(QRect rect)=0;
    virtual void clear()=0;
    virtual void enableContent(bool flag)=0;
    virtual void setCorePointer(editorCore *core){this->core = core;}


public slots:
    virtual void updateContent(abstractBaseWidget* widget)=0;


protected:
    editorCore *core;


signals:
    void somethingChange(abstractBaseWidget *widget);


};
////////////////////////////////////////////////////////////////////////

#endif // ABSTRACTBASEWIDGET_H
