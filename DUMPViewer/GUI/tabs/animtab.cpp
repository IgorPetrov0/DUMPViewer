#include "animtab.h"
#include "ui_animtab.h"



animTab::animTab(QWidget *parent) :
    abstractWidget(parent),
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
void animTab::updateInfo(){
    graphicObject *object=core->currentObject()->getMainMesh();
    unsigned int size=object->numAnimations();
    for(unsigned int n=0;n!=size;n++){
        animation *tmpAnim=object->getAnimation(n);
        ui->comboBox->addItem(QString::fromStdString(tmpAnim->getName()));
    }
}






