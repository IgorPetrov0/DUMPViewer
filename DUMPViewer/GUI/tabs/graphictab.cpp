#include "graphictab.h"
#include "ui_graphictab.h"

graphicTab::graphicTab(QWidget *parent) :
    abstractBaseWidget(parent),
    ui(new Ui::graphicTab)
{
    ui->setupUi(this);
}
////////////////////////////////////////////////////////////
graphicTab::~graphicTab()
{
    delete ui;
}
////////////////////////////////////////////////////////////////
void graphicTab::updateContent(){

}
////////////////////////////////////////////////////////////////
void graphicTab::resizeWidget(QRect rect){
    QRect tRect;
    tRect.setWidth(rect.width());
    tRect.setHeight(rect.height());
    this->setGeometry(rect);
    ui->toolBox->setGeometry(tRect);
    ui->meshWidget->setGeometry(ui->toolBox->widget(0)->geometry());
}
////////////////////////////////////////////////////////////////
void graphicTab::clear(){

}
