/********************************************************************************
** Form generated from reading UI file 'rigidbodyestab.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RIGIDBODYESTAB_H
#define UI_RIGIDBODYESTAB_H

#include <GUI/tooltabshortinfobox.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rigidBodyesTab
{
public:
    QComboBox *typeComboBox;
    toolTabShortInfoBox *meshInfoWidget;
    QRadioButton *showRigidBodyRadioButton;
    QGroupBox *rigidBodyesGroup;
    QGroupBox *addGroup;
    QComboBox *meshSourceComboBox;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QListWidget *rigidBodiesList;
    QGroupBox *massGroup;
    QDoubleSpinBox *massSpinBox;
    QGroupBox *massCenterGroup;
    QDoubleSpinBox *massCenterXSpinBox;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *massCenterYSpinBox;
    QLabel *label_6;
    QDoubleSpinBox *massCenterZSpinBox;
    QPushButton *geometricCenterButton;

    void setupUi(QWidget *rigidBodyesTab)
    {
        if (rigidBodyesTab->objectName().isEmpty())
            rigidBodyesTab->setObjectName(QStringLiteral("rigidBodyesTab"));
        rigidBodyesTab->resize(221, 728);
        typeComboBox = new QComboBox(rigidBodyesTab);
        typeComboBox->setObjectName(QStringLiteral("typeComboBox"));
        typeComboBox->setGeometry(QRect(10, 360, 191, 22));
        meshInfoWidget = new toolTabShortInfoBox(rigidBodyesTab);
        meshInfoWidget->setObjectName(QStringLiteral("meshInfoWidget"));
        meshInfoWidget->setGeometry(QRect(10, 390, 191, 140));
        meshInfoWidget->setContextMenuPolicy(Qt::NoContextMenu);
        showRigidBodyRadioButton = new QRadioButton(rigidBodyesTab);
        showRigidBodyRadioButton->setObjectName(QStringLiteral("showRigidBodyRadioButton"));
        showRigidBodyRadioButton->setGeometry(QRect(10, 10, 121, 17));
        rigidBodyesGroup = new QGroupBox(rigidBodyesTab);
        rigidBodyesGroup->setObjectName(QStringLiteral("rigidBodyesGroup"));
        rigidBodyesGroup->setGeometry(QRect(10, 30, 191, 321));
        addGroup = new QGroupBox(rigidBodyesGroup);
        addGroup->setObjectName(QStringLiteral("addGroup"));
        addGroup->setGeometry(QRect(10, 230, 121, 71));
        meshSourceComboBox = new QComboBox(addGroup);
        meshSourceComboBox->setObjectName(QStringLiteral("meshSourceComboBox"));
        meshSourceComboBox->setGeometry(QRect(10, 20, 101, 22));
        addButton = new QPushButton(addGroup);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(20, 44, 75, 23));
        deleteButton = new QPushButton(rigidBodyesGroup);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(140, 240, 41, 61));
        rigidBodiesList = new QListWidget(rigidBodyesGroup);
        rigidBodiesList->setObjectName(QStringLiteral("rigidBodiesList"));
        rigidBodiesList->setGeometry(QRect(10, 20, 171, 201));
        rigidBodiesList->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        rigidBodiesList->setTextElideMode(Qt::ElideMiddle);
        massGroup = new QGroupBox(rigidBodyesTab);
        massGroup->setObjectName(QStringLiteral("massGroup"));
        massGroup->setGeometry(QRect(10, 530, 191, 191));
        massSpinBox = new QDoubleSpinBox(massGroup);
        massSpinBox->setObjectName(QStringLiteral("massSpinBox"));
        massSpinBox->setGeometry(QRect(10, 20, 91, 22));
        massCenterGroup = new QGroupBox(massGroup);
        massCenterGroup->setObjectName(QStringLiteral("massCenterGroup"));
        massCenterGroup->setGeometry(QRect(10, 50, 171, 131));
        massCenterXSpinBox = new QDoubleSpinBox(massCenterGroup);
        massCenterXSpinBox->setObjectName(QStringLiteral("massCenterXSpinBox"));
        massCenterXSpinBox->setGeometry(QRect(50, 20, 61, 22));
        label_4 = new QLabel(massCenterGroup);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 20, 41, 21));
        label_5 = new QLabel(massCenterGroup);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 43, 51, 21));
        massCenterYSpinBox = new QDoubleSpinBox(massCenterGroup);
        massCenterYSpinBox->setObjectName(QStringLiteral("massCenterYSpinBox"));
        massCenterYSpinBox->setGeometry(QRect(70, 43, 61, 22));
        label_6 = new QLabel(massCenterGroup);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 66, 51, 21));
        massCenterZSpinBox = new QDoubleSpinBox(massCenterGroup);
        massCenterZSpinBox->setObjectName(QStringLiteral("massCenterZSpinBox"));
        massCenterZSpinBox->setGeometry(QRect(90, 66, 61, 22));
        geometricCenterButton = new QPushButton(massCenterGroup);
        geometricCenterButton->setObjectName(QStringLiteral("geometricCenterButton"));
        geometricCenterButton->setGeometry(QRect(10, 90, 141, 23));

        retranslateUi(rigidBodyesTab);

        QMetaObject::connectSlotsByName(rigidBodyesTab);
    } // setupUi

    void retranslateUi(QWidget *rigidBodyesTab)
    {
        rigidBodyesTab->setWindowTitle(QApplication::translate("rigidBodyesTab", "Form", nullptr));
        showRigidBodyRadioButton->setText(QApplication::translate("rigidBodyesTab", "Show rigid bodies", nullptr));
        rigidBodyesGroup->setTitle(QApplication::translate("rigidBodyesTab", "Rigid bodies list", nullptr));
        addGroup->setTitle(QApplication::translate("rigidBodyesTab", "Add new", nullptr));
        addButton->setText(QApplication::translate("rigidBodyesTab", "Add", nullptr));
        deleteButton->setText(QApplication::translate("rigidBodyesTab", "Delete", nullptr));
        massGroup->setTitle(QApplication::translate("rigidBodyesTab", "Mass", nullptr));
        massCenterGroup->setTitle(QApplication::translate("rigidBodyesTab", "Mass center", nullptr));
        label_4->setText(QApplication::translate("rigidBodyesTab", "X pos", nullptr));
        label_5->setText(QApplication::translate("rigidBodyesTab", "Y pos", nullptr));
        label_6->setText(QApplication::translate("rigidBodyesTab", "Z pos", nullptr));
        geometricCenterButton->setText(QApplication::translate("rigidBodyesTab", "Geometric center", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rigidBodyesTab: public Ui_rigidBodyesTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RIGIDBODYESTAB_H
