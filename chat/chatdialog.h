#pragma once

#include <QMainWindow>
#include "ui_chatdialog.h"
#include "global.h"

class ChatDialog : public QMainWindow
{
	Q_OBJECT

public:
	ChatDialog(QWidget* parent = nullptr);
	~ChatDialog();
	void addChatUserList();
private:
	void showSearch(bool bsearch);
	Ui::ChatDialog* ui;
	ChatUIMode _mode;
	ChatUIMode _state;
	bool _b_loading;
public slots:
	void slotLoadingChatUser();
};
