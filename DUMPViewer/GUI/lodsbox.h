#ifndef LODSBOX_H
#define LODSBOX_H

#include <QWidget>

enum lodName{
    LOD_1,
    LOD_2,
    LOD_3
};



namespace Ui {
class lodsBox;
}

class lodsBox : public QWidget
{
    Q_OBJECT

public:
    explicit lodsBox(QWidget *parent=0);
    ~lodsBox();

private:
    Ui::lodsBox *ui;
};

#endif // LODSBOX_H
