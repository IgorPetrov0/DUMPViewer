#include "dfiledialog.h"

dFileDialog::dFileDialog(QWidget *parent, const QString &caption, const QString &directory, const QString &filter, editorCore *app):
    QFileDialog(parent, caption, directory, filter)
{
    this->app=app;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
dFileDialog::dFileDialog(QWidget *parent, Qt::WindowFlags flags):
    QFileDialog(parent,flags)
{
    this->app=app;
}
///////////////////////////////////////////////////////////////////////
dFileDialog::dFileDialog(editorCore *app){
    this->app=app;
}
/////////////////////////////////////////////////////////////////////////
QString	dFileDialog::getOpenFileName(editorCore *app, const QString &caption, const QString &dir, const QString &filter, QString *selectedFilter, Options options){
    QString file=QFileDialog::getOpenFileName(app->mainWindowPointer(),caption,dir,filter,selectedFilter,options);
    app->setCurrentPath(getPath(file));
    return file;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QString	dFileDialog::getSaveFileName(editorCore *app, const QString &caption, const QString &dir, const QString &filter, QString *selectedFilter, Options options){
    QString file=QFileDialog::getSaveFileName(app->mainWindowPointer(),caption,dir,filter,selectedFilter,options);
    app->setCurrentPath(getPath(file));
    return file;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
QString dFileDialog::getPath(QString fileName){
    if(!fileName.isEmpty()){
        QFileInfo fi(fileName);
        return fi.absolutePath();
    }
    return QString();
}
