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
	void on_getCode_clicked();
	void regModFinishSlot(ReqID id, QString res, ErrorCodes ec);
	void on_confirmBtn_clicked();

private:
	void initHttpHandlers();
	void showTip(QString, bool);
	Ui::RegisterDialog* ui;
	QMap<ReqID, std::function<void(const QJsonObject&)>>_handlers;
};

#endif // REGISTERDIALOG_H
