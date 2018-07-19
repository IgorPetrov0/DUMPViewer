#include "meshbox.h"
#include "ui_meshbox.h"

meshBox::meshBox(QWidget *parent) :
    dumpViewerWidget(parent),
    ui(new Ui::meshBox)
{
    ui->setupUi(this);
    connect(ui->loadButton,SIGNAL(clicked(bool)),this,SLOT(loadSlot()));
    connect(ui->deleteButton,SIGNAL(clicked(bool)),this,SLOT(deleteSlot()));
    ui->infoBox->setCorePointer(core);
    //ui->infoBox->setOriginSize();
}
/////////////////////////////////////////////////////////////////////////////
meshBox::~meshBox(){
    delete ui;
}
////////////////////////////////////////////////////////////////////////
void meshBox::updateContent(){

}
/////////////////////////////////////////////////////////////////
void meshBox::resizeWidget(QRect rect){

}
////////////////////////////////////////////////////////
void meshBox::loadSlot(){

    IS_CORE_POINTER

    QString name=dFileDialog::getOpenFileName(core,tr("Open mesh file"),core->currentPath(),core->modelFilter());
    if(!name.isEmpty()){
        QFileInfo fi(name);
        ui->fileNameLine->setText(fi.fileName());
        editabelGraphicObject *object = new editabelGraphicObject;
        object->setName(fi.fileName().toStdString());
        if(!core->loadGraphicObject(name,object)){
            QMessageBox box(core->mainWindowPointer());
            box.setWindowTitle(tr("Error"));
            box.setIcon(QMessageBox::Warning);
            box.setDefaultButton(QMessageBox::Ok);
            box.setText(core->getLastError());
            box.exec();
            delete object;
            return;
        }
        if(!core->loadObjectShaders(object)){
            QMessageBox box(core->mainWindowPointer());
            box.setWindowTitle(tr("Shaders load error!"));
            box.setIcon(QMessageBox::Critical);
            box.setText(core->getLastError());
            box.exec();
            delete object;
            return;
        }
        ui->infoBox->setMesh(object);
        emit meshLoaded(object);
    }
}
////////////////////////////////////////////////////////
void meshBox::resizeEvent(QResizeEvent *event){
    QRect rect;

    rect=ui->meshGroup->geometry();
    rect.setWidth(this->width()-15);
    ui->meshGroup->setGeometry(rect);

    rect=ui->fileNameLine->geometry();
    rect.setWidth(ui->meshGroup->width()-20);
    ui->fileNameLine->setGeometry(rect);

    rect=ui->loadButton->geometry();
    rect.setX(10);
    ui->loadButton->setGeometry(rect);

    rect=ui->deleteButton->geometry();
    rect.setX(ui->meshGroup->width()-10-rect.width());
    ui->deleteButton->setGeometry(rect);

    rect=ui->infoBox->geometry();
    rect.setX(ui->loadButton->geometry().x());
    rect.setWidth(ui->meshGroup->geometry().width()-20);
    ui->infoBox->setGeometry(rect);
}
///////////////////////////////////////////////////////////////////
void meshBox::clear(){
    ui->fileNameLine->clear();
    ui->infoBox->clear();
}
/////////////////////////////////////////////////////////////////////
void meshBox::deleteSlot(){
    clear();
    emit meshDeleted();
}
///////////////////////////////////////////////////////////////////////
void meshBox::setCorePointer(editorCore *pointer){
    core=pointer;
    ui->infoBox->setCorePointer(pointer);
}
