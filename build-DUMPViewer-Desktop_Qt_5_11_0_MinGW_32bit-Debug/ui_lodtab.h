/********************************************************************************
** Form generated from reading UI file 'lodtab.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LODTAB_H
#define UI_LODTAB_H

#include <GUI/tooltabinfobox.h>
#include <GUI/widgets/distancewidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LODTab
{
public:
    toolTabInfoBox *LOD1InfoWidget;
    distanceWidget *LOD1DistanceWidget;

    void setupUi(QWidget *LODTab)
    {
        if (LODTab->objectName().isEmpty())
            LODTab->setObjectName(QStringLiteral("LODTab"));
        LODTab->resize(221, 898);
        LOD1InfoWidget = new toolTabInfoBox(LODTab);
        LOD1InfoWidget->setObjectName(QStringLiteral("LOD1InfoWidget"));
        LOD1InfoWidget->setGeometry(QRect(10, 10, 200, 201));
        LOD1DistanceWidget = new distanceWidget(LODTab);
        LOD1DistanceWidget->setObjectName(QStringLiteral("LOD1DistanceWidget"));
        LOD1DistanceWidget->setGeometry(QRect(10, 210, 200, 89));

        retranslateUi(LODTab);

        QMetaObject::connectSlotsByName(LODTab);
    } // setupUi

    void retranslateUi(QWidget *LODTab)
    {
        LODTab->setWindowTitle(QApplication::translate("LODTab", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LODTab: public Ui_LODTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LODTAB_H
