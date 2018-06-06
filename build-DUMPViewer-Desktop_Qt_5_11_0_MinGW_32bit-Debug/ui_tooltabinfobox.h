/********************************************************************************
** Form generated from reading UI file 'tooltabinfobox.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLTABINFOBOX_H
#define UI_TOOLTABINFOBOX_H

#include <GUI/tooltabshortinfobox.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_toolTabInfoBox
{
public:
    QGroupBox *meshGroup;
    QLineEdit *fileNameLine;
    QPushButton *loadButton;
    QPushButton *deleteButton;
    toolTabShortInfoBox *infoBox;

    void setupUi(QWidget *toolTabInfoBox)
    {
        if (toolTabInfoBox->objectName().isEmpty())
            toolTabInfoBox->setObjectName(QStringLiteral("toolTabInfoBox"));
        toolTabInfoBox->resize(200, 216);
        meshGroup = new QGroupBox(toolTabInfoBox);
        meshGroup->setObjectName(QStringLiteral("meshGroup"));
        meshGroup->setGeometry(QRect(1, 1, 181, 211));
        fileNameLine = new QLineEdit(meshGroup);
        fileNameLine->setObjectName(QStringLiteral("fileNameLine"));
        fileNameLine->setGeometry(QRect(10, 20, 161, 20));
        loadButton = new QPushButton(meshGroup);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        loadButton->setGeometry(QRect(10, 50, 61, 23));
        deleteButton = new QPushButton(meshGroup);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(110, 50, 61, 23));
        infoBox = new toolTabShortInfoBox(meshGroup);
        infoBox->setObjectName(QStringLiteral("infoBox"));
        infoBox->setGeometry(QRect(10, 80, 161, 121));

        retranslateUi(toolTabInfoBox);

        QMetaObject::connectSlotsByName(toolTabInfoBox);
    } // setupUi

    void retranslateUi(QWidget *toolTabInfoBox)
    {
        toolTabInfoBox->setWindowTitle(QApplication::translate("toolTabInfoBox", "Form", nullptr));
        meshGroup->setTitle(QApplication::translate("toolTabInfoBox", "Mesh", nullptr));
        fileNameLine->setText(QString());
        loadButton->setText(QApplication::translate("toolTabInfoBox", "Load", nullptr));
        deleteButton->setText(QApplication::translate("toolTabInfoBox", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class toolTabInfoBox: public Ui_toolTabInfoBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLTABINFOBOX_H
