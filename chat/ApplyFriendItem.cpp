#include "ApplyFriendItem.h"

ApplyFriendItem::ApplyFriendItem(QWidget* parent) :
	ListItemBase(parent), _added(false),
	ui(new Ui::ApplyFriendItem)
{
	ui->setupUi(this);
	setItemType(ListItemType::APPLY_FRIEND_ITEM);
	ui->addBtn->setState("normal", "hover", "press");
	ui->addBtn->hide();
	connect(ui->addBtn, &ClickedBtn::clicked, [this]() {
		emit this->sigAuthFriend(_apply_info);
		});
}
ApplyFriendItem::~ApplyFriendItem()
{
	delete ui;
}
void ApplyFriendItem::setInfo(std::shared_ptr<ApplyInfo> apply_info)
{
	_apply_info = apply_info;
	// 加载图片
	QPixmap pixmap(_apply_info->_icon);
	// 设置图片自动缩放
	ui->iconLabel->setPixmap(pixmap.scaled(ui->iconLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
	ui->iconLabel->setScaledContents(true);
	ui->userNameLabel->setText(_apply_info->_name);
	ui->userChatLabel->setText(_apply_info->_desc);
}
void ApplyFriendItem::showAddBtn(bool bshow)
{
	if (bshow) {
		ui->addBtn->show();
		ui->alreadyAddLabel->hide();
		_added = false;
	}
	else {
		ui->addBtn->hide();
		ui->alreadyAddLabel->show();
		_added = true;
	}
}
int ApplyFriendItem::getUid() {
	return _apply_info->_uid;
}

QSize ApplyFriendItem::sizeHint() const
{
	return QSize(250, 80);
}