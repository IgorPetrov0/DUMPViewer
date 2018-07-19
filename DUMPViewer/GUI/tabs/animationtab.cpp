#include "animationtab.h"

animationTab::animationTab(QWidget *parent):
    dvBaseWidget(parent)
{
    animWidget = new animationWidget(this);
    addWidget(animWidget);
}

animationTab::~animationTab()
{
    delete animWidget;
}
////////////////////////////////////////////////////////////
void animationTab::updateContent(){

}
////////////////////////////////////////////////////////////
void animationTab::resizeWidget(QRect rect){

}
