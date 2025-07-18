/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickedlabel.h>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *errorLabel;
    QLabel *headLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *emailLabel;
    QLineEdit *emailEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *pwdLabel;
    QLineEdit *pwdEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    ClickedLabel *forgetLabel;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *loginBtn;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *regBtn;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(300, 500);
        verticalLayout_2 = new QVBoxLayout(LoginDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        widget = new QWidget(LoginDialog);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        errorLabel = new QLabel(widget);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(errorLabel, 0, 0, 1, 1);

        headLabel = new QLabel(widget);
        headLabel->setObjectName("headLabel");
        headLabel->setMinimumSize(QSize(254, 200));
        headLabel->setMaximumSize(QSize(254, 200));
        headLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(headLabel, 1, 0, 1, 1);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        emailLabel = new QLabel(LoginDialog);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setMinimumSize(QSize(30, 25));
        emailLabel->setMaximumSize(QSize(30, 25));

        horizontalLayout->addWidget(emailLabel);

        emailEdit = new QLineEdit(LoginDialog);
        emailEdit->setObjectName("emailEdit");
        emailEdit->setMinimumSize(QSize(0, 25));
        emailEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(emailEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(7);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        pwdLabel = new QLabel(LoginDialog);
        pwdLabel->setObjectName("pwdLabel");
        pwdLabel->setMinimumSize(QSize(30, 25));
        pwdLabel->setMaximumSize(QSize(30, 25));

        horizontalLayout_2->addWidget(pwdLabel);

        pwdEdit = new QLineEdit(LoginDialog);
        pwdEdit->setObjectName("pwdEdit");
        pwdEdit->setMinimumSize(QSize(0, 25));
        pwdEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(pwdEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        forgetLabel = new ClickedLabel(LoginDialog);
        forgetLabel->setObjectName("forgetLabel");
        forgetLabel->setMinimumSize(QSize(0, 25));
        forgetLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(forgetLabel);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        loginBtn = new QPushButton(LoginDialog);
        loginBtn->setObjectName("loginBtn");
        loginBtn->setMinimumSize(QSize(100, 30));
        loginBtn->setMaximumSize(QSize(100, 30));

        horizontalLayout_4->addWidget(loginBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        regBtn = new QPushButton(LoginDialog);
        regBtn->setObjectName("regBtn");
        regBtn->setMinimumSize(QSize(100, 30));
        regBtn->setMaximumSize(QSize(100, 30));

        horizontalLayout_6->addWidget(regBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        errorLabel->setText(QCoreApplication::translate("LoginDialog", "error", nullptr));
        headLabel->setText(QString());
        emailLabel->setText(QCoreApplication::translate("LoginDialog", "\351\202\256\347\256\261:", nullptr));
        pwdLabel->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201:", nullptr));
        forgetLabel->setText(QCoreApplication::translate("LoginDialog", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        loginBtn->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        regBtn->setText(QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
