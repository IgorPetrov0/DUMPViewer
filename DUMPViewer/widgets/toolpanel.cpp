#include "toolpanel.h"

toolPanel::toolPanel(QWidget *parent):
    QTabWidget(parent)
{
    this->setGeometry(0,0,w,0);

    createPhisicTab();
    createGraphicTab();
    createViewTab();

    setConnections();
}
//////////////////////////////////////////////////
toolPanel::~toolPanel(){
    delete phisicTab;
    delete graphTab;
    delete viewBar;
}
///////////////////////////////////////////////////
void toolPanel::createPhisicTab(){
    phisicTab=new dTabBar(this);

    phisicInfo=new toolTabInfoBox();
    showPhisicMeshCheckBox=new QCheckBox(tr("Show mesh"));

    addTab(phisicTab,tr("Phisyc"));
    phisicTabWidget=new QTabWidget();
    rigidBodiesBar=new dTabBar(phisicTab);
    constraintsBar=new dTabBar(phisicTab);
    phisicTabWidget->addTab(rigidBodiesBar,tr("Rigid body"));
    phisicTabWidget->addTab(constraintsBar,tr("Contraints"));
    phisicTab->addWidget(phisicTabWidget);


    //phisicTab->addWidget(phisicInfo);
    //showPhisicMeshCheckBox->setGeometry(1,1,100,20);
    //phisicTab->addWidget(showPhisicMeshCheckBox);


}
///////////////////////////////////////////////////////
void toolPanel::createGraphicTab(){
    graphTab=new dTabBar(this);   
    createLODsTab();
    graphTab->addWidget(LODsTab);
    addTab(graphTab,tr("Graphic"));
}
/////////////////////////////////////////////////////////
void toolPanel::createLODsTab(){
    LODsTab=new QTabWidget();

    graphicInfo=new toolTabInfoBox();
    LOD1Info=new toolTabInfoBox();
    LOD2Info=new toolTabInfoBox();
    LOD3Info=new toolTabInfoBox();

    LOD1Distance=new distanceWidget();
    LOD2Distance=new distanceWidget();
    LOD3Distance=new distanceWidget();

    LOD0Tab=new dTabBar(graphTab);
    LOD1Tab=new dTabBar(graphTab);
    LOD2Tab=new dTabBar(graphTab);
    LOD3Tab=new dTabBar(graphTab);

    LOD0Tab->addWidget(graphicInfo);
    LOD1Tab->addWidget(LOD1Info);
    LOD1Tab->addWidget(LOD1Distance);
    LOD2Tab->addWidget(LOD2Info);
    LOD2Tab->addWidget(LOD2Distance);
    LOD3Tab->addWidget(LOD3Info);
    LOD3Tab->addWidget(LOD3Distance);

    LODsTab->addTab(LOD0Tab,tr("Mesh"));
    LODsTab->addTab(LOD1Tab,tr("LOD 1"));
    LODsTab->addTab(LOD2Tab,tr("LOD 2"));
    LODsTab->addTab(LOD3Tab,tr("LOD 3"));
    LODsTab->setCurrentIndex(0);

    showGraphicMeshCheckBox=new QCheckBox(tr("Show mesh"));
    showGraphicMeshCheckBox->setGeometry(1,1,100,20);
    LOD0Tab->addWidget(showGraphicMeshCheckBox);
}
//////////////////////////////////////////////////////////////////////
void toolPanel::createViewTab(){
    viewBar=new dTabBar(this);
    addTab(viewBar,tr("View"));
}
////////////////////////////////////////////////////////////////////////////////
void toolPanel::setConnections(){
    connect(phisicInfo,SIGNAL(loadSignal(QString)),this,SLOT(openSlot(QString)));
    connect(showPhisicMeshCheckBox,SIGNAL(toggled(bool)),this,SLOT(showHidePhisicMeshSlot(bool)));
    connect(graphicInfo,SIGNAL(loadSignal(QString)),this,SLOT(openSlot(QString)));
    connect(showGraphicMeshCheckBox,SIGNAL(toggled(bool)),this,SLOT(showHideGraphicMeshSlot(bool)));
    connect(LOD1Info,SIGNAL(loadSignal(QString)),this,SLOT(openSlot(QString)));
    connect(LOD1Distance,SIGNAL(changeDistance(double)),this,SLOT(setDistanceSlot(double)));
    connect(LOD1Distance,SIGNAL(moveMeshToDistance(bool)),this,SLOT(moveMeshToDistanceSlot(bool)));
    connect(LOD2Info,SIGNAL(loadSignal(QString)),this,SLOT(openSlot(QString)));
    connect(LOD2Distance,SIGNAL(changeDistance(double)),this,SLOT(setDistanceSlot(double)));
    connect(LOD2Distance,SIGNAL(moveMeshToDistance(bool)),this,SLOT(moveMeshToDistanceSlot(bool)));
    connect(LOD3Info,SIGNAL(loadSignal(QString)),this,SLOT(openSlot(QString)));
    connect(LOD3Distance,SIGNAL(changeDistance(double)),this,SLOT(setDistanceSlot(double)));
    connect(LOD3Distance,SIGNAL(moveMeshToDistance(bool)),this,SLOT(moveMeshToDistanceSlot(bool)));
}
/////////////////////////////////////////////////////////////////////////////////
void toolPanel::resizeEvent(QResizeEvent *event){
    LODsTab->setGeometry(1,1,w-10,this->height());
    //эта хрень, что-бы при ресайзе обновлялись таббары
    int i=currentIndex();
    if(i==0){
        setCurrentIndex(1);
    }
    else{
        setCurrentIndex(0);
    }
    setCurrentIndex(i);
}
/////////////////////////////////////////////////////////////////////////////////
void toolPanel::openSlot(QString name){
    switch(currentIndex()){
        case(0):{//открыта вкладка физического объекта
            emit openPhisicMesh(name);
            break;
        }
        case(1):{//открыта вкладка графического объекта
            emit openGraphicMesh(name,LODsTab->currentIndex());
            break;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////
void toolPanel::setDistanceSlot(double distance){
    emit setLODDistance(distance,LODsTab->currentIndex());
}
////////////////////////////////////////////////////////////////////////////////
void toolPanel::moveMeshToDistanceSlot(bool checked){
    if(checked){
        emit moveMeshToDistance();
    }
    else{
        emit returnLastDistance();
    }
}
/////////////////////////////////////////////////////////////////////////////////
void toolPanel::showHideGraphicMeshSlot(bool show){
    emit showHideGraphicMesh(show);
}
////////////////////////////////////////////////////////////////////////////////
void toolPanel::showHidePhisicMeshSlot(bool show){
    emit showHidePhisicMesh(show);
}
////////////////////////////////////////////////////////////////////////////////
