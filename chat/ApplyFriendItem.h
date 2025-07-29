#pragma once

#include <QWidget>
#include "ui_ApplyFriendItem.h"
#include <memory>
#include "listitembase.h"
#include "userdata.h"

namespace Ui {
	class ApplyFriendItem;
}

class ApplyFriendItem : public ListItemBase
{
	Q_OBJECT
public:
	explicit ApplyFriendItem(QWidget* parent = nullptr);
	~ApplyFriendItem();
	void setInfo(std::shared_ptr<ApplyInfo> apply_info);
	void showAddBtn(bool bshow);
	QSize sizeHint() const override;
	int getUid();
private:
	Ui::ApplyFriendItem* ui;
	std::shared_ptr<ApplyInfo> _apply_info;
	bool _added;
signals:
	void sigAuthFriend(std::shared_ptr<ApplyInfo> apply_info);
};
