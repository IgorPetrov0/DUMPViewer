#include "tabbar.h"

dTabBar::dTabBar(QTabWidget *parent):
    QTabBar(parent)
{
    scrollBar=new QScrollBar(this);
    scrollBar->setGeometry(this->width()-13,0,13,this->height());
    scrollBar->setFocusPolicy(Qt::StrongFocus);
    scrollBar->setSingleStep(10);
    connect(scrollBar,SIGNAL(valueChanged(int)),this,SLOT(moveWidgets(int)));
    endWidget=NULL;
    app=NULL;
}
///////////////////////////////////////////////////////////////////
dTabBar::~dTabBar(){
    int size=widgetsArray.size();
    for(int n=0;n!=size;n++){
        delete widgetsArray[n];
    }
    delete scrollBar;
}
///////////////////////////////////////////////////////////////////
void dTabBar::addWidget(QWidget *widget){
    widget->setParent(this);
    widgetsArray.append(widget);
    //ищем последний виджет по максимальному значению geometry.y()
    endWidget=widgetsArray[0];
    QRect r=widget->geometry();
    int size=widgetsArray.size();
    for(int n=0;n!=size;n++){
        if(endWidget->geometry().y()<widgetsArray[n]->geometry().y()){
            endWidget=widgetsArray[n];
        }
    }
}
/////////////////////////////////////////////////////////////////////////
void dTabBar::resizeEvent(QResizeEvent *event){
    scrollBar->setGeometry(this->width()-SCROLLBAR_WIDTH,0,SCROLLBAR_WIDTH,this->height());
    checkSize();
}
//////////////////////////////////////////////////////////////////////////////
void dTabBar::wheelEvent(QWheelEvent *event){
    if(event->delta()>0){
        scrollBar->setValue(scrollBar->value()-10);
    }
    else if(event->delta()<0){
        scrollBar->setValue(scrollBar->value()+10);
    }
}
//////////////////////////////////////////////////////////////////////////////////
void dTabBar::checkSize(){
    //определяем, нужна-ли полоса прокрутки
    int bottomY=bottomYCoordinate();
    if(bottomY>=this->height()){
        scrollBar->setMinimum(0);
        scrollBar->setMaximum(bottomY-this->height());
        scrollBar->setPageStep(this->height());
    }
    else{
        scrollBar->setMaximum(0);
        scrollBar->setMinimum(0);
    }
}
//////////////////////////////////////////////////////////////////////////////////
void dTabBar::moveWidgets(int value){
    static int lastPos=0;
    int size=widgetsArray.size();
    for(int n=0;n!=size;n++){
        QRect r=widgetsArray[n]->geometry();
        r.moveTop(r.y()+(lastPos-value));
        widgetsArray[n]->setGeometry(r);
    }
    lastPos=value;
}
/////////////////////////////////////////////////////////////////////////////////
int dTabBar::bottomYCoordinate(){
    int oldScrolllBarValue=scrollBar->value();
    scrollBar->setValue(0);
    int sum=endWidget->geometry().y()+endWidget->height();
    scrollBar->setValue(oldScrolllBarValue);
    return sum;
}
/////////////////////////////////////////////////////////////////////////////////
void dTabBar::setApplication(editorCore *app){
    this->app=app;
}
//////////////////////////////////////////////////////////////////////////////////
void dTabBar::disableTab(bool disable){
    int size=widgetsArray.size();
    for(int n=0;n!=size;n++){
        widgetsArray.at(n)->setEnabled(!disable);
    }
}
