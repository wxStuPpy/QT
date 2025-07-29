#pragma once

#include <QWidget>
#include "ui_GroupTipItem.h"
#include "listitembase.h"
#include <QString>

namespace Ui {
	class GroupTipItem;
}

class GroupTipItem : public ListItemBase
{
	Q_OBJECT

public:
	GroupTipItem(QWidget* parent = nullptr);
	~GroupTipItem();
	QSize sizeHint() const override;
	void setGroupTip(QString str);
private:
	QString _tip;
	Ui::GroupTipItem* ui;
};
