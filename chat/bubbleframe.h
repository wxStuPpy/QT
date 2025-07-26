#pragma once
#include "global.h"
#include <QFrame>
#include <QHBoxLayout>

class BubbleFrame : public QFrame
{
	Q_OBJECT
public:
	BubbleFrame(ChatRole role, QWidget* parent = nullptr);
	void setMargin(int margin);
	//inline int margin(){return margin;}
	void setWidget(QWidget* w);
protected:
	void paintEvent(QPaintEvent* e);
private:
	QHBoxLayout* _pHLayout;
	ChatRole _role;
	int      _margin;
};
