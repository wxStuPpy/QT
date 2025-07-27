#pragma once

#include <QMainWindow>
#include "ui_chatdialog.h"
#include "global.h"
#include "statewidget.h"

class ChatDialog : public QMainWindow
{
	Q_OBJECT

public:
	ChatDialog(QWidget* parent = nullptr);
	~ChatDialog();
	void addChatUserList();
private:
	void showSearch(bool bsearch);
	void addLBGroup(StateWidget* s);
	void clearLabelState(StateWidget* s);
	Ui::ChatDialog* ui;
	ChatUIMode _mode;
	ChatUIMode _state;
	bool _b_loading;
	QList<StateWidget*> _lb_list; //鼠标点击标签的状态组
public slots:
	void slotLoadingChatUser();
	void slotSideChat();
	void slotSideContact();
	void slotTextChanged(const QString& str);
};
