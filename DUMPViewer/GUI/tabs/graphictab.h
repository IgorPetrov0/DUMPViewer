#ifndef GRAPHICTAB_H
#define GRAPHICTAB_H

#include <QRadioButton>
#include "GUI/widgets/dvbasewidget.h"
#include "GUI/widgets/showradiobutton.h"
#include "GUI/widgets/meshbox.h"



class graphicTab : public dvBaseWidget
{
    Q_OBJECT

public:
    graphicTab(QWidget *parent);
    virtual void updateContent();
    virtual void resizeWidget(QRect rect);


protected:
    showRadioButton *showGraphicRB;
    meshBox *meshWidget;




};

#endif // GRAPHICTAB_H
