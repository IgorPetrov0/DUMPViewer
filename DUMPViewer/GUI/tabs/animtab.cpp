#include "animtab.h"
#include "ui_animtab.h"



animTab::animTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::animTab)
{
    ui->setupUi(this);

    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(selectAnimation(QString)));
}
//////////////////////////////////////////////////////////////
animTab::~animTab()
{
    delete ui;
}
////////////////////////////////////////////////////////////////
void animTab::setCorePointer(editorCore *value){
    core = value;
}
////////////////////////////////////////////////////////////////
void animTab::selectAnimation(QString name){
    if(!name.isEmpty()){

    }
}
////////////////////////////////////////////////////////////////
void animTab::updateInfoSlot(){
    for(int n=0;n!=core->currentObject()->getMainMesh()->)
}
