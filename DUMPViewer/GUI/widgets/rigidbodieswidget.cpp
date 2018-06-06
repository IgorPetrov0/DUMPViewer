#include "rigidbodieswidget.h"
#include "ui_rigidBodiesWidget.h"

rigidBodiesWidget::rigidBodiesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rigidBodiesWidget)
{
    ui->setupUi(this);
}
///////////////////////////////////////////////////////////////////////
rigidBodiesWidget::~rigidBodiesWidget()
{
    delete ui;
}
///////////////////////////////////////////////////////////////////////
