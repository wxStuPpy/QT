#pragma once

#include <QWidget>
#include "ui_ConUserItem.h"
#include "listitembase.h"
#include "userdata.h"

class ConUserItem : public ListItemBase
{
	Q_OBJECT
public:
	explicit ConUserItem(QWidget* parent = nullptr);
	~ConUserItem();
	QSize sizeHint() const override;
	void setInfo(std::shared_ptr<AuthInfo> auth_info);
	void setInfo(std::shared_ptr<AuthRsp> auth_rsp);
	void setInfo(int uid, QString name, QString icon);
	void showRedPoint(bool show = false);
private:
	Ui::ConUserItem* ui;
	std::shared_ptr<UserInfo> _info;
};
