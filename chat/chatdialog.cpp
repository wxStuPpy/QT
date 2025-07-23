#include "chatdialog.h"
#include "ui_chatdialog.h"
#include "clickedbtn.h"

ChatDialog::ChatDialog(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::ChatDialogClass)
{
	ui->setupUi(this);
	ui->addBtn->setState("normal", "hover", "press");
}

ChatDialog::~ChatDialog()
{
}