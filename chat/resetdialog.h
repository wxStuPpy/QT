#pragma once
#include <QDialog>
#include "global.h"

namespace Ui {
	class ResetDialog;
}

class ResetDialog : public QDialog
{
	Q_OBJECT

public:
	explicit ResetDialog(QWidget* parent = nullptr);
	~ResetDialog();

private slots:
	void onReturnBtnClicked();
	void onVerifyBtnClicked();
	void slotResetModFinish(ReqID id, QString res, ErrorCodes err);
	void onSureBtnClicked();
	//void on_cancel_btn_clicked();

private:
	bool checkUserValid();
	bool checkPassValid();
	void showTip(QString str, bool b_ok);
	bool checkEmailValid();
	bool checkVerifyValid();
	void AddTipErr(TipErr te, QString tips);
	void DelTipErr(TipErr te);
	void initHandlers();
	Ui::ResetDialog* ui;
	QMap<TipErr, QString> _tip_errs;
	QMap<ReqID, std::function<void(const QJsonObject&)>> _handlers;
signals:
	void switchLogin();
};
