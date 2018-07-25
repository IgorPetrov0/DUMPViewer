#include "graphictab.h"
#include "ui_graphictab.h"

graphicTab::graphicTab(QWidget *parent) :
    abstractBaseWidget(parent),
    ui(new Ui::graphicTab)
{
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(0);
}
////////////////////////////////////////////////////////////
graphicTab::~graphicTab()
{
    delete ui;
}
////////////////////////////////////////////////////////////////
void graphicTab::updateContent(abstractBaseWidget *widget){

}
////////////////////////////////////////////////////////////////
void graphicTab::resizeWidget(QRect rect){
    QRect tRect;
    tRect.setWidth(rect.width());
    tRect.setHeight(rect.height());
    this->setGeometry(rect);
    ui->toolBox->setGeometry(tRect);
    tRect=ui->toolBox->currentWidget()->geometry();
    ui->meshWidget->resizeWidget(tRect);
    ui->LOD1Widget->resizeWidget(tRect);
    ui->LOD2Widget->resizeWidget(tRect);
    ui->LOD3Widget->resizeWidget(tRect);
    ui->LOD4Widget->resizeWidget(tRect);
}
////////////////////////////////////////////////////////////////
void graphicTab::clear(){

}
///////////////////////////////////////////////////////////////////
void graphicTab::setCorePointer(editorCore *core){
    ui->meshWidget->setCorePointer(core);
    ui->LOD1Widget->setCorePointer(core);
    ui->LOD2Widget->setCorePointer(core);
    ui->LOD3Widget->setCorePointer(core);
    ui->LOD4Widget->setCorePointer(core);
    abstractBaseWidget::setCorePointer(core);
}
