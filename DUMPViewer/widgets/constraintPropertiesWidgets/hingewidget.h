#ifndef HINGEWIDGET_H
#define HINGEWIDGET_H

#include "widgets/dumpviewerwidget.h"

namespace Ui {
class hingeWidget;
}

class hingeWidget : public dumpViewerWidget
{
    Q_OBJECT

public:
    explicit hingeWidget(QWidget *parent = 0);
    ~hingeWidget();

private:
    Ui::hingeWidget *ui;
};

#endif // HINGEWIDGET_H
