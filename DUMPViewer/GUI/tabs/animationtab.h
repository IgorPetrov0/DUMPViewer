#ifndef ANIMATIONTAB_H
#define ANIMATIONTAB_H

#include "GUI/widgets/dvbasewidget.h"
#include "GUI/widgets/animationwidget.h"


class animationTab : public dvBaseWidget
{
public:
    animationTab(QWidget *parent);
    ~animationTab();
    virtual void updateContent();
    virtual void resizeWidget(QRect rect);

protected:
    animationWidget *animWidget;

};

#endif // ANIMATIONTAB_H
