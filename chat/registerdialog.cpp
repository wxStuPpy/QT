#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "global.h"
#include "httpmgr.h"

RegisterDialog::RegisterDialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::RegisterDialog)
{
	ui->setupUi(this);
	//设置输入类型
	ui->pwdEdit->setEchoMode(QLineEdit::Password);
	ui->confirmEdit->setEchoMode(QLineEdit::Password);
	//设置初始状态
	ui->errorLabel->setProperty("state", "normal");
	//刷新
	rePolish(ui->errorLabel);
	connect(HttpMgr::getInstance().get(), &HttpMgr::regModFinishSig
		, this, &RegisterDialog::regModFinishSlot);
	initHttpHandlers();
}

RegisterDialog::~RegisterDialog()
{
	delete ui;
}

void RegisterDialog::on_getCode_clicked()
{
	auto email = ui->emailEdit->text();
	QRegularExpression regx(R"((\w+)(\.|_)?@(\w+)(\.(\w+))+)");
	//匹配正则表达式
	if (regx.match(email).hasMatch()) {
		//send HttpCode
		QJsonObject jsonObj;
		jsonObj["email"] = email;
		HttpMgr::getInstance()->postHttpReq(QUrl(gateURLPrefix + "/post_test"),
			jsonObj, ReqID::ID_GET_VARIFY_CODE, Modules::REGISTERMOD);
	}
	else {
		showTip(tr("error eamil!"), false);
	}
}

void RegisterDialog::regModFinishSlot(ReqID id, QString res, ErrorCodes ec)
{
	if (ec != ErrorCodes::SUCCESS) {
		showTip(tr("网络请求错误"), false);
		return;
	}

	//解析Json,res转化为QByteArray
	QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
	if (jsonDoc.isNull()) {
		showTip(tr("json解析失败"), false);
		return;
	}
	//json解析错误
	if (!jsonDoc.isObject()) {
		showTip(tr("json解析失败"), false);
		return;
	}
	_handlers[id](jsonDoc.object());
}

void RegisterDialog::initHttpHandlers()
{
	//注册获取验证码回包的逻辑
	_handlers.insert(ReqID::ID_GET_VARIFY_CODE, [this](const QJsonObject& jsonObj) {
		int error = jsonObj["error"].toInt();
		if (error != ErrorCodes::SUCCESS) {
			showTip(tr("Parameter error"), false);
			return;
		}
		auto email = jsonObj["email"].toString();
		showTip(tr("The verification code has been sent to the email"), true);
		qDebug() << "email is" << email;
		});

	_handlers.insert(ReqID::ID_REG_USER, [this](QJsonObject jsonObj) {
		int error = jsonObj["error"].toInt();
		if (error != ErrorCodes::SUCCESS) {
			showTip(tr("Parameter error"), false);
			return;
		}
		auto email = jsonObj["email"].toString();
		showTip(tr("The user has registered successfully."), true);
		qDebug() << "user uid is" << jsonObj["uid"].toString();
		qDebug() << "email is " << email;
		});
}

void RegisterDialog::showTip(QString str, bool ok)
{
	ui->errorLabel->setText(str);
	if (ok)
	{
		ui->errorLabel->setProperty("state", "normal");
	}
	else {
		ui->errorLabel->setProperty("state", "error");
	}
	rePolish(ui->errorLabel);
}

void RegisterDialog::on_confirmBtn_clicked()
{
	if (ui->userEdit->text() == "") {
		showTip(tr("The username cannot be empty"), false);
		return;
	}
	if (ui->emailEdit->text() == "") {
		showTip(tr("The email cannot be empty"), false);
		return;
	}
	if (ui->pwdEdit->text() == "") {
		showTip(tr("The password cannot be empty"), false);
		return;
	}
	if (ui->confirmEdit->text() == "") {
		showTip(tr("The confirm password cannot be empty"), false);
		return;
	}
	if (ui->confirmEdit->text() != ui->pwdEdit->text()) {
		showTip(tr("The password and the confirmation password do not match"), false);
		return;
	}
	if (ui->verifyEdit->text() == "") {
		showTip(tr("The verification code cannot be empty"), false);
		return;
	}
	//day11 发送http请求注册用户
	QJsonObject json_obj;
	json_obj["user"] = ui->userEdit->text();
	json_obj["email"] = ui->emailEdit->text();
	json_obj["passwd"] = ui->pwdEdit->text();
	json_obj["confirm"] = ui->confirmEdit->text();
	json_obj["verifycode"] = ui->verifyEdit->text();
	HttpMgr::getInstance()->postHttpReq(QUrl(gateURLPrefix + "/user_register"),
		json_obj, ReqID::ID_REG_USER, Modules::REGISTERMOD);
}