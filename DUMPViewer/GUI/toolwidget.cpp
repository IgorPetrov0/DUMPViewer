#include "toolwidget.h"
#include "ui_toolwidget.h"

toolWidget::toolWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::toolWidget)
{

    ui->setupUi(this);
    core=NULL;
    connect(ui->graphTab,SIGNAL(somethingChange(abstractBaseWidget*)),this,SLOT(updateInfoSlot(abstractBaseWidget*)));
    connect(ui->animTab,SIGNAL(somethingChange(abstractBaseWidget*)),this,SLOT(updateInfoSlot(abstractBaseWidget*)));
}
/////////////////////////////////////////////////
toolWidget::~toolWidget()
{
    clearLODTabsArray();
    delete ui;
}
//////////////////////////////////////////////////
void toolWidget::resizeEvent(QResizeEvent *event){
    QRect tabGeometry=ui->tabWidget->geometry();
    tabGeometry.setHeight(this->height());
    ui->tabWidget->setGeometry(tabGeometry);
    ui->animTab->resizeWidget(ui->tabWidget->currentWidget()->geometry());
    QRect rect=ui->graphTab->geometry();
    rect.setHeight(tabGeometry.height()-rect.y()-30);
    ui->graphTab->resizeWidget(rect);
}
////////////////////////////////////////////////////////////////////////////////////////
void toolWidget::enableToolPanel(bool flag){
    ui->showGraphicRadioButton->setEnabled(flag);
    ui->graphTab->enableContent(flag);
    ui->animTab->enableContent(flag);
}
/////////////////////////////////////////////////////////////////////////////////////////
void toolWidget::resetToolPanel(){
    clearLODTabsArray();
}
/////////////////////////////////////////////////////////////////////////////////////////
void toolWidget::update(){
    //ui->animationWidget->update();
}
///////////////////////////////////////////////////////////////////////////////////////
void toolWidget::graphicTabSelectedSlot(int index){
    IS_CORE_POINTER

    static int lastIndex=0;
    static float lastDistance=0;

//    if(index==ui->graphicTab->count()-1){
//        if(LODTabsArray.size() < 4){
//            addLODTab();
//            return;
//        }
//    }
    if(index==0){//если переключились на mainMesh
        core->setViewDistance(lastDistance);
        core->currentObject()->showMainMesh(true);
    }
    else{
        if(lastIndex==0){
            lastDistance=core->getViewDistance();
        }
        LOD *lod=core->currentObject()->getLod(index-1);
        if(lod!=NULL){
            core->setViewDistance(-lod->getDistance());
            core->currentObject()->showLOD(index-1,true);
        }
    }
    lastIndex=index;
}
///////////////////////////////////////////////////////////////////////
void toolWidget::LODTabDeleteSlot(unsigned int tabIndex, unsigned int LODNumber){
    if(LODTabsArray.size()>=4){
       // ui->graphicTab->setTabEnabled(ui->graphicTab->count()-1,true);
    }
    unsigned int firstTabIndex=LODTabsArray.at(0)->getTabNumber();

    //ui->graphicTab->setCurrentIndex(tabIndex-1);
    //ui->graphicTab->removeTab(tabIndex);
    delete LODTabsArray.at(LODNumber);
    LODTabsArray.remove(LODNumber);
    unsigned int size=(unsigned int)LODTabsArray.size();
    for(unsigned int n=0;n!=size;n++){//переписываем все номера LOD-ов
        LODTabsArray.at(n)->setLODNumber(n);
        LODTabsArray.at(n)->setTabNumber(firstTabIndex+n);
        //ui->graphicTab->setTabText(n+1,tr("LOD")+QString::number(n+1));//надписи переписываем, начиная с 1-го таба т.к. 1-й mainMesh
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void toolWidget::clearLODTabsArray(){
    int size=LODTabsArray.size();
    for(int n=0;n!=size;n++){
       // ui->graphicTab->removeTab(1);
        delete LODTabsArray[n];
    }
    LODTabsArray.clear();
   // ui->graphicTab->setCurrentIndex(0);
    //ui->meshTabBar->resetTab();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void toolWidget::updateInfoSlot(abstractBaseWidget* widget){
    ui->graphTab->updateContent(widget);
    ui->animTab->updateContent(widget);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void toolWidget::setCorePointer(editorCore *core){
    IS_CORE_POINTER

    this->core=core;
    //ui->constraintsTabBar->setCorePointer(core);
    //ui->rigidBodiesTabBar->setCorePointer(core);
    ui->animTab->setCorePointer(core);
    ui->graphTab->setCorePointer(core);

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
