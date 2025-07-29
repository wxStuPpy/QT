#pragma once
#include <QListWidget>
#include <QEvent>
#include <QWheelEvent>
#include <QScrollBar>
#include <QDebug>
#include <memory>
#include "userdata.h"
class ConUserItem;

class ContactUserList : public QListWidget
{
	Q_OBJECT
public:
	ContactUserList(QWidget* parent = nullptr);
	void showRedPoint(bool bshow = true);
protected:
	bool eventFilter(QObject* watched, QEvent* event) override;
private:
	void addContactUserList();
public slots:
	void slotItemClicked(QListWidgetItem* item);
	// void slotAddAuthFirend(std::shared_ptr<AuthInfo>);
	// void slotAuthRsp(std::shared_ptr<AuthRsp>);
signals:
	void sigLoadingContactUser();
	void sigSwitchApplyFriendPage();
	// void sigSwitchFriendInfoPage(std::shared_ptr<UserInfo> user_info);
private:
	bool _load_pending;
	ConUserItem* _add_friend_item;
	QListWidgetItem* _groupitem;
};
