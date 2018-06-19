#include "meshtab.h"
#include "ui_meshtab.h"

meshTab::meshTab(QTabWidget *parent) :
    dTabBar(parent),
    ui(new Ui::meshTab)
{
    ui->setupUi(this);
    createTab();
    connect(ui->meshInfoWidget,SIGNAL(loadSignal()),this,SLOT(loadMeshSlot()));
    connect(ui->meshInfoWidget,SIGNAL(deleteSignal()),this,SLOT(mainMeshDeleteSlot()));
}
///////////////////////////////////////////////////////
meshTab::~meshTab(){
    delete ui;
}
///////////////////////////////////////////////////////
void meshTab::createTab(){
    addWidget(ui->meshInfoWidget);
    ui->meshInfoWidget->setOriginSize();
}
///////////////////////////////////////////////////////
void meshTab::loadMeshSlot(){

    QString name=dFileDialog::getOpenFileName(app,tr("Open mesh file"),app->currentPath(),app->modelFilter());
    if(!name.isEmpty()){
        if(app->currentObject()->mainMeshExsist()){
            mainMeshDeleteSlot();
        }
        QFileInfo fi(name);
        ui->meshInfoWidget->setFileName(fi.fileName());
        editabelGraphicObject *object = new editabelGraphicObject;
        if(!app->loadGraphicObject(name,object)){
            QMessageBox box(parentWidget());
            box.setWindowTitle(tr("Error"));
            box.setIcon(QMessageBox::Warning);
            box.setDefaultButton(QMessageBox::Ok);
            box.setText(app->getLastError());
            box.exec();
            return;
        }
        app->currentObject()->setMainMesh(object);
        app->view()->addModel(app->currentObject()->getMainMesh());
        app->view()->update();
        ui->meshInfoWidget->calculateMeshParameters(app->currentObject()->getMainMesh());
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
void meshTab::mainMeshDeleteSlot(){
    app->view()->removeModel(app->currentObject()->getMainMesh());
    app->currentObject()->deleteMainMesh();
    app->checkMaterials();
    resetTab();
    app->view()->update();
}
/////////////////////////////////////////////////////////////////////////////////////////
void meshTab::updateInfoSlot(){
    if(app->currentObject()!=NULL){
        ui->meshInfoWidget->setFileName(QString::fromStdString(app->currentObject()->getMainMesh()->getName()));
        ui->meshInfoWidget->calculateMeshParameters(app->currentObject()->getMainMesh());
    }
    else{
        ui->meshInfoWidget->clear();
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void meshTab::resetTab(){
    ui->meshInfoWidget->clear();
}
