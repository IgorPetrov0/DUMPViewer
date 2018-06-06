#ifndef DUMPVIEWERWIDGET_H
#define DUMPVIEWERWIDGET_H

#include <QWidget>

#define SCROLLBAR_WIDTH 13



class dumpViewerWidget:public QWidget
{

    Q_OBJECT

public:
    dumpViewerWidget(QWidget *parent);
    void setOriginSize();

protected:
     int boxWidth, boxHeigth;

     void resizeEvent(QResizeEvent *event);


};

#endif // DUMPVIEWERWIDGET_H
