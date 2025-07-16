#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "global.h"

namespace Ui {
	class RegisterDialog;
}

class RegisterDialog : public QDialog
{
	Q_OBJECT

public:
	explicit RegisterDialog(QWidget* parent = nullptr);
	~RegisterDialog();

private slots:
	// 获取验证码按钮的点击事件
	void on_getCode_clicked();

	// 注册模块完成后的回调槽函数
	void regModFinishSlot(ReqID id, QString res, ErrorCodes ec);

	// 确认按钮的点击事件
	void on_confirmBtn_clicked();

	void on_returnBtn_clicked();

private:
	// 初始化处理网络请求的回调函数
	void initHttpHandlers();

	// 显示提示信息的函数，显示成功/失败的提示
	void showTip(QString message, bool success);

	//修改页面
	void changeTipPage();

	Ui::RegisterDialog* ui;

	// 存储注册模块的回调函数，根据不同请求 ID，执行相应的函数
	QMap<ReqID, std::function<void(const QJsonObject&)>> _handlers;

	// 检查用户输入的用户名、邮箱、密码和验证码是否有效
	bool checkUserValid();
	bool checkEmailValid();
	bool checkPassValid();
	bool checkConfirmValid();
	bool checkVerifyValid();

	QMap<TipErr, QString> _tip_errs;
	void AddTipErr(TipErr te, QString tips);
	void DelTipErr(TipErr te);

	QTimer* _countDownTimer;
	int _countDown;

signals:
	void sigSwitchLogin();
};

#endif // REGISTERDIALOG_H
