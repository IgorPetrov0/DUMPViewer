#ifndef SHOWRADIOBUTTON_H
#define SHOWRADIOBUTTON_H

#include "GUI/widgets/abstractbasewidget.h"

namespace Ui {
class showRadioButton;
}

class showRadioButton : public abstractBaseWidget
{
    Q_OBJECT

public:
    explicit showRadioButton(QWidget *parent, QString text);
    ~showRadioButton();
    virtual void updateContent();
    virtual void resizeWidget(QRect rect);
    virtual void clear();


private:
    Ui::showRadioButton *ui;
};

#endif // SHOWRADIOBUTTON_H
