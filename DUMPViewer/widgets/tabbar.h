#ifndef TABBAR_H
#define TABBAR_H

#include <QTabBar>
#include <QVector>
#include <QScrollBar>
#include <QWheelEvent>
#include <QTabWidget>

#include "widgets/dumpviewerwidget.h"
#include "gameObject/gameobject.h"
#include "application.h"


enum tabType{
    TAB_CONSTRAINT,
    TAB_MESH,
    TAB_LOD1,
    TAB_LOD2,
    TAB_LOD3,

};


class dTabBar : public QTabBar
{
    Q_OBJECT
public:
    dTabBar(QTabWidget *parent=0);
    ~dTabBar();
    void addWidget(QWidget *widget);
    void setEndWidget(QWidget *winget);
    void setApplication(application *app);
    void disableTab(bool disable);

protected:
    void wheelEvent(QWheelEvent *event);
    void resizeEvent(QResizeEvent *event);
    void checkSize();//проверка размера для скроллбара
    int bottomYCoordinate();//получение самой нижней координаты Y

    QVector<QWidget*> widgetsArray;//массив указателей на размещенные виджеты
    QScrollBar *scrollBar;
    QWidget *endWidget;//последний виджет в таббаре, по которому считается скролбар
    application *app;

protected slots:
    void moveWidgets(int value);



};

#endif // TABBAR_H
