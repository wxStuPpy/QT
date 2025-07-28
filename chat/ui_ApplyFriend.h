/********************************************************************************
** Form generated from reading UI file 'ApplyFriend.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLYFRIEND_H
#define UI_APPLYFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickedbtn.h>
#include <clickedoncelabel.h>
#include <customizeedit.h>

QT_BEGIN_NAMESPACE

class Ui_ApplyFriend
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *applyLabel;
    QWidget *applyWid;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    CustomizeEdit *nameEdit;
    QLabel *label_3;
    CustomizeEdit *backEdit;
    QLabel *label;
    QWidget *labelGroupWid;
    QVBoxLayout *verticalLayout_4;
    QWidget *gridWid;
    QLineEdit *labelEdit;
    QWidget *inputTipWid;
    QVBoxLayout *verticalLayout_5;
    ClickedOnceLabel *tipLabel;
    QFrame *line;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *labelListWid;
    QWidget *moreLabelWid;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_3;
    ClickedOnceLabel *moreLabel;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer;
    QWidget *applySureWid;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    ClickedBtn *sureBtn;
    QSpacerItem *horizontalSpacer_2;
    ClickedBtn *cancelBtn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *ApplyFriend)
    {
        if (ApplyFriend->objectName().isEmpty())
            ApplyFriend->setObjectName("ApplyFriend");
        ApplyFriend->resize(361, 621);
        verticalLayout = new QVBoxLayout(ApplyFriend);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(ApplyFriend);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setMinimumSize(QSize(0, 500));
        scrollArea->setWidgetResizable(true);
        scrollContents = new QWidget();
        scrollContents->setObjectName("scrollContents");
        scrollContents->setGeometry(QRect(0, 0, 359, 498));
        verticalLayout_2 = new QVBoxLayout(scrollContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, -1, 0, -1);
        applyLabel = new QLabel(scrollContents);
        applyLabel->setObjectName("applyLabel");
        applyLabel->setMinimumSize(QSize(0, 25));
        applyLabel->setMaximumSize(QSize(16777215, 25));
        applyLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(applyLabel);

        applyWid = new QWidget(scrollContents);
        applyWid->setObjectName("applyWid");
        verticalLayout_3 = new QVBoxLayout(applyWid);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(applyWid);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 25));
        label_2->setMaximumSize(QSize(16777215, 25));

        verticalLayout_3->addWidget(label_2);

        nameEdit = new CustomizeEdit(applyWid);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setMinimumSize(QSize(0, 35));
        nameEdit->setMaximumSize(QSize(16777215, 35));

        verticalLayout_3->addWidget(nameEdit);

        label_3 = new QLabel(applyWid);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 25));
        label_3->setMaximumSize(QSize(16777215, 25));

        verticalLayout_3->addWidget(label_3);

        backEdit = new CustomizeEdit(applyWid);
        backEdit->setObjectName("backEdit");
        backEdit->setMinimumSize(QSize(0, 35));
        backEdit->setMaximumSize(QSize(16777215, 35));

        verticalLayout_3->addWidget(backEdit);

        label = new QLabel(applyWid);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 25));
        label->setMaximumSize(QSize(16777215, 25));

        verticalLayout_3->addWidget(label);

        labelGroupWid = new QWidget(applyWid);
        labelGroupWid->setObjectName("labelGroupWid");
        labelGroupWid->setMinimumSize(QSize(0, 50));
        verticalLayout_4 = new QVBoxLayout(labelGroupWid);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        gridWid = new QWidget(labelGroupWid);
        gridWid->setObjectName("gridWid");
        gridWid->setMinimumSize(QSize(0, 40));
        gridWid->setMaximumSize(QSize(16777215, 40));
        labelEdit = new QLineEdit(gridWid);
        labelEdit->setObjectName("labelEdit");
        labelEdit->setGeometry(QRect(2, 2, 108, 35));
        labelEdit->setMinimumSize(QSize(108, 0));
        labelEdit->setMaximumSize(QSize(16777215, 35));

        verticalLayout_4->addWidget(gridWid);

        inputTipWid = new QWidget(labelGroupWid);
        inputTipWid->setObjectName("inputTipWid");
        inputTipWid->setMinimumSize(QSize(0, 35));
        inputTipWid->setMaximumSize(QSize(16777215, 35));
        verticalLayout_5 = new QVBoxLayout(inputTipWid);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tipLabel = new ClickedOnceLabel(inputTipWid);
        tipLabel->setObjectName("tipLabel");

        verticalLayout_5->addWidget(tipLabel);


        verticalLayout_4->addWidget(inputTipWid);


        verticalLayout_3->addWidget(labelGroupWid);

        line = new QFrame(applyWid);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_3->addWidget(line);

        widget = new QWidget(applyWid);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 60));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelListWid = new QWidget(widget);
        labelListWid->setObjectName("labelListWid");
        labelListWid->setMinimumSize(QSize(287, 50));
        labelListWid->setMaximumSize(QSize(287, 16777215));

        horizontalLayout_2->addWidget(labelListWid);

        moreLabelWid = new QWidget(widget);
        moreLabelWid->setObjectName("moreLabelWid");
        moreLabelWid->setMinimumSize(QSize(30, 0));
        moreLabelWid->setMaximumSize(QSize(30, 16777215));
        verticalLayout_6 = new QVBoxLayout(moreLabelWid);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_3);

        moreLabel = new ClickedOnceLabel(moreLabelWid);
        moreLabel->setObjectName("moreLabel");
        moreLabel->setMinimumSize(QSize(25, 25));
        moreLabel->setMaximumSize(QSize(25, 25));

        verticalLayout_6->addWidget(moreLabel);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);


        horizontalLayout_2->addWidget(moreLabelWid);


        verticalLayout_3->addWidget(widget);


        verticalLayout_2->addWidget(applyWid);

        scrollArea->setWidget(scrollContents);

        verticalLayout->addWidget(scrollArea);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        applySureWid = new QWidget(ApplyFriend);
        applySureWid->setObjectName("applySureWid");
        applySureWid->setMinimumSize(QSize(0, 50));
        horizontalLayout = new QHBoxLayout(applySureWid);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sureBtn = new ClickedBtn(applySureWid);
        sureBtn->setObjectName("sureBtn");
        sureBtn->setMinimumSize(QSize(100, 30));
        sureBtn->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(sureBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        cancelBtn = new ClickedBtn(applySureWid);
        cancelBtn->setObjectName("cancelBtn");
        cancelBtn->setMinimumSize(QSize(100, 30));
        cancelBtn->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(cancelBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(applySureWid);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(ApplyFriend);

        QMetaObject::connectSlotsByName(ApplyFriend);
    } // setupUi

    void retranslateUi(QDialog *ApplyFriend)
    {
        ApplyFriend->setWindowTitle(QCoreApplication::translate("ApplyFriend", "ApplyFriend", nullptr));
        applyLabel->setText(QCoreApplication::translate("ApplyFriend", "\347\224\263\350\257\267\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        label_2->setText(QCoreApplication::translate("ApplyFriend", "\345\217\221\351\200\201\346\267\273\345\212\240\345\245\275\345\217\213\347\224\263\350\257\267:", nullptr));
        label_3->setText(QCoreApplication::translate("ApplyFriend", "\345\244\207\346\263\250\345\220\215:", nullptr));
        label->setText(QCoreApplication::translate("ApplyFriend", "\346\240\207\347\255\276:", nullptr));
        tipLabel->setText(QCoreApplication::translate("ApplyFriend", "TextLabel", nullptr));
        moreLabel->setText(QString());
        sureBtn->setText(QCoreApplication::translate("ApplyFriend", "\347\241\256\350\256\244", nullptr));
        cancelBtn->setText(QCoreApplication::translate("ApplyFriend", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ApplyFriend: public Ui_ApplyFriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLYFRIEND_H
