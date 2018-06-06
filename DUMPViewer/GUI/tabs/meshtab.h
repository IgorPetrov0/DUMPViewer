#ifndef MESHTAB_H
#define MESHTAB_H

#include <QMessageBox>
#include "GUI/serviceWindows/dfiledialog.h"
#include "GUI/tabs/tabbar.h"

namespace Ui {
class meshTab;
}

class meshTab : public dTabBar
{
    Q_OBJECT

public:
    explicit meshTab(QTabWidget *parent = 0);
    void resetTab();
    ~meshTab();




private:
    Ui::meshTab *ui;
    void createTab();

protected slots:
    void loadMeshSlot();
    void mainMeshDeleteSlot();
    void updateInfoSlot();

};

#endif // MESHTAB_H
