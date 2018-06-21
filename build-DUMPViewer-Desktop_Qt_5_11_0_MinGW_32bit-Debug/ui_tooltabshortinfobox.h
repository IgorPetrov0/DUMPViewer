/********************************************************************************
** Form generated from reading UI file 'tooltabshortinfobox.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLTABSHORTINFOBOX_H
#define UI_TOOLTABSHORTINFOBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_toolTabShortInfoBox
{
public:
    QGroupBox *meshGroup;
    QGroupBox *boundBoxGroup;
    QLabel *xSizeLabel;
    QLabel *ySizeLabel;
    QLabel *zSizeLabel;
    QLabel *trianglesValueLabel;
    QGroupBox *groupBox;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;

    void setupUi(QWidget *toolTabShortInfoBox)
    {
        if (toolTabShortInfoBox->objectName().isEmpty())
            toolTabShortInfoBox->setObjectName(QStringLiteral("toolTabShortInfoBox"));
        toolTabShortInfoBox->resize(172, 262);
        meshGroup = new QGroupBox(toolTabShortInfoBox);
        meshGroup->setObjectName(QStringLiteral("meshGroup"));
        meshGroup->setGeometry(QRect(0, 0, 161, 241));
        boundBoxGroup = new QGroupBox(meshGroup);
        boundBoxGroup->setObjectName(QStringLiteral("boundBoxGroup"));
        boundBoxGroup->setGeometry(QRect(10, 20, 141, 71));
        xSizeLabel = new QLabel(boundBoxGroup);
        xSizeLabel->setObjectName(QStringLiteral("xSizeLabel"));
        xSizeLabel->setGeometry(QRect(10, 15, 111, 21));
        ySizeLabel = new QLabel(boundBoxGroup);
        ySizeLabel->setObjectName(QStringLiteral("ySizeLabel"));
        ySizeLabel->setGeometry(QRect(10, 30, 111, 21));
        zSizeLabel = new QLabel(boundBoxGroup);
        zSizeLabel->setObjectName(QStringLiteral("zSizeLabel"));
        zSizeLabel->setGeometry(QRect(10, 45, 111, 21));
        trianglesValueLabel = new QLabel(meshGroup);
        trianglesValueLabel->setObjectName(QStringLiteral("trianglesValueLabel"));
        trianglesValueLabel->setGeometry(QRect(10, 100, 151, 16));
        groupBox = new QGroupBox(meshGroup);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 130, 141, 111));
        doubleSpinBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(60, 20, 71, 17));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 47, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 47, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 80, 47, 16));
        doubleSpinBox_3 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(60, 50, 71, 17));
        doubleSpinBox_4 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(60, 80, 71, 17));

        retranslateUi(toolTabShortInfoBox);

        QMetaObject::connectSlotsByName(toolTabShortInfoBox);
    } // setupUi

    void retranslateUi(QWidget *toolTabShortInfoBox)
    {
        toolTabShortInfoBox->setWindowTitle(QApplication::translate("toolTabShortInfoBox", "Form", nullptr));
        meshGroup->setTitle(QApplication::translate("toolTabShortInfoBox", "Mesh", nullptr));
        boundBoxGroup->setTitle(QApplication::translate("toolTabShortInfoBox", "Bound Box", nullptr));
        xSizeLabel->setText(QApplication::translate("toolTabShortInfoBox", "X Size= ", nullptr));
        ySizeLabel->setText(QApplication::translate("toolTabShortInfoBox", "Y Size= ", nullptr));
        zSizeLabel->setText(QApplication::translate("toolTabShortInfoBox", "Z Size= ", nullptr));
        trianglesValueLabel->setText(QApplication::translate("toolTabShortInfoBox", "Triangles=", nullptr));
        groupBox->setTitle(QApplication::translate("toolTabShortInfoBox", "Model matrix", nullptr));
        label->setText(QApplication::translate("toolTabShortInfoBox", "Position", nullptr));
        label_2->setText(QApplication::translate("toolTabShortInfoBox", "Rotation", nullptr));
        label_3->setText(QApplication::translate("toolTabShortInfoBox", "Scale", nullptr));
    } // retranslateUi

};

namespace Ui {
    class toolTabShortInfoBox: public Ui_toolTabShortInfoBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLTABSHORTINFOBOX_H
