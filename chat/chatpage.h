#pragma once

#include <QWidget>
#include "ui_chatpage.h"

namespace Ui {
	ChatPage;
}

class ChatPage : public QWidget
{
	Q_OBJECT

public:
	ChatPage(QWidget* parent = nullptr);
	~ChatPage();

private:
	Ui::ChatPage* ui;
};
