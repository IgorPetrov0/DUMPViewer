#include "meshinfobox.h"
#include "ui_meshinfobox.h"

meshInfoBox::meshInfoBox(QWidget *parent) :
    dumpViewerWidget(parent),
    ui(new Ui::meshInfoBox)
{
    ui->setupUi(this);
    clear();
}
////////////////////////////////////////////////////////////////
meshInfoBox::~meshInfoBox()
{
    delete ui;
}
//////////////////////////////////////////////////////////////////
void meshInfoBox::clear(){
    ui->trianglesValueLabel->setText(tr("Tiangles = "));
    ui->xSizeLabel->setText(tr("X Size = "));
    ui->ySizeLabel->setText(tr("Y Size = "));
    ui->zSizeLabel->setText(tr("Z Size = "));
}
////////////////////////////////////////////////////////////////////
void meshInfoBox::setMesh(editabelGraphicObject *value){
    mesh = value;
    calculateMeshParameters();
}
//////////////////////////////////////////////////////////////////
void meshInfoBox::calculateMeshParameters(){
   unsigned int indexObjectsCount=mesh->getNumIndicesObjects();
   unsigned int indicesCount=0;
   for(unsigned int n=0;n!=indexObjectsCount;n++){
       indicesCount+=mesh->getIndexObject(n)->getIndicesCount();
   }
   ui->trianglesValueLabel->setText(tr("Tiangles = ")+QString::number(indicesCount/3));
   ui->xSizeLabel->setText(tr("X Size = ")+QString::number(mesh->getBoundBox().x()));
   ui->ySizeLabel->setText(tr("Y Size = ")+QString::number(mesh->getBoundBox().y()));
   ui->zSizeLabel->setText(tr("Z Size = ")+QString::number(mesh->getBoundBox().z()));
}
////////////////////////////////////////////////////////////////////////////////////////
