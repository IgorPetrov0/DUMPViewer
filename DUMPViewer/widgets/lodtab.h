#ifndef LODTAB_H
#define LODTAB_H

#include <QTableWidget>
#include "widgets/tabbar.h"
#include "serviceWindows/dfiledialog.h"

namespace Ui {
class LODTab;
}

class LODTab : public dTabBar
{
    Q_OBJECT

public:
    explicit LODTab(QTabWidget *parent = 0);
    ~LODTab();
    void setTabNumber(unsigned int number);
    void setLODNumber(unsigned int number);
    unsigned int getTabNumber();
    unsigned int getLODNumber();
    bool isLODDefined();

signals:
    void deleteSignal(unsigned int tabNumber, unsigned int LODNumber);

private:
    Ui::LODTab *ui;

protected:
    void createTab();
    void deleteLod();
    unsigned int tabNumber;
    unsigned int LODNumber;
    editableLOD *lodPointer;

protected slots:
    void loadSlot();
    void deleteSlot();
    void setLodDistance(double value);
    void moveToDistanceSlot();
    void updateInfoSlot();
};

#endif // LODTAB_H
