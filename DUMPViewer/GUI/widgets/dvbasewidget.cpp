#include "dvbasewidget.h"

dvBaseWidget::dvBaseWidget(QWidget *parent):
    abstractBaseWidget(parent)
{
    core=NULL;
    scrollBar=NULL;

}
///////////////////////////////////////////////////////////////////////////
dvBaseWidget::~dvBaseWidget(){
    if(scrollBar!=NULL){
        delete scrollBar;
    }
}
///////////////////////////////////////////////////////////////////////////
void dvBaseWidget::setCorePointer(editorCore *corePointer){
    core=corePointer;
}
////////////////////////////////////////////////////////////////////
void dvBaseWidget::setPosition(int x, int y){
    QRect g=this->geometry();
    g.setX(x);
    g.setY(y);
    this->setGeometry(g);
}
////////////////////////////////////////////////////////////////////
void dvBaseWidget::updateContent(){
    int t=0;
    t++;
}
////////////////////////////////////////////////////////////////////
void dvBaseWidget::resizeWidget(QRect rect){
    int t=0;
    t++;
}
///////////////////////////////////////////////////////////////////////////
void dvBaseWidget::addWidget(QWidget *widget){
    widgetsArray.append(widget);
    calculateScrollBar();
}
///////////////////////////////////////////////////////////////////////////
void dvBaseWidget::resizeEvent(QResizeEvent *event){
    QPushButton *button = new QPushButton(this);
    QRect rect;
    rect.setX(0);
    rect.setY(0);
    rect.setWidth(201);
    rect.setHeight(160);
    button->setGeometry(rect);
    button->setText("________________");
    addWidget(button);
}
////////////////////////////////////////////////////////////////////////////
void dvBaseWidget::calculateScrollBar(){
    //получаем необходимую высоту для размещения всех виджетов
    unsigned int size=widgetsArray.size();
    QWidget *tmp = widgetsArray.at(0);
    for(int n=1;n!=size;n++){//ищем самый нижний виджет
        if(tmp->geometry().y()<widgetsArray.at(n)->geometry().y()){
            tmp=widgetsArray.at(n);
        }
    }
    QRect rect=tmp->geometry();
    int heigth=tmp->geometry().y()+tmp->geometry().height();//высота = Y самого нижнего+его высота
    if(heigth>this->geometry().height()){//если необходимая высота больше собственной
        if(scrollBar==NULL){
            scrollBar = new QScrollBar(this);
            QRect rect;
            rect.setWidth(10);
            rect.setHeight(this->geometry().height());
            rect.setX(0);
            rect.setY(0);
            scrollBar->setGeometry(rect);
            scrollBar->setMaximum(heigth);
            scrollBar->setPageStep(this->geometry().height());
            connect(scrollBar,SIGNAL(valueChanged(int)),this,SLOT(scrollSlot(int)));
        }
    }
    else{
        if(scrollBar!=NULL){
            delete scrollBar;
        }
    }
}
////////////////////////////////////////////////////////////////////////////
void dvBaseWidget::scrollSlot(int value){
    int size=widgetsArray.size();
    for(int n=0;n!=size;n++){
        QWidget *widget = widgetsArray.at(n);
        QRect rect=widget->geometry();
        rect.setY(-value);
        widget->setGeometry(rect);
    }
}
///////////////////////////////////////////////////////////////////////////

