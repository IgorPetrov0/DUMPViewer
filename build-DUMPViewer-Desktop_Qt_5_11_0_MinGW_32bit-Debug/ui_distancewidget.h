/********************************************************************************
** Form generated from reading UI file 'distancewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISTANCEWIDGET_H
#define UI_DISTANCEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_distanceWidget
{
public:
    QGroupBox *groupBox;
    QDoubleSpinBox *distanceSpinBox;
    QPushButton *moveButton;

    void setupUi(QWidget *distanceWidget)
    {
        if (distanceWidget->objectName().isEmpty())
            distanceWidget->setObjectName(QStringLiteral("distanceWidget"));
        distanceWidget->resize(200, 89);
        groupBox = new QGroupBox(distanceWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(1, 1, 181, 81));
        distanceSpinBox = new QDoubleSpinBox(groupBox);
        distanceSpinBox->setObjectName(QStringLiteral("distanceSpinBox"));
        distanceSpinBox->setGeometry(QRect(10, 20, 161, 22));
        distanceSpinBox->setDecimals(4);
        moveButton = new QPushButton(groupBox);
        moveButton->setObjectName(QStringLiteral("moveButton"));
        moveButton->setGeometry(QRect(10, 50, 161, 23));

        retranslateUi(distanceWidget);

        QMetaObject::connectSlotsByName(distanceWidget);
    } // setupUi

    void retranslateUi(QWidget *distanceWidget)
    {
        distanceWidget->setWindowTitle(QApplication::translate("distanceWidget", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("distanceWidget", "Distance", nullptr));
        moveButton->setText(QApplication::translate("distanceWidget", "Move to distance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class distanceWidget: public Ui_distanceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISTANCEWIDGET_H
