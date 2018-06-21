#ifndef TOOLTABINFOBOX_H
#define TOOLTABINFOBOX_H

#include <QFileDialog>
#include "widgets/dumpviewerwidget.h"
#include "gameObject/graphicobject.h"
#include "gameObject/phisycobject.h"
#include "gameObject/editabelObjects/editabelgraphicobject.h"


namespace Ui {
class meshBox;
}

class meshBox : public dumpViewerWidget
{
    Q_OBJECT

public:
    explicit meshBox(QWidget *parent=0);

    ~meshBox();
    void setFileName(QString fileName);
    void clear();
    void setMesh(editabelGraphicObject *mesh);

protected:
    void resizeEvent(QResizeEvent *event);



signals:
    void loadSignal();
    void deleteSignal();


private slots:
    void loadSlot();

private:
    Ui::meshBox *ui;
};

#endif // TOOLTABINFOBOX_H
