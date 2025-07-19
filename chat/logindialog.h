#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "global.h"

namespace Ui {
	class LoginDialog;
}

class LoginDialog : public QDialog
{
	Q_OBJECT

signals:
	void sigSwitchRegister();
	void sigSwitchReset();
	void sigConnectTCP(ServerInfo);

private slots:
	void slotForgetPwd();
	void onLoginBtnClicked();
	void slotLoginModFinish(ReqID id, QString res, ErrorCodes err);

public:
	explicit LoginDialog(QWidget* parent = nullptr);
	~LoginDialog();

private:
	Ui::LoginDialog* ui;
	QMap<TipErr, QString> _tip_errs;
	QMap<ReqID, std::function<void(const QJsonObject&)>> _handlers;
	void initHeadImg();
	bool checkEmailValid();
	bool checkPwdValid();
	void AddTipErr(TipErr te, QString tips);
	void DelTipErr(TipErr te);
	void showTip(QString str, bool b_ok);
	void enable(bool b_enable);
	void initHttpHandlers();
};

#endif // LOGINDIALOG_H
