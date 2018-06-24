#ifndef DUMPVIEWERWIDGET_H
#define DUMPVIEWERWIDGET_H

#include <QWidget>
#include "editorCore.h"

#define SCROLLBAR_WIDTH 13


class dumpViewerWidget : public QWidget
{
    Q_OBJECT

public:
    dumpViewerWidget(QWidget *parent);
    void setOriginSize();
    virtual void setCorePointer(editorCore *value);

protected:
    int boxWidth, boxHeigth;
    editorCore *core;
    void resizeEvent(QResizeEvent *event);

};

#endif // DUMPVIEWERWIDGET_H
