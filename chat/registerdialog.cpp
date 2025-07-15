#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "global.h"
#include "httpmgr.h"

// 构造函数：初始化 UI 和设置初始状态
RegisterDialog::RegisterDialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::RegisterDialog) // 初始化 UI 组件
{
	ui->setupUi(this); // 设置界面
	// 设置密码输入框为密码模式，隐藏密码
	ui->pwdEdit->setEchoMode(QLineEdit::Password);
	ui->confirmEdit->setEchoMode(QLineEdit::Password);
	// 设置初始错误提示状态
	ui->errorLabel->setProperty("state", "normal");
	// 刷新控件状态
	rePolish(ui->errorLabel);
	// 连接 HTTP 请求完成的信号与槽
	connect(HttpMgr::getInstance().get(), &HttpMgr::regModFinishSig,
		this, &RegisterDialog::regModFinishSlot);
	// 初始化 HTTP 请求的回调处理
	initHttpHandlers();
}

// 析构函数：销毁 UI 组件
RegisterDialog::~RegisterDialog()
{
	delete ui;
}

// 获取验证码按钮点击事件
void RegisterDialog::on_getCode_clicked()
{
	auto email = ui->emailEdit->text(); // 获取用户输入的电子邮件
	// 正则表达式用于验证邮箱格式
	QRegularExpression regx(R"((\w+)(\.|_)?@(\w+)(\.(\w+))+)");

	// 使用正则表达式进行匹配
	if (regx.match(email).hasMatch()) {
		// 如果邮箱格式正确，发送 HTTP 请求
		QJsonObject jsonObj;
		jsonObj["email"] = email; // 将邮箱放入 JSON 请求体
		HttpMgr::getInstance()->postHttpReq(QUrl(gateURLPrefix + "/post_test"),
			jsonObj, ReqID::ID_GET_VERIFY_CODE, Modules::REGISTERMOD);
	}
	else {
		// 如果邮箱格式不正确，显示错误提示
		showTip(tr("error email!"), false);
	}
}

// 注册模块完成后的回调函数
void RegisterDialog::regModFinishSlot(ReqID id, QString res, ErrorCodes ec)
{
	if (ec != ErrorCodes::SUCCESS) { // 网络请求失败
		showTip(tr("error NetWork"), false);
		return;
	}

	// 解析返回的 JSON 数据
	QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
	if (jsonDoc.isNull()) { // JSON 解析失败
		showTip(tr("JSON parsing failed"), false);
		return;
	}

	// 检查解析是否为一个 JSON 对象
	if (!jsonDoc.isObject()) {
		showTip(tr("JSON parsing failed"), false);
		return;
	}
	// 调用对应的回调函数处理返回的数据
	_handlers[id](jsonDoc.object());
}

// 初始化 HTTP 请求的回调处理函数
void RegisterDialog::initHttpHandlers()
{
	// 处理获取验证码的回调
	_handlers.insert(ReqID::ID_GET_VERIFY_CODE, [this](const QJsonObject& jsonObj) {
		int error = jsonObj["error"].toInt(); // 获取错误码
		qDebug() << "get verify code error is" << error;
		if (error != ErrorCodes::SUCCESS) { // 如果出错，显示错误提示
			showTip(tr("Parameter error"), false);
			return;
		}
		auto email = jsonObj["email"].toString(); // 获取返回的邮箱
		// 显示验证码发送成功的提示
		showTip(tr("The verification code has been sent to the email"), true);
		qDebug() << "email is" << email;
		});

	// 处理用户注册的回调
	_handlers.insert(ReqID::ID_REG_USER, [this](QJsonObject jsonObj) {
		int error = jsonObj["error"].toInt(); // 获取错误码
		if (error != ErrorCodes::SUCCESS) { // 如果出错，显示错误提示
			showTip(tr("Parameter error"), false);
			return;
		}
		auto email = jsonObj["email"].toString(); // 获取返回的邮箱
		// 显示注册成功的提示
		showTip(tr("The user has registered successfully."), true);
		qDebug() << "user uid is" << jsonObj["uid"].toString();
		qDebug() << "email is " << email;
		});
}

// 显示提示信息
void RegisterDialog::showTip(QString str, bool ok)
{
	ui->errorLabel->setText(str); // 设置提示信息文本
	if (ok) {
		// 如果成功，设置为正常状态
		ui->errorLabel->setProperty("state", "normal");
	}
	else {
		// 如果失败，设置为错误状态
		ui->errorLabel->setProperty("state", "error");
	}
	// 刷新控件
	rePolish(ui->errorLabel);
}

// 确认按钮点击事件
void RegisterDialog::on_confirmBtn_clicked()
{
	// 检查各项输入是否为空，若为空则显示提示
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
		// 如果密码和确认密码不匹配，显示提示
		showTip(tr("The password and the confirmation password do not match"), false);
		return;
	}
	if (ui->verifyEdit->text() == "") {
		showTip(tr("The verification code cannot be empty"), false);
		return;
	}

	// 如果输入有效，构建 JSON 请求体并发送 HTTP 请求注册用户
	QJsonObject json_obj;
	json_obj["user"] = ui->userEdit->text();
	json_obj["email"] = ui->emailEdit->text();
	json_obj["passwd"] = xorString(ui->pwdEdit->text());
	json_obj["confirm"] = xorString(ui->confirmEdit->text());
	json_obj["verifycode"] = ui->verifyEdit->text();
	// 发送用户注册的 HTTP 请求
	HttpMgr::getInstance()->postHttpReq(QUrl(gateURLPrefix + "/user_register"),
		json_obj, ReqID::ID_REG_USER, Modules::REGISTERMOD);
}