#ifndef MESHTAB_H
#define MESHTAB_H

#include <QMessageBox>

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
    void setCorePointer(editorCore *pointer);
    void updateInfo();


private:
    Ui::meshTab *ui;

protected slots:
    void meshLoaded(editabelGraphicObject *mesh);
    void meshDeleted();

};

#endif // MESHTAB_H
