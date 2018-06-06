/********************************************************************************
** Form generated from reading UI file 'rigidbodieswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RIGIDBODIESWIDGET_H
#define UI_RIGIDBODIESWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rigidBodiesWidget
{
public:
    QGroupBox *groupBox;
    QListView *ridgidBodiesList;
    QGroupBox *groupBox_2;
    QLabel *label;
    QDoubleSpinBox *massSpinBox;
    QGroupBox *groupBox_3;
    QDoubleSpinBox *massCenterXSpinBox;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *massCenterYSpinBox;
    QLabel *label_4;
    QDoubleSpinBox *massCenterZSpinBox;

    void setupUi(QWidget *rigidBodiesWidget)
    {
        if (rigidBodiesWidget->objectName().isEmpty())
            rigidBodiesWidget->setObjectName(QStringLiteral("rigidBodiesWidget"));
        rigidBodiesWidget->resize(200, 455);
        groupBox = new QGroupBox(rigidBodiesWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 181, 451));
        ridgidBodiesList = new QListView(groupBox);
        ridgidBodiesList->setObjectName(QStringLiteral("ridgidBodiesList"));
        ridgidBodiesList->setGeometry(QRect(10, 20, 161, 192));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 220, 161, 221));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(9, 22, 71, 21));
        massSpinBox = new QDoubleSpinBox(groupBox_2);
        massSpinBox->setObjectName(QStringLiteral("massSpinBox"));
        massSpinBox->setGeometry(QRect(80, 20, 71, 22));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 50, 141, 101));
        massCenterXSpinBox = new QDoubleSpinBox(groupBox_3);
        massCenterXSpinBox->setObjectName(QStringLiteral("massCenterXSpinBox"));
        massCenterXSpinBox->setGeometry(QRect(50, 20, 81, 22));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 41, 21));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 43, 51, 21));
        massCenterYSpinBox = new QDoubleSpinBox(groupBox_3);
        massCenterYSpinBox->setObjectName(QStringLiteral("massCenterYSpinBox"));
        massCenterYSpinBox->setGeometry(QRect(50, 43, 81, 22));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 66, 51, 21));
        massCenterZSpinBox = new QDoubleSpinBox(groupBox_3);
        massCenterZSpinBox->setObjectName(QStringLiteral("massCenterZSpinBox"));
        massCenterZSpinBox->setGeometry(QRect(50, 66, 81, 22));

        retranslateUi(rigidBodiesWidget);

        QMetaObject::connectSlotsByName(rigidBodiesWidget);
    } // setupUi

    void retranslateUi(QWidget *rigidBodiesWidget)
    {
        rigidBodiesWidget->setWindowTitle(QApplication::translate("rigidBodiesWidget", "Form", 0));
        groupBox->setTitle(QApplication::translate("rigidBodiesWidget", "Rigid bodies", 0));
        groupBox_2->setTitle(QApplication::translate("rigidBodiesWidget", "Properties", 0));
        label->setText(QApplication::translate("rigidBodiesWidget", "Mass", 0));
        groupBox_3->setTitle(QApplication::translate("rigidBodiesWidget", "Mass center", 0));
        label_2->setText(QApplication::translate("rigidBodiesWidget", "X pos", 0));
        label_3->setText(QApplication::translate("rigidBodiesWidget", "Y pos", 0));
        label_4->setText(QApplication::translate("rigidBodiesWidget", "Z pos", 0));
    } // retranslateUi

};

namespace Ui {
    class rigidBodiesWidget: public Ui_rigidBodiesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RIGIDBODIESWIDGET_H
