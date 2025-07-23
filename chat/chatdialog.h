#pragma once

#include <QMainWindow>
#include "ui_chatdialog.h"

class ChatDialog : public QMainWindow
{
	Q_OBJECT

public:
	ChatDialog(QWidget* parent = nullptr);
	~ChatDialog();

private:
	Ui::ChatDialogClass* ui;
};
