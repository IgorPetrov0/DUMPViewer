#include "animationtab.h"

animationTab::animationTab(QWidget *parent):
    dvBaseWidget(parent)
{
    animWidget = new animationWidget(this);
    addWidget(animWidget,0);
}
////////////////////////////////////////////////////////////
animationTab::~animationTab()
{
    delete animWidget;
}
////////////////////////////////////////////////////////////
void animationTab::updateContent(){

}
////////////////////////////////////////////////////////////
void animationTab::resizeWidget(QRect rect){
    this->setGeometry(rect);
    dvBaseWidget::resizeWidget(rect);
}
//////////////////////////////////////////////////////////////
