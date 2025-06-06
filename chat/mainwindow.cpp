#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _loginDialog=new LoginDialog(this);
    setCentralWidget(_loginDialog);
    _loginDialog->show();

    //创建和注册消息连接
    connect(_loginDialog,&LoginDialog::switchRegister,this,&MainWindow::slotSwitchReg);
    _regDialog=new RegisterDialog(this);

    //设置窗口样式
    _loginDialog->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    _regDialog->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    //初始化隐藏注册窗口
    _regDialog->hide();
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

void MainWindow::slotSwitchReg()
{
    setCentralWidget(_regDialog);
    _loginDialog->hide();
    _regDialog->show();
}

