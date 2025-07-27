#include "chatdialog.h"
#include "clickedbtn.h"
#include <QAction>
#include <QRandomGenerator>
#include "chatuserwid.h"
#include "chatuserlist.h"
#include "loadingdialog.h"
#include <QMouseEvent>

ChatDialog::ChatDialog(QWidget* parent)
	: QDialog(parent)
	, ui(new Ui::ChatDialog), _mode(ChatUIMode::ChatMode), _b_loading(false),
	_state(ChatUIMode::ChatMode)
{
	ui->setupUi(this);
	ui->addBtn->setState("normal", "hover", "press");
	ui->searchEdit->setMaxLength(15);

	QAction* searchAction = new QAction(ui->searchEdit);
	searchAction->setIcon(QIcon(":/res/search.png"));
	ui->searchEdit->addAction(searchAction, QLineEdit::LeadingPosition);
	ui->searchEdit->setPlaceholderText(QStringLiteral("search"));
	// 创建一个清除动作并设置图标
	QAction* clearAction = new QAction(ui->searchEdit);
	clearAction->setIcon(QIcon(":/res/close_transparent.png"));

	// 初始时不显示清除图标
	// 将清除动作添加到LineEdit的末尾位置
	ui->searchEdit->addAction(clearAction, QLineEdit::TrailingPosition);
	// 当需要显示清除图标时，更改为实际的清除图标
	connect(ui->searchEdit, &QLineEdit::textChanged, [clearAction](const QString& text) {
		if (!text.isEmpty()) {
			clearAction->setIcon(QIcon(":/res/close_search.png"));
		}
		else {
			clearAction->setIcon(QIcon(":/res/close_transparent.png")); // 文本为空时，切换回透明图标
		}
		});

	// 连接清除动作的触发信号到槽函数，用于清除文本
	connect(clearAction, &QAction::triggered, [this, clearAction]() {
		ui->searchEdit->clear();
		clearAction->setIcon(QIcon(":/res/close_transparent.png")); // 清除文本后，切换回透明图标
		ui->searchEdit->clearFocus();
		//清除按钮被按下则不显示搜索框
		showSearch(false);
		});
	ui->searchEdit->setMaxLength(15);
	showSearch(false);
	connect(ui->userList, &ChatUserList::sigLoadingChatUser, this, &ChatDialog::slotLoadingChatUser);
	addChatUserList();

	QPixmap pixmap(":/res/head_1.jpg");
	ui->headLabel->setPixmap(pixmap); // 将图片设置到QLabel上
	QPixmap scaledPixmap = pixmap.scaled(ui->headLabel->size(), Qt::KeepAspectRatio); // 将图片缩放到label的大小
	ui->headLabel->setPixmap(scaledPixmap); // 将缩放后的图片设置到QLabel上
	ui->headLabel->setScaledContents(true); // 设置QLabel自动缩放图片内容以适应大小

	ui->chatWid->setProperty("state", "normal");

	ui->chatWid->setState("normal", "hover", "pressed", "selected_normal", "selected_hover", "selected_pressed");

	ui->contactWid->setState("normal", "hover", "pressed", "selected_normal", "selected_hover", "selected_pressed");

	addLBGroup(ui->chatWid);
	addLBGroup(ui->contactWid);

	connect(ui->chatWid, &StateWidget::clicked, this, &ChatDialog::slotSideChat);
	connect(ui->contactWid, &StateWidget::clicked, this, &ChatDialog::slotSideContact);

	//链接搜索框输入变化
	connect(ui->searchEdit, &QLineEdit::textChanged, this, &ChatDialog::slotTextChanged);

	this->installEventFilter(this);//安装事件过滤器
}

ChatDialog::~ChatDialog()
{
	delete ui;
}

bool ChatDialog::eventFilter(QObject* watched, QEvent* event) {
	if (event->type() == QEvent::MouseButtonPress) {
		QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
		handleGlobalMousePress(mouseEvent);
	}
	return QDialog::eventFilter(watched, event);
}

void ChatDialog::handleGlobalMousePress(QMouseEvent* event)
{
	// 实现点击位置的判断和处理逻辑
	// 先判断是否处于搜索模式，如果不处于搜索模式则直接返回
	if (_mode != ChatUIMode::SearchMode) {
		return;
	}

	// 将鼠标点击位置转换为搜索列表坐标系中的位置
	QPoint posInSearchList = ui->searchList->mapFromGlobal(event->globalPos());
	// 判断点击位置是否在聊天列表的范围内
	if (!ui->searchList->rect().contains(posInSearchList)) {
		// 如果不在聊天列表内，清空输入框
		ui->searchEdit->clear();
		showSearch(false);
	}
}

void ChatDialog::showSearch(bool bsearch = false)
{
	if (bsearch) {
		ui->userList->hide();
		ui->conUserList->hide();
		ui->searchList->show();
		_mode = ChatUIMode::SearchMode;
	}
	else if (_state == ChatUIMode::ChatMode) {
		ui->userList->show();
		ui->conUserList->hide();
		ui->searchList->hide();
		_mode = ChatUIMode::ChatMode;
	}
	else if (_state == ChatUIMode::ContactMode) {
		ui->userList->hide();
		ui->searchList->hide();
		ui->conUserList->show();
		_mode = ChatUIMode::ContactMode;
	}
}

void ChatDialog::addLBGroup(StateWidget* lb)
{
	_lb_list.push_back(lb);
}

void ChatDialog::clearLabelState(StateWidget* lb)
{
	for (auto& ele : _lb_list) {
		if (ele == lb) {
			continue;
		}

		ele->clearState();
	}
}

void ChatDialog::slotSideChat()
{
	qDebug() << "receive side chat clicked";
	clearLabelState(ui->chatWid);
	ui->stackedWidget->setCurrentWidget(ui->chatPage);
	_state = ChatUIMode::ChatMode;
	showSearch(false);
}

void ChatDialog::slotSideContact()
{
	qDebug() << "receive side contact clicked";
	clearLabelState(ui->contactWid);
	//设置
	ui->stackedWidget->setCurrentWidget(ui->friendApplyPage);
	_state = ChatUIMode::ContactMode;
	showSearch(false);
}

void ChatDialog::slotTextChanged(const QString& str)
{
	//qDebug()<< "receive slot text changed str is " << str;
	if (!str.isEmpty()) {
		showSearch(true);
	}
}

#if 1
std::vector<QString>  strs = { "hello world !",
							 "nice to meet u",
							 "New year，new life",
							"You have to love yourself",
							"My love is written in the wind ever since the whole world is you" };
std::vector<QString> heads = {
	":/res/head_1.jpg",
	":/res/head_2.jpg",
	":/res/head_3.jpg",
	":/res/head_4.jpg",
	":/res/head_5.jpg"
};
std::vector<QString> names = {
	"llfc",
	"zack",
	"golang",
	"cpp",
	"java",
	"nodejs",
	"python",
	"rust"
};

#endif

void ChatDialog::addChatUserList()
{
	// 创建QListWidgetItem，并设置自定义的widget
	for (int i = 0; i < 13; i++) {
		int randomValue = QRandomGenerator::global()->bounded(100); // 生成0到99之间的随机整数
		int str_i = randomValue % strs.size();
		int head_i = randomValue % heads.size();
		int name_i = randomValue % names.size();
		auto* chat_user_wid = new ChatUserWid();
		chat_user_wid->setInfo(names[name_i], heads[head_i], strs[str_i]);
		QListWidgetItem* item = new QListWidgetItem;
		//qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
		item->setSizeHint(chat_user_wid->sizeHint());
		ui->userList->addItem(item);
		ui->userList->setItemWidget(item, chat_user_wid);
	}
}

void ChatDialog::slotLoadingChatUser() {
	if (_b_loading) {
		return;
	}
	_b_loading = true;
	LoadingDialog* loadingDialog = new LoadingDialog(this);
	loadingDialog->setModal(true);
	loadingDialog->show();
	qDebug() << "add new data to list.....";
	addChatUserList();
	// 加载完成后关闭对话框
	loadingDialog->deleteLater();
	_b_loading = false;
}