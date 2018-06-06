/********************************************************************************
** Form generated from reading UI file 'conetwistwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONETWISTWIDGET_H
#define UI_CONETWISTWIDGET_H

#include <GUI/widgets/constraintPropertiesWidgets/transformwidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_coneTwistWidget
{
public:
    transformWidget *transformAWidget;
    transformWidget *transformBWidget;

    void setupUi(QWidget *coneTwistWidget)
    {
        if (coneTwistWidget->objectName().isEmpty())
            coneTwistWidget->setObjectName(QStringLiteral("coneTwistWidget"));
        coneTwistWidget->resize(191, 339);
        transformAWidget = new transformWidget(coneTwistWidget);
        transformAWidget->setObjectName(QStringLiteral("transformAWidget"));
        transformAWidget->setGeometry(QRect(10, 10, 176, 157));
        transformBWidget = new transformWidget(coneTwistWidget);
        transformBWidget->setObjectName(QStringLiteral("transformBWidget"));
        transformBWidget->setGeometry(QRect(10, 170, 176, 157));

        retranslateUi(coneTwistWidget);

        QMetaObject::connectSlotsByName(coneTwistWidget);
    } // setupUi

    void retranslateUi(QWidget *coneTwistWidget)
    {
        coneTwistWidget->setWindowTitle(QApplication::translate("coneTwistWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class coneTwistWidget: public Ui_coneTwistWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONETWISTWIDGET_H
