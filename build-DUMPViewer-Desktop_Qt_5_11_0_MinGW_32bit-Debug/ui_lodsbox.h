/********************************************************************************
** Form generated from reading UI file 'lodsbox.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LODSBOX_H
#define UI_LODSBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lodsBox
{
public:
    QGroupBox *groupBox;
    QGroupBox *groupLOD1;
    QPushButton *loadButton;
    QLineEdit *FileNameLine;
    QSpinBox *distance;
    QLabel *label;
    QCheckBox *showCheckBox;
    QRadioButton *distButton;
    QGroupBox *groupLOD2;
    QPushButton *loadButton_2;
    QLineEdit *FileNameLine_2;
    QSpinBox *distance_2;
    QLabel *label_2;
    QCheckBox *showCheckBox_2;
    QRadioButton *distButton_2;
    QGroupBox *groupLOD3;
    QPushButton *loadButton_4;
    QLineEdit *FileNameLine_4;
    QSpinBox *distance_4;
    QLabel *label_4;
    QCheckBox *showCheckBox_4;
    QRadioButton *distButton_4;

    void setupUi(QWidget *lodsBox)
    {
        if (lodsBox->objectName().isEmpty())
            lodsBox->setObjectName(QStringLiteral("lodsBox"));
        lodsBox->resize(200, 522);
        groupBox = new QGroupBox(lodsBox);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 181, 501));
        groupLOD1 = new QGroupBox(groupBox);
        groupLOD1->setObjectName(QStringLiteral("groupLOD1"));
        groupLOD1->setGeometry(QRect(10, 20, 161, 151));
        loadButton = new QPushButton(groupLOD1);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        loadButton->setGeometry(QRect(40, 50, 75, 23));
        FileNameLine = new QLineEdit(groupLOD1);
        FileNameLine->setObjectName(QStringLiteral("FileNameLine"));
        FileNameLine->setGeometry(QRect(10, 20, 141, 20));
        distance = new QSpinBox(groupLOD1);
        distance->setObjectName(QStringLiteral("distance"));
        distance->setGeometry(QRect(81, 80, 71, 22));
        label = new QLabel(groupLOD1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 75, 71, 31));
        showCheckBox = new QCheckBox(groupLOD1);
        showCheckBox->setObjectName(QStringLiteral("showCheckBox"));
        showCheckBox->setGeometry(QRect(10, 120, 71, 17));
        distButton = new QRadioButton(groupLOD1);
        distButton->setObjectName(QStringLiteral("distButton"));
        distButton->setGeometry(QRect(100, 120, 51, 17));
        groupLOD2 = new QGroupBox(groupBox);
        groupLOD2->setObjectName(QStringLiteral("groupLOD2"));
        groupLOD2->setGeometry(QRect(10, 180, 161, 151));
        loadButton_2 = new QPushButton(groupLOD2);
        loadButton_2->setObjectName(QStringLiteral("loadButton_2"));
        loadButton_2->setGeometry(QRect(40, 50, 75, 23));
        FileNameLine_2 = new QLineEdit(groupLOD2);
        FileNameLine_2->setObjectName(QStringLiteral("FileNameLine_2"));
        FileNameLine_2->setGeometry(QRect(10, 20, 141, 20));
        distance_2 = new QSpinBox(groupLOD2);
        distance_2->setObjectName(QStringLiteral("distance_2"));
        distance_2->setGeometry(QRect(81, 80, 71, 22));
        label_2 = new QLabel(groupLOD2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 75, 71, 31));
        showCheckBox_2 = new QCheckBox(groupLOD2);
        showCheckBox_2->setObjectName(QStringLiteral("showCheckBox_2"));
        showCheckBox_2->setGeometry(QRect(10, 120, 71, 17));
        distButton_2 = new QRadioButton(groupLOD2);
        distButton_2->setObjectName(QStringLiteral("distButton_2"));
        distButton_2->setGeometry(QRect(100, 120, 51, 17));
        groupLOD3 = new QGroupBox(groupBox);
        groupLOD3->setObjectName(QStringLiteral("groupLOD3"));
        groupLOD3->setGeometry(QRect(10, 340, 161, 151));
        loadButton_4 = new QPushButton(groupLOD3);
        loadButton_4->setObjectName(QStringLiteral("loadButton_4"));
        loadButton_4->setGeometry(QRect(40, 50, 75, 23));
        FileNameLine_4 = new QLineEdit(groupLOD3);
        FileNameLine_4->setObjectName(QStringLiteral("FileNameLine_4"));
        FileNameLine_4->setGeometry(QRect(10, 20, 141, 20));
        distance_4 = new QSpinBox(groupLOD3);
        distance_4->setObjectName(QStringLiteral("distance_4"));
        distance_4->setGeometry(QRect(81, 80, 71, 22));
        label_4 = new QLabel(groupLOD3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 75, 71, 31));
        showCheckBox_4 = new QCheckBox(groupLOD3);
        showCheckBox_4->setObjectName(QStringLiteral("showCheckBox_4"));
        showCheckBox_4->setGeometry(QRect(10, 120, 71, 17));
        distButton_4 = new QRadioButton(groupLOD3);
        distButton_4->setObjectName(QStringLiteral("distButton_4"));
        distButton_4->setGeometry(QRect(100, 120, 51, 17));

        retranslateUi(lodsBox);

        QMetaObject::connectSlotsByName(lodsBox);
    } // setupUi

    void retranslateUi(QWidget *lodsBox)
    {
        lodsBox->setWindowTitle(QApplication::translate("lodsBox", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("lodsBox", "LODs", nullptr));
        groupLOD1->setTitle(QApplication::translate("lodsBox", "LOD 1", nullptr));
        loadButton->setText(QApplication::translate("lodsBox", "Load", nullptr));
        label->setText(QApplication::translate("lodsBox", "Distance", nullptr));
        showCheckBox->setText(QApplication::translate("lodsBox", "Show", nullptr));
        distButton->setText(QApplication::translate("lodsBox", "Dist", nullptr));
        groupLOD2->setTitle(QApplication::translate("lodsBox", "LOD 2", nullptr));
        loadButton_2->setText(QApplication::translate("lodsBox", "Load", nullptr));
        label_2->setText(QApplication::translate("lodsBox", "Distance", nullptr));
        showCheckBox_2->setText(QApplication::translate("lodsBox", "Show", nullptr));
        distButton_2->setText(QApplication::translate("lodsBox", "Dist", nullptr));
        groupLOD3->setTitle(QApplication::translate("lodsBox", "LOD 3", nullptr));
        loadButton_4->setText(QApplication::translate("lodsBox", "Load", nullptr));
        label_4->setText(QApplication::translate("lodsBox", "Distance", nullptr));
        showCheckBox_4->setText(QApplication::translate("lodsBox", "Show", nullptr));
        distButton_4->setText(QApplication::translate("lodsBox", "Dist", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lodsBox: public Ui_lodsBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LODSBOX_H
