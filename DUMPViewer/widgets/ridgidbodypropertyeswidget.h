#ifndef RIDGIDBODYPROPERTYESWIDGET_H
#define RIDGIDBODYPROPERTYESWIDGET_H

#include <QWidget>

namespace Ui {
class ridgidBodyPropertyesWidget;
}

class ridgidBodyPropertyesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ridgidBodyPropertyesWidget(QWidget *parent = 0);
    ~ridgidBodyPropertyesWidget();

private:
    Ui::ridgidBodyPropertyesWidget *ui;
};

#endif // RIDGIDBODYPROPERTYESWIDGET_H
