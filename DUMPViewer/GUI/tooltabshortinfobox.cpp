#include "tooltabshortinfobox.h"
#include "ui_tooltabshortinfobox.h"

toolTabShortInfoBox::toolTabShortInfoBox(QWidget *parent) :
    dumpViewerWidget(parent),
    ui(new Ui::toolTabShortInfoBox)
{
    ui->setupUi(this);
    clear();
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
void toolTabShortInfoBox::calculateMeshParameters(editabelGraphicObject *object){
   ui->trianglesValueLabel->setText(tr("Tiangles = ")+QString::number(object->getTrianglesCount()));
   ui->xSizeLabel->setText(tr("X Size = ")+QString::number(object->getBoundBox().x()));
   ui->ySizeLabel->setText(tr("Y Size = ")+QString::number(object->getBoundBox().y()));
   ui->zSizeLabel->setText(tr("Z Size = ")+QString::number(object->getBoundBox().z()));
}
////////////////////////////////////////////////////////////////////////////////////////
