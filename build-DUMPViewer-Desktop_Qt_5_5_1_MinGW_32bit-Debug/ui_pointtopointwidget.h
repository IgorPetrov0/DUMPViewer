/********************************************************************************
** Form generated from reading UI file 'pointtopointwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTTOPOINTWIDGET_H
#define UI_POINTTOPOINTWIDGET_H

#include <GUI/widgets/constraintPropertiesWidgets/pivotwidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pointToPointWidget
{
public:
    pivotWidget *pivotAWidget;
    pivotWidget *pivotBWidget;

    void setupUi(QWidget *pointToPointWidget)
    {
        if (pointToPointWidget->objectName().isEmpty())
            pointToPointWidget->setObjectName(QStringLiteral("pointToPointWidget"));
        pointToPointWidget->resize(191, 278);
        pivotAWidget = new pivotWidget(pointToPointWidget);
        pivotAWidget->setObjectName(QStringLiteral("pivotAWidget"));
        pivotAWidget->setGeometry(QRect(5, 10, 176, 127));
        pivotBWidget = new pivotWidget(pointToPointWidget);
        pivotBWidget->setObjectName(QStringLiteral("pivotBWidget"));
        pivotBWidget->setGeometry(QRect(5, 140, 176, 127));

        retranslateUi(pointToPointWidget);

        QMetaObject::connectSlotsByName(pointToPointWidget);
    } // setupUi

    void retranslateUi(QWidget *pointToPointWidget)
    {
        pointToPointWidget->setWindowTitle(QApplication::translate("pointToPointWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class pointToPointWidget: public Ui_pointToPointWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTTOPOINTWIDGET_H
