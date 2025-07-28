#include "ApplyFriend.h"
#include "clickedlabel.h"
#include "FriendLabel.h"
#include <QScrollBar>
#include "usermgr.h"
#include "tcpmgr.h"

ApplyFriend::ApplyFriend(QWidget* parent) :
	QDialog(),
	ui(new Ui::ApplyFriend), _label_point(2, 6)
{
	ui->setupUi(this);
	// 隐藏对话框标题栏
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	this->setObjectName("ApplyFriend");
	this->setModal(true);
	ui->nameEdit->setPlaceholderText(tr("llfc"));
	ui->labelEdit->setPlaceholderText("search add tag");
	ui->backEdit->setPlaceholderText("bill");

	ui->labelEdit->setMaxLength(21);
	ui->labelEdit->move(2, 2);
	ui->labelEdit->setFixedHeight(20);
	ui->labelEdit->setMaxLength(10);
	ui->inputTipWid->hide();

	_tip_cur_point = QPoint(5, 5);

	_tip_data = {
	"Classmate",        // 同学
	"Family",           // 家人
	"Rookie Tutorial",  // 菜鸟教程
	"C++ Primer",       // C++ Primer（书名通常保留原名）
	"Rust Programming", // Rust 程序设计
	"Parent and Child Learn Python", // 父与子学Python
	"Node.js Development Guide",     // nodejs开发指南
	"Go Language Development Guide", // go 语言开发指南
	"Game Partner",     // 游戏伙伴
	"Financial Investment", // 金融投资
	"WeChat Reading",   // 微信读书
	"Pinduoduo Shopping Mate" // 拼多多拼友
	};

	connect(ui->moreLabel, &ClickedOnceLabel::clicked, this, &ApplyFriend::showMoreLabel);
	InitTipLbs();
	//链接输入标签回车事件
	connect(ui->labelEdit, &CustomizeEdit::returnPressed, this, &ApplyFriend::slotLabelEnter);
	connect(ui->labelEdit, &CustomizeEdit::textChanged, this, &ApplyFriend::slotLabelTextChange);
	connect(ui->labelEdit, &CustomizeEdit::editingFinished, this, &ApplyFriend::slotLabelEditFinished);
	connect(ui->tipLabel, &ClickedOnceLabel::clicked, this, &ApplyFriend::slotAddFirendLabelByClickTip);

	ui->scrollArea->horizontalScrollBar()->setHidden(true);
	ui->scrollArea->verticalScrollBar()->setHidden(true);
	ui->scrollArea->installEventFilter(this);
	ui->sureBtn->setState("normal", "hover", "press");
	ui->cancelBtn->setState("normal", "hover", "press");
	//连接确认和取消按钮的槽函数
	connect(ui->cancelBtn, &QPushButton::clicked, this, &ApplyFriend::slotApplyCancel);
	connect(ui->sureBtn, &QPushButton::clicked, this, &ApplyFriend::slotApplySure);
}

ApplyFriend::~ApplyFriend()
{
	qDebug() << "ApplyFriend destruct";
	delete ui;
}

void ApplyFriend::InitTipLbs()
{
	int lines = 1;
	for (int i = 0; i < _tip_data.size(); i++) {
		auto* lb = new ClickedLabel(ui->labelListWid);
		lb->setState("normal", "hover", "pressed", "selected_normal",
			"selected_hover", "selected_pressed");
		lb->setObjectName("tipslb");
		lb->setText(_tip_data[i]);
		connect(lb, &ClickedLabel::clicked, this, &ApplyFriend::slotChangeFriendLabelByTip);

		QFontMetrics fontMetrics(lb->font()); // 获取QLabel控件的字体信息
		int textWidth = fontMetrics.horizontalAdvance(lb->text()); // 获取文本的宽度
		int textHeight = fontMetrics.height(); // 获取文本的高度

		if (_tip_cur_point.x() + textWidth + tip_offset > ui->labelListWid->width()) {
			lines++;
			if (lines > 2) {
				delete lb;
				return;
			}

			_tip_cur_point.setX(tip_offset);
			_tip_cur_point.setY(_tip_cur_point.y() + textHeight + 15);
		}

		auto next_point = _tip_cur_point;

		AddTipLbs(lb, _tip_cur_point, next_point, textWidth, textHeight);

		_tip_cur_point = next_point;
	}
}

void ApplyFriend::AddTipLbs(ClickedLabel* lb, QPoint cur_point, QPoint& next_point, int text_width, int text_height)
{
	Q_UNUSED(text_height);
	lb->move(cur_point);
	lb->show();
	_add_labels.insert(lb->text(), lb);
	_add_label_keys.push_back(lb->text());
	next_point.setX(lb->pos().x() + text_width + 15);
	next_point.setY(lb->pos().y());
}

bool ApplyFriend::eventFilter(QObject* obj, QEvent* event)
{
	if (obj == ui->scrollArea && event->type() == QEvent::Enter)
	{
		ui->scrollArea->verticalScrollBar()->setHidden(false);
	}
	else if (obj == ui->scrollArea && event->type() == QEvent::Leave)
	{
		ui->scrollArea->verticalScrollBar()->setHidden(true);
	}
	return QObject::eventFilter(obj, event);
}

void ApplyFriend::SetSearchInfo(std::shared_ptr<SearchInfo> si)
{
	_si = si;
	auto applyname = UserMgr::getInstance()->getName();
	auto bakname = si->_name;
	ui->nameEdit->setText(applyname);
	ui->backEdit->setText(bakname);
}

void ApplyFriend::showMoreLabel()
{
	qDebug() << "receive more label clicked";
	ui->moreLabelWid->hide();

	ui->labelListWid->setFixedWidth(325);
	_tip_cur_point = QPoint(5, 5);
	auto next_point = _tip_cur_point;
	int textWidth;
	int textHeight;
	//重拍现有的label
	for (auto& added_key : _add_label_keys) {
		auto added_lb = _add_labels[added_key];

		QFontMetrics fontMetrics(added_lb->font()); // 获取QLabel控件的字体信息
		textWidth = fontMetrics.horizontalAdvance(added_lb->text()); // 获取文本的宽度
		textHeight = fontMetrics.height(); // 获取文本的高度

		if (_tip_cur_point.x() + textWidth + tip_offset > ui->labelListWid->width()) {
			_tip_cur_point.setX(tip_offset);
			_tip_cur_point.setY(_tip_cur_point.y() + textHeight + 15);
		}
		added_lb->move(_tip_cur_point);

		next_point.setX(added_lb->pos().x() + textWidth + 15);
		next_point.setY(_tip_cur_point.y());

		_tip_cur_point = next_point;
	}

	//添加未添加的
	for (int i = 0; i < _tip_data.size(); i++) {
		auto iter = _add_labels.find(_tip_data[i]);
		if (iter != _add_labels.end()) {
			continue;
		}

		auto* lb = new ClickedLabel(ui->labelListWid);
		lb->setState("normal", "hover", "pressed", "selected_normal",
			"selected_hover", "selected_pressed");
		lb->setObjectName("tipslb");
		lb->setText(_tip_data[i]);
		connect(lb, &ClickedLabel::clicked, this, &ApplyFriend::slotChangeFriendLabelByTip);

		QFontMetrics fontMetrics(lb->font()); // 获取QLabel控件的字体信息
		int textWidth = fontMetrics.horizontalAdvance(lb->text()); // 获取文本的宽度
		int textHeight = fontMetrics.height(); // 获取文本的高度

		if (_tip_cur_point.x() + textWidth + tip_offset > ui->labelListWid->width()) {
			_tip_cur_point.setX(tip_offset);
			_tip_cur_point.setY(_tip_cur_point.y() + textHeight + 15);
		}

		next_point = _tip_cur_point;

		AddTipLbs(lb, _tip_cur_point, next_point, textWidth, textHeight);

		_tip_cur_point = next_point;
	}

	int diff_height = next_point.y() + textHeight + tip_offset - ui->labelListWid->height();
	ui->labelListWid->setFixedHeight(next_point.y() + textHeight + tip_offset);

	//qDebug()<<"after resize ui->labelListWid size is " <<  ui->labelListWid->size();
	ui->scrollContents->setFixedHeight(ui->scrollContents->height() + diff_height);
}

void ApplyFriend::resetLabels()
{
	auto max_width = ui->gridWid->width();
	auto label_height = 0;
	for (auto iter = _friend_labels.begin(); iter != _friend_labels.end(); iter++) {
		//todo... 添加宽度统计
		if (_label_point.x() + iter.value()->width() > max_width) {
			_label_point.setY(_label_point.y() + iter.value()->height() + 6);
			_label_point.setX(2);
		}

		iter.value()->move(_label_point);
		iter.value()->show();

		_label_point.setX(_label_point.x() + iter.value()->width() + 2);
		_label_point.setY(_label_point.y());
		label_height = iter.value()->height();
	}

	if (_friend_labels.isEmpty()) {
		ui->labelEdit->move(_label_point);
		return;
	}

	if (_label_point.x() + MIN_APPLY_LABEL_ED_LEN > ui->gridWid->width()) {
		ui->labelEdit->move(2, _label_point.y() + label_height + 6);
	}
	else {
		ui->labelEdit->move(_label_point);
	}
}

void ApplyFriend::addLabel(QString name)
{
	if (_friend_labels.find(name) != _friend_labels.end()) {
		ui->labelEdit->clear();
		return;
	}

	auto tmplabel = new FriendLabel(ui->gridWid);
	tmplabel->setText(name);
	tmplabel->setObjectName("FriendLabel");

	auto max_width = ui->gridWid->width();
	//todo... 添加宽度统计
	if (_label_point.x() + tmplabel->width() > max_width) {
		_label_point.setY(_label_point.y() + tmplabel->height() + 6);
		_label_point.setX(2);
	}
	else {
	}

	tmplabel->move(_label_point);
	tmplabel->show();
	_friend_labels[tmplabel->text()] = tmplabel;
	_friend_label_keys.push_back(tmplabel->text());

	connect(tmplabel, &FriendLabel::sigClose, this, &ApplyFriend::slotRemoveFriendLabel);

	_label_point.setX(_label_point.x() + tmplabel->width() + 2);

	if (_label_point.x() + MIN_APPLY_LABEL_ED_LEN > ui->gridWid->width()) {
		ui->labelEdit->move(2, _label_point.y() + tmplabel->height() + 2);
	}
	else {
		ui->labelEdit->move(_label_point);
	}

	ui->labelEdit->clear();

	if (ui->gridWid->height() < _label_point.y() + tmplabel->height() + 2) {
		ui->gridWid->setFixedHeight(_label_point.y() + tmplabel->height() * 2 + 2);
	}
}

void ApplyFriend::slotLabelEnter()
{
	if (ui->labelEdit->text().isEmpty()) {
		return;
	}

	auto text = ui->labelEdit->text();

	addLabel(ui->labelEdit->text());

	ui->inputTipWid->hide();

	auto find_it = std::find(_tip_data.begin(), _tip_data.end(), text);
	//找到了就只需设置状态为选中即可
	if (find_it == _tip_data.end()) {
		_tip_data.push_back(text);
	}

	//判断标签展示栏是否有该标签
	auto find_add = _add_labels.find(text);
	if (find_add != _add_labels.end()) {
		find_add.value()->setCurState(ClickLbState::Selected);
		return;
	}

	//标签展示栏也增加一个标签, 并设置绿色选中
	auto* lb = new ClickedLabel(ui->labelListWid);
	lb->setState("normal", "hover", "pressed", "selected_normal",
		"selected_hover", "selected_pressed");
	lb->setObjectName("tipslb");
	lb->setText(text);
	connect(lb, &ClickedLabel::clicked, this, &ApplyFriend::slotChangeFriendLabelByTip);
	qDebug() << "ui->labelListWid->width() is " << ui->labelListWid->width();
	qDebug() << "_tip_cur_point.x() is " << _tip_cur_point.x();

	QFontMetrics fontMetrics(lb->font()); // 获取QLabel控件的字体信息
	int textWidth = fontMetrics.horizontalAdvance(lb->text()); // 获取文本的宽度
	int textHeight = fontMetrics.height(); // 获取文本的高度
	qDebug() << "textWidth is " << textWidth;

	if (_tip_cur_point.x() + textWidth + tip_offset + 3 > ui->labelListWid->width()) {
		_tip_cur_point.setX(5);
		_tip_cur_point.setY(_tip_cur_point.y() + textHeight + 15);
	}

	auto next_point = _tip_cur_point;

	AddTipLbs(lb, _tip_cur_point, next_point, textWidth, textHeight);
	_tip_cur_point = next_point;

	int diff_height = next_point.y() + textHeight + tip_offset - ui->labelListWid->height();
	ui->labelListWid->setFixedHeight(next_point.y() + textHeight + tip_offset);

	lb->setCurState(ClickLbState::Selected);

	ui->scrollContents->setFixedHeight(ui->scrollContents->height() + diff_height);
}

void ApplyFriend::slotRemoveFriendLabel(QString name)
{
	qDebug() << "receive close signal";

	_label_point.setX(2);
	_label_point.setY(6);

	auto find_iter = _friend_labels.find(name);

	if (find_iter == _friend_labels.end()) {
		return;
	}

	auto find_key = _friend_label_keys.end();
	for (auto iter = _friend_label_keys.begin(); iter != _friend_label_keys.end();
		iter++) {
		if (*iter == name) {
			find_key = iter;
			break;
		}
	}

	if (find_key != _friend_label_keys.end()) {
		_friend_label_keys.erase(find_key);
	}

	delete find_iter.value();

	_friend_labels.erase(find_iter);

	resetLabels();

	auto find_add = _add_labels.find(name);
	if (find_add == _add_labels.end()) {
		return;
	}

	find_add.value()->resetNormalState();
}

//点击标已有签添加或删除新联系人的标签
void ApplyFriend::slotChangeFriendLabelByTip(QString lbtext, ClickLbState state)
{
	auto find_iter = _add_labels.find(lbtext);
	if (find_iter == _add_labels.end()) {
		return;
	}

	if (state == ClickLbState::Selected) {
		//编写添加逻辑
		addLabel(lbtext);
		return;
	}

	if (state == ClickLbState::Normal) {
		//编写删除逻辑
		slotRemoveFriendLabel(lbtext);
		return;
	}
}

void ApplyFriend::slotLabelTextChange(const QString& text)
{
	if (text.isEmpty()) {
		ui->tipLabel->setText("");
		ui->inputTipWid->hide();
		return;
	}

	auto iter = std::find(_tip_data.begin(), _tip_data.end(), text);
	if (iter == _tip_data.end()) {
		auto new_text = add_prefix + text;
		ui->tipLabel->setText(new_text);
		ui->inputTipWid->show();
		return;
	}
	ui->tipLabel->setText(text);
	ui->inputTipWid->show();
}

void ApplyFriend::slotLabelEditFinished()
{
	ui->inputTipWid->hide();
}

void ApplyFriend::slotAddFirendLabelByClickTip(QString text)
{
	int index = text.indexOf(add_prefix);
	if (index != -1) {
		text = text.mid(index + add_prefix.length());
	}
	addLabel(text);

	auto find_it = std::find(_tip_data.begin(), _tip_data.end(), text);
	//找到了就只需设置状态为选中即可
	if (find_it == _tip_data.end()) {
		_tip_data.push_back(text);
	}

	//判断标签展示栏是否有该标签
	auto find_add = _add_labels.find(text);
	if (find_add != _add_labels.end()) {
		find_add.value()->setCurState(ClickLbState::Selected);
		return;
	}

	//标签展示栏也增加一个标签, 并设置绿色选中
	auto* lb = new ClickedLabel(ui->labelListWid);
	lb->setState("normal", "hover", "pressed", "selected_normal",
		"selected_hover", "selected_pressed");
	lb->setObjectName("tipslb");
	lb->setText(text);
	connect(lb, &ClickedLabel::clicked, this, &ApplyFriend::slotChangeFriendLabelByTip);
	qDebug() << "ui->labelListWid->width() is " << ui->labelListWid->width();
	qDebug() << "_tip_cur_point.x() is " << _tip_cur_point.x();

	QFontMetrics fontMetrics(lb->font()); // 获取QLabel控件的字体信息
	int textWidth = fontMetrics.horizontalAdvance(lb->text()); // 获取文本的宽度
	int textHeight = fontMetrics.height(); // 获取文本的高度
	qDebug() << "textWidth is " << textWidth;

	if (_tip_cur_point.x() + textWidth + tip_offset + 3 > ui->labelListWid->width()) {
		_tip_cur_point.setX(5);
		_tip_cur_point.setY(_tip_cur_point.y() + textHeight + 15);
	}

	auto next_point = _tip_cur_point;

	AddTipLbs(lb, _tip_cur_point, next_point, textWidth, textHeight);
	_tip_cur_point = next_point;

	int diff_height = next_point.y() + textHeight + tip_offset - ui->labelListWid->height();
	ui->labelListWid->setFixedHeight(next_point.y() + textHeight + tip_offset);

	lb->setCurState(ClickLbState::Selected);

	ui->scrollContents->setFixedHeight(ui->scrollContents->height() + diff_height);
}

void ApplyFriend::slotApplySure()
{
	qDebug() << "slot Apply Sure called";
	//发送请求逻辑
	QJsonObject jsonObj;
	auto uid = UserMgr::getInstance()->getUid();
	jsonObj["uid"] = uid;
	auto name = ui->nameEdit->text();
	if (name.isEmpty()) {
		name = ui->nameEdit->placeholderText();
	}

	jsonObj["applyname"] = name;

	auto bakname = ui->backEdit->text();
	if (bakname.isEmpty()) {
		bakname = ui->backEdit->placeholderText();
	}

	jsonObj["bakname"] = bakname;
	jsonObj["touid"] = _si->_uid;

	QJsonDocument doc(jsonObj);
	QByteArray jsonData = doc.toJson(QJsonDocument::Compact);

	//发送tcp请求给chat server
	emit TcpMgr::getInstance()->sigSendData(ReqID::ID_ADD_FRIEND_REQ, jsonData);
	this->hide();
	deleteLater();
}

void ApplyFriend::slotApplyCancel()
{
	qDebug() << "slot Apply Cancel";
	this->hide();
	deleteLater();
}