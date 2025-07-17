/********************************************************************************
** Form generated from reading UI file 'resetdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETDIALOG_H
#define UI_RESETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <timerbtn.h>

QT_BEGIN_NAMESPACE

class Ui_ResetDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *err_tip;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *userLabel;
    QLineEdit *userEdit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *emailLabel;
    QLineEdit *emailEdit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *verifyLabel;
    QLineEdit *verifyEdit;
    TimerBtn *verifyBtn;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *pwdLabel;
    QLineEdit *pwdEdit;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *sure_btn;
    QPushButton *returnBtn;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *ResetDialog)
    {
        if (ResetDialog->objectName().isEmpty())
            ResetDialog->setObjectName("ResetDialog");
        ResetDialog->resize(354, 538);
        verticalLayout = new QVBoxLayout(ResetDialog);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        err_tip = new QLabel(ResetDialog);
        err_tip->setObjectName("err_tip");
        err_tip->setMinimumSize(QSize(0, 25));
        err_tip->setMaximumSize(QSize(16777215, 25));
        err_tip->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(err_tip);

        widget = new QWidget(ResetDialog);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        userLabel = new QLabel(widget);
        userLabel->setObjectName("userLabel");
        userLabel->setMinimumSize(QSize(0, 25));
        userLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(userLabel);

        userEdit = new QLineEdit(widget);
        userEdit->setObjectName("userEdit");
        userEdit->setMinimumSize(QSize(0, 25));
        userEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(userEdit);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(ResetDialog);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        emailLabel = new QLabel(widget_2);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setMinimumSize(QSize(48, 25));
        emailLabel->setMaximumSize(QSize(48, 25));

        horizontalLayout_2->addWidget(emailLabel);

        emailEdit = new QLineEdit(widget_2);
        emailEdit->setObjectName("emailEdit");
        emailEdit->setMinimumSize(QSize(0, 25));
        emailEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(emailEdit);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(ResetDialog);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verifyLabel = new QLabel(widget_3);
        verifyLabel->setObjectName("verifyLabel");
        verifyLabel->setMinimumSize(QSize(0, 25));
        verifyLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(verifyLabel);

        verifyEdit = new QLineEdit(widget_3);
        verifyEdit->setObjectName("verifyEdit");
        verifyEdit->setMinimumSize(QSize(0, 25));
        verifyEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(verifyEdit);

        verifyBtn = new TimerBtn(widget_3);
        verifyBtn->setObjectName("verifyBtn");
        verifyBtn->setMinimumSize(QSize(0, 25));
        verifyBtn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(verifyBtn);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(ResetDialog);
        widget_4->setObjectName("widget_4");
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pwdLabel = new QLabel(widget_4);
        pwdLabel->setObjectName("pwdLabel");
        pwdLabel->setMinimumSize(QSize(0, 25));
        pwdLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(pwdLabel);

        pwdEdit = new QLineEdit(widget_4);
        pwdEdit->setObjectName("pwdEdit");
        pwdEdit->setMinimumSize(QSize(0, 25));
        pwdEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(pwdEdit);


        verticalLayout->addWidget(widget_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        widget_5 = new QWidget(ResetDialog);
        widget_5->setObjectName("widget_5");
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        sure_btn = new QPushButton(widget_5);
        sure_btn->setObjectName("sure_btn");
        sure_btn->setMinimumSize(QSize(0, 25));
        sure_btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(sure_btn);

        returnBtn = new QPushButton(widget_5);
        returnBtn->setObjectName("returnBtn");
        returnBtn->setMinimumSize(QSize(0, 25));
        returnBtn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(returnBtn);


        verticalLayout->addWidget(widget_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(ResetDialog);

        QMetaObject::connectSlotsByName(ResetDialog);
    } // setupUi

    void retranslateUi(QDialog *ResetDialog)
    {
        ResetDialog->setWindowTitle(QCoreApplication::translate("ResetDialog", "Dialog", nullptr));
        err_tip->setText(QString());
        userLabel->setText(QCoreApplication::translate("ResetDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        emailLabel->setText(QCoreApplication::translate("ResetDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        verifyLabel->setText(QCoreApplication::translate("ResetDialog", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        verifyBtn->setText(QCoreApplication::translate("ResetDialog", "\350\216\267\345\217\226", nullptr));
        pwdLabel->setText(QCoreApplication::translate("ResetDialog", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        sure_btn->setText(QCoreApplication::translate("ResetDialog", "\347\241\256\350\256\244", nullptr));
        returnBtn->setText(QCoreApplication::translate("ResetDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetDialog: public Ui_ResetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETDIALOG_H
