#ifndef DFILEDIALOG_H
#define DFILEDIALOG_H

#include <QFileDialog>
#include "application.h"

class dFileDialog : public QFileDialog
{
public:
    dFileDialog(QWidget *parent, const QString &caption, const QString & directory, const QString &filter, application *app);
    dFileDialog(QWidget *parent, Qt::WindowFlags flags);
    dFileDialog(application *app);

    static QString	getOpenFileName(application *app, const QString &caption=QString(), const QString &dir=QString(), const QString &filter=QString(), QString *selectedFilter=0, Options options=0);
    static QString	getSaveFileName(application *app, const QString &caption=QString(), const QString &dir=QString(), const QString &filter=QString(), QString *selectedFilter=0, Options options=0);
protected:
    application *app;
    static QString getPath(QString fileName);


};

#endif // DFILEDIALOG_H
