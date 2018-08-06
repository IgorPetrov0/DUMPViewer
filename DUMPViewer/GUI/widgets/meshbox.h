#ifndef TOOLTABINFOBOX_H
#define TOOLTABINFOBOX_H

#include <QFileDialog>
#include "GUI/widgets/abstractbasewidget.h"
#include "gameObject/graphicobject.h"
#include "gameObject/phisycobject.h"
#include "gameObject/editabelObjects/editabelgraphicobject.h"
#include "GUI/serviceWindows/dfiledialog.h"

namespace Ui {
class meshBox;
}

class meshBox : public abstractBaseWidget
{
    Q_OBJECT

public:
    explicit meshBox(QWidget *parent);
    ~meshBox();
    virtual void resizeWidget(QRect rect);
    virtual void clear();
    virtual void enableContent(bool flag);
    void setCorePointer(editorCore *pointer);
    void setMeshType(meshType type);


public slots:
    virtual void updateContent();

protected:
    meshType type;


private slots:
    void loadSlot();
    void deleteSlot();

private:
    Ui::meshBox *ui;




};

#endif // TOOLTABINFOBOX_H
