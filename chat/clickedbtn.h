#pragma once

#include<QPushButton>
#include<QObject>

class ClickedBtn : public QPushButton
{
	Q_OBJECT
public:
	ClickedBtn(QWidget* parent = nullptr);
	~ClickedBtn();
	void setState(QString normal, QString hover, QString press);
protected:
	void enterEvent(QEnterEvent* event) override;
	void leaveEvent(QEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
private:
	QString _normal;
	QString _hover;
	QString _press;
};
