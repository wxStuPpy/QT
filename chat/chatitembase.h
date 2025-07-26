#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include "global.h"

class BubbleFrame;

class ChatItemBase : public QWidget
{
	Q_OBJECT
public:
	explicit ChatItemBase(ChatRole role, QWidget* parent = nullptr);
	void setUserName(const QString& name);
	void setUserIcon(const QPixmap& icon);
	void setWidget(QWidget* w);

private:
	ChatRole _role;
	QLabel* _pNameLabel;
	QLabel* _pIconLabel;
	QWidget* _pBubble;
};
