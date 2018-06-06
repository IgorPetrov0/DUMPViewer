#ifndef DFILEDIALOG_H
#define DFILEDIALOG_H

#include <QFileDialog>
#include "editorCore.h"

class dFileDialog : public QFileDialog
{
public:
    dFileDialog(QWidget *parent, const QString &caption, const QString & directory, const QString &filter, editorCore *app);
    dFileDialog(QWidget *parent, Qt::WindowFlags flags);
    dFileDialog(editorCore *app);

    static QString	getOpenFileName(editorCore *app, const QString &caption=QString(), const QString &dir=QString(), const QString &filter=QString(), QString *selectedFilter=0, Options options=0);
    static QString	getSaveFileName(editorCore *app, const QString &caption=QString(), const QString &dir=QString(), const QString &filter=QString(), QString *selectedFilter=0, Options options=0);
protected:
    editorCore *app;
    static QString getPath(QString fileName);


};

#endif // DFILEDIALOG_H
