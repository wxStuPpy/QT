#pragma once

#include <QFrame>
#include "ui_FriendLabel.h"

class FriendLabel : public QFrame
{
	Q_OBJECT

public:
	FriendLabel(QWidget* parent = nullptr);
	~FriendLabel();
	void setText(QString& text);
	int width();
	int height();
	QString text();
private:
	Ui::FriendLabel* ui;
	QString _text;
	int _width;
	int _height;
public slots:
	void slotClose();
signals:
	void sigClose(QString);
};
