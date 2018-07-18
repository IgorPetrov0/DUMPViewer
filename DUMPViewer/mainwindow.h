#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QApplication>
#include <QMessageBox>
#include <QKeyEvent>
#include <QProgressBar>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <vector>
#include "GUI/toolWidget.h"
#include "viewwindow.h"
#include "GUI/serviceWindows/newgameobjectnamewindow.h"
#include "editorCore.h"
#include "gameObject/stream.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setCorePointer(editorCore *pointer);

    ~MainWindow();

protected:
    viewWindow *view;
    QString modelFileName;
    QString lastOpenDir;//TODO потом запоминать. пока будет папка приложения(задаем в конструкторе)
    QProgressBar *progressBar;
    QLabel *statusLable;
    toolWidget *tPanel;
    QPushButton *boundBoxButton;
    editorCore *core;


    void keyPressEvent(QKeyEvent *event);
    void resizeEvent(QResizeEvent *event);
    void setWidgetsGeometry();//устанавливает размер и положение виджетов
    void createStatusBar();//конфигурирование статус-бара
    void connections();
    void disableTools(bool disable);
    bool saveModelFile();

protected slots:
    void openModel();
    void openGameObjectSlot();
    bool saveGameObjectSlot();
    void saveGameObjectAsSlot();
    void newGameObjectSlot();
    void showBoundBoxSlot();
    void closeCurrentObjectSlot();
    void loadShaders();
    void someChanged();


signals:
    void updateTPanel();//сигнал для панели инструментов обновить информацию об объекте

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
