#pragma once

#include <QListWidget>
#include <QEvent>

class ApplyFriendList : public QListWidget
{
	Q_OBJECT
public:
	ApplyFriendList(QWidget* parent = nullptr);
protected:
	bool eventFilter(QObject* watched, QEvent* event) override;

private slots:
signals:
	void sigShowSearch(bool);
};
