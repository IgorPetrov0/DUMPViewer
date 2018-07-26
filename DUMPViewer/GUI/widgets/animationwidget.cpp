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
void animationWidget::updateContent(abstractBaseWidget *widget){

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
///////////////////////////////////////////////////////////////////////////////
void animationWidget::enableContent(bool flag){
    ui->animationsComboBox->setEnabled(flag);
    ui->horizontalSlider->setEnabled(flag);
    ui->playPushButton->setEnabled(flag);
}
