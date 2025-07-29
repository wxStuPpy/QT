/********************************************************************************
** Form generated from reading UI file 'chatdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIALOG_H
#define UI_CHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <chatpage.h>
#include <chatuserlist.h>
#include <clickedbtn.h>
#include <contactuserlist.h>
#include <customizeedit.h>
#include <searchlist.h>
#include <statewidget.h>

QT_BEGIN_NAMESPACE

class Ui_ChatDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *sideBar;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *headLabel;
    StateWidget *chatWid;
    StateWidget *contactWid;
    QSpacerItem *verticalSpacer;
    QWidget *userWid;
    QVBoxLayout *verticalLayout_2;
    QWidget *searchWid;
    QHBoxLayout *horizontalLayout_2;
    CustomizeEdit *searchEdit;
    QSpacerItem *horizontalSpacer;
    ClickedBtn *addBtn;
    ChatUserList *userList;
    SearchList *searchList;
    ContactUserList *conUserList;
    QStackedWidget *stackedWidget;
    ChatPage *chatPage;
    QWidget *friendApplyPage;

    void setupUi(QDialog *ChatDialog)
    {
        if (ChatDialog->objectName().isEmpty())
            ChatDialog->setObjectName("ChatDialog");
        ChatDialog->resize(712, 519);
        horizontalLayout = new QHBoxLayout(ChatDialog);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sideBar = new QWidget(ChatDialog);
        sideBar->setObjectName("sideBar");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sideBar->sizePolicy().hasHeightForWidth());
        sideBar->setSizePolicy(sizePolicy);
        sideBar->setMinimumSize(QSize(56, 0));
        sideBar->setMaximumSize(QSize(56, 16777215));
        verticalLayout = new QVBoxLayout(sideBar);
        verticalLayout->setSpacing(7);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 30, 0, 0);
        widget = new QWidget(sideBar);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 0));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(30);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        headLabel = new QLabel(widget);
        headLabel->setObjectName("headLabel");
        headLabel->setMinimumSize(QSize(30, 30));
        headLabel->setMaximumSize(QSize(30, 30));

        verticalLayout_3->addWidget(headLabel);

        chatWid = new StateWidget(widget);
        chatWid->setObjectName("chatWid");
        chatWid->setMinimumSize(QSize(30, 30));
        chatWid->setMaximumSize(QSize(30, 30));

        verticalLayout_3->addWidget(chatWid);

        contactWid = new StateWidget(widget);
        contactWid->setObjectName("contactWid");
        contactWid->setMinimumSize(QSize(30, 30));
        contactWid->setMaximumSize(QSize(30, 30));

        verticalLayout_3->addWidget(contactWid);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(sideBar);

        userWid = new QWidget(ChatDialog);
        userWid->setObjectName("userWid");
        userWid->setMaximumSize(QSize(250, 16777215));
        verticalLayout_2 = new QVBoxLayout(userWid);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        searchWid = new QWidget(userWid);
        searchWid->setObjectName("searchWid");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(searchWid->sizePolicy().hasHeightForWidth());
        searchWid->setSizePolicy(sizePolicy1);
        searchWid->setMinimumSize(QSize(0, 60));
        searchWid->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_2 = new QHBoxLayout(searchWid);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        searchEdit = new CustomizeEdit(searchWid);
        searchEdit->setObjectName("searchEdit");

        horizontalLayout_2->addWidget(searchEdit);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        addBtn = new ClickedBtn(searchWid);
        addBtn->setObjectName("addBtn");
        addBtn->setMinimumSize(QSize(24, 24));
        addBtn->setMaximumSize(QSize(24, 24));

        horizontalLayout_2->addWidget(addBtn);


        verticalLayout_2->addWidget(searchWid);

        userList = new ChatUserList(userWid);
        userList->setObjectName("userList");

        verticalLayout_2->addWidget(userList);

        searchList = new SearchList(userWid);
        searchList->setObjectName("searchList");

        verticalLayout_2->addWidget(searchList);

        conUserList = new ContactUserList(userWid);
        conUserList->setObjectName("conUserList");

        verticalLayout_2->addWidget(conUserList);


        horizontalLayout->addWidget(userWid);

        stackedWidget = new QStackedWidget(ChatDialog);
        stackedWidget->setObjectName("stackedWidget");
        chatPage = new ChatPage();
        chatPage->setObjectName("chatPage");
        stackedWidget->addWidget(chatPage);
        friendApplyPage = new QWidget();
        friendApplyPage->setObjectName("friendApplyPage");
        stackedWidget->addWidget(friendApplyPage);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(ChatDialog);

        QMetaObject::connectSlotsByName(ChatDialog);
    } // setupUi

    void retranslateUi(QDialog *ChatDialog)
    {
        ChatDialog->setWindowTitle(QCoreApplication::translate("ChatDialog", "ChatDialog", nullptr));
        headLabel->setText(QString());
        addBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatDialog: public Ui_ChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H
