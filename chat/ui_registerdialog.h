/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickedlabel.h>
#include <timerbtn.h>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *errorLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *userLabel;
    QLineEdit *userEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *emailLabel;
    QLineEdit *emailEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *pwdLabel;
    QLineEdit *pwdEdit;
    ClickedLabel *pwdVisible;
    QHBoxLayout *horizontalLayout_7;
    QLabel *confirmLabel;
    QLineEdit *confirmEdit;
    ClickedLabel *confVisible;
    QHBoxLayout *horizontalLayout_8;
    QLabel *varifyLabel;
    QLineEdit *verifyEdit;
    TimerBtn *getCode;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *confirmBtn;
    QPushButton *cancelBtn;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_4;
    QLabel *tip1Label;
    QLabel *tip2Label;
    QSpacerItem *verticalSpacer_6;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *returnBtn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName("RegisterDialog");
        RegisterDialog->resize(306, 500);
        verticalLayout_2 = new QVBoxLayout(RegisterDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(RegisterDialog);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        widget = new QWidget(page);
        widget->setObjectName("widget");
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        errorLabel = new QLabel(widget);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(errorLabel);


        verticalLayout_3->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        userLabel = new QLabel(page);
        userLabel->setObjectName("userLabel");
        userLabel->setMinimumSize(QSize(0, 25));
        userLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(userLabel);

        userEdit = new QLineEdit(page);
        userEdit->setObjectName("userEdit");
        userEdit->setMinimumSize(QSize(0, 25));
        userEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(userEdit);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        emailLabel = new QLabel(page);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setMinimumSize(QSize(0, 25));
        emailLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(emailLabel);

        emailEdit = new QLineEdit(page);
        emailEdit->setObjectName("emailEdit");
        emailEdit->setMinimumSize(QSize(0, 25));
        emailEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(emailEdit);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        pwdLabel = new QLabel(page);
        pwdLabel->setObjectName("pwdLabel");
        pwdLabel->setMinimumSize(QSize(0, 25));
        pwdLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_6->addWidget(pwdLabel);

        pwdEdit = new QLineEdit(page);
        pwdEdit->setObjectName("pwdEdit");
        pwdEdit->setMinimumSize(QSize(0, 25));
        pwdEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_6->addWidget(pwdEdit);

        pwdVisible = new ClickedLabel(page);
        pwdVisible->setObjectName("pwdVisible");
        pwdVisible->setMinimumSize(QSize(20, 20));
        pwdVisible->setMaximumSize(QSize(20, 20));

        horizontalLayout_6->addWidget(pwdVisible);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        confirmLabel = new QLabel(page);
        confirmLabel->setObjectName("confirmLabel");
        confirmLabel->setMinimumSize(QSize(0, 25));
        confirmLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_7->addWidget(confirmLabel);

        confirmEdit = new QLineEdit(page);
        confirmEdit->setObjectName("confirmEdit");
        confirmEdit->setMinimumSize(QSize(0, 25));
        confirmEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_7->addWidget(confirmEdit);

        confVisible = new ClickedLabel(page);
        confVisible->setObjectName("confVisible");
        confVisible->setMinimumSize(QSize(20, 20));
        confVisible->setMaximumSize(QSize(20, 20));

        horizontalLayout_7->addWidget(confVisible);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        varifyLabel = new QLabel(page);
        varifyLabel->setObjectName("varifyLabel");
        varifyLabel->setMinimumSize(QSize(0, 25));
        varifyLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(varifyLabel);

        verifyEdit = new QLineEdit(page);
        verifyEdit->setObjectName("verifyEdit");
        verifyEdit->setMinimumSize(QSize(0, 25));
        verifyEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(verifyEdit);

        getCode = new TimerBtn(page);
        getCode->setObjectName("getCode");
        getCode->setMinimumSize(QSize(0, 25));
        getCode->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(getCode);


        verticalLayout_3->addLayout(horizontalLayout_8);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        confirmBtn = new QPushButton(page);
        confirmBtn->setObjectName("confirmBtn");
        confirmBtn->setMinimumSize(QSize(0, 25));
        confirmBtn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_9->addWidget(confirmBtn);

        cancelBtn = new QPushButton(page);
        cancelBtn->setObjectName("cancelBtn");
        cancelBtn->setMinimumSize(QSize(0, 25));
        cancelBtn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_9->addWidget(cancelBtn);


        verticalLayout_3->addLayout(horizontalLayout_9);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_5 = new QVBoxLayout(page_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        tip1Label = new QLabel(page_2);
        tip1Label->setObjectName("tip1Label");
        tip1Label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(tip1Label);

        tip2Label = new QLabel(page_2);
        tip2Label->setObjectName("tip2Label");
        tip2Label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(tip2Label);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_6);

        widget_2 = new QWidget(page_2);
        widget_2->setObjectName("widget_2");
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        returnBtn = new QPushButton(widget_2);
        returnBtn->setObjectName("returnBtn");
        returnBtn->setMinimumSize(QSize(100, 25));
        returnBtn->setMaximumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(returnBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_5->addWidget(widget_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(RegisterDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QCoreApplication::translate("RegisterDialog", "Dialog", nullptr));
        errorLabel->setText(QCoreApplication::translate("RegisterDialog", "error", nullptr));
        userLabel->setText(QCoreApplication::translate("RegisterDialog", "\347\224\250\346\210\267", nullptr));
        emailLabel->setText(QCoreApplication::translate("RegisterDialog", "\351\202\256\347\256\261:", nullptr));
        pwdLabel->setText(QCoreApplication::translate("RegisterDialog", "\345\257\206\347\240\201:", nullptr));
        pwdVisible->setText(QString());
        confirmLabel->setText(QCoreApplication::translate("RegisterDialog", "\347\241\256\350\256\244:", nullptr));
        confVisible->setText(QString());
        varifyLabel->setText(QCoreApplication::translate("RegisterDialog", "\351\252\214\350\257\201\347\240\201:", nullptr));
        getCode->setText(QCoreApplication::translate("RegisterDialog", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", nullptr));
        confirmBtn->setText(QCoreApplication::translate("RegisterDialog", "\347\241\256\350\256\244", nullptr));
        cancelBtn->setText(QCoreApplication::translate("RegisterDialog", "\345\217\226\346\266\210", nullptr));
        tip1Label->setText(QCoreApplication::translate("RegisterDialog", "Registration successful, returning in 5 seconds.", nullptr));
        tip2Label->setText(QCoreApplication::translate("RegisterDialog", "Click the button to return immediately", nullptr));
        returnBtn->setText(QCoreApplication::translate("RegisterDialog", "Return to login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
