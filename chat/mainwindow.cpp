#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	_loginDialog = new LoginDialog(this);
	_loginDialog->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	setCentralWidget(_loginDialog);
	_loginDialog->show();

	//创建和注册消息连接
	connect(_loginDialog, &LoginDialog::switchRegister, this, &MainWindow::slotSwitchReg);
	connect(_loginDialog, &LoginDialog::switchReset, this, &MainWindow::slotSwitchReset);
}
MainWindow::~MainWindow()
{
	delete ui;
	//    if(_loginDialog){
	//        delete _loginDialog;
	//        _loginDialog=nullptr;
	//    }
	//    if(_regDialog){
	//        delete _regDialog;
	//        _regDialog=nullptr;
	//    }
}

//切换页面会导致原来的login页面被析构 需要重新创建
void MainWindow::slotSwitchLogin()
{
	_loginDialog = new LoginDialog(this);
	_loginDialog->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	setCentralWidget(_loginDialog);
	_loginDialog->show();

	//创建和注册消息连接
	connect(_loginDialog, &LoginDialog::switchRegister, this, &MainWindow::slotSwitchReg);
}

void MainWindow::slotSwitchReset()
{
	//创建一个CentralWidget, 并将其设置为MainWindow的中心部件
	_resetDialog = new ResetDialog(this);
	_resetDialog->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	setCentralWidget(_resetDialog);
	_loginDialog->hide();
	_resetDialog->show();
	//注册返回登录信号和槽函数
	connect(_resetDialog, &ResetDialog::switchLogin, this, &MainWindow::slotSwitchLogin2);
}

void MainWindow::slotSwitchLogin2()
{
	// 切换回登录界面
	_loginDialog = new LoginDialog(this);
	_loginDialog->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	setCentralWidget(_loginDialog);
	_loginDialog->hide(); // 隐藏注册界面
	_loginDialog->show();
	//创建和注册消息连接
	connect(_loginDialog, &LoginDialog::switchRegister, this, &MainWindow::slotSwitchReg);
	// 连接重置密码信号和槽函数
	connect(_loginDialog, &LoginDialog::switchReset, this, &MainWindow::slotSwitchReset);
}

void MainWindow::slotSwitchReg()
{
	_regDialog = new RegisterDialog(this);

	//设置窗口样式
	_regDialog->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	//连接信号和槽
	connect(_regDialog, &RegisterDialog::sigSwitchLogin, this, &MainWindow::slotSwitchLogin);
	setCentralWidget(_regDialog);
	_loginDialog->hide();
	_regDialog->show();
}