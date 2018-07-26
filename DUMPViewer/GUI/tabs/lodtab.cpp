#include "lodtab.h"
#include "ui_lodtab.h"

LODTab::LODTab(QWidget *parent) :
    dvBaseWidget(parent),
    ui(new Ui::LODTab)
{
    ui->setupUi(this);
    addWidget(ui->LOD1InfoWidget,0);
    addWidget(ui->LOD1DistanceWidget,0);
    lodPointer=NULL;
}
//////////////////////////////////////////////////////
LODTab::~LODTab()
{
    delete ui;
}
/////////////////////////////////////////////////////////////////
void LODTab::meshLoaded(editabelGraphicObject *mesh){
    IS_CORE_POINTER

    if(lodPointer!=NULL){
        core->deleteMesh(getLodType());
    }
    lodPointer = new editableLOD(mesh,0);
    delete mesh;
    core->addLOD(LODNumber,lodPointer);
}
/////////////////////////////////////////////////////////////////
void LODTab::meshDeleted(){
    core->deleteMesh(getLodType());
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
    switch(number) {
        case(1):{
            ui->LOD1InfoWidget->setMeshType(MESH_LOD1);
            break;
        }
        case(2):{
            ui->LOD1InfoWidget->setMeshType(MESH_LOD2);
            break;
        }
        case(3):{
            ui->LOD1InfoWidget->setMeshType(MESH_LOD3);
            break;
        }
        case(4):{
            ui->LOD1InfoWidget->setMeshType(MESH_LOD4);
            break;
        }
    }
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
    core->setViewDistance(-ui->LOD1DistanceWidget->getValue());
}
//////////////////////////////////////////////////////////////////////////
bool LODTab::isLODDefined(){
    if(lodPointer!=NULL){
        return true;
    }
    return false;
}
////////////////////////////////////////////////////////////////////////////
void LODTab::setCorePointer(editorCore *pointer){
    core=pointer;
    ui->LOD1InfoWidget->setCorePointer(pointer);
}
/////////////////////////////////////////////////////////////////////////////////
void LODTab::updateInfoSlot(){
    lodPointer=core->currentObject()->getLod(LODNumber);
    ui->LOD1DistanceWidget->setValue(lodPointer->getDistance());
    //ui->LOD1InfoWidget->calculateMeshParameters(lodPointer->getGraphicObject());
    //ui->LOD1InfoWidget->setFileName(QString::fromStdString(lodPointer->getName()));
}
///////////////////////////////////////////////////////////////////////////////////////
meshType LODTab::getLodType(){
    switch(LODNumber){
        case(0):{
            return MESH_LOD1;
        }
        case(1):{
            return MESH_LOD2;
        }
        case(2):{
            return MESH_LOD3;
        }
        case(3):{
            return MESH_LOD4;
        }
    }
}
