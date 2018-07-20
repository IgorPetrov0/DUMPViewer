#ifndef MESHTAB_H
#define MESHTAB_H

#include <QMessageBox>

#include "GUI/widgets/dvbasewidget.h"

namespace Ui {
class meshTab;
}

class meshTab : public dvBaseWidget
{
    Q_OBJECT

public:
    explicit meshTab(QWidget *parent);
    ~meshTab();
    virtual void setCorePointer(editorCore *core);
    virtual void updateContent();




private:
    Ui::meshTab *ui;

protected slots:
    void meshLoaded(editabelGraphicObject *mesh);
    void meshDeleted();

};

#endif // MESHTAB_H
