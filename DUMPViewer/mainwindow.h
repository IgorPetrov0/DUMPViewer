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
#include "GUI/toolWidget.h"
#include "viewwindow.h"
#include "objectCompiller/objectcompiller.h"
#include "GUI/serviceWindows/newgameobjectnamewindow.h"
#include "application.h"
#include "gameObject/stream.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

protected:
    viewWindow *view;
    QString modelFileName;
    QString lastOpenDir;//TODO потом запоминать. пока будет папка приложения(задаем в конструкторе)
    QProgressBar *progressBar;
    QLabel *statusLable;
    toolWidget *tPanel;
    QPushButton *boundBoxButton;
    application *app;


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

signals:
    void objectLoaded();//сигнал для дочерних виджетов обновить информацию об объекте

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
