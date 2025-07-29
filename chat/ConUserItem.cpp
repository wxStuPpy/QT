#include "ConUserItem.h"

ConUserItem::ConUserItem(QWidget* parent) :
	ListItemBase(parent),
	ui(new Ui::ConUserItem)
{
	ui->setupUi(this);
	setItemType(ListItemType::CONTACT_USER_ITEM);
	ui->redPoint->raise();
	showRedPoint(true);
}
ConUserItem::~ConUserItem()
{
	delete ui;
}
QSize ConUserItem::sizeHint() const
{
	return QSize(250, 70); // 返回自定义的尺寸
}
void ConUserItem::setInfo(std::shared_ptr<AuthInfo> auth_info)
{
	_info = std::make_shared<UserInfo>(auth_info);
	// 加载图片
	QPixmap pixmap(_info->_icon);
	// 设置图片自动缩放
	ui->iconLabel->setPixmap(pixmap.scaled(ui->iconLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
	ui->iconLabel->setScaledContents(true);
	ui->userNameLabel->setText(_info->_name);
}
void ConUserItem::setInfo(int uid, QString name, QString icon)
{
	_info = std::make_shared<UserInfo>(uid, name, icon);
	// 加载图片
	QPixmap pixmap(_info->_icon);
	// 设置图片自动缩放
	ui->iconLabel->setPixmap(pixmap.scaled(ui->iconLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
	ui->iconLabel->setScaledContents(true);
	ui->userNameLabel->setText(_info->_name);
}
void ConUserItem::setInfo(std::shared_ptr<AuthRsp> auth_rsp) {
	_info = std::make_shared<UserInfo>(auth_rsp);
	// 加载图片
	QPixmap pixmap(_info->_icon);
	// 设置图片自动缩放
	ui->iconLabel->setPixmap(pixmap.scaled(ui->iconLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
	ui->iconLabel->setScaledContents(true);
	ui->userNameLabel->setText(_info->_name);
}
void ConUserItem::showRedPoint(bool show)
{
	if (show) {
		ui->redPoint->show();
	}
	else {
		ui->redPoint->hide();
	}
}