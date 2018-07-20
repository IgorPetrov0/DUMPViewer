#include "graphictab.h"

graphicTab::graphicTab(QWidget *parent):
    dvBaseWidget(parent)
{
    showGraphicRB = new showRadioButton(this,tr("Show graphic"));
    addWidget(showGraphicRB,0);
    meshWidget = new meshBox(this);
    addWidget(meshWidget,0);

}
////////////////////////////////////////////////////////////////
void graphicTab::updateContent(){

}
///////////////////////////////////////////////////////////////
void graphicTab::resizeWidget(QRect rect){
    this->setGeometry(rect);
    dvBaseWidget::resizeWidget(rect);
}
/////////////////////////////////////////////////////////////////