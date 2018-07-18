#ifndef LODTAB_H
#define LODTAB_H

#include <QTableWidget>
#include "GUI/tabs/tabbar.h"
#include "GUI/serviceWindows/dfiledialog.h"

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
    meshType getLodType();
    bool isLODDefined();
    void setCorePointer(editorCore *pointer);

signals:
    void deleteSignal(unsigned int tabNumber, unsigned int LODNumber);

private:
    Ui::LODTab *ui;

protected:
    unsigned int tabNumber;
    unsigned int LODNumber;
    editableLOD *lodPointer;

protected slots:
    void meshLoaded(editabelGraphicObject *mesh);
    void meshDeleted();
    void setLodDistance(double value);
    void moveToDistanceSlot();
    void updateInfoSlot();
};

#endif // LODTAB_H
