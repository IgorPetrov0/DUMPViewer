/********************************************************************************
** Form generated from reading UI file 'hingewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HINGEWIDGET_H
#define UI_HINGEWIDGET_H

#include <GUI/widgets/constraintPropertiesWidgets/transformwidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hingeWidget
{
public:
    transformWidget *transformAWidget;
    QCheckBox *useReferenceACheckBox;
    transformWidget *transformBWidget;
    QCheckBox *useReferenceBCheckBox;

    void setupUi(QWidget *hingeWidget)
    {
        if (hingeWidget->objectName().isEmpty())
            hingeWidget->setObjectName(QStringLiteral("hingeWidget"));
        hingeWidget->resize(191, 380);
        transformAWidget = new transformWidget(hingeWidget);
        transformAWidget->setObjectName(QStringLiteral("transformAWidget"));
        transformAWidget->setGeometry(QRect(10, 20, 176, 157));
        useReferenceACheckBox = new QCheckBox(hingeWidget);
        useReferenceACheckBox->setObjectName(QStringLiteral("useReferenceACheckBox"));
        useReferenceACheckBox->setGeometry(QRect(10, 180, 171, 17));
        transformBWidget = new transformWidget(hingeWidget);
        transformBWidget->setObjectName(QStringLiteral("transformBWidget"));
        transformBWidget->setGeometry(QRect(10, 200, 176, 157));
        useReferenceBCheckBox = new QCheckBox(hingeWidget);
        useReferenceBCheckBox->setObjectName(QStringLiteral("useReferenceBCheckBox"));
        useReferenceBCheckBox->setGeometry(QRect(10, 360, 171, 17));

        retranslateUi(hingeWidget);

        QMetaObject::connectSlotsByName(hingeWidget);
    } // setupUi

    void retranslateUi(QWidget *hingeWidget)
    {
        hingeWidget->setWindowTitle(QApplication::translate("hingeWidget", "Form", nullptr));
        useReferenceACheckBox->setText(QApplication::translate("hingeWidget", "Use reference A", nullptr));
        useReferenceBCheckBox->setText(QApplication::translate("hingeWidget", "Use reference B", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hingeWidget: public Ui_hingeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HINGEWIDGET_H
