#include "meshinfobox.h"
#include "ui_meshinfobox.h"

meshInfoBox::meshInfoBox(QWidget *parent) :
    dvBaseWidget(parent),
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

    glm::vec3 vector=mesh->getMoveVector();
    ui->posXSpinBox->setValue((double)vector.x);
    ui->posYSpinBox->setValue((double)vector.y);
    ui->posZSpinBox->setValue((double)vector.z);

    vector=mesh->getRotateVector();
    ui->rotXSpinBox->setValue((double)vector.x);
    ui->rotYSpinBox->setValue((double)vector.y);
    ui->rotZSpinBox->setValue((double)vector.z);

    vector=mesh->getScaleVector();
    ui->scaleXSpinBox->setValue((double)vector.x);
    ui->scaleYSpinBox->setValue((double)vector.y);
    ui->scaleZSpinBox->setValue((double)vector.z);
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::posXChange(double value){
    IS_CORE_POINTER
    glm::vec3 vector = mesh->getMoveVector();
    vector.x=(float)value;
    mesh->setMoveVector(vector);
    core->updateView();
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::posYChange(double value){
    IS_CORE_POINTER
    glm::vec3 vector = mesh->getMoveVector();
    vector.y=(float)value;
    mesh->setMoveVector(vector);
    core->updateView();
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::posZChange(double value){
    IS_CORE_POINTER
    glm::vec3 vector = mesh->getMoveVector();
    vector.z=(float)value;
    mesh->setMoveVector(vector);
    core->updateView();
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::rotXChange(double value){
    IS_CORE_POINTER
    glm::vec3 vector = mesh->getRotateVector();
    vector.x=(float)value;
    mesh->setRotateVector(vector);
    core->updateView();
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::rotYChange(double value){
    IS_CORE_POINTER
    glm::vec3 vector = mesh->getRotateVector();
    vector.y=(float)value;
    mesh->setRotateVector(vector);
    core->updateView();
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::rotZChange(double value){
    IS_CORE_POINTER
    glm::vec3 vector = mesh->getRotateVector();
    vector.z=(float)value;
    mesh->setRotateVector(vector);
    core->updateView();
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::scaleXChange(double value){
    IS_CORE_POINTER
    glm::vec3 vector = mesh->getScaleVector();
    vector.x=(float)value;
    mesh->setScaleVector(vector);
    core->updateView();
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::scaleYChange(double value){
    IS_CORE_POINTER
    glm::vec3 vector = mesh->getScaleVector();
    vector.y=(float)value;
    mesh->setScaleVector(vector);
    core->updateView();
}
////////////////////////////////////////////////////////////////////////////////////////
void meshInfoBox::scaleZChange(double value){
    IS_CORE_POINTER
    glm::vec3 vector = mesh->getScaleVector();
    vector.z=(float)value;
    mesh->setScaleVector(vector);
    core->updateView();
}
////////////////////////////////////////////////////////////////////////////////////////
