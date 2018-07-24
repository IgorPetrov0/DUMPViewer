#include "distancewidget.h"
#include "ui_distancewidget.h"

distanceWidget::distanceWidget(QWidget *parent) :
    abstractBaseWidget(parent),
    ui(new Ui::distanceWidget)
{
    ui->setupUi(this);
    ui->distanceSpinBox->setMaximum(std::numeric_limits<double>::max());
    connect(ui->distanceSpinBox,SIGNAL(editingFinished()),this,SLOT(changeDistanceSlot()));
    connect(ui->moveButton,SIGNAL(clicked(bool)),this,SIGNAL(moveMeshToDistance(bool)));
}
///////////////////////////////////////////////////////////
distanceWidget::~distanceWidget()
{
    delete ui;
}
////////////////////////////////////////////////////////////
void distanceWidget::moveMeshSlot(bool checked){
    emit moveMeshToDistance(checked);
}
////////////////////////////////////////////////////////////
void distanceWidget::disableWidget(bool disable){
    ui->groupBox->setDisabled(disable);
}
///////////////////////////////////////////////////////////
float distanceWidget::getValue(){
    return (float)ui->distanceSpinBox->value();
}
////////////////////////////////////////////////////////////
void distanceWidget::changeDistanceSlot(){
    emit changeDistance(ui->distanceSpinBox->value());
}
///////////////////////////////////////////////////////////////////
void distanceWidget::setValue(float value){
    ui->distanceSpinBox->setValue(value);
}
/////////////////////////////////////////////////////////////////////
void distanceWidget::updateContent(abstractBaseWidget *widget){

}
//////////////////////////////////////////////////////////////////////
void distanceWidget::resizeWidget(QRect rect){

}
///////////////////////////////////////////////////////////////////////
void distanceWidget::clear(){

}
