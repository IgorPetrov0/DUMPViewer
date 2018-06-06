/********************************************************************************
** Form generated from reading UI file 'ridgidbodypropertyeswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RIDGIDBODYPROPERTYESWIDGET_H
#define UI_RIDGIDBODYPROPERTYESWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ridgidBodyPropertyesWidget
{
public:
    QLabel *label;
    QDoubleSpinBox *massSpinBox;
    QGroupBox *groupBox;
    QDoubleSpinBox *massCenterXSpinBox;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *massCenterYSpinBox;
    QLabel *label_4;
    QDoubleSpinBox *massCenterZSpinBox;

    void setupUi(QWidget *ridgidBodyPropertyesWidget)
    {
        if (ridgidBodyPropertyesWidget->objectName().isEmpty())
            ridgidBodyPropertyesWidget->setObjectName(QStringLiteral("ridgidBodyPropertyesWidget"));
        ridgidBodyPropertyesWidget->resize(179, 151);
        label = new QLabel(ridgidBodyPropertyesWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(9, 12, 71, 21));
        massSpinBox = new QDoubleSpinBox(ridgidBodyPropertyesWidget);
        massSpinBox->setObjectName(QStringLiteral("massSpinBox"));
        massSpinBox->setGeometry(QRect(80, 10, 91, 22));
        groupBox = new QGroupBox(ridgidBodyPropertyesWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 161, 101));
        massCenterXSpinBox = new QDoubleSpinBox(groupBox);
        massCenterXSpinBox->setObjectName(QStringLiteral("massCenterXSpinBox"));
        massCenterXSpinBox->setGeometry(QRect(50, 20, 61, 22));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 41, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 43, 51, 21));
        massCenterYSpinBox = new QDoubleSpinBox(groupBox);
        massCenterYSpinBox->setObjectName(QStringLiteral("massCenterYSpinBox"));
        massCenterYSpinBox->setGeometry(QRect(70, 43, 61, 22));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 66, 51, 21));
        massCenterZSpinBox = new QDoubleSpinBox(groupBox);
        massCenterZSpinBox->setObjectName(QStringLiteral("massCenterZSpinBox"));
        massCenterZSpinBox->setGeometry(QRect(90, 66, 61, 22));

        retranslateUi(ridgidBodyPropertyesWidget);

        QMetaObject::connectSlotsByName(ridgidBodyPropertyesWidget);
    } // setupUi

    void retranslateUi(QWidget *ridgidBodyPropertyesWidget)
    {
        ridgidBodyPropertyesWidget->setWindowTitle(QApplication::translate("ridgidBodyPropertyesWidget", "Form", 0));
        label->setText(QApplication::translate("ridgidBodyPropertyesWidget", "Mass", 0));
        groupBox->setTitle(QApplication::translate("ridgidBodyPropertyesWidget", "Mass center", 0));
        label_2->setText(QApplication::translate("ridgidBodyPropertyesWidget", "X pos", 0));
        label_3->setText(QApplication::translate("ridgidBodyPropertyesWidget", "Y pos", 0));
        label_4->setText(QApplication::translate("ridgidBodyPropertyesWidget", "Z pos", 0));
    } // retranslateUi

};

namespace Ui {
    class ridgidBodyPropertyesWidget: public Ui_ridgidBodyPropertyesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RIDGIDBODYPROPERTYESWIDGET_H
