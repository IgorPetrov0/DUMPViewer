/********************************************************************************
** Form generated from reading UI file 'constraintstab.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSTRAINTSTAB_H
#define UI_CONSTRAINTSTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_constraintsTab
{
public:
    QGroupBox *groupBox_2;
    QListView *constraintsType;
    QComboBox *constraintsTypeComboBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *bodyAComboBox;
    QComboBox *bodyBComboBox;
    QLabel *label_3;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QRadioButton *showConstraintsRadioButton;
    QGroupBox *propertiesBox;

    void setupUi(QWidget *constraintsTab)
    {
        if (constraintsTab->objectName().isEmpty())
            constraintsTab->setObjectName(QStringLiteral("constraintsTab"));
        constraintsTab->resize(221, 1080);
        groupBox_2 = new QGroupBox(constraintsTab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 191, 351));
        constraintsType = new QListView(groupBox_2);
        constraintsType->setObjectName(QStringLiteral("constraintsType"));
        constraintsType->setGeometry(QRect(10, 20, 171, 201));
        constraintsTypeComboBox = new QComboBox(groupBox_2);
        constraintsTypeComboBox->setObjectName(QStringLiteral("constraintsTypeComboBox"));
        constraintsTypeComboBox->setGeometry(QRect(58, 260, 121, 22));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 260, 47, 13));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 290, 47, 13));
        bodyAComboBox = new QComboBox(groupBox_2);
        bodyAComboBox->setObjectName(QStringLiteral("bodyAComboBox"));
        bodyAComboBox->setGeometry(QRect(60, 290, 121, 22));
        bodyBComboBox = new QComboBox(groupBox_2);
        bodyBComboBox->setObjectName(QStringLiteral("bodyBComboBox"));
        bodyBComboBox->setGeometry(QRect(60, 320, 121, 22));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 320, 47, 13));
        addButton = new QPushButton(groupBox_2);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(10, 230, 75, 23));
        deleteButton = new QPushButton(groupBox_2);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(100, 230, 75, 23));
        showConstraintsRadioButton = new QRadioButton(constraintsTab);
        showConstraintsRadioButton->setObjectName(QStringLiteral("showConstraintsRadioButton"));
        showConstraintsRadioButton->setGeometry(QRect(20, 0, 121, 17));
        propertiesBox = new QGroupBox(constraintsTab);
        propertiesBox->setObjectName(QStringLiteral("propertiesBox"));
        propertiesBox->setGeometry(QRect(10, 380, 191, 341));

        retranslateUi(constraintsTab);

        QMetaObject::connectSlotsByName(constraintsTab);
    } // setupUi

    void retranslateUi(QWidget *constraintsTab)
    {
        constraintsTab->setWindowTitle(QApplication::translate("constraintsTab", "Form", 0));
        groupBox_2->setTitle(QApplication::translate("constraintsTab", "Constraints list", 0));
        label->setText(QApplication::translate("constraintsTab", "Type:", 0));
        label_2->setText(QApplication::translate("constraintsTab", "Body A", 0));
        label_3->setText(QApplication::translate("constraintsTab", "Body B", 0));
        addButton->setText(QApplication::translate("constraintsTab", "Add", 0));
        deleteButton->setText(QApplication::translate("constraintsTab", "Delete", 0));
        showConstraintsRadioButton->setText(QApplication::translate("constraintsTab", "Show constraints", 0));
        propertiesBox->setTitle(QApplication::translate("constraintsTab", "Properties", 0));
    } // retranslateUi

};

namespace Ui {
    class constraintsTab: public Ui_constraintsTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSTRAINTSTAB_H
