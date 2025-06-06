#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "global.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    //设置输入类型
    ui->pwdEdit->setEchoMode(QLineEdit::Password);
    ui->confirmEdit->setEchoMode(QLineEdit::Password);
    //设置初始状态
    ui->errorLabel->setProperty("state","normal");
    //刷新
    rePolish(ui->errorLabel);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_getCode_clicked()
{
    auto email=ui->emailEdit->text();
    QRegularExpression regx(R"((\w+)(\.|_)?@(\w+)(\.(\w+))+)");
    //匹配正则表达式
    if(regx.match(email).hasMatch()){
        //send HttpCode
    }
    else{
       showTip(tr("邮箱不正确!"),false);
    }
}

void RegisterDialog::showTip(QString str,bool ok)
{   ui->errorLabel->setText(str);
    if(ok)
    {
        ui->errorLabel->setProperty("state","normal");
    }
    else{
        ui->errorLabel->setProperty("state","error");
    }
    rePolish(ui->errorLabel);
}

