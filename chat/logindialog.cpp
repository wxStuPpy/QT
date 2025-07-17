#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::LoginDialog)
{
	ui->setupUi(this);
	//切换窗口到注册界面
	connect(ui->regBtn, &QPushButton::clicked, this, &LoginDialog::switchRegister);
	ui->forgetLabel->setState("normal", "hover", "", "selected", "selected_hover", "");
	connect(ui->forgetLabel, &ClickedLabel::clicked, this, &LoginDialog::slotForgetPwd);
}

LoginDialog::~LoginDialog()
{
	delete ui;
}

void LoginDialog::slotForgetPwd() {
	// 处理忘记密码逻辑
	qDebug() << "Forget password clicked!";
	emit switchReset(); // 这里可以发出信号切换到注册界面或其他处理
}