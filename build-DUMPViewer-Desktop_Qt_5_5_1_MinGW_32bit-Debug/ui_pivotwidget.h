/********************************************************************************
** Form generated from reading UI file 'pivotwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIVOTWIDGET_H
#define UI_PIVOTWIDGET_H

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

class Ui_pivotWidget
{
public:
    QGroupBox *pivotGroupBox;
    QDoubleSpinBox *XSpinBox;
    QDoubleSpinBox *YSpinBox;
    QDoubleSpinBox *ZSpinBox;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *pivotWidget)
    {
        if (pivotWidget->objectName().isEmpty())
            pivotWidget->setObjectName(QStringLiteral("pivotWidget"));
        pivotWidget->resize(176, 127);
        pivotGroupBox = new QGroupBox(pivotWidget);
        pivotGroupBox->setObjectName(QStringLiteral("pivotGroupBox"));
        pivotGroupBox->setGeometry(QRect(0, 0, 171, 121));
        XSpinBox = new QDoubleSpinBox(pivotGroupBox);
        XSpinBox->setObjectName(QStringLiteral("XSpinBox"));
        XSpinBox->setGeometry(QRect(60, 20, 101, 22));
        YSpinBox = new QDoubleSpinBox(pivotGroupBox);
        YSpinBox->setObjectName(QStringLiteral("YSpinBox"));
        YSpinBox->setGeometry(QRect(60, 50, 101, 22));
        ZSpinBox = new QDoubleSpinBox(pivotGroupBox);
        ZSpinBox->setObjectName(QStringLiteral("ZSpinBox"));
        ZSpinBox->setGeometry(QRect(60, 80, 101, 22));
        label_4 = new QLabel(pivotGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 20, 31, 21));
        label_5 = new QLabel(pivotGroupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 50, 31, 21));
        label_6 = new QLabel(pivotGroupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 80, 31, 21));

        retranslateUi(pivotWidget);

        QMetaObject::connectSlotsByName(pivotWidget);
    } // setupUi

    void retranslateUi(QWidget *pivotWidget)
    {
        pivotWidget->setWindowTitle(QApplication::translate("pivotWidget", "Form", 0));
        pivotGroupBox->setTitle(QApplication::translate("pivotWidget", "Pivot A", 0));
        label_4->setText(QApplication::translate("pivotWidget", "X=", 0));
        label_5->setText(QApplication::translate("pivotWidget", "Y=", 0));
        label_6->setText(QApplication::translate("pivotWidget", "Z=", 0));
    } // retranslateUi

};

namespace Ui {
    class pivotWidget: public Ui_pivotWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIVOTWIDGET_H
