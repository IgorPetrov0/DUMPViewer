/********************************************************************************
** Form generated from reading UI file 'meshtab.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESHTAB_H
#define UI_MESHTAB_H

#include <GUI/meshbox.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_meshTab
{
public:
    meshBox *meshInfoWidget;

    void setupUi(QWidget *meshTab)
    {
        if (meshTab->objectName().isEmpty())
            meshTab->setObjectName(QStringLiteral("meshTab"));
        meshTab->resize(221, 898);
        meshInfoWidget = new meshBox(meshTab);
        meshInfoWidget->setObjectName(QStringLiteral("meshInfoWidget"));
        meshInfoWidget->setGeometry(QRect(10, 10, 200, 341));

        retranslateUi(meshTab);

        QMetaObject::connectSlotsByName(meshTab);
    } // setupUi

    void retranslateUi(QWidget *meshTab)
    {
        meshTab->setWindowTitle(QApplication::translate("meshTab", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class meshTab: public Ui_meshTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESHTAB_H
