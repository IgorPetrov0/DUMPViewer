#include "toolwidget.h"
#include "ui_toolwidget.h"

toolWidget::toolWidget(application *app, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::toolWidget)
{

    ui->setupUi(this);
    ui->graphicTab->setCurrentIndex(0);
    ui->graphicTab->setUsesScrollButtons(true);

    this->app=app;
    ui->constraintsTabBar->setApplication(app);
    ui->constraintsTabBar->setApplication(app);
    ui->rigidBodiesTabBar->setApplication(app);
    ui->meshTabBar->setApplication(app);
    ui->showRadioButton->setChecked(true);

    connect(this,SIGNAL(updateInfo()),ui->meshTabBar,SLOT(updateInfoSlot()));
    connect(this,SIGNAL(updateInfo()),ui->rigidBodiesTabBar,SLOT(updateInfoSlot()));
    connect(ui->showRadioButton,SIGNAL(toggled(bool)),this,SLOT(showGraphicSlot(bool)));
    


}
/////////////////////////////////////////////////
toolWidget::~toolWidget()
{
    clearLODTabsArray();
    delete ui;
}
//////////////////////////////////////////////////
void toolWidget::resizeEvent(QResizeEvent *event){
    QRect widgetGeometry=ui->tabWidget->geometry();
    widgetGeometry.setHeight(this->height());
    ui->tabWidget->setGeometry(widgetGeometry);
    int childHeigth=widgetGeometry.height()-ui->tabWidget->tabBar()->rect().height();
    widgetGeometry.setHeight(childHeigth);    
    ui->phisicTab->setGeometry(widgetGeometry);
    widgetGeometry.setY(ui->graphicTab->geometry().y());
    ui->graphicTab->setGeometry(widgetGeometry);
}
////////////////////////////////////////////////////////////////////////////////////////
void toolWidget::disableToolPanel(bool disable){
    ui->graphicTab->setDisabled(disable);
    ui->phisicTab->setDisabled(disable);
    if(disable){
        disconnect(ui->graphicTab,SIGNAL(currentChanged(int)),this,SLOT(graphicTabSelectedSlot(int)));
    }
    else{
        connect(ui->graphicTab,SIGNAL(currentChanged(int)),this,SLOT(graphicTabSelectedSlot(int)));
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
void toolWidget::resetToolPanel(){
    clearLODTabsArray();
}
///////////////////////////////////////////////////////////////////////////////////////
void toolWidget::graphicTabSelectedSlot(int index){
    static int lastIndex=0;
    static float lastDistance=0;


    if(index==ui->graphicTab->count()-1){
        if(LODTabsArray.size() < 4){
            addLODTab();
            return;
        }
    }
    if(ui->showRadioButton->isChecked()){//если галка show стоит
        if(index==0){//если переключились на mainMesh
            app->view()->setDistance(lastDistance);
            app->currentObject()->showMainMesh(true);
            app->view()->update();
        }
        else{
            if(lastIndex==0){
                lastDistance=app->view()->getDistance();
            }
            LOD *lod=app->currentObject()->getLod(index-1);
            if(lod!=NULL){
                app->view()->setDistance(-lod->getDistance());
                app->currentObject()->showLOD(index-1,true);
            }
            app->view()->update();
        }
        lastIndex=index;
    }

}
///////////////////////////////////////////////////////////////////////
void toolWidget::LODTabDeleteSlot(unsigned int tabIndex, unsigned int LODNumber){
    if(LODTabsArray.size()>=4){
        ui->graphicTab->setTabEnabled(ui->graphicTab->count()-1,true);
    }
    unsigned int firstTabIndex=LODTabsArray.at(0)->getTabNumber();

    ui->graphicTab->setCurrentIndex(tabIndex-1);
    ui->graphicTab->removeTab(tabIndex);
    delete LODTabsArray.at(LODNumber);
    LODTabsArray.remove(LODNumber);
    unsigned int size=(unsigned int)LODTabsArray.size();
    for(unsigned int n=0;n!=size;n++){//переписываем все номера LOD-ов
        LODTabsArray.at(n)->setLODNumber(n);
        LODTabsArray.at(n)->setTabNumber(firstTabIndex+n);
        ui->graphicTab->setTabText(n+1,tr("LOD")+QString::number(n+1));//надписи переписываем, начиная с 1-го таба т.к. 1-й mainMesh
    }
}
//////////////////////////////////////////////////////////////////////
void toolWidget::addLODTab(){
    for(int n=0;n!=LODTabsArray.size();n++){//если хоть в одном предыдущем табе не определен лод
        if(!LODTabsArray[n]->isLODDefined()){
            return;//то выходим
        }
    }
    LODTab *newLODTab=new LODTab;
    newLODTab->setApplication(app);
    LODTabsArray.append(newLODTab);
    newLODTab->setTabNumber(ui->graphicTab->count()-1);
    newLODTab->setLODNumber(LODTabsArray.size()-1);
    ui->graphicTab->insertTab(ui->graphicTab->count()-1,newLODTab,tr("LOD")+QString::number(LODTabsArray.size()));
    ui->graphicTab->setCurrentIndex(ui->graphicTab->count()-2);
    if(LODTabsArray.size()>=4){
        ui->graphicTab->setTabEnabled(ui->graphicTab->count()-1,false);
    }
    connect(newLODTab,SIGNAL(deleteSignal(uint,uint)),this,SLOT(LODTabDeleteSlot(uint,uint)));
    connect(this,SIGNAL(updateInfo()),newLODTab,SLOT(updateInfoSlot()));
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void toolWidget::clearLODTabsArray(){
    int size=LODTabsArray.size();
    for(int n=0;n!=size;n++){
        ui->graphicTab->removeTab(1);
        delete LODTabsArray[n];
    }
    LODTabsArray.clear();
    ui->graphicTab->setCurrentIndex(0);
    ui->meshTabBar->resetTab();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void toolWidget::updateInfoSlot(){
    unsigned int size=app->currentObject()->LODsSize();
    if(size!=0){
        for(unsigned int n=0;n!=size;n++){
            addLODTab();
            emit updateInfo();
        }
    }
    else{
        emit updateInfo();
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void toolWidget::showGraphicSlot(bool checked){
    if(!checked){
        app->currentObject()->showMainMesh(false);
        app->currentObject()->showLOD(0,false);
        app->view()->update();
    }
    else{
        graphicTabSelectedSlot(ui->graphicTab->currentIndex());
    }
}
