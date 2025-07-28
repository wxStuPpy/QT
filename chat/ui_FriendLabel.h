/********************************************************************************
** Form generated from reading UI file 'FriendLabel.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDLABEL_H
#define UI_FRIENDLABEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <clickedlabel.h>

QT_BEGIN_NAMESPACE

class Ui_FriendLabel
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *tipLabel;
    QWidget *closeWid;
    QHBoxLayout *horizontalLayout_2;
    ClickedLabel *closeLabel;

    void setupUi(QWidget *FriendLabel)
    {
        if (FriendLabel->objectName().isEmpty())
            FriendLabel->setObjectName("FriendLabel");
        FriendLabel->resize(600, 43);
        horizontalLayout = new QHBoxLayout(FriendLabel);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tipLabel = new QLabel(FriendLabel);
        tipLabel->setObjectName("tipLabel");

        horizontalLayout->addWidget(tipLabel);

        closeWid = new QWidget(FriendLabel);
        closeWid->setObjectName("closeWid");
        closeWid->setMinimumSize(QSize(25, 25));
        closeWid->setMaximumSize(QSize(25, 25));
        horizontalLayout_2 = new QHBoxLayout(closeWid);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        closeLabel = new ClickedLabel(closeWid);
        closeLabel->setObjectName("closeLabel");
        closeLabel->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(closeLabel);


        horizontalLayout->addWidget(closeWid);


        retranslateUi(FriendLabel);

        QMetaObject::connectSlotsByName(FriendLabel);
    } // setupUi

    void retranslateUi(QWidget *FriendLabel)
    {
        FriendLabel->setWindowTitle(QCoreApplication::translate("FriendLabel", "FriendLabel", nullptr));
        tipLabel->setText(QCoreApplication::translate("FriendLabel", "TextLabel", nullptr));
        closeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendLabel: public Ui_FriendLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDLABEL_H
