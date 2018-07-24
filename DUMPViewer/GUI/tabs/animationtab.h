#ifndef ANIMATIONTAB_H
#define ANIMATIONTAB_H

#include "GUI/widgets/dvbasewidget.h"
#include "GUI/widgets/animationwidget.h"


class animationTab : public dvBaseWidget
{
public:
    animationTab(QWidget *parent);
    ~animationTab();
    virtual void resizeWidget(QRect rect);

public slots:
    virtual void updateContent(abstractBaseWidget* widget);

protected:
    animationWidget *animWidget;

};

#endif // ANIMATIONTAB_H
