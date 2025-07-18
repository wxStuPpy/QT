#include "logindialog.h"
#include "ui_logindialog.h"
#include <QPainter>
#include <QPainterPath>
#include <QDebug>

void LoginDialog::onLoginBtnClicked()
{
	qDebug() << "login btn clicked";
	if (checkUserValid() == false) {
		return;
	}
	if (checkPwdValid() == false) {
		return;
	}
	auto user = ui->user_edit->text();
	auto pwd = ui->pass_edit->text();
	//发送http请求登录
	QJsonObject json_obj;
	json_obj["user"] = user;
	json_obj["passwd"] = xorString(pwd);
	HttpMgr::GetInstance()->PostHttpReq(QUrl(gate_url_prefix + "/user_login"),
		json_obj, ReqId::ID_LOGIN_USER, Modules::LOGINMOD);
}

LoginDialog::LoginDialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::LoginDialog)
{
	ui->setupUi(this);
	//切换窗口到注册界面
	connect(ui->regBtn, &QPushButton::clicked, this, &LoginDialog::switchRegister);
	ui->forgetLabel->setState("normal", "hover", "", "selected", "selected_hover", "");
	connect(ui->forgetLabel, &ClickedLabel::clicked, this, &LoginDialog::slotForgetPwd);
	connect(ui->loginBtn, &QPushButton::clicked, this, &LoginDialog::onLoginBtnClicked);
	initHeadImg(); // 初始化头像图片
}

LoginDialog::~LoginDialog()
{
	delete ui;
}

void LoginDialog::initHeadImg()
{
	// 加载图片
	QPixmap originalPixmap(":/res/head_1.jpg");
	// 设置图片自动缩放
	qDebug() << originalPixmap.size() << ui->headLabel->size();
	originalPixmap = originalPixmap.scaled(ui->headLabel->size(),
		Qt::KeepAspectRatio, Qt::SmoothTransformation);

	// 创建一个和原始图片相同大小的QPixmap，用于绘制圆角图片
	QPixmap roundedPixmap(originalPixmap.size());
	roundedPixmap.fill(Qt::transparent); // 用透明色填充

	QPainter painter(&roundedPixmap);
	painter.setRenderHint(QPainter::Antialiasing); // 设置抗锯齿，使圆角更平滑
	painter.setRenderHint(QPainter::SmoothPixmapTransform);

	// 使用QPainterPath设置圆角
	QPainterPath path;
	path.addRoundedRect(0, 0, originalPixmap.width(), originalPixmap.height(), 10, 10); // 最后两个参数分别是x和y方向的圆角半径
	painter.setClipPath(path);

	// 将原始图片绘制到roundedPixmap上
	painter.drawPixmap(0, 0, originalPixmap);

	// 设置绘制好的圆角图片到QLabel上
	ui->headLabel->setPixmap(roundedPixmap);
}

bool LoginDialog::checkUserValid()
{
	return false;
}

void LoginDialog::slotForgetPwd() {
	// 处理忘记密码逻辑
	qDebug() << "Forget password clicked!";
	emit switchReset(); // 这里可以发出信号切换到注册界面或其他处理
}