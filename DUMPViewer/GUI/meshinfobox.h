#ifndef MESHINFOBOX_H
#define MESHINFOBOX_H

#include <glm/glm.hpp>
#include "GUI/widgets/dvbasewidget.h"
#include "widgets/abstractbasewidget.h"
#include "gameObject/editabelObjects/editabelgraphicobject.h"

namespace Ui {
class meshInfoBox;
}

class meshInfoBox : public abstractBaseWidget
{
    Q_OBJECT

public:
    explicit meshInfoBox(QWidget *parent);
    ~meshInfoBox();
    void setMesh(editabelGraphicObject *value);
    virtual void resizeWidget(QRect rect);
    virtual void clear();
    virtual void enableContent(bool flag);


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

public slots:
    virtual void updateContent(abstractBaseWidget* widget);



private:
    Ui::meshInfoBox *ui;
};

#endif // MESHINFOBOX_H
