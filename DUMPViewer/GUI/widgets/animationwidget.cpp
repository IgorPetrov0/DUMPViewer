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
