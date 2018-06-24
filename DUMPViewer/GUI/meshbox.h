#ifndef TOOLTABINFOBOX_H
#define TOOLTABINFOBOX_H

#include <QFileDialog>
#include "widgets/dumpviewerwidget.h"
#include "gameObject/graphicobject.h"
#include "gameObject/phisycobject.h"
#include "gameObject/editabelObjects/editabelgraphicobject.h"
#include "GUI/serviceWindows/dfiledialog.h"

namespace Ui {
class meshBox;
}

class meshBox : public dumpViewerWidget
{
    Q_OBJECT

public:
    explicit meshBox(QWidget *parent);
    ~meshBox();
    void clear();
    void setCorePointer(editorCore *pointer);

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void loadSlot();
    void deleteSlot();

private:
    Ui::meshBox *ui;

signals:
    void meshLoaded(editabelGraphicObject *mesh);
    void meshDeleted();


};

#endif // TOOLTABINFOBOX_H
