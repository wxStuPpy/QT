#pragma once

#include <QWidget>
#include "userdata.h"
#include <memory>
#include <QJsonArray>
#include <unordered_map>
#include "ApplyFriendItem.h"
#include "ui_ApplyFriendPage.h"

namespace Ui {
	class ApplyFriendPage;
}
class ApplyFriendPage : public QWidget
{
	Q_OBJECT
public:
	explicit ApplyFriendPage(QWidget* parent = nullptr);
	~ApplyFriendPage();
	void addNewApply(std::shared_ptr<AddFriendApply> apply);
protected:
	void paintEvent(QPaintEvent* event);
private:
	void loadApplyList();
	Ui::ApplyFriendPage* ui;
	std::unordered_map<int, ApplyFriendItem*> _unauth_items;
public slots:
	void slotAuthRsp(std::shared_ptr<AuthRsp>);
signals:
	void sigShowSearch(bool);
};
