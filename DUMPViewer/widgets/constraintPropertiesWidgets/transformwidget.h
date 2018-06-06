#ifndef TRANSFORMWIDGET_H
#define TRANSFORMWIDGET_H

#include <QWidget>

namespace Ui {
class transformWidget;
}

class transformWidget : public QWidget
{
    Q_OBJECT

public:
    explicit transformWidget(QWidget *parent = 0);
    void setFrameTitle(QString text);
    ~transformWidget();

private:
    Ui::transformWidget *ui;
};

#endif // TRANSFORMWIDGET_H
