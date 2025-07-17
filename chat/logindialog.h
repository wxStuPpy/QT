#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
	class LoginDialog;
}

class LoginDialog : public QDialog
{
	Q_OBJECT

signals:
	void switchRegister();
	void switchReset();

public slots:
	void slotForgetPwd();

public:
	explicit LoginDialog(QWidget* parent = nullptr);
	~LoginDialog();

private:
	Ui::LoginDialog* ui;
};

#endif // LOGINDIALOG_H
