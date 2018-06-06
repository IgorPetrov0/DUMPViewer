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

    void setupUi(QWidget *toolTabShortInfoBox)
    {
        if (toolTabShortInfoBox->objectName().isEmpty())
            toolTabShortInfoBox->setObjectName(QStringLiteral("toolTabShortInfoBox"));
        toolTabShortInfoBox->resize(172, 130);
        meshGroup = new QGroupBox(toolTabShortInfoBox);
        meshGroup->setObjectName(QStringLiteral("meshGroup"));
        meshGroup->setGeometry(QRect(0, 0, 161, 121));
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
    } // retranslateUi

};

namespace Ui {
    class toolTabShortInfoBox: public Ui_toolTabShortInfoBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLTABSHORTINFOBOX_H
