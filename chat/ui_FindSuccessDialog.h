/********************************************************************************
** Form generated from reading UI file 'FindSuccessDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDSUCCESSDIALOG_H
#define UI_FINDSUCCESSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickedbtn.h>

QT_BEGIN_NAMESPACE

class Ui_FindSuccessDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *headLabel;
    QLabel *nameLabel;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    ClickedBtn *addFriendBtn;

    void setupUi(QDialog *FindSuccessDialog)
    {
        if (FindSuccessDialog->objectName().isEmpty())
            FindSuccessDialog->setObjectName("FindSuccessDialog");
        FindSuccessDialog->resize(280, 190);
        FindSuccessDialog->setMinimumSize(QSize(280, 190));
        FindSuccessDialog->setMaximumSize(QSize(280, 190));
        verticalLayout = new QVBoxLayout(FindSuccessDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(FindSuccessDialog);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        headLabel = new QLabel(widget);
        headLabel->setObjectName("headLabel");
        headLabel->setMinimumSize(QSize(50, 50));
        headLabel->setMaximumSize(QSize(50, 50));

        horizontalLayout->addWidget(headLabel);

        nameLabel = new QLabel(widget);
        nameLabel->setObjectName("nameLabel");

        horizontalLayout->addWidget(nameLabel);

        horizontalSpacer = new QSpacerItem(125, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(FindSuccessDialog);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        addFriendBtn = new ClickedBtn(widget_2);
        addFriendBtn->setObjectName("addFriendBtn");
        addFriendBtn->setMinimumSize(QSize(120, 35));
        addFriendBtn->setMaximumSize(QSize(120, 35));

        horizontalLayout_2->addWidget(addFriendBtn);


        verticalLayout->addWidget(widget_2);


        retranslateUi(FindSuccessDialog);

        QMetaObject::connectSlotsByName(FindSuccessDialog);
    } // setupUi

    void retranslateUi(QDialog *FindSuccessDialog)
    {
        FindSuccessDialog->setWindowTitle(QCoreApplication::translate("FindSuccessDialog", "FindSuccessDialog", nullptr));
        headLabel->setText(QCoreApplication::translate("FindSuccessDialog", "l", nullptr));
        nameLabel->setText(QCoreApplication::translate("FindSuccessDialog", "TextLabel", nullptr));
        addFriendBtn->setText(QCoreApplication::translate("FindSuccessDialog", "\346\267\273\345\212\240\351\200\232\350\256\257\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindSuccessDialog: public Ui_FindSuccessDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDSUCCESSDIALOG_H
