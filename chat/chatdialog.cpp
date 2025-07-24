#include "chatdialog.h"
#include "clickedbtn.h"
#include <QAction>
#include <QRandomGenerator>
#include "chatuserwid.h"

ChatDialog::ChatDialog(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::ChatDialog), _mode(ChatUIMode::ChatMode),
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

	showSearch(false);
	addChatUserList();
}

ChatDialog::~ChatDialog()
{
	delete ui;
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