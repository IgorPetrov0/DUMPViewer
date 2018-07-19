#ifndef DVBASEWIDGET_H
#define DVBASEWIDGET_H

//задача: создать базовый виджет со следующим функционалом:
//1)вертикальный скроллбар появлется, когда виджеты не помещаются в размеры
//2)наследники меняют размеры в зависимости от размеров родителя
//3)добавляется указатель на ядро приложения
//4)виджеты передают и получают данные по иерархии


#include <QVector>
#include <QRect>
#include <QScrollBar>
#include <QPushButton>
#include "editorCore.h"
#include "abstractbasewidget.h"


class dvBaseWidget : public  abstractBaseWidget
{
    Q_OBJECT

public:
    dvBaseWidget(QWidget *parent);
    ~dvBaseWidget();
    virtual void setCorePointer(editorCore *corePointer);
    virtual void setPosition(int x,int y);
    virtual void updateContent();
    virtual void resizeWidget(QRect rect);
    void addWidget(abstractBaseWidget *widget);

protected:
    editorCore *core;
    QVector<abstractBaseWidget*> widgetsArray;
    QScrollBar *scrollBar;
    int contentHeigth;
    void resizeEvent(QResizeEvent *event);
    void calculateScrollBar();
    void calculateContentHeigth();

protected slots:
    void scrollSlot(int value);



};

#endif // DVBASEWIDGET_H
