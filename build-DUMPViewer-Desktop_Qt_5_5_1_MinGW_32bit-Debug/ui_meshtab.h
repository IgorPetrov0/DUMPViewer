/********************************************************************************
** Form generated from reading UI file 'meshtab.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESHTAB_H
#define UI_MESHTAB_H

#include <GUI/tooltabinfobox.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_meshTab
{
public:
    toolTabInfoBox *meshInfoWidget;

    void setupUi(QWidget *meshTab)
    {
        if (meshTab->objectName().isEmpty())
            meshTab->setObjectName(QStringLiteral("meshTab"));
        meshTab->resize(221, 898);
        meshInfoWidget = new toolTabInfoBox(meshTab);
        meshInfoWidget->setObjectName(QStringLiteral("meshInfoWidget"));
        meshInfoWidget->setGeometry(QRect(10, 10, 200, 201));

        retranslateUi(meshTab);

        QMetaObject::connectSlotsByName(meshTab);
    } // setupUi

    void retranslateUi(QWidget *meshTab)
    {
        meshTab->setWindowTitle(QApplication::translate("meshTab", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class meshTab: public Ui_meshTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESHTAB_H
