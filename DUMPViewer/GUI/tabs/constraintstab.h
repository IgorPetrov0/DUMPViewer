#ifndef CONSTRAINTSTAB_H
#define CONSTRAINTSTAB_H

#include "GUI/widgets/constraintPropertiesWidgets/pointtopointwidget.h"
#include "GUI/widgets/constraintPropertiesWidgets/hingewidget.h"
#include "GUI/widgets/constraintPropertiesWidgets/conetwistwidget.h"
#include "gameObject/constraint.h"


namespace Ui {
class constraintsTab;
}

class constraintsTab : public QWidget
{
    Q_OBJECT

public:
    explicit constraintsTab(QWidget *parent = 0);
    ~constraintsTab();
    void updateInfo();

private:
    Ui::constraintsTab *ui;
    dumpViewerWidget *currentPropertiesWidgetPointer;
    void createTab();
    void deleteCurrrentPropWidget();

protected slots:
    void constraintTypeChanged(int index);

};

#endif // CONSTRAINTSTAB_H
