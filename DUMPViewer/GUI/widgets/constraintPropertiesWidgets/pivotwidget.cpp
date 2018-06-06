#include "pivotwidget.h"
#include "ui_pivotwidget.h"

pivotWidget::pivotWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pivotWidget)
{
    ui->setupUi(this);
    connect(ui->XSpinBox,SIGNAL(valueChanged(double)),this,SLOT(changeValues(double)));
    connect(ui->YSpinBox,SIGNAL(valueChanged(double)),this,SLOT(changeValues(double)));
    connect(ui->ZSpinBox,SIGNAL(valueChanged(double)),this,SLOT(changeValues(double)));
}
////////////////////////////////////////////////
pivotWidget::~pivotWidget()
{
    delete ui;
}
/////////////////////////////////////////////////
void pivotWidget::setPivot(vector3 coordinates){
    ui->XSpinBox->setValue(coordinates.x());
    ui->YSpinBox->setValue(coordinates.y());
    ui->ZSpinBox->setValue(coordinates.z());
}
///////////////////////////////////////////////////
vector3 pivotWidget::getPivot(){
    vector3 returnedVector;
    returnedVector.setX(ui->XSpinBox->value());
    returnedVector.setY(ui->YSpinBox->value());
    returnedVector.setZ(ui->ZSpinBox->value());
    return returnedVector;
}
///////////////////////////////////////////////////////
void pivotWidget::changeValues(double value){
    emit valuesChanged(getPivot());
}
///////////////////////////////////////////////////////
void pivotWidget::setPivotFrameName(QString name){
    ui->pivotGroupBox->setTitle(name);
}
///////////////////////////////////////////////////////
