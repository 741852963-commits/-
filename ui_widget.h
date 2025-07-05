/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *user;
    QLineEdit *passw;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *PBC;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *PBD;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(734, 557);
        Widget->setMinimumSize(QSize(734, 557));
        Widget->setMaximumSize(QSize(734, 557));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 150, 71, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        label->setFont(font);
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 240, 71, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font1.setPointSize(14);
        label_2->setFont(font1);
        user = new QLineEdit(Widget);
        user->setObjectName("user");
        user->setGeometry(QRect(240, 160, 291, 31));
        passw = new QLineEdit(Widget);
        passw->setObjectName("passw");
        passw->setGeometry(QRect(240, 250, 291, 31));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(-10, 350, 758, 100));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        PBC = new QPushButton(layoutWidget);
        PBC->setObjectName("PBC");
        PBC->setMinimumSize(QSize(131, 71));
        PBC->setMaximumSize(QSize(131, 71));
        PBC->setFont(font1);

        horizontalLayout->addWidget(PBC);

        verticalSpacer_2 = new QSpacerItem(20, 98, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer_2);

        horizontalSpacer = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        PBD = new QPushButton(layoutWidget);
        PBD->setObjectName("PBD");
        PBD->setMinimumSize(QSize(131, 71));
        PBD->setMaximumSize(QSize(131, 71));
        PBD->setFont(font1);

        horizontalLayout->addWidget(PBD);

        horizontalSpacer_3 = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\350\264\246\345\217\267\357\274\232</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-weight:700;\">\345\257\206\347\240\201\357\274\232</span></p></body></html>", nullptr));
        PBC->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
        PBD->setText(QCoreApplication::translate("Widget", "\347\231\273\351\231\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
