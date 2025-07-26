#pragma once

#include <QWidget>
#include "ui_chatpage.h"

namespace Ui {
	class ChatPage;
}

class ChatPage : public QWidget
{
	Q_OBJECT

public:
	ChatPage(QWidget* parent = nullptr);
	~ChatPage();
public slots:
	void slotOnSendBtnClicked();
protected:
	virtual void paintEvent(QPaintEvent* event)override;

private:
	Ui::ChatPage* ui;
};
