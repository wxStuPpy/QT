/********************************************************************************
** Form generated from reading UI file 'ApplyFriendPage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLYFRIENDPAGE_H
#define UI_APPLYFRIENDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <applyfriendlist.h>

QT_BEGIN_NAMESPACE

class Ui_ApplyFriendPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *friendApplyWid;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *friendApplyLabel;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    ApplyFriendList *applyFriendList;

    void setupUi(QWidget *ApplyFriendPage)
    {
        if (ApplyFriendPage->objectName().isEmpty())
            ApplyFriendPage->setObjectName("ApplyFriendPage");
        ApplyFriendPage->resize(727, 466);
        verticalLayout = new QVBoxLayout(ApplyFriendPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        friendApplyWid = new QWidget(ApplyFriendPage);
        friendApplyWid->setObjectName("friendApplyWid");
        horizontalLayout = new QHBoxLayout(friendApplyWid);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        friendApplyLabel = new QLabel(friendApplyWid);
        friendApplyLabel->setObjectName("friendApplyLabel");
        friendApplyLabel->setMinimumSize(QSize(0, 40));
        friendApplyLabel->setMaximumSize(QSize(16777215, 40));

        horizontalLayout->addWidget(friendApplyLabel);

        horizontalSpacer = new QSpacerItem(663, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(friendApplyWid);

        widget_2 = new QWidget(ApplyFriendPage);
        widget_2->setObjectName("widget_2");
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        applyFriendList = new ApplyFriendList(widget_2);
        applyFriendList->setObjectName("applyFriendList");

        verticalLayout_2->addWidget(applyFriendList);


        verticalLayout->addWidget(widget_2);


        retranslateUi(ApplyFriendPage);

        QMetaObject::connectSlotsByName(ApplyFriendPage);
    } // setupUi

    void retranslateUi(QWidget *ApplyFriendPage)
    {
        ApplyFriendPage->setWindowTitle(QCoreApplication::translate("ApplyFriendPage", "ApplyFriendPage", nullptr));
        friendApplyLabel->setText(QCoreApplication::translate("ApplyFriendPage", "\346\226\260\347\232\204\346\234\213\345\217\213:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ApplyFriendPage: public Ui_ApplyFriendPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLYFRIENDPAGE_H
