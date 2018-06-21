#include "tooltabshortinfobox.h"
#include "ui_tooltabshortinfobox.h"

toolTabShortInfoBox::toolTabShortInfoBox(QWidget *parent) :
    dumpViewerWidget(parent),
    ui(new Ui::toolTabShortInfoBox)
{
    ui->setupUi(this);
    clear();
    QRect rect=this->geometry();
}
////////////////////////////////////////////////////////////////
toolTabShortInfoBox::~toolTabShortInfoBox()
{
    delete ui;
}
//////////////////////////////////////////////////////////////////
void toolTabShortInfoBox::clear(){
    ui->trianglesValueLabel->setText(tr("Tiangles = "));
    ui->xSizeLabel->setText(tr("X Size = "));
    ui->ySizeLabel->setText(tr("Y Size = "));
    ui->zSizeLabel->setText(tr("Z Size = "));
}
//////////////////////////////////////////////////////////////////
void toolTabShortInfoBox::calculateMeshParameters(meshObject *object){
   unsigned int indexObjectsCount=object->getNumIndicesObjects();
   unsigned int indicesCount=0;
   for(unsigned int n=0;n!=indexObjectsCount;n++){
       indicesCount+=object->getIndexObject(n)->getIndicesCount();
   }
   ui->trianglesValueLabel->setText(tr("Tiangles = ")+QString::number(indicesCount/3));
   ui->xSizeLabel->setText(tr("X Size = ")+QString::number(object->getBoundBox().x()));
   ui->ySizeLabel->setText(tr("Y Size = ")+QString::number(object->getBoundBox().y()));
   ui->zSizeLabel->setText(tr("Z Size = ")+QString::number(object->getBoundBox().z()));
}
////////////////////////////////////////////////////////////////////////////////////////
