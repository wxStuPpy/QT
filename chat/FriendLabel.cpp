#include "FriendLabel.h"
#include <QDebug>
#include "clickedlabel.h"

FriendLabel::FriendLabel(QWidget* parent) :
	QFrame(parent),
	ui(new Ui::FriendLabel)
{
	ui->setupUi(this);
	ui->closeLabel->setState("normal", "hover", "pressed",
		"selected_normal", "selected_hover", "selected_pressed");
	connect(ui->closeLabel, &ClickedLabel::clicked, this, &FriendLabel::slotClose);
}

FriendLabel::~FriendLabel()
{
	delete ui;
}

void FriendLabel::setText(QString& text)
{
	_text = text;
	ui->tipLabel->setText(_text);
	ui->tipLabel->adjustSize();

	QFontMetrics fontMetrics(ui->tipLabel->font()); // 获取QLabel控件的字体信息
	auto textWidth = fontMetrics.horizontalAdvance(ui->tipLabel->text()); // 获取文本的宽度
	auto textHeight = fontMetrics.height(); // 获取文本的高度

	qDebug() << " ui->tipLabel.width() is " << ui->tipLabel->width();
	qDebug() << " ui->closeLabel->width() is " << ui->closeLabel->width();
	qDebug() << " textWidth is " << textWidth;
	this->setFixedWidth(ui->tipLabel->width() + ui->closeLabel->width() + 5);
	this->setFixedHeight(textHeight + 2);
	qDebug() << "  this->setFixedHeight " << this->height();
	_width = this->width();
	_height = this->height();
}

int FriendLabel::width()
{
	return _width;
}

int FriendLabel::height()
{
	return _height;
}

QString FriendLabel::text()
{
	return _text;
}

void FriendLabel::slotClose()
{
	emit sigClose(_text);
}