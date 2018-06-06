/********************************************************************************
** Form generated from reading UI file 'toolwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLWIDGET_H
#define UI_TOOLWIDGET_H

#include <GUI/tabs/constraintstab.h>
#include <GUI/tabs/meshtab.h>
#include <GUI/tabs/rigidbodyestab.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_toolWidget
{
public:
    QTabWidget *tabWidget;
    QWidget *phisicTabWidget;
    QTabWidget *phisicTab;
    rigidBodyesTab *rigidBodiesTabBar;
    constraintsTab *constraintsTabBar;
    QWidget *graphicTabWidget;
    QTabWidget *graphicTab;
    meshTab *meshTabBar;
    QWidget *plusLODTabBar;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *showRadioButton;

    void setupUi(QWidget *toolWidget)
    {
        if (toolWidget->objectName().isEmpty())
            toolWidget->setObjectName(QStringLiteral("toolWidget"));
        toolWidget->resize(221, 898);
        tabWidget = new QTabWidget(toolWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 220, 901));
        phisicTabWidget = new QWidget();
        phisicTabWidget->setObjectName(QStringLiteral("phisicTabWidget"));
        phisicTab = new QTabWidget(phisicTabWidget);
        phisicTab->setObjectName(QStringLiteral("phisicTab"));
        phisicTab->setGeometry(QRect(0, 10, 220, 871));
        phisicTab->setTabShape(QTabWidget::Triangular);
        rigidBodiesTabBar = new rigidBodyesTab();
        rigidBodiesTabBar->setObjectName(QStringLiteral("rigidBodiesTabBar"));
        phisicTab->addTab(rigidBodiesTabBar, QString());
        constraintsTabBar = new constraintsTab();
        constraintsTabBar->setObjectName(QStringLiteral("constraintsTabBar"));
        phisicTab->addTab(constraintsTabBar, QString());
        tabWidget->addTab(phisicTabWidget, QString());
        graphicTabWidget = new QWidget();
        graphicTabWidget->setObjectName(QStringLiteral("graphicTabWidget"));
        graphicTab = new QTabWidget(graphicTabWidget);
        graphicTab->setObjectName(QStringLiteral("graphicTab"));
        graphicTab->setGeometry(QRect(0, 40, 216, 461));
        graphicTab->setTabShape(QTabWidget::Triangular);
        graphicTab->setUsesScrollButtons(true);
        graphicTab->setDocumentMode(false);
        graphicTab->setTabsClosable(false);
        meshTabBar = new meshTab();
        meshTabBar->setObjectName(QStringLiteral("meshTabBar"));
        meshTabBar->setContextMenuPolicy(Qt::DefaultContextMenu);
        graphicTab->addTab(meshTabBar, QString());
        plusLODTabBar = new QWidget();
        plusLODTabBar->setObjectName(QStringLiteral("plusLODTabBar"));
        groupBox = new QGroupBox(plusLODTabBar);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 211, 71));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 191, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 151, 16));
        graphicTab->addTab(plusLODTabBar, QString());
        showRadioButton = new QRadioButton(graphicTabWidget);
        showRadioButton->setObjectName(QStringLiteral("showRadioButton"));
        showRadioButton->setGeometry(QRect(10, 10, 191, 17));
        showRadioButton->setCheckable(true);
        showRadioButton->setChecked(false);
        tabWidget->addTab(graphicTabWidget, QString());

        retranslateUi(toolWidget);

        tabWidget->setCurrentIndex(1);
        phisicTab->setCurrentIndex(1);
        graphicTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(toolWidget);
    } // setupUi

    void retranslateUi(QWidget *toolWidget)
    {
        toolWidget->setWindowTitle(QApplication::translate("toolWidget", "Form", nullptr));
        phisicTab->setTabText(phisicTab->indexOf(rigidBodiesTabBar), QApplication::translate("toolWidget", "Rigid bodies", nullptr));
        phisicTab->setTabText(phisicTab->indexOf(constraintsTabBar), QApplication::translate("toolWidget", "Constraints", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(phisicTabWidget), QApplication::translate("toolWidget", "Phisic", nullptr));
        graphicTab->setTabText(graphicTab->indexOf(meshTabBar), QApplication::translate("toolWidget", "Mesh", nullptr));
        groupBox->setTitle(QApplication::translate("toolWidget", "Error", nullptr));
        label->setText(QApplication::translate("toolWidget", "Please define previous LOD befor ", nullptr));
        label_2->setText(QApplication::translate("toolWidget", "created new.", nullptr));
        graphicTab->setTabText(graphicTab->indexOf(plusLODTabBar), QApplication::translate("toolWidget", "Add LOD", nullptr));
        showRadioButton->setText(QApplication::translate("toolWidget", "Show graphic", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(graphicTabWidget), QApplication::translate("toolWidget", "Graphic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class toolWidget: public Ui_toolWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLWIDGET_H
