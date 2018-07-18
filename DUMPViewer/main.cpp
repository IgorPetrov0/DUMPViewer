#include <QApplication>
#include "mainwindow.h"
#include "editorCore.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    editorCore core;
    MainWindow w;
    w.setCorePointer(&core);
    w.show();
    w.resize(w.width()-1,w.height()-1);

    return a.exec();
}
