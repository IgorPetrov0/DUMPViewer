#ifndef TOOLTABSHORTINFOBOX_H
#define TOOLTABSHORTINFOBOX_H

#include "GUI/infobox.h"
#include "widgets/dumpviewerwidget.h"
#include "gameObject/meshobject.h"

namespace Ui {
class toolTabShortInfoBox;
}

class toolTabShortInfoBox : public dumpViewerWidget
{
    Q_OBJECT

public:
    explicit toolTabShortInfoBox(QWidget *parent = 0);
    void calculateMeshParameters(meshObject *object);
    ~toolTabShortInfoBox();
    void clear();


private:
    Ui::toolTabShortInfoBox *ui;
};

#endif // TOOLTABSHORTINFOBOX_H
