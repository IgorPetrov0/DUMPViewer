#ifndef RIGIDBODYESTAB_H
#define RIGIDBODYESTAB_H

#include <QListWidgetItem>
#include "GUI/serviceWindows/dfiledialog.h"
#include "gameObject/rigidbody.h"


namespace Ui {
class rigidBodyesTab;
}

class rigidBodyesTab : public QWidget
{
    Q_OBJECT

public:
    explicit rigidBodyesTab(QWidget *parent = 0);
    ~rigidBodyesTab();
    void updateList();

private:
    Ui::rigidBodyesTab *ui;
    rigidBody *currentBody;

    void setCurrentBody(rigidBody *body);
    void createTab();
    void configureSourceComboBox();
    void connectAll();
    void disconnectAll();

protected slots:
    void updateInfoSlot();
    void addSlot();
    void deleteSlot();
    void bodyChangeSlot();
    void nameChangedSlot();
    void setMassSlot(double value);
    void setMassCenterSlot();
    void setTypeSlot(int type);


};

#endif // RIGIDBODYESTAB_H
