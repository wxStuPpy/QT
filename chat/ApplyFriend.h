#pragma once

#include <QDialog>
#include "ui_ApplyFriend.h"

class ApplyFriend : public QDialog
{
	Q_OBJECT

public:
	ApplyFriend(QWidget* parent = nullptr);
	~ApplyFriend();

private:
	Ui::ApplyFriend ui;
};
