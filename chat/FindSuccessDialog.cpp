#include "FindSuccessDialog.h"
#include "ui_FindSuccessDialog.h"
#include <QDir>
#include "ApplyFriend.h"

// 移除对 <QDir> 和 <QCoreApplication> 的引用，因为不再需要它们来构建文件系统路径
// #include <QDir>
// #include <QCoreApplication>
#include <QPixmap> // 仍然需要 QPixmap 来处理图片

FindSuccessDialog::FindSuccessDialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::FindSuccessDialog)
{
	ui->setupUi(this);
	// 设置对话框标题
	setWindowTitle("添加");
	// 隐藏对话框标题栏
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	QPixmap head_pix(":/res/head_1.jpg");
	head_pix = head_pix.scaled(ui->headLabel->size(),
		Qt::KeepAspectRatio, Qt::SmoothTransformation);
	ui->headLabel->setPixmap(head_pix);
	ui->addFriendBtn->setState("normal", "hover", "press");
	this->setModal(true);
	connect(ui->addFriendBtn, &QPushButton::clicked, this, &FindSuccessDialog::onAddFriendBtnClicked);
}

FindSuccessDialog::~FindSuccessDialog()
{
	delete ui;
}

void FindSuccessDialog::SetSearchInfo(std::shared_ptr<SearchInfo> si)
{
	ui->nameLabel->setText(si->_name);
	_si = si;
}

void FindSuccessDialog::onAddFriendBtnClicked() {
	this->hide();
	//弹出加好友界面
	auto applyFriend = new ApplyFriend(_parent);
	applyFriend->SetSearchInfo(_si);
	applyFriend->setModal(true);
	applyFriend->show();
}