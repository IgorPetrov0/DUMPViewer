#ifndef TOOLWIDGET_H
#define TOOLWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "gameObject/editabelObjects/editabelgameobject.h"
#include "GUI/tabs/lodtab.h"
#include "editorCore.h"

namespace Ui {
class toolWidget;
}

class toolWidget : public QWidget
{
    Q_OBJECT

public:
    explicit toolWidget(QWidget *parent);
    void setCorePointer(editorCore *core);
    void disableToolPanel(bool disable);
    void resetToolPanel();
    void createLODTab(LOD *lod);
    void update();//обновляет информацию
    ~toolWidget();

signals:
    void updateInfo();

protected:
    void resizeEvent(QResizeEvent *event);
    void clearLODTabsArray();
    QVector<LODTab*>LODTabsArray;
    editorCore *core;


protected slots:
    void graphicTabSelectedSlot(int index);
    void LODTabDeleteSlot(unsigned int tabIndex, unsigned int LODNumber);
    void updateInfoSlot();


private:
    Ui::toolWidget *ui;
};

#endif // TOOLWIDGET_H
