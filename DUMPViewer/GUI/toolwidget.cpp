#include "toolwidget.h"
#include "ui_toolwidget.h"

toolWidget::toolWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::toolWidget)
{

    ui->setupUi(this);
    core=NULL;
    connect(ui->graphTab,SIGNAL(somethingChange()),this,SLOT(updateInfoSlot()));
    ui->tabWidget->setCurrentIndex(1);
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
    QRect rect=ui->graphTab->geometry();
    rect.setHeight(tabGeometry.height()-rect.y()-30);
    ui->graphTab->resizeWidget(rect);
}
////////////////////////////////////////////////////////////////////////////////////////
void toolWidget::enableToolPanel(bool flag){
    ui->showGraphicRadioButton->setEnabled(flag);
    ui->graphTab->enableContent(flag);
}
/////////////////////////////////////////////////////////////////////////////////////////
void toolWidget::resetToolPanel(){
    clearLODTabsArray();
}
/////////////////////////////////////////////////////////////////////////////////////////
void toolWidget::update(){
    //ui->animationWidget->update();
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
void toolWidget::updateInfoSlot(){
    ui->graphTab->updateContent();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void toolWidget::setCorePointer(editorCore *core){
    IS_CORE_POINTER

    this->core=core;
    //ui->constraintsTabBar->setCorePointer(core);
    //ui->rigidBodiesTabBar->setCorePointer(core);
    ui->graphTab->setCorePointer(core);

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
