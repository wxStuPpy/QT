#include "resetdialog.h"
#include "ui_resetdialog.h"
#include <QDebug>
#include <QRegularExpression>
#include "global.h"
#include "httpmgr.h"

ResetDialog::ResetDialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::ResetDialog)
{
	ui->setupUi(this);

	connect(ui->userEdit, &QLineEdit::editingFinished, this, [this]() {
		checkUserValid();
		});

	connect(ui->emailEdit, &QLineEdit::editingFinished, this, [this]() {
		checkEmailValid();
		});

	connect(ui->pwdEdit, &QLineEdit::editingFinished, this, [this]() {
		checkPassValid();
		});

	connect(ui->verifyEdit, &QLineEdit::editingFinished, this, [this]() {
		checkVerifyValid();
		});

	//连接reset相关信号和注册处理回调
	initHandlers();
	connect(HttpMgr::getInstance().get(), &HttpMgr::resetModFinishSig, this,
		&ResetDialog::slotResetModFinish);
}

ResetDialog::~ResetDialog()
{
	delete ui;
}

void ResetDialog::on_return_btn_clicked()
{
	qDebug() << "sure btn clicked ";
	emit switchLogin();
}

void ResetDialog::on_verify_btn_clicked()
{
	qDebug() << "receive verify btn clicked ";
	auto email = ui->emailEdit->text();
	auto bcheck = checkEmailValid();
	if (!bcheck) {
		return;
	}

	//发送http请求获取验证码
	QJsonObject json_obj;
	json_obj["email"] = email;
	HttpMgr::getInstance()->postHttpReq(QUrl(gateURLPrefix + "/get_verifycode"),
		json_obj, ReqID::ID_GET_VERIFY_CODE, Modules::RESETMOD);
}

void ResetDialog::slotResetModFinish(ReqID id, QString res, ErrorCodes err)
{
	if (err != ErrorCodes::SUCCESS) {
		showTip(tr("Network error"), false);
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

bool ResetDialog::checkUserValid()
{
	if (ui->userEdit->text() == "") {
		AddTipErr(TipErr::TIP_USER_ERR, tr("The username cannot be empty"));
		return false;
	}

	DelTipErr(TipErr::TIP_USER_ERR);
	return true;
}

bool ResetDialog::checkPassValid()
{
	auto pass = ui->pwdEdit->text();

	if (pass.length() < 6 || pass.length() > 15) {
		//提示长度不准确
		AddTipErr(TipErr::TIP_PWD_ERR, tr("The password length should be 6 to 15"));
		return false;
	}

	// 创建一个正则表达式对象，按照上述密码要求
	// 这个正则表达式解释：
	// ^[a-zA-Z0-9!@#$%^&*]{6,15}$ 密码长度至少6，可以是字母、数字和特定的特殊字符
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

bool ResetDialog::checkEmailValid()
{
	//验证邮箱的地址正则表达式
	auto email = ui->emailEdit->text();
	// 邮箱地址的正则表达式
	QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
	bool match = regex.match(email).hasMatch(); // 执行正则表达式匹配
	if (!match) {
		//提示邮箱不正确
		AddTipErr(TipErr::TIP_EMAIL_ERR, tr("The email address is incorrect"));
		return false;
	}

	DelTipErr(TipErr::TIP_EMAIL_ERR);
	return true;
}

bool ResetDialog::checkVerifyValid()
{
	auto pass = ui->verifyEdit->text();
	if (pass.isEmpty()) {
		AddTipErr(TipErr::TIP_VARIFY_ERR, tr("The verification code cannot be empty"));
		return false;
	}

	DelTipErr(TipErr::TIP_VARIFY_ERR);
	return true;
}

void ResetDialog::AddTipErr(TipErr te, QString tips)
{
	_tip_errs[te] = tips;
	showTip(tips, false);
}

void ResetDialog::DelTipErr(TipErr te)
{
	_tip_errs.remove(te);
	if (_tip_errs.empty()) {
		ui->err_tip->clear();
		return;
	}

	showTip(_tip_errs.first(), false);
}

void ResetDialog::initHandlers()
{
	//注册获取验证码回包逻辑
	_handlers.insert(ReqID::ID_GET_VERIFY_CODE, [this](QJsonObject jsonObj) {
		int error = jsonObj["error"].toInt();
		if (error != ErrorCodes::SUCCESS) {
			showTip(tr("Parameter error"), false);
			return;
		}
		auto email = jsonObj["email"].toString();
		showTip(tr("The verification code has been sent to your email."), true);
		qDebug() << "email is " << email;
		});

	//注册注册用户回包逻辑
	_handlers.insert(ReqID::ID_RESET_PWD, [this](QJsonObject jsonObj) {
		int error = jsonObj["error"].toInt();
		if (error != ErrorCodes::SUCCESS) {
			showTip(tr("Parameter error"), false);
			return;
		}
		auto email = jsonObj["email"].toString();
		showTip(tr("Reset successful. Click \"Return to Login\""), true);
		qDebug() << "email is " << email;
		});
}

void ResetDialog::showTip(QString str, bool b_ok)
{
	if (b_ok) {
		ui->err_tip->setProperty("state", "normal");
	}
	else {
		ui->err_tip->setProperty("state", "err");
	}

	ui->err_tip->setText(str);

	rePolish(ui->err_tip);
}

void ResetDialog::on_sure_btn_clicked()
{
	bool valid = checkUserValid();
	if (!valid) {
		return;
	}

	valid = checkEmailValid();
	if (!valid) {
		return;
	}

	valid = checkPassValid();
	if (!valid) {
		return;
	}

	valid = checkVerifyValid();
	if (!valid) {
		return;
	}

	//发送http重置用户请求
	QJsonObject json_obj;
	json_obj["user"] = ui->userEdit->text();
	json_obj["email"] = ui->emailEdit->text();
	json_obj["passwd"] = xorString(ui->pwdEdit->text());
	json_obj["verifycode"] = ui->verifyEdit->text();
	HttpMgr::getInstance()->postHttpReq(QUrl(gateURLPrefix + "/reset_pwd"),
		json_obj, ReqID::ID_RESET_PWD, Modules::RESETMOD);
}

//void ResetDialog::on_cancel_btn_clicked()
//{
//	qDebug() << "cancel btn clicked ";
//	emit switchLogin();
//}