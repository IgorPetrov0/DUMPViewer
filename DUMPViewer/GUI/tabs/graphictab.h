#ifndef GRAPHICTAB_H
#define GRAPHICTAB_H

#include <QWidget>
#include "GUI/widgets/abstractbasewidget.h"

namespace Ui {
class graphicTab;
}

class graphicTab : public abstractBaseWidget
{
    Q_OBJECT

public:
    explicit graphicTab(QWidget *parent);
    ~graphicTab();
    virtual void resizeWidget(QRect rect);
    virtual void clear();

public slots:
    virtual void updateContent(abstractBaseWidget* widget);

private:
    Ui::graphicTab *ui;
};

#endif // GRAPHICTAB_H
