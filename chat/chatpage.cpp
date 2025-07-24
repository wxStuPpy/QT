#include "chatpage.h"
#include <QStyleOption>
#include <QPainter>

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