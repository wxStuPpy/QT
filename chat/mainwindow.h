#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logindialog.h"
#include "registerdialog.h"
/******************************************************************************
 *
 * @file       mainwindow.h
 * @brief      XXXX Function
 *
 * @date       2025/06/06
 * @history
 *****************************************************************************/

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

public slots:
	void slotSwitchReg();
	void slotSwitchLogin();

private:
	Ui::MainWindow* ui;
	LoginDialog* _loginDialog;
	RegisterDialog* _regDialog;
};
#endif // MAINWINDOW_H
