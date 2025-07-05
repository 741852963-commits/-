/********************************************************************************
** Form generated from reading UI file 'gn.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GN_H
#define UI_GN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(552, 398);
        pushButton = new QPushButton(Form);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 130, 75, 24));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 180, 75, 24));
        pushButton_3 = new QPushButton(Form);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 240, 75, 24));
        pushButton_4 = new QPushButton(Form);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(40, 310, 75, 24));
        pushButton_5 = new QPushButton(Form);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(170, 310, 75, 24));
        pushButton_6 = new QPushButton(Form);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(250, 310, 75, 24));
        pushButton_7 = new QPushButton(Form);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(220, 250, 75, 24));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GN_H
