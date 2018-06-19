#ifndef TOOLTABINFOBOX_H
#define TOOLTABINFOBOX_H

#include <QFileDialog>
#include "widgets/dumpviewerwidget.h"
#include "gameObject/graphicobject.h"
#include "gameObject/phisycobject.h"
#


namespace Ui {
class toolTabInfoBox;
}

class toolTabInfoBox : public dumpViewerWidget
{
    Q_OBJECT

public:
    explicit toolTabInfoBox(QWidget *parent=0);

    ~toolTabInfoBox();
    void setFileName(QString fileName);
    void clear();
    void calculateMeshParameters(meshObject *mesh);

protected:
    void resizeEvent(QResizeEvent *event);



signals:
    void loadSignal();
    void deleteSignal();


private slots:
    void loadSlot();

private:
    Ui::toolTabInfoBox *ui;
};

#endif // TOOLTABINFOBOX_H
