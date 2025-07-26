/********************************************************************************
** Form generated from reading UI file 'chatuserwid.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATUSERWID_H
#define UI_CHATUSERWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatUserWid
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *iconWid;
    QHBoxLayout *horizontalLayout_2;
    QLabel *iconLabel;
    QWidget *userInfoWid;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLabel *chatLabel;
    QWidget *timeWid;
    QLabel *timeLabel;

    void setupUi(QWidget *ChatUserWid)
    {
        if (ChatUserWid->objectName().isEmpty())
            ChatUserWid->setObjectName("ChatUserWid");
        ChatUserWid->resize(600, 70);
        ChatUserWid->setMinimumSize(QSize(0, 70));
        ChatUserWid->setMaximumSize(QSize(16777215, 70));
        horizontalLayout = new QHBoxLayout(ChatUserWid);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(6, 2, 6, 2);
        iconWid = new QWidget(ChatUserWid);
        iconWid->setObjectName("iconWid");
        iconWid->setMinimumSize(QSize(50, 50));
        iconWid->setMaximumSize(QSize(50, 50));
        horizontalLayout_2 = new QHBoxLayout(iconWid);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        iconLabel = new QLabel(iconWid);
        iconLabel->setObjectName("iconLabel");
        iconLabel->setMinimumSize(QSize(45, 45));
        iconLabel->setMaximumSize(QSize(45, 45));
        iconLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(iconLabel);


        horizontalLayout->addWidget(iconWid);

        userInfoWid = new QWidget(ChatUserWid);
        userInfoWid->setObjectName("userInfoWid");
        verticalLayout = new QVBoxLayout(userInfoWid);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        nameLabel = new QLabel(userInfoWid);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setMaximumSize(QSize(130, 16777215));

        verticalLayout->addWidget(nameLabel);

        chatLabel = new QLabel(userInfoWid);
        chatLabel->setObjectName("chatLabel");
        chatLabel->setMaximumSize(QSize(130, 16777215));

        verticalLayout->addWidget(chatLabel);


        horizontalLayout->addWidget(userInfoWid);

        timeWid = new QWidget(ChatUserWid);
        timeWid->setObjectName("timeWid");
        timeWid->setMinimumSize(QSize(50, 50));
        timeWid->setMaximumSize(QSize(50, 50));
        timeLabel = new QLabel(timeWid);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setGeometry(QRect(0, 20, 54, 16));
        timeLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(timeWid);


        retranslateUi(ChatUserWid);

        QMetaObject::connectSlotsByName(ChatUserWid);
    } // setupUi

    void retranslateUi(QWidget *ChatUserWid)
    {
        ChatUserWid->setWindowTitle(QCoreApplication::translate("ChatUserWid", "ChatUserWid", nullptr));
        iconLabel->setText(QString());
        nameLabel->setText(QCoreApplication::translate("ChatUserWid", "Kobe", nullptr));
        chatLabel->setText(QCoreApplication::translate("ChatUserWid", "what can i say", nullptr));
        timeLabel->setText(QCoreApplication::translate("ChatUserWid", "13.55", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatUserWid: public Ui_ChatUserWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATUSERWID_H
