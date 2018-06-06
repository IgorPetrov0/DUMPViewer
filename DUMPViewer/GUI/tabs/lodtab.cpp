#include "lodtab.h"
#include "ui_lodtab.h"

LODTab::LODTab(QTabWidget *parent) :
    dTabBar(parent),
    ui(new Ui::LODTab)
{
    ui->setupUi(this);
    createTab();
    connect(ui->LOD1InfoWidget,SIGNAL(loadSignal()),this,SLOT(loadSlot()));
    connect(ui->LOD1InfoWidget,SIGNAL(deleteSignal()),this,SLOT(deleteSlot()));
    connect(ui->LOD1DistanceWidget,SIGNAL(changeDistance(double)),this,SLOT(setLodDistance(double)));
    connect(ui->LOD1DistanceWidget,SIGNAL(moveMeshToDistance(bool)),this,SLOT(moveToDistanceSlot()));
    lodPointer=NULL;
}
//////////////////////////////////////////////////////
LODTab::~LODTab()
{
    delete ui;
}
//////////////////////////////////////////////////////
void LODTab::createTab(){
    addWidget(ui->LOD1InfoWidget);
    addWidget(ui->LOD1DistanceWidget);
    ui->LOD1InfoWidget->setOriginSize();
}
/////////////////////////////////////////////////////////////////
void LODTab::loadSlot(){

    QString name=dFileDialog::getOpenFileName(app,tr("Open mesh file"),app->currentPath(),app->modelFilter());
    if(!name.isEmpty()){

        editableLOD *lod=new editableLOD;
        if(!app->loadGraphicObject(name,lod)){//загружаем графику
            delete lod;//в случае неудачи убиваем лод
            QMessageBox box(parentWidget());
            box.setWindowTitle(tr("Error"));
            box.setIcon(QMessageBox::Warning);
            box.setDefaultButton(QMessageBox::Ok);
            box.setText(app->getLastError());
            box.exec();
            return;
        }
        if(lodPointer!=NULL){//если он был, то убираем его из видового экрана
            app->view()->removeModel(lodPointer);
        }
        lodPointer=lod;

        QFileInfo fi(name);
        ui->LOD1InfoWidget->setFileName(fi.fileName());

        lodPointer->setDistance(ui->LOD1DistanceWidget->getValue());//задаем значение
        app->currentObject()->addLOD(lodPointer,LODNumber);
        app->view()->addModel(lodPointer);
        app->currentObject()->showLOD(LODNumber,true);
        app->view()->update();
        ui->LOD1InfoWidget->calculateMeshParameters(lodPointer);
    } 
}
/////////////////////////////////////////////////////////////////
void LODTab::deleteSlot(){
    deleteLod();
    emit deleteSignal(tabNumber,LODNumber);
}
//////////////////////////////////////////////////////////////////
unsigned int LODTab::getTabNumber(){
    return tabNumber;
}
///////////////////////////////////////////////////////////////////
unsigned int LODTab::getLODNumber(){
    return LODNumber;
}
//////////////////////////////////////////////////////////////////
void LODTab::setLODNumber(unsigned int number){
    LODNumber=number;
}
///////////////////////////////////////////////////////////////////
void LODTab::setTabNumber(unsigned int number){
    tabNumber=number;
}
////////////////////////////////////////////////////////////////////
void LODTab::setLodDistance(double value){
    if(lodPointer!=NULL){
        lodPointer->setDistance((float)value);
    }
}
//////////////////////////////////////////////////////////////////////
void LODTab::moveToDistanceSlot(){
    app->view()->setDistance(-ui->LOD1DistanceWidget->getValue());
    app->view()->update();
}
//////////////////////////////////////////////////////////////////////////
bool LODTab::isLODDefined(){
    if(lodPointer!=NULL){
        return true;
    }
    return false;
}
/////////////////////////////////////////////////////////////////////////////
void LODTab::deleteLod(){
    if(lodPointer!=NULL){
        app->view()->removeModel(lodPointer);
        app->currentObject()->deleteLOD(LODNumber);
        app->view()->update();
        lodPointer=NULL;
    }
}
/////////////////////////////////////////////////////////////////////////////////
void LODTab::updateInfoSlot(){
    lodPointer=app->currentObject()->getLod(LODNumber);
    ui->LOD1DistanceWidget->setValue(lodPointer->getDistance());
    ui->LOD1InfoWidget->calculateMeshParameters(lodPointer->getGraphicObject());
    ui->LOD1InfoWidget->setFileName(QString::fromStdString(lodPointer->getName()));
}
