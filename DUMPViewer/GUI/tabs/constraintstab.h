#ifndef CONSTRAINTSTAB_H
#define CONSTRAINTSTAB_H

#include "GUI/tabs/tabbar.h"
#include "GUI/widgets/constraintPropertiesWidgets/pointtopointwidget.h"
#include "GUI/widgets/constraintPropertiesWidgets/hingewidget.h"
#include "GUI/widgets/constraintPropertiesWidgets/conetwistwidget.h"
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
