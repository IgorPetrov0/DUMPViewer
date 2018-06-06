#ifndef PIVOTWIDGET_H
#define PIVOTWIDGET_H

#include <QWidget>
#include "mathPrimitives/vector3.h"

namespace Ui {
class pivotWidget;
}

class pivotWidget : public QWidget
{
    Q_OBJECT

public:
    explicit pivotWidget(QWidget *parent = 0);
    ~pivotWidget();
    void setPivot(vector3 coordinates);
    vector3 getPivot();
    void setPivotFrameName(QString name);

signals:
    void valuesChanged(vector2 coordinates);


protected:


protected slots:
    void changeValues(double value);


private:
    Ui::pivotWidget *ui;
};

#endif // PIVOTWIDGET_H
