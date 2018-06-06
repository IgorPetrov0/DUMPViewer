#include "pointtopointwidget.h"
#include "ui_pointtopointwidget.h"

pointToPointWidget::pointToPointWidget(QWidget *parent) :
    dumpViewerWidget(parent),
    ui(new Ui::pointToPointWidget)
{
    ui->setupUi(this);
    ui->pivotBWidget->setPivotFrameName(tr("Pivot B"));

}
////////////////////////////////////////////////////////////////////
pointToPointWidget::~pointToPointWidget()
{
    delete ui;
}
