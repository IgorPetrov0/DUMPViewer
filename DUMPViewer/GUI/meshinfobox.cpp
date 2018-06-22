#include "meshinfobox.h"
#include "ui_meshinfobox.h"

meshInfoBox::meshInfoBox(QWidget *parent) :
    dumpViewerWidget(parent),
    ui(new Ui::meshInfoBox)
{
    ui->setupUi(this);
    clear();
    connect(ui->posXSpinBox,SIGNAL(valueChanged(double)),this,SLOT(posXChange(double)));
    connect(ui->posYSpinBox,SIGNAL(valueChanged(double)),this,SLOT(posYChange(double)));
    connect(ui->posZSpinBox,SIGNAL(valueChanged(double)),this,SLOT(posZChange(double)));

    connect(ui->rotXSpinBox,SIGNAL(valueChanged(double)),this,SLOT(rotXChange(double)));
    connect(ui->rotYSpinBox,SIGNAL(valueChanged(double)),this,SLOT(rotYChange(double)));
    connect(ui->rotZSpinBox,SIGNAL(valueChanged(double)),this,SLOT(rotZChange(double)));

    connect(ui->scaleXSpinBox,SIGNAL(valueChanged(double)),this,SLOT(scaleXChange(double)));
    connect(ui->scaleYSpinBox,SIGNAL(valueChanged(double)),this,SLOT(scaleYChange(double)));
    connect(ui->scaleZSpinBox,SIGNAL(valueChanged(double)),this,SLOT(scaleZChange(double)));
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

    ui->posXSpinBox->setValue((double)mesh->getMoveVector().x);
    ui->posYSpinBox->setValue((double)mesh->getMoveVector().y);
    ui->posZSpinBox->setValue((double)mesh->getMoveVector().z);

    ui->rotXSpinBox->setValue((double)mesh->getRotateVector().x);
    ui->rotYSpinBox->setValue((double)mesh->getRotateVector().y);
    ui->rotZSpinBox->setValue((double)mesh->getRotateVector().z);

    ui->scaleXSpinBox->setValue((double)mesh->getScaleVector().x);
    ui->scaleYSpinBox->setValue((double)mesh->getScaleVector().y);
    ui->scaleZSpinBox->setValue((double)mesh->getScaleVector().z);
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::posXChange(double value){
    glm::vec3 vector;
    vector.x=(float)value;
    mesh->setMoveVector(vector);
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::posYChange(double value){
    glm::vec3 vector;
    vector.y=(float)value;
    mesh->setMoveVector(vector);
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::posZChange(double value){
    glm::vec3 vector;
    vector.z=(float)value;
    mesh->setMoveVector(vector);
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::rotXChange(double value){
    glm::vec3 vector;
    vector.x=(float)value;
    mesh->setRotateVector(vector);
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::rotYChange(double value){
    glm::vec3 vector;
    vector.y=(float)value;
    mesh->setRotateVector(vector);
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::rotZChange(double value){
    glm::vec3 vector;
    vector.z=(float)value;
    mesh->setRotateVector(vector);
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::scaleXChange(double value){
    glm::vec3 vector;
    vector.x=(float)value;
    mesh->setScaleVector(vector);
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::scaleYChange(double value){
    glm::vec3 vector;
    vector.y=(float)value;
    mesh->setScaleVector(vector);
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::scaleZChange(double value){
    glm::vec3 vector;
    vector.z=(float)value;
    mesh->setScaleVector(vector);
}
////////////////////////////////////////////////////////////////////////////////////////
