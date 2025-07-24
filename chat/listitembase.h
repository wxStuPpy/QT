#pragma once

#include <QWidget>
#include "global.h"
#include <QEvent>
class ListItemBase : public QWidget
{
	Q_OBJECT
public:
	explicit ListItemBase(QWidget* parent = nullptr);
	void setItemType(ListItemType itemType);
	ListItemType getItemType();
protected:
	virtual void paintEvent(QPaintEvent* event);
private:
	ListItemType _itemType;
public slots:
signals:
};