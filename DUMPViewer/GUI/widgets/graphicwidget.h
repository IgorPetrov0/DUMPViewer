#ifndef GAPHICWIDGET_H
#define GAPHICWIDGET_H

#include <QWidget>
#include "GUI/widgets/dvbasewidget.h"

namespace Ui {
class graphicWidget;
}

class graphicWidget : public dvBaseWidget
{
    Q_OBJECT

public:
    explicit graphicWidget(QWidget *parent = 0);
    ~graphicWidget();

private:
    Ui::graphicWidget *ui;
};

#endif // GAPHICWIDGET_H
