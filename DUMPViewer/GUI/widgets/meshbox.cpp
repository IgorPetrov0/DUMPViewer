#include "meshbox.h"
#include "ui_meshbox.h"

meshBox::meshBox(QWidget *parent) :
    abstractBaseWidget(parent),
    ui(new Ui::meshBox)
{
    ui->setupUi(this);
    connect(ui->loadButton,SIGNAL(clicked(bool)),this,SLOT(loadSlot()));
    connect(ui->deleteButton,SIGNAL(clicked(bool)),this,SLOT(deleteSlot()));
    ui->infoBox->setCorePointer(core);
    type=MESH_NOMESH;
}
/////////////////////////////////////////////////////////////////////////////
meshBox::~meshBox(){
    delete ui;
}
////////////////////////////////////////////////////////////////////////
void meshBox::updateContent(abstractBaseWidget *widget){
    ui->infoBox->updateContent(this);
}
/////////////////////////////////////////////////////////////////
void meshBox::resizeWidget(QRect rect){

}
////////////////////////////////////////////////////////
void meshBox::loadSlot(){

    IS_CORE_POINTER

    QString name=dFileDialog::getOpenFileName(core,tr("Open mesh file"),core->currentPath(),core->modelFilter());
    if(!name.isEmpty()){
        if(!core->loadGraphicObject(name,type)){
            QMessageBox box(core->mainWindowPointer());
            box.setWindowTitle(tr("Error"));
            box.setIcon(QMessageBox::Critical);
            box.setDefaultButton(QMessageBox::Ok);
            box.setText(core->getLastError());
            box.exec();
            return;
        }
        QFileInfo fi(name);
        ui->fileNameLine->setText(fi.fileName());
        emit somethingChange(this);
    }
}
///////////////////////////////////////////////////////////////////
void meshBox::clear(){
    ui->fileNameLine->clear();
    ui->infoBox->clear();
}
////////////////////////////////////////////////////////////////////////
void meshBox::enableContent(bool flag){
    ui->deleteButton->setEnabled(flag);
    ui->loadButton->setEnabled(flag);
    ui->fileNameLine->setEnabled(flag);
    ui->infoBox->enableContent(flag);
}
/////////////////////////////////////////////////////////////////////
void meshBox::deleteSlot(){
    clear();
    emit somethingChange(this);
}
///////////////////////////////////////////////////////////////////////
void meshBox::setCorePointer(editorCore *pointer){
    core=pointer;
    ui->infoBox->setCorePointer(pointer);
}
///////////////////////////////////////////////////////////////////////////////
void meshBox::setMeshType(meshType type){
    this->type=type;
    ui->infoBox->setMeshType(type);
}
