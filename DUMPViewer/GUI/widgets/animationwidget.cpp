#include "animationwidget.h"
#include "ui_animationwidget.h"

animationWidget::animationWidget(QWidget *parent) :
    abstractBaseWidget(parent),
    ui(new Ui::animationWidget)
{
    ui->setupUi(this);
}
//////////////////////////////////////////////////////////////////////////////
animationWidget::~animationWidget()
{
    delete ui;
}
//////////////////////////////////////////////////////////////////////////////
void animationWidget::updateContent(){

}
//////////////////////////////////////////////////////////////////////////////
void animationWidget::resizeWidget(QRect rect){

}
///////////////////////////////////////////////////////////////////////////////
void animationWidget::clear(){
    ui->animationsComboBox->clear();
    ui->horizontalSlider->setValue(0);
    ui->playPushButton->setChecked(false);
    ui->duration->setText("0");
    ui->tickPerSecond->setText("0");
    ui->currentTick->setText("0");
}