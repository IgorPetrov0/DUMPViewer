#include "meshtab.h"
#include "ui_meshtab.h"

meshTab::meshTab(QWidget *parent) :
    dvBaseWidget(parent),
    ui(new Ui::meshTab)
{
    ui->setupUi(this);
    addWidget(ui->meshInfoWidget,0);
    ui->meshInfoWidget->setMeshType(MESH_MAIN_MESH);
}
///////////////////////////////////////////////////////
meshTab::~meshTab(){
    delete ui;
}
/////////////////////////////////////////////////////////////////////////////////////////
void meshTab::setCorePointer(editorCore *pointer){
    ui->meshInfoWidget->setCorePointer(pointer);
}
////////////////////////////////////////////////////////////////////////////////////////
void meshTab::updateContent(abstractBaseWidget *widget){

}
////////////////////////////////////////////////////////////////////////////////////////
void meshTab::meshLoaded(editabelGraphicObject *mesh){
    IS_CORE_POINTER

    core->addMainMesh(mesh);
}
////////////////////////////////////////////////////////////////////////////////////////
void meshTab::meshDeleted(){
    IS_CORE_POINTER

    core->deleteMesh(MESH_MAIN_MESH);
}
