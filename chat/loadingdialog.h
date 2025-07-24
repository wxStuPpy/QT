#pragma once

#include <QDialog>
#include "ui_loadingdialog.h"

namespace Ui {
	class LoginDialog;
}

class LoadingDialog : public QDialog
{
	Q_OBJECT

public:
	LoadingDialog(QWidget* parent = nullptr);
	~LoadingDialog();

private:
	Ui::LoadingDialog* ui;
};
