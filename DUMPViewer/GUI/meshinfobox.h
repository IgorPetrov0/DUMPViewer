#ifndef MESHINFOBOX_H
#define MESHINFOBOX_H

#include <glm/glm.hpp>
#include "GUI/infobox.h"
#include "widgets/dumpviewerwidget.h"
#include "gameObject/editabelObjects/editabelgraphicobject.h"

namespace Ui {
class meshInfoBox;
}

class meshInfoBox : public dumpViewerWidget
{
    Q_OBJECT

public:
    explicit meshInfoBox(QWidget *parent = 0);  
    ~meshInfoBox();
    void clear();
    void setMesh(editabelGraphicObject *value);

protected:
    editabelGraphicObject *mesh;
    void calculateMeshParameters();

protected slots:
    void posXChange(double value);
    void posYChange(double value);
    void posZChange(double value);

    void rotXChange(double value);
    void rotYChange(double value);
    void rotZChange(double value);

    void scaleXChange(double value);
    void scaleYChange(double value);
    void scaleZChange(double value);


private:
    Ui::meshInfoBox *ui;
};

#endif // MESHINFOBOX_H
