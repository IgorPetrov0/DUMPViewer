#ifndef NEWGAMEOBJECTNAMEWINDOW_H
#define NEWGAMEOBJECTNAMEWINDOW_H

#include <QDialog>

namespace Ui {
class newGameObjectNameWindow;
}

class newGameObjectNameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit newGameObjectNameWindow(QWidget *parent = 0);
    ~newGameObjectNameWindow();
    QString getName();
    void setDefaultName(QString name);

protected slots:
    void okClicked(bool state);
    void canselClicked(bool state);



private:
    Ui::newGameObjectNameWindow *ui;
};

#endif // NEWGAMEOBJECTNAMEWINDOW_H
