#pragma once

#include <QPushButton>
#include <QTimer>

class TimerBtn : public QPushButton
{
	Q_OBJECT
public:
	explicit TimerBtn(QWidget* parent = nullptr);
	~TimerBtn();
	void mouseReleaseEvent(QMouseEvent* event) override;
private:
	QTimer* _timer;
	int _counter;
};
