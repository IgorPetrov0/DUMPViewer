#ifndef DISTANCEWIDGET_H
#define DISTANCEWIDGET_H

#include <limits>
#include <QWidget>
#include "GUI/widgets/abstractbasewidget.h"


namespace Ui {
class distanceWidget;
}

class distanceWidget : public abstractBaseWidget
{
    Q_OBJECT

public:
    explicit distanceWidget(QWidget *parent = 0);
    ~distanceWidget();
    void disableWidget(bool disable);
    float getValue();
    void setValue(float value);
    virtual void resizeWidget(QRect rect);
    virtual void clear();
    virtual void enableContent(bool flag);

public slots:
    virtual void updateContent();


signals:
    void changeDistance(double distance);
    void moveMeshToDistance(bool checked);


protected slots:
    void changeDistanceSlot();
    void moveMeshSlot(bool checked);

private:
    Ui::distanceWidget *ui;
};

#endif // DISTANCEWIDGET_H
