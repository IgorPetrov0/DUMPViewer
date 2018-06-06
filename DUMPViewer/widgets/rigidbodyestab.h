#ifndef RIGIDBODYESTAB_H
#define RIGIDBODYESTAB_H

#include <QListWidgetItem>
#include "serviceWindows/dfiledialog.h"
#include "widgets/tabbar.h"
#include "gameObject/rigidbody.h"


namespace Ui {
class rigidBodyesTab;
}

class rigidBodyesTab : public dTabBar
{
    Q_OBJECT

public:
    explicit rigidBodyesTab(QTabWidget *parent = 0);
    ~rigidBodyesTab();
    void updateList();

private:
    Ui::rigidBodyesTab *ui;
    rigidBody *currentBody;


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
