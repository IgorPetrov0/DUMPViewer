#ifndef ANIMATIONWIDGET_H
#define ANIMATIONWIDGET_H

#include "GUI/widgets/abstractbasewidget.h"

namespace Ui {
class animationWidget;
}

class animationWidget : public abstractBaseWidget
{
    Q_OBJECT

public:
    explicit animationWidget(QWidget *parent = 0);
    ~animationWidget();
    virtual void updateContent();
    virtual void resizeWidget(QRect rect);
    virtual void clear();

private:
    Ui::animationWidget *ui;
};

#endif // ANIMATIONWIDGET_H
