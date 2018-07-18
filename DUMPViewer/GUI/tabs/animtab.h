#ifndef ANIMTAB_H
#define ANIMTAB_H

#include <QWidget>
#include "GUI/tabs/tabbar.h"
#include "editorCore.h"


namespace Ui {
class animTab;
}

class animTab : public QWidget
{
    Q_OBJECT

public:
    explicit animTab(QWidget *parent = 0);
    ~animTab();   
    void setCorePointer(editorCore *value);

protected:
    editorCore *core;

protected slots:
    void selectAnimation(QString name);
    void updateInfoSlot();


private:
    Ui::animTab *ui;
};

#endif // ANIMTAB_H
