#include "animationwidget.h"
#include "ui_animationwidget.h"

animationWidget::animationWidget(QWidget *parent) :
    abstractBaseWidget(parent),
    ui(new Ui::animationWidget)
{
    ui->setupUi(this);
    type=MESH_NOMESH;
    connect(ui->animationsComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(readAnimationData(int)));
}
//////////////////////////////////////////////////////////////////////////////
animationWidget::~animationWidget()
{
    delete ui;
}
//////////////////////////////////////////////////////////////////////////////
void animationWidget::updateContent(){
    editabelGraphicObject *currentMesh=getCurrentMesh();
    ui->animationsComboBox->clear();
    if(currentMesh!=NULL){
        int size=currentMesh->numAnimations();
        if(size!=0){
            disconnect(ui->animationsComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(readAnimationData(int)));
            for(int n=0;n!=size;n++){
                ui->animationsComboBox->addItem(QString::fromStdString(currentMesh->getAnimation(n)->getName()));
            }
            ui->animationsComboBox->setCurrentIndex(0);
            readAnimationData(0);
            connect(ui->animationsComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(readAnimationData(int)));
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
editabelGraphicObject *animationWidget::getCurrentMesh(){
    switch(type){
        case(MESH_MAIN_MESH):{
            return core->currentObject()->getMainMesh();
        }
        case(MESH_LOD1):{
            return core->currentObject()->getLod(0);
        }
        case(MESH_LOD2):{
            return core->currentObject()->getLod(1);
        }
        case(MESH_LOD3):{
            return core->currentObject()->getLod(2);
        }
        case(MESH_LOD4):{
            return core->currentObject()->getLod(3);
        }
        default:{
            return NULL;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void animationWidget::readAnimationData(int index){
    editabelGraphicObject *currentMesh=getCurrentMesh();
    animation *currentAnimation=currentMesh->getAnimation(index);
    if(currentAnimation!=NULL){
        int dur=currentAnimation->getDuration();
        int tps=currentAnimation->getTickPerSecond();
        ui->tDuration->setText(QString::number(dur));
        ui->sDuration->setText(QString::number((float)dur/tps));
        ui->tickPerSecond->setText(QString::number(tps));
        ui->horizontalSlider->setMaximum(dur);
        ui->horizontalSlider->setValue(0);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
void animationWidget::moveSliderSlot(int value){

}
////////////////////////////////////////////////////////////////////////////////
void animationWidget::setMeshType(const meshType &value){
    type = value;
}
//////////////////////////////////////////////////////////////////////////////
void animationWidget::resizeWidget(QRect rect){

}
///////////////////////////////////////////////////////////////////////////////
void animationWidget::clear(){
    ui->animationsComboBox->clear();
    ui->horizontalSlider->setValue(0);
    ui->playPushButton->setChecked(false);
    ui->sDuration->setText("0");
    ui->tDuration->setText("0");
    ui->tickPerSecond->setText("0");
    ui->currentTick->setText("0");
}
///////////////////////////////////////////////////////////////////////////////
void animationWidget::enableContent(bool flag){
    ui->animationsComboBox->setEnabled(flag);
    ui->horizontalSlider->setEnabled(flag);
    ui->playPushButton->setEnabled(flag);
}
