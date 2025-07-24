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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <chatpage.h>
#include <chatuserlist.h>
#include <clickedbtn.h>
#include <customizeedit.h>

QT_BEGIN_NAMESPACE

class Ui_ChatDialog
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *sideBar;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *chatLabel;
    QLabel *contactLabel;
    QLabel *headLabel;
    QSpacerItem *verticalSpacer;
    QWidget *userWid;
    QVBoxLayout *verticalLayout_2;
    QWidget *searchWid;
    QHBoxLayout *horizontalLayout_2;
    CustomizeEdit *searchEdit;
    QSpacerItem *horizontalSpacer;
    ClickedBtn *addBtn;
    ChatUserList *searchList;
    ChatUserList *userList;
    QListWidget *conUserList;
    QStackedWidget *stackedWidget;
    ChatPage *chatPage;
    QWidget *friendApplyPage;

    void setupUi(QMainWindow *ChatDialog)
    {
        if (ChatDialog->objectName().isEmpty())
            ChatDialog->setObjectName("ChatDialog");
        ChatDialog->resize(649, 520);
        centralWidget = new QWidget(ChatDialog);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sideBar = new QWidget(centralWidget);
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
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(30);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        chatLabel = new QLabel(widget);
        chatLabel->setObjectName("chatLabel");
        chatLabel->setMinimumSize(QSize(30, 30));
        chatLabel->setMaximumSize(QSize(30, 30));

        verticalLayout_3->addWidget(chatLabel);

        contactLabel = new QLabel(widget);
        contactLabel->setObjectName("contactLabel");
        contactLabel->setMinimumSize(QSize(30, 30));
        contactLabel->setMaximumSize(QSize(30, 30));

        verticalLayout_3->addWidget(contactLabel);

        headLabel = new QLabel(widget);
        headLabel->setObjectName("headLabel");
        headLabel->setMinimumSize(QSize(30, 30));
        headLabel->setMaximumSize(QSize(30, 30));

        verticalLayout_3->addWidget(headLabel);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(sideBar);

        userWid = new QWidget(centralWidget);
        userWid->setObjectName("userWid");
        userWid->setMaximumSize(QSize(250, 16777215));
        verticalLayout_2 = new QVBoxLayout(userWid);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        searchWid = new QWidget(userWid);
        searchWid->setObjectName("searchWid");
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

        searchList = new ChatUserList(userWid);
        searchList->setObjectName("searchList");

        verticalLayout_2->addWidget(searchList);

        userList = new ChatUserList(userWid);
        userList->setObjectName("userList");

        verticalLayout_2->addWidget(userList);

        conUserList = new QListWidget(userWid);
        conUserList->setObjectName("conUserList");

        verticalLayout_2->addWidget(conUserList);


        horizontalLayout->addWidget(userWid);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        chatPage = new ChatPage();
        chatPage->setObjectName("chatPage");
        stackedWidget->addWidget(chatPage);
        friendApplyPage = new QWidget();
        friendApplyPage->setObjectName("friendApplyPage");
        stackedWidget->addWidget(friendApplyPage);

        horizontalLayout->addWidget(stackedWidget);

        ChatDialog->setCentralWidget(centralWidget);

        retranslateUi(ChatDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ChatDialog);
    } // setupUi

    void retranslateUi(QMainWindow *ChatDialog)
    {
        ChatDialog->setWindowTitle(QCoreApplication::translate("ChatDialog", "ChatDialog", nullptr));
        chatLabel->setText(QString());
        contactLabel->setText(QString());
        headLabel->setText(QString());
        addBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatDialog: public Ui_ChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H
