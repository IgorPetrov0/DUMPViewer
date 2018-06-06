/********************************************************************************
** Form generated from reading UI file 'transformwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORMWIDGET_H
#define UI_TRANSFORMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_transformWidget
{
public:
    QGroupBox *groupBox;
    QLineEdit *vzLineEdit;
    QLineEdit *yyLineEdit;
    QLineEdit *zxLineEdit;
    QLabel *label_2;
    QLineEdit *xxLineEdit;
    QLineEdit *yxLineEdit;
    QLineEdit *yzLineEdit;
    QLineEdit *zyLineEdit;
    QLineEdit *vyLineEdit;
    QLabel *label;
    QLineEdit *xzLineEdit;
    QLineEdit *zzLineEdit;
    QLineEdit *xyLineEdit;
    QLineEdit *vxLineEdit;

    void setupUi(QWidget *transformWidget)
    {
        if (transformWidget->objectName().isEmpty())
            transformWidget->setObjectName(QStringLiteral("transformWidget"));
        transformWidget->resize(176, 157);
        groupBox = new QGroupBox(transformWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 171, 151));
        vzLineEdit = new QLineEdit(groupBox);
        vzLineEdit->setObjectName(QStringLiteral("vzLineEdit"));
        vzLineEdit->setGeometry(QRect(110, 120, 51, 20));
        yyLineEdit = new QLineEdit(groupBox);
        yyLineEdit->setObjectName(QStringLiteral("yyLineEdit"));
        yyLineEdit->setGeometry(QRect(60, 60, 51, 20));
        zxLineEdit = new QLineEdit(groupBox);
        zxLineEdit->setObjectName(QStringLiteral("zxLineEdit"));
        zxLineEdit->setGeometry(QRect(10, 80, 51, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 100, 47, 13));
        xxLineEdit = new QLineEdit(groupBox);
        xxLineEdit->setObjectName(QStringLiteral("xxLineEdit"));
        xxLineEdit->setGeometry(QRect(10, 40, 51, 20));
        yxLineEdit = new QLineEdit(groupBox);
        yxLineEdit->setObjectName(QStringLiteral("yxLineEdit"));
        yxLineEdit->setGeometry(QRect(10, 60, 51, 20));
        yzLineEdit = new QLineEdit(groupBox);
        yzLineEdit->setObjectName(QStringLiteral("yzLineEdit"));
        yzLineEdit->setGeometry(QRect(110, 60, 51, 20));
        zyLineEdit = new QLineEdit(groupBox);
        zyLineEdit->setObjectName(QStringLiteral("zyLineEdit"));
        zyLineEdit->setGeometry(QRect(60, 80, 51, 20));
        vyLineEdit = new QLineEdit(groupBox);
        vyLineEdit->setObjectName(QStringLiteral("vyLineEdit"));
        vyLineEdit->setGeometry(QRect(60, 120, 51, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 47, 13));
        xzLineEdit = new QLineEdit(groupBox);
        xzLineEdit->setObjectName(QStringLiteral("xzLineEdit"));
        xzLineEdit->setGeometry(QRect(110, 40, 51, 20));
        zzLineEdit = new QLineEdit(groupBox);
        zzLineEdit->setObjectName(QStringLiteral("zzLineEdit"));
        zzLineEdit->setGeometry(QRect(110, 80, 51, 20));
        xyLineEdit = new QLineEdit(groupBox);
        xyLineEdit->setObjectName(QStringLiteral("xyLineEdit"));
        xyLineEdit->setGeometry(QRect(60, 40, 51, 20));
        vxLineEdit = new QLineEdit(groupBox);
        vxLineEdit->setObjectName(QStringLiteral("vxLineEdit"));
        vxLineEdit->setGeometry(QRect(10, 120, 51, 20));

        retranslateUi(transformWidget);

        QMetaObject::connectSlotsByName(transformWidget);
    } // setupUi

    void retranslateUi(QWidget *transformWidget)
    {
        transformWidget->setWindowTitle(QApplication::translate("transformWidget", "Form", 0));
        groupBox->setTitle(QApplication::translate("transformWidget", "Transform A", 0));
        label_2->setText(QApplication::translate("transformWidget", "Vector", 0));
        label->setText(QApplication::translate("transformWidget", "Matrix", 0));
    } // retranslateUi

};

namespace Ui {
    class transformWidget: public Ui_transformWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORMWIDGET_H
