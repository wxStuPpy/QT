#include "customizeedit.h"

CustomizeEdit::CustomizeEdit(QWidget* parent) : QLineEdit(parent), _maxLen(0)
{
	connect(this, &QLineEdit::textChanged, this, &CustomizeEdit::limitTextLength);
}

CustomizeEdit::~CustomizeEdit()
{
}

void CustomizeEdit::setMaxLength(int maxLen)
{
	_maxLen = maxLen;
}

void CustomizeEdit::focusOutEvent(QFocusEvent* event)
{
	// 执行失去焦点时的处理逻辑
	//qDebug() << "CustomizeEdit focusout";
	// 调用基类的focusOutEvent()方法，保证基类的行为得到执行
	QLineEdit::focusOutEvent(event);
	//发送失去焦点得信号
	emit sigFocusOut();
}

void CustomizeEdit::limitTextLength(QString text) {
	if (_maxLen <= 0) {
		return;
	}

	QByteArray byteArray = text.toUtf8();

	if (byteArray.size() > _maxLen) {
		byteArray = byteArray.left(_maxLen);
		this->setText(QString::fromUtf8(byteArray));
	}
}