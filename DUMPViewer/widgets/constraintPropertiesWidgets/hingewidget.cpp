#include "hingewidget.h"
#include "ui_hingewidget.h"

hingeWidget::hingeWidget(QWidget *parent) :
    dumpViewerWidget(parent),
    ui(new Ui::hingeWidget)
{
    ui->setupUi(this);
    ui->transformAWidget->setFrameTitle(tr("Transform A"));
    ui->transformBWidget->setFrameTitle(tr("Transform B"));
}
//////////////////////////////////////////////////////
hingeWidget::~hingeWidget()
{
    delete ui;
}
