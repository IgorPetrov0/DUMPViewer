#include "showradiobutton.h"
#include "ui_showradiobutton.h"

showRadioButton::showRadioButton(QWidget *parent, QString text) :
    abstractBaseWidget(parent),
    ui(new Ui::showRadioButton)
{
    ui->setupUi(this);
    ui->radioButton->setText(text);
}
/////////////////////////////////////////////////////////
showRadioButton::~showRadioButton()
{
    delete ui;
}
//////////////////////////////////////////////////////////////////////
void showRadioButton::updateContent(){

}
//////////////////////////////////////////////////////////////////////
void showRadioButton::resizeWidget(QRect rect){

}
//////////////////////////////////////////////////////////////////////
void showRadioButton::clear(){
    ui->radioButton->setChecked(true);
}
