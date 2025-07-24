#pragma once

#include <QLineEdit>

class CustomizeEdit : public QLineEdit
{
	Q_OBJECT
public:
	explicit CustomizeEdit(QWidget* parent = nullptr);
	~CustomizeEdit();
	void setMaxLength(int maxLen);
protected:
	void focusOutEvent(QFocusEvent* event) override;
private:
	void limitTextLength(QString text);
	int _maxLen;
signals:
	void sigFocusOut();
};