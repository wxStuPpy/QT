/********************************************************************************
** Form generated from reading UI file 'chatpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATPAGE_H
#define UI_CHATPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <chatview.h>
#include <clickedbtn.h>
#include <clickedlabel.h>
#include <messagetext.h>

QT_BEGIN_NAMESPACE

class Ui_ChatPage
{
public:
	QVBoxLayout* verticalLayout;
	QWidget* dataWid;
	QVBoxLayout* verticalLayout_4;
	QWidget* titleWid;
	QVBoxLayout* verticalLayout_5;
	QWidget* widget_2;
	QHBoxLayout* horizontalLayout_3;
	QLabel* titleLabel;
	ChatView* chatDataList;
	QWidget* toolWid;
	QHBoxLayout* horizontalLayout_4;
	QSpacerItem* horizontalSpacer_4;
	ClickedLabel* emojiLabel;
	QSpacerItem* horizontalSpacer_2;
	ClickedLabel* fileLabel;
	QSpacerItem* horizontalSpacer_3;
	MessageTextEdit* chatEdit;
	QWidget* sendWid;
	QHBoxLayout* horizontalLayout_5;
	QSpacerItem* horizontalSpacer_5;
	ClickedBtn* recvBtn;
	QSpacerItem* horizontalSpacer_7;
	ClickedBtn* sendBtn;
	QSpacerItem* horizontalSpacer_6;

	void setupUi(QWidget* ChatPage)
	{
		if (ChatPage->objectName().isEmpty())
			ChatPage->setObjectName("ChatPage");
		ChatPage->resize(600, 400);
		verticalLayout = new QVBoxLayout(ChatPage);
		verticalLayout->setSpacing(0);
		verticalLayout->setContentsMargins(11, 11, 11, 11);
		verticalLayout->setObjectName("verticalLayout");
		verticalLayout->setContentsMargins(0, 0, 0, 0);
		dataWid = new QWidget(ChatPage);
		dataWid->setObjectName("dataWid");
		verticalLayout_4 = new QVBoxLayout(dataWid);
		verticalLayout_4->setSpacing(0);
		verticalLayout_4->setContentsMargins(11, 11, 11, 11);
		verticalLayout_4->setObjectName("verticalLayout_4");
		verticalLayout_4->setContentsMargins(0, 0, 0, 0);
		titleWid = new QWidget(dataWid);
		titleWid->setObjectName("titleWid");
		titleWid->setMinimumSize(QSize(0, 40));
		titleWid->setMaximumSize(QSize(16777215, 40));
		verticalLayout_5 = new QVBoxLayout(titleWid);
		verticalLayout_5->setSpacing(7);
		verticalLayout_5->setContentsMargins(11, 11, 11, 11);
		verticalLayout_5->setObjectName("verticalLayout_5");
		verticalLayout_5->setContentsMargins(11, 2, 2, 2);
		widget_2 = new QWidget(titleWid);
		widget_2->setObjectName("widget_2");
		horizontalLayout_3 = new QHBoxLayout(widget_2);
		horizontalLayout_3->setSpacing(6);
		horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
		horizontalLayout_3->setObjectName("horizontalLayout_3");
		horizontalLayout_3->setContentsMargins(2, 2, 2, 2);
		titleLabel = new QLabel(widget_2);
		titleLabel->setObjectName("titleLabel");

		horizontalLayout_3->addWidget(titleLabel);

		verticalLayout_5->addWidget(widget_2);

		verticalLayout_4->addWidget(titleWid);

		chatDataList = new ChatView(dataWid);
		chatDataList->setObjectName("chatDataList");
		chatDataList->setMinimumSize(QSize(0, 0));
		chatDataList->setMaximumSize(QSize(16777215, 16777215));

		verticalLayout_4->addWidget(chatDataList);

		toolWid = new QWidget(dataWid);
		toolWid->setObjectName("toolWid");
		toolWid->setMinimumSize(QSize(0, 60));
		toolWid->setMaximumSize(QSize(16777215, 60));
		horizontalLayout_4 = new QHBoxLayout(toolWid);
		horizontalLayout_4->setSpacing(7);
		horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
		horizontalLayout_4->setObjectName("horizontalLayout_4");
		horizontalLayout_4->setContentsMargins(2, 2, 2, 2);
		horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

		horizontalLayout_4->addItem(horizontalSpacer_4);

		emojiLabel = new ClickedLabel(toolWid);
		emojiLabel->setObjectName("emojiLabel");
		emojiLabel->setMinimumSize(QSize(25, 25));
		emojiLabel->setMaximumSize(QSize(25, 25));

		horizontalLayout_4->addWidget(emojiLabel);

		horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

		horizontalLayout_4->addItem(horizontalSpacer_2);

		fileLabel = new ClickedLabel(toolWid);
		fileLabel->setObjectName("fileLabel");
		fileLabel->setMinimumSize(QSize(25, 25));
		fileLabel->setMaximumSize(QSize(25, 25));

		horizontalLayout_4->addWidget(fileLabel);

		horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

		horizontalLayout_4->addItem(horizontalSpacer_3);

		verticalLayout_4->addWidget(toolWid);

		chatEdit = new MessageTextEdit(dataWid);
		chatEdit->setObjectName("chatEdit");
		chatEdit->setMinimumSize(QSize(0, 150));
		chatEdit->setMaximumSize(QSize(16777215, 150));

		verticalLayout_4->addWidget(chatEdit);

		sendWid = new QWidget(dataWid);
		sendWid->setObjectName("sendWid");
		sendWid->setMinimumSize(QSize(0, 40));
		sendWid->setMaximumSize(QSize(16777215, 40));
		sendWid->setSizeIncrement(QSize(0, 0));
		sendWid->setBaseSize(QSize(0, 0));
		horizontalLayout_5 = new QHBoxLayout(sendWid);
		horizontalLayout_5->setSpacing(6);
		horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
		horizontalLayout_5->setObjectName("horizontalLayout_5");
		horizontalLayout_5->setContentsMargins(-1, 2, -1, 2);
		horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

		horizontalLayout_5->addItem(horizontalSpacer_5);

		recvBtn = new ClickedBtn(sendWid);
		recvBtn->setObjectName("recvBtn");
		recvBtn->setMinimumSize(QSize(100, 30));
		recvBtn->setMaximumSize(QSize(100, 30));

		horizontalLayout_5->addWidget(recvBtn);

		horizontalSpacer_7 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

		horizontalLayout_5->addItem(horizontalSpacer_7);

		sendBtn = new ClickedBtn(sendWid);
		sendBtn->setObjectName("sendBtn");
		sendBtn->setMinimumSize(QSize(100, 30));
		sendBtn->setMaximumSize(QSize(100, 30));

		horizontalLayout_5->addWidget(sendBtn);

		horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

		horizontalLayout_5->addItem(horizontalSpacer_6);

		verticalLayout_4->addWidget(sendWid);

		verticalLayout->addWidget(dataWid);

		retranslateUi(ChatPage);

		QMetaObject::connectSlotsByName(ChatPage);
	} // setupUi

	void retranslateUi(QWidget* ChatPage)
	{
		ChatPage->setWindowTitle(QCoreApplication::translate("ChatPage", "ChatPage", nullptr));
		titleLabel->setText(QCoreApplication::translate("ChatPage", "Bill", nullptr));
		emojiLabel->setText(QString());
		fileLabel->setText(QString());
		recvBtn->setText(QCoreApplication::translate("ChatPage", "\346\216\245\346\224\266", nullptr));
		sendBtn->setText(QCoreApplication::translate("ChatPage", "\345\217\221\351\200\201", nullptr));
	} // retranslateUi
};

namespace Ui {
	class ChatPage : public Ui_ChatPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATPAGE_H
