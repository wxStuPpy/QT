#include "loadingdialog.h"
#include <QMovie>

LoadingDialog::LoadingDialog(QWidget* parent)
	: QDialog(parent), ui(new Ui::LoadingDialog)
{
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog | Qt::WindowStaysOnTopHint | Qt::WindowSystemMenuHint);
	setAttribute(Qt::WA_TranslucentBackground);// 设置窗口透明背景
	//获取尺寸
	setFixedSize(parent->size());
	QMovie* movie = new QMovie(":/res/loading.gif");
	ui->loadingLabel->setMovie(movie);
	movie->start();
}

LoadingDialog::~LoadingDialog()
{
	delete ui;
}