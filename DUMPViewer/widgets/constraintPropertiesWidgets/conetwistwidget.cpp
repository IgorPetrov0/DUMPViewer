#include "conetwistwidget.h"
#include "ui_conetwistwidget.h"

coneTwistWidget::coneTwistWidget(QWidget *parent) :
    dumpViewerWidget(parent),
    ui(new Ui::coneTwistWidget)
{
    ui->setupUi(this);
}
//////////////////////////////////////////////////////////////
coneTwistWidget::~coneTwistWidget()
{
    delete ui;
}
