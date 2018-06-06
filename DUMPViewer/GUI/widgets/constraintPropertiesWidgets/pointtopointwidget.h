#ifndef POINTTOPOINTWIDGET_H
#define POINTTOPOINTWIDGET_H

#include "GUI/widgets/dumpviewerwidget.h"

namespace Ui {
class pointToPointWidget;
}

class pointToPointWidget : public dumpViewerWidget
{
    Q_OBJECT

public:
    explicit pointToPointWidget(QWidget *parent = 0);
    ~pointToPointWidget();

private:
    Ui::pointToPointWidget *ui;
};

#endif // POINTTOPOINTWIDGET_H
