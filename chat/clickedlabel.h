#pragma once
#include <QLabel>
#include "global.h"

class ClickedLabel :public QLabel
{
	Q_OBJECT
public:
	ClickedLabel(QWidget* parent = nullptr);
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void enterEvent(QEnterEvent* event) override;
	void leaveEvent(QEvent* event) override;
	void setState(QString normal = "", QString hover = "", QString press = "",
		QString select = "", QString select_hover = "", QString select_press = "");
	bool setCurState(ClickLbState state);
	ClickLbState getCurState();
	void resetNormalState();
private:
	QString _normal;
	QString _normalHover;
	QString _normalPress;
	QString _selected;
	QString _selectedHover;
	QString _selectedPress;
	ClickLbState _curState;
signals:
	void clicked(QString, ClickLbState);
};