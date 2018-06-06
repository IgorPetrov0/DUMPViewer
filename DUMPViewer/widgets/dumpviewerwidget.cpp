#include "dumpviewerwidget.h"

dumpViewerWidget::dumpViewerWidget(QWidget *parent):
    QWidget(parent)
{

}
//////////////////////////////////////////////////////////////
void dumpViewerWidget::resizeEvent(QResizeEvent *event){
    QRect rect;

    //автоматически подгоняем внешний вид в зависимости от размеров

    //это не бред. Тут выставляется размер, заданный в редакторе.
    rect=this->geometry();
    rect.setWidth(boxWidth);
    rect.setHeight(boxHeigth);
    this->setGeometry(rect);
}
/////////////////////////////////////////////////////////////////////
void dumpViewerWidget::setOriginSize(){
    boxWidth=this->width();
    boxHeigth=this->height();
    resizeEvent(0);
}
