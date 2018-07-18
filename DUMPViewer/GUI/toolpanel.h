#ifndef TOOLPANEL_H
#define TOOLPANEL_H

#include <QTabWidget>
#include <QScrollBar>
#include <QCheckBox>
#include <QListView>
#include "GUI/meshbox.h"
#include "GUI/tabs/tabbar.h"
#include "GUI/widgets/distancewidget.h"


class toolPanel : public QTabWidget
{
    Q_OBJECT

public:
    toolPanel(QWidget *parent);
    ~toolPanel();

signals:
    void openPhisicMesh(QString fileName);
    void openGraphicMesh(QString fileName,int numberOfLOD);
    void showHidePhisicMesh(bool show);
    void showHideGraphicMesh(bool show);
    void setLODDistance(float distance, int numberOfLOD);
    void moveMeshToDistance();
    void returnLastDistance();

protected:
    meshBox *phisicInfo;
    meshBox *graphicInfo;
    meshBox *LOD1Info;
    meshBox *LOD2Info;
    meshBox *LOD3Info;
    QTabWidget *LODsTab;
    QTabWidget *phisicTabWidget;
    dTabBar *LOD0Tab;
    dTabBar *LOD1Tab;
    dTabBar *LOD2Tab;
    dTabBar *LOD3Tab;
    dTabBar *phisicTab;
    dTabBar *graphTab;
    dTabBar *viewBar;
    dTabBar *rigidBodiesBar;
    dTabBar *constraintsBar;
    distanceWidget *LOD1Distance;
    distanceWidget *LOD2Distance;
    distanceWidget *LOD3Distance;
    QCheckBox *showPhisicMeshCheckBox;
    QCheckBox *showGraphicMeshCheckBox;


    int w=210;

    void createGraphicTab();
    void createPhisicTab();
    void createLODsTab();
    void createViewTab();
    void resizeEvent(QResizeEvent *event);
    void setConnections();

protected slots:
    void openSlot(QString name);
    void setDistanceSlot(double distance);
    void moveMeshToDistanceSlot(bool checked);
    void showHideGraphicMeshSlot(bool show);
    void showHidePhisicMeshSlot(bool checked);





};

#endif // TOOLPANEL_H
