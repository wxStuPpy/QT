#include "timerbtn.h"
#include <QMouseEvent>
#include <QDebug>

TimerBtn::TimerBtn(QWidget* parent) : QPushButton(parent), _timer(new QTimer(this)), _counter(10)
{
	connect(_timer, &QTimer::timeout, [this]() {
		_counter--;
		if (_counter <= 0) {
			_timer->stop();
			_counter = 10;
			this->setText("Resend code");
			this->setEnabled(true);
			return;
		}
		this->setText(QString::number(_counter));
		});
}

TimerBtn::~TimerBtn()
{
	_timer->stop();
}

void TimerBtn::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		// 在这里处理鼠标左键释放事件
		qDebug() << "MyButton was released!";
		this->setEnabled(false);
		this->setText(QString::number(_counter));
		_timer->start(1000);
		emit clicked(); // 发出点击信号
	}
	QPushButton::mouseReleaseEvent(event); // 调用基类的事件处理
}