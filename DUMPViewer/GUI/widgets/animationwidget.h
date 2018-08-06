#ifndef ANIMATIONWIDGET_H
#define ANIMATIONWIDGET_H

#include "GUI/widgets/abstractbasewidget.h"

namespace Ui {
class animationWidget;
}

class animationWidget : public abstractBaseWidget
{
    Q_OBJECT

public:
    explicit animationWidget(QWidget *parent = 0);
    ~animationWidget();
    virtual void resizeWidget(QRect rect);
    virtual void clear();
    virtual void enableContent(bool flag);
    void setMeshType(const meshType &value);


public slots:
    virtual void updateContent();

protected:
    meshType type;
    editabelGraphicObject *getCurrentMesh();

private:
    Ui::animationWidget *ui;

private slots:
    void readAnimationData(int index);
    void moveSliderSlot(int value);

};

#endif // ANIMATIONWIDGET_H
