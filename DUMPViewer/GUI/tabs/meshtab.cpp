#include "meshtab.h"
#include "ui_meshtab.h"

meshTab::meshTab(QTabWidget *parent) :
    dTabBar(parent),
    ui(new Ui::meshTab)
{
    ui->setupUi(this);
    addWidget(ui->meshInfoWidget);
    ui->meshInfoWidget->setOriginSize();
    connect(ui->meshInfoWidget,SIGNAL(meshLoaded(editabelGraphicObject*)),this,SLOT(meshLoaded(editabelGraphicObject*)));
    connect(ui->meshInfoWidget,SIGNAL(meshDeleted()),this,SLOT(meshDeleted()));

}
///////////////////////////////////////////////////////
meshTab::~meshTab(){
    delete ui;
}
/////////////////////////////////////////////////////////////////////////////////////////
void meshTab::setCorePointer(editorCore *pointer){
    core=pointer;
    ui->meshInfoWidget->setCorePointer(pointer);
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
