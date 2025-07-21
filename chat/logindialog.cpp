#include "logindialog.h"
#include "ui_logindialog.h"
#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include "httpmgr.h"
#include "tcpmgr.h"

LoginDialog::LoginDialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::LoginDialog)
{
	ui->setupUi(this);
	//切换窗口到注册界面
	connect(ui->regBtn, &QPushButton::clicked, this, &LoginDialog::sigSwitchRegister);
	ui->forgetLabel->setState("normal", "hover", "", "selected", "selected_hover", "");
	connect(ui->forgetLabel, &ClickedLabel::clicked, this, &LoginDialog::slotForgetPwd);
	connect(ui->loginBtn, &QPushButton::clicked, this, &LoginDialog::onLoginBtnClicked);
	initHeadImg(); // 初始化头像图片
	initHttpHandlers();
	connect(HttpMgr::getInstance().get(), &HttpMgr::sigLoginModFinish, this, &LoginDialog::slotLoginModFinish);

	//连接tcp连接请求的信号和槽函数
	connect(this, &LoginDialog::sigConnectTCP, TcpMgr::getInstance().get(), &TcpMgr::slotTcpConnect);
	//连接tcp管理者发出的连接成功信号
	connect(TcpMgr::getInstance().get(), &TcpMgr::sigConnectSuccess, this, &LoginDialog::slotTcpConnFinish);
	//连接tcp管理者发出的登陆失败信号
	connect(TcpMgr::getInstance().get(), &TcpMgr::sigLoginFailed, this, &LoginDialog::slotLoginFailed);
}

LoginDialog::~LoginDialog()
{
	delete ui;
}

bool LoginDialog::checkEmailValid()
{
	auto user = ui->emailEdit->text();
	if (user.isEmpty()) {
		qDebug() << "Email empty ";
		AddTipErr(TipErr::TIP_USER_ERR, tr("The email cannot be empty"));
		return false;
	}
	DelTipErr(TipErr::TIP_USER_ERR);
	return true;
}

bool LoginDialog::checkPwdValid()
{
	auto pass = ui->pwdEdit->text();
	QRegularExpression regExp("^[a-zA-Z0-9!@#$%^&*.]{6,15}$");
	bool match = regExp.match(pass).hasMatch();
	if (!match) {
		//提示字符非法
		AddTipErr(TipErr::TIP_PWD_ERR, tr("No illegal characters can be included"));
		return false;;
	}
	DelTipErr(TipErr::TIP_PWD_ERR);
	return true;
}

void LoginDialog::onLoginBtnClicked()
{
	qDebug() << "login btn clicked";
	if (checkEmailValid() == false) {
		return;
	}
	if (checkPwdValid() == false) {
		return;
	}
	auto email = ui->emailEdit->text();
	auto pwd = ui->pwdEdit->text();
	enableBtn(false);
	//发送http请求登录
	QJsonObject json_obj;
	json_obj["email"] = email;
	json_obj["passwd"] = xorString(pwd);
	HttpMgr::getInstance()->postHttpReq(QUrl(gateURLPrefix + "/user_login"),
		json_obj, ReqID::ID_LOGIN_USER, Modules::LOGINMOD);
}

void LoginDialog::slotLoginModFinish(ReqID id, QString res, ErrorCodes err)
{
	if (err != ErrorCodes::SUCCESS) {
		showTip(tr("error network"), false);
		return;
	}

	// 解析 JSON 字符串,res需转化为QByteArray
	QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
	//json解析错误
	if (jsonDoc.isNull()) {
		showTip(tr("json parsing error"), false);
		return;
	}

	//json解析错误
	if (!jsonDoc.isObject()) {
		showTip(tr("json parsing error"), false);
		return;
	}
	//调用对应的逻辑,根据id回调。
	_handlers[id](jsonDoc.object());

	return;
}

void LoginDialog::slotTcpConnFinish(bool bsuccess)
{
	if (bsuccess) {
		showTip(tr("connected chatserver successfully，Logining..."), true);
		QJsonObject jsonObj;
		jsonObj["uid"] = _uid;
		jsonObj["token"] = _token;

		QJsonDocument doc(jsonObj);
		QByteArray jsonData = doc.toJson(QJsonDocument::Indented);

		//发送tcp请求给chat server
		emit TcpMgr::getInstance()->sigSendData(ReqID::ID_CHAT_LOGIN, jsonData);
	}
	else {
		showTip(tr("error network"), false);
		enableBtn(true);
	}
}

void LoginDialog::slotLoginFailed(int err)
{
	QString result = QString("login failed, err is %1")
		.arg(err);
	showTip(result, false);
	enableBtn(true);
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

void LoginDialog::slotForgetPwd() {
	// 处理忘记密码逻辑
	qDebug() << "Forget password clicked!";
	emit sigSwitchReset(); // 这里可以发出信号切换到注册界面或其他处理
}

void LoginDialog::AddTipErr(TipErr te, QString tips)
{
	_tip_errs[te] = tips;
	showTip(tips, false);
}

void LoginDialog::DelTipErr(TipErr te)
{
	_tip_errs.remove(te);
	if (_tip_errs.empty()) {
		ui->errorLabel->clear();
		return;
	}

	showTip(_tip_errs.first(), false);
}

void LoginDialog::showTip(QString str, bool b_ok)
{
	if (b_ok) {
		ui->errorLabel->setProperty("state", "normal");
	}
	else {
		ui->errorLabel->setProperty("state", "error");
	}

	ui->errorLabel->setText(str);

	rePolish(ui->errorLabel);
}

void LoginDialog::enableBtn(bool b_enable)
{
	if (b_enable) {
		ui->emailEdit->setEnabled(true);
		ui->pwdEdit->setEnabled(true);
		ui->loginBtn->setEnabled(true);
		ui->regBtn->setEnabled(true);
	}
	else {
		ui->emailEdit->setDisabled(true);
		ui->pwdEdit->setDisabled(true);
		ui->loginBtn->setDisabled(true);
		ui->regBtn->setDisabled(true);
	}
}

void LoginDialog::initHttpHandlers()
{
	//注册获取登录回包逻辑
	_handlers.insert(ReqID::ID_LOGIN_USER, [this](QJsonObject jsonObj) {
		int error = jsonObj["error"].toInt();
		if (error != ErrorCodes::SUCCESS) {
			showTip(tr("Parameter error"), false);
			return;
		}
		auto email = jsonObj["email"].toString();
		showTip(tr("Login successfully"), true);
		qDebug() << "email is " << email;

		ServerInfo server_info;
		server_info.Host = jsonObj["host"].toString();
		server_info.Port = jsonObj["port"].toString();
		server_info.Token = jsonObj["token"].toString();
		server_info.Uid = jsonObj["uid"].toInt();
		qDebug() << "email is " << email << " uid is " << server_info.Uid << " host is "
			<< server_info.Host << " Port is " << server_info.Port << " Token is " << server_info.Token;
		emit sigConnectTCP(server_info);
		});
}