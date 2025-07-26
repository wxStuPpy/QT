#include "chatpage.h"
#include "global.h"
#include <QStyleOption>
#include <QPainter>
#include "chatitembase.h"
#include "textbubble.h"
#include "picturebubble.h"
#include "messagetext.h"

ChatPage::ChatPage(QWidget* parent)
	: QWidget(parent), ui(new Ui::ChatPage)
{
	ui->setupUi(this);
	//设置按钮样式
	ui->recvBtn->setState("normal", "hover", "press");
	ui->sendBtn->setState("normal", "hover", "press");
	//设置图标样式
	ui->emojiLabel->setState("normal", "hover", "press", "normal", "hover", "press");
	ui->fileLabel->setState("normal", "hover", "press", "normal", "hover", "press");

	connect(ui->sendBtn, &QPushButton::clicked, this, &ChatPage::slotOnSendBtnClicked);
}

ChatPage::~ChatPage()
{
	delete ui;
}

void ChatPage::paintEvent(QPaintEvent* event)
{
	QStyleOption opt;
	opt.initFrom(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void ChatPage::slotOnSendBtnClicked()
{
	auto pTextEdit = ui->chatEdit;
	ChatRole role = ChatRole::Self;
	QString userName = QStringLiteral("恋恋风辰");
	QString userIcon = ":/res/head_1.jpg";

	const QVector<MsgInfo>& msgList = pTextEdit->getMsgList();
	for (int i = 0; i < msgList.size(); ++i)
	{
		QString type = msgList[i].msgFlag;
		ChatItemBase* pChatItem = new ChatItemBase(role);
		pChatItem->setUserName(userName);
		pChatItem->setUserIcon(QPixmap(userIcon));
		QWidget* pBubble = nullptr;
		if (type == "text")
		{
			pBubble = new TextBubble(role, msgList[i].content);
		}
		else if (type == "image")
		{
			pBubble = new PictureBubble(QPixmap(msgList[i].content), role);
		}
		else if (type == "file")
		{
		}
		if (pBubble != nullptr)
		{
			pChatItem->setWidget(pBubble);
			ui->chatDataList->appendChatItem(pChatItem);
		}
	}
}