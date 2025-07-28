#pragma once

#include <QFrame>
#include "ui_FriendLabel.h"

class FriendLabel : public QFrame
{
	Q_OBJECT

public:
	FriendLabel(QWidget* parent = nullptr);
	~FriendLabel();

private:
	Ui::FriendLabel ui;
};
