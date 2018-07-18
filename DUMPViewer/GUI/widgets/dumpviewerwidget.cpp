#include "dumpviewerwidget.h"

dumpViewerWidget::dumpViewerWidget(QWidget *parent):
    QWidget(parent)
{
    core=NULL;
}
//////////////////////////////////////////////////////////////
void dumpViewerWidget::resizeEvent(QResizeEvent *event){
    QRect rect;

    //автоматически подгоняем внешний вид в зависимости от размеров

    //это не бред. Тут выставляется размер, заданный в редакторе.
    //или всетаки бред?????
    rect.setWidth(boxWidth);
    rect.setHeight(boxHeigth);
    //this->setGeometry(rect);
}
/////////////////////////////////////////////////////////////////////
void dumpViewerWidget::setOriginSize(){
    boxWidth=this->width();
    boxHeigth=this->height();
    resizeEvent(0);
}
/////////////////////////////////////////////////////////////////////
void dumpViewerWidget::setCorePointer(editorCore *pointer){
    core=pointer;
}
