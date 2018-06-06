/********************************************************************************
** Form generated from reading UI file 'newgameobjectnamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAMEOBJECTNAMEWINDOW_H
#define UI_NEWGAMEOBJECTNAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_newGameObjectNameWindow
{
public:
    QLineEdit *nameLine;
    QPushButton *OKButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *newGameObjectNameWindow)
    {
        if (newGameObjectNameWindow->objectName().isEmpty())
            newGameObjectNameWindow->setObjectName(QStringLiteral("newGameObjectNameWindow"));
        newGameObjectNameWindow->resize(293, 93);
        newGameObjectNameWindow->setModal(true);
        nameLine = new QLineEdit(newGameObjectNameWindow);
        nameLine->setObjectName(QStringLiteral("nameLine"));
        nameLine->setGeometry(QRect(20, 10, 261, 20));
        OKButton = new QPushButton(newGameObjectNameWindow);
        OKButton->setObjectName(QStringLiteral("OKButton"));
        OKButton->setGeometry(QRect(20, 50, 75, 23));
        cancelButton = new QPushButton(newGameObjectNameWindow);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(210, 50, 75, 23));

        retranslateUi(newGameObjectNameWindow);

        QMetaObject::connectSlotsByName(newGameObjectNameWindow);
    } // setupUi

    void retranslateUi(QDialog *newGameObjectNameWindow)
    {
        newGameObjectNameWindow->setWindowTitle(QApplication::translate("newGameObjectNameWindow", "Dialog", nullptr));
        OKButton->setText(QApplication::translate("newGameObjectNameWindow", "OK", nullptr));
        cancelButton->setText(QApplication::translate("newGameObjectNameWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newGameObjectNameWindow: public Ui_newGameObjectNameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAMEOBJECTNAMEWINDOW_H
