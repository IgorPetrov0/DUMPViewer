#include "constraintstab.h"
#include "ui_constraintstab.h"

constraintsTab::constraintsTab(QWidget *parent):
    ui(new Ui::constraintsTab)
{
    ui->setupUi((QWidget*)this);
    currentPropertiesWidgetPointer=NULL;
    createTab();

}
//////////////////////////////////////////////////////////
constraintsTab::~constraintsTab()
{
    deleteCurrrentPropWidget();
    delete ui;
}
///////////////////////////////////////////////////////////
void constraintsTab::updateInfo(){

}
/////////////////////////////////////////////////////////////
void constraintsTab::createTab(){
//    addWidget(ui->showConstraintsRadioButton);
//    addWidget(ui->groupBox_2);
//    addWidget(ui->propertiesBox);

    ui->constraintsTypeComboBox->insertItem(0,tr("Point to point"),QVariant(CONSTRAINT_POINT_TO_POINT));
    ui->constraintsTypeComboBox->insertItem(1,tr("Hinge"),QVariant(CONSTRAINT_HINGE));
    ui->constraintsTypeComboBox->insertItem(2,tr("Slider"),QVariant(CONSTRAINT_SLIDER));
    ui->constraintsTypeComboBox->insertItem(3,tr("Cone twist"),QVariant(CONSTRAINT_CONE_TWIST));
    ui->constraintsTypeComboBox->insertItem(4,tr("Generic 6 DOF"),QVariant(CONSTRAINT_GENERIC_6_DOF));

//    connect(ui->constraintsTypeComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(constraintTypeChanged(int)));

    constraintTypeChanged(ui->constraintsTypeComboBox->currentIndex());

}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void constraintsTab::constraintTypeChanged(int index){
    deleteCurrrentPropWidget();
    switch(ui->constraintsTypeComboBox->itemData(index).toInt()){
        case(CONSTRAINT_POINT_TO_POINT):{
            currentPropertiesWidgetPointer=new pointToPointWidget(ui->propertiesBox);           
            break;
        }
        case(CONSTRAINT_HINGE):{
            currentPropertiesWidgetPointer=new hingeWidget(ui->propertiesBox);
            break;
        }
        case(CONSTRAINT_SLIDER):{
            currentPropertiesWidgetPointer=new hingeWidget(ui->propertiesBox);
            break;
        }
        case(CONSTRAINT_CONE_TWIST):{
            currentPropertiesWidgetPointer=new coneTwistWidget(ui->propertiesBox);
            break;
        }
        case(CONSTRAINT_GENERIC_6_DOF):{
            currentPropertiesWidgetPointer=new hingeWidget(ui->propertiesBox);
            break;
        }
    }
    currentPropertiesWidgetPointer->setOriginSize();
    currentPropertiesWidgetPointer->show();
    QRect g=ui->propertiesBox->geometry();
    g.setHeight(currentPropertiesWidgetPointer->height()+5);
    ui->propertiesBox->setGeometry(g);
    //checkSize();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void constraintsTab::deleteCurrrentPropWidget(){
    if(currentPropertiesWidgetPointer!=NULL){
        delete currentPropertiesWidgetPointer;
        currentPropertiesWidgetPointer=NULL;
    }
}
