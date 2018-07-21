#include "graphicwidget.h"
#include "ui_gaphicwidget.h"

graphicWidget::graphicWidget(QWidget *parent) :
    dvBaseWidget(parent),
    ui(new Ui::graphicWidget)
{
    ui->setupUi(this);
}
//////////////////////////////////////////////////////
graphicWidget::~graphicWidget()
{
    delete ui;
}
