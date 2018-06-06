#ifndef CONSTRAINTSTAB_H
#define CONSTRAINTSTAB_H

#include "widgets/tabbar.h"
#include "widgets/constraintPropertiesWidgets/pointtopointwidget.h"
#include "widgets/constraintPropertiesWidgets/hingewidget.h"
#include "widgets/constraintPropertiesWidgets/conetwistwidget.h"
#include "gameObject/constraint.h"


namespace Ui {
class constraintsTab;
}

class constraintsTab : public dTabBar
{
    Q_OBJECT

public:
    explicit constraintsTab(QTabWidget *parent = 0);
    ~constraintsTab();

private:
    Ui::constraintsTab *ui;
    dumpViewerWidget *currentPropertiesWidgetPointer;
    void createTab();
    void deleteCurrrentPropWidget();

protected slots:
    void constraintTypeChanged(int index);

};

#endif // CONSTRAINTSTAB_H
