#ifndef rigidBodiesWidget_H
#define rigidBodiesWidget_H

#include <QWidget>

namespace Ui {
class rigidBodiesWidget;
}

class rigidBodiesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit rigidBodiesWidget(QWidget *parent = 0);
    ~rigidBodiesWidget();

protected:



private:
    Ui::rigidBodiesWidget *ui;
};

#endif // rigidBodiesWidget_H
