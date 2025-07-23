#include "clickedbtn.h"
#include "global.h"

ClickedBtn::ClickedBtn(QWidget* parent) : QPushButton(parent)
{
	setCursor(Qt::PointingHandCursor);// 设置鼠标指针为手型
}

ClickedBtn::~ClickedBtn()
{
}

void ClickedBtn::setState(QString normal, QString hover, QString press)
{
	_hover = hover;
	_normal = normal;
	_press = press;
	setProperty("state", normal);
	rePolish(this);
	update();
}

void ClickedBtn::enterEvent(QEnterEvent* event)
{
	setProperty("state", _hover);
	rePolish(this);
	update();
	QPushButton::enterEvent(event);
}

void ClickedBtn::leaveEvent(QEvent* event)
{
	setProperty("state", _normal);
	rePolish(this);
	update();
	QPushButton::leaveEvent(event);
}

void ClickedBtn::mousePressEvent(QMouseEvent* event)
{
	setProperty("state", _press);
	rePolish(this);
	update();
	QPushButton::mousePressEvent(event);
}

void ClickedBtn::mouseReleaseEvent(QMouseEvent* event)
{
	setProperty("state", _hover);
	rePolish(this);
	update();
	QPushButton::mouseReleaseEvent(event);
}