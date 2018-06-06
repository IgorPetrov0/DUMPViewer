#ifndef CONETWISTWIDGET_H
#define CONETWISTWIDGET_H

#include "widgets/dumpviewerwidget.h"

namespace Ui {
class coneTwistWidget;
}

class coneTwistWidget : public dumpViewerWidget
{
    Q_OBJECT

public:
    explicit coneTwistWidget(QWidget *parent = 0);
    ~coneTwistWidget();

private:
    Ui::coneTwistWidget *ui;
};

#endif // CONETWISTWIDGET_H
