#ifndef ABSTRACTBASEWIDGET_H
#define ABSTRACTBASEWIDGET_H

#include <QWidget>
#include "editorCore.h"

class abstractBaseWidget : public QWidget
{
    Q_OBJECT

public:
    abstractBaseWidget(QWidget *parent):QWidget(parent){core=NULL;}
    virtual void updateContent()=0;
    virtual void resizeWidget(QRect rect)=0;
    virtual void clear()=0;
    virtual void setCorePointer(editorCore *core){this->core = core;}


protected:
    editorCore *core;


};
////////////////////////////////////////////////////////////////////////

#endif // ABSTRACTBASEWIDGET_H
