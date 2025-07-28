#include "clickedlabel.h"
#include <QMouseEvent>

ClickedLabel::ClickedLabel(QWidget* parent) : QLabel(parent), _curState(ClickLbState::Normal)
{
	this->setCursor(Qt::PointingHandCursor);
	setFocusPolicy(Qt::NoFocus);
}

void ClickedLabel::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		if (_curState == ClickLbState::Normal) {
			qDebug() << "clicked , change to selected hover: " << _selectedHover;
			_curState = ClickLbState::Selected;
			setProperty("state", _selectedHover);
			rePolish(this);
			update();
		}
		else {
			qDebug() << "clicked , change to normal hover: " << _normalHover;
			_curState = ClickLbState::Normal;
			setProperty("state", _normalHover);
			rePolish(this);
			update();
		}
		return;
	}
	// 调用基类的mousePressEvent以保证正常的事件处理
	QLabel::mousePressEvent(event);
}

void ClickedLabel::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		if (_curState == ClickLbState::Normal) {
			// qDebug()<<"ReleaseEvent , change to normal hover: "<< _normal_hover;
			setProperty("state", _normalHover);
			rePolish(this);
			update();
		}
		else {
			//  qDebug()<<"ReleaseEvent , change to select hover: "<< _selected_hover;
			setProperty("state", _selectedHover);
			rePolish(this);
			update();
		}
		emit clicked(this->text(), _curState);
		return;
	}
	// 调用基类的mousePressEvent以保证正常的事件处理
	QLabel::mousePressEvent(event);
}

void ClickedLabel::enterEvent(QEnterEvent* event)
{
	// 在这里处理鼠标悬停进入的逻辑
	if (_curState == ClickLbState::Normal) {
		qDebug() << "enter , change to normal hover: " << _normalHover;
		setProperty("state", _normalHover);
		rePolish(this);
		update();
	}
	else {
		qDebug() << "enter , change to selected hover: " << _selectedHover;
		setProperty("state", _selectedHover);
		rePolish(this);
		update();
	}
	QLabel::enterEvent(event);
}

void ClickedLabel::leaveEvent(QEvent* event)
{
	// 在这里处理鼠标悬停离开的逻辑
	if (_curState == ClickLbState::Normal) {
		qDebug() << "leave , change to normal : " << _normal;
		setProperty("state", _normal);
		rePolish(this);
		update();
	}
	else {
		qDebug() << "leave , change to normal hover: " << _selected;
		setProperty("state", _selected);
		rePolish(this);
		update();
	}
	QLabel::leaveEvent(event);
}

void ClickedLabel::setState(QString normal, QString hover, QString press, QString select, QString selectHover, QString selectPress)
{
	_normal = normal;
	_normalHover = hover;
	_normalPress = press;
	_selected = select;
	_selectedHover = selectHover;
	_selectedPress = selectPress;
	setProperty("state", normal);
	rePolish(this);
}

bool ClickedLabel::setCurState(ClickLbState state)
{
	_curState = state;
	if (_curState == ClickLbState::Normal) {
		setProperty("state", _normal);
		rePolish(this);
	}
	else if (_curState == ClickLbState::Selected) {
		setProperty("state", _selected);
		rePolish(this);
	}

	return true;
}

ClickLbState ClickedLabel::getCurState()
{
	return _curState;
}

void ClickedLabel::resetNormalState()
{
	_curState = ClickLbState::Normal;
	setProperty("state", _normal);
	rePolish(this);
}