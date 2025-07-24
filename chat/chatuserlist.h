#pragma once

#include <QListWidget>
#include <QWheelEvent>
#include <QEvent>
#include <QScrollBar>
#include <QDebug>
class ChatUserList : public QListWidget
{
	Q_OBJECT
public:
	ChatUserList(QWidget* parent = nullptr);
protected:
	bool eventFilter(QObject* watched, QEvent* event) override;
signals:
	void sigLoadingChatUser();
};