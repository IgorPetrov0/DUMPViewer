#ifndef ANIMTAB_H
#define ANIMTAB_H

#include "GUI/abstractwidget.h"
#include "GUI/tabs/tabbar.h"
#include "editorCore.h"


namespace Ui {
class animTab;
}

class animTab : public abstractWidget
{
    Q_OBJECT

public:
    explicit animTab(QWidget *parent = 0);
    ~animTab();   
    void setCorePointer(editorCore *value);
    void updateInfo();

protected:
    editorCore *core;

protected slots:
    void selectAnimation(QString name);



private:
    Ui::animTab *ui;
};

#endif // ANIMTAB_H
