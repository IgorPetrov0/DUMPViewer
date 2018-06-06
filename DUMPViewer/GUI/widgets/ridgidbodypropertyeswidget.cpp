#include "ridgidbodypropertyeswidget.h"
#include "ui_ridgidbodypropertyeswidget.h"

ridgidBodyPropertyesWidget::ridgidBodyPropertyesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ridgidBodyPropertyesWidget)
{
    ui->setupUi(this);
}

ridgidBodyPropertyesWidget::~ridgidBodyPropertyesWidget()
{
    delete ui;
}
