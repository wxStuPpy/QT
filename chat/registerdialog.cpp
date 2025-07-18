#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "global.h"
#include "httpmgr.h"

// 构造函数：初始化 UI 和设置初始状态
RegisterDialog::RegisterDialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::RegisterDialog),// 初始化 UI 组件
	_countDown(5)
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
	// 清除初次错误提示标签的文本
	ui->errorLabel->clear();

	connect(ui->userEdit, &QLineEdit::editingFinished, this, [this]() {
		checkUserValid();
		});
	connect(ui->emailEdit, &QLineEdit::editingFinished, this, [this]() {
		checkEmailValid();
		});
	connect(ui->pwdEdit, &QLineEdit::editingFinished, this, [this]() {
		checkPassValid();
		});
	connect(ui->confirmEdit, &QLineEdit::editingFinished, this, [this]() {
		checkConfirmValid();
		});
	connect(ui->verifyEdit, &QLineEdit::editingFinished, this, [this]() {
		checkVerifyValid();
		});

	//设置鼠标指针样式为手型
	ui->pwdVisible->setCursor(Qt::PointingHandCursor);
	ui->confVisible->setCursor(Qt::PointingHandCursor);
	// 设置密码可见性切换按钮的状态
	ui->pwdVisible->setState("unvisible", "unvisible_hover", "", "visible",
		"visible_hover", "");
	ui->confVisible->setState("unvisible", "unvisible_hover", "", "visible",
		"visible_hover", "");

	//连接点击事件
	connect(ui->pwdVisible, &ClickedLabel::clicked, this, [this]() {
		auto state = ui->pwdVisible->getCurState();
		if (state == ClickLbState::Normal) {
			ui->pwdEdit->setEchoMode(QLineEdit::Password);
		}
		else {
			ui->pwdEdit->setEchoMode(QLineEdit::Normal);
		}
		qDebug() << "Label was clicked!";
		});
	connect(ui->confVisible, &ClickedLabel::clicked, this, [this]() {
		auto state = ui->confVisible->getCurState();
		if (state == ClickLbState::Normal) {
			ui->confirmEdit->setEchoMode(QLineEdit::Password);
		}
		else {
			ui->confirmEdit->setEchoMode(QLineEdit::Normal);
		}
		qDebug() << "Label was clicked!";
		});

	// 创建定时器
	_countDownTimer = new QTimer(this);
	// 连接信号和槽
	connect(_countDownTimer, &QTimer::timeout, [this]() {
		if (_countDown == 0) {
			_countDownTimer->stop();
			emit sigSwitchLogin();
			return;
		}
		_countDown--;
		auto str = QString("Registration successful, returning to login in %1 s").arg(_countDown);;
		ui->tip1Label->setText(str);
		});

	//连接返回按钮的点击事件
	connect(ui->returnBtn, &QPushButton::clicked, this, &RegisterDialog::onReturnBtnClicked);
	//连接取消按钮的点击事件
	connect(ui->cancelBtn, &QPushButton::clicked, this, &RegisterDialog::onCancelBtnClicked);
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
		HttpMgr::getInstance()->postHttpReq(QUrl(gateURLPrefix + "/get_verifycode"),
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
		if (error != ErrorCodes::SUCCESS) { // 如果出错，显示错误提示
			showTip(tr("Parameter error"), false);
			qDebug() << "get verify code error is" << error;
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
			qDebug() << "get verify code error is" << error;
			showTip(tr("Parameter error"), false);
			return;
		}
		auto email = jsonObj["email"].toString(); // 获取返回的邮箱
		// 显示注册成功的提示
		showTip(tr("The user has registered successfully."), true);
		qDebug() << "user uid is" << jsonObj["uid"].toString();
		qDebug() << "email is " << email;
		// 切换到登录页面
		changeTipPage();
		});
}
void RegisterDialog::AddTipErr(TipErr te, QString tips)
{
	_tip_errs[te] = tips;
	showTip(tips, false);
}
void RegisterDialog::DelTipErr(TipErr te)
{
	_tip_errs.remove(te);
	if (_tip_errs.empty()) {
		ui->errorLabel->clear();
		return;
	}
	showTip(_tip_errs.first(), false);
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

void RegisterDialog::changeTipPage()
{
	_countDownTimer->stop();
	ui->stackedWidget->setCurrentWidget(ui->page_2);
	// 启动定时器，设置间隔为1000毫秒（1秒）
	_countDownTimer->start(1000);
}

bool RegisterDialog::checkUserValid()
{
	if (ui->userEdit->text() == "") {
		AddTipErr(TipErr::TIP_USER_ERR, tr("The username cannot be empty"));
		return false;
	}
	DelTipErr(TipErr::TIP_USER_ERR);
	return true;
}

bool RegisterDialog::checkEmailValid()
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

bool RegisterDialog::checkPassValid()
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
	QRegularExpression regExp("^[a-zA-Z0-9!@#$%^&*]{6,15}$");
	bool match = regExp.match(pass).hasMatch();
	if (!match) {
		//提示字符非法
		AddTipErr(TipErr::TIP_PWD_ERR, tr("No illegal characters can be included"));
		return false;;
	}
	DelTipErr(TipErr::TIP_PWD_ERR);
	return true;
}

bool RegisterDialog::checkConfirmValid()
{
	auto pwd = ui->pwdEdit->text();
	auto confirm = ui->confirmEdit->text();
	if (pwd != confirm) {
		//提示两次输入的密码不一致
		AddTipErr(TipErr::TIP_CONFIRM_ERR, tr("The two passwords are inconsistent"));
		return false;
	}
	DelTipErr(TipErr::TIP_CONFIRM_ERR);
	return true;
}

bool RegisterDialog::checkVerifyValid()
{
	auto pass = ui->verifyEdit->text();
	if (pass.isEmpty()) {
		AddTipErr(TipErr::TIP_VARIFY_ERR, tr("The verification code cannot be empty"));
		return false;
	}
	DelTipErr(TipErr::TIP_VARIFY_ERR);
	return true;
}

// 确认按钮点击事件
void RegisterDialog::onConfirmBtnClicked()
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

void RegisterDialog::onReturnBtnClicked()
{
	// 停止定时器
	_countDownTimer->stop();
	// 切换到登录页面
	emit sigSwitchLogin();
}

void RegisterDialog::onCancelBtnClicked()
{
	// 停止定时器
	_countDownTimer->stop();
	// 切换到登录页面
	emit sigSwitchLogin();
}