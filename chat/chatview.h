#pragma once
#include <QWidget>      // 包含 QWidget 基类，ChatView 继承自它
#include <QScrollArea>  // 包含 QScrollArea，用于提供可滚动的区域来显示聊天项
#include <QVBoxLayout>  // 包含 QVBoxLayout，用于垂直布局聊天项
#include <QTimer>       /
// ChatView 类，继承自 QWidget，用于显示聊天消息的视图
class ChatView : public QWidget
{
	Q_OBJECT // 必须添加此宏，以支持 Qt 的元对象系统，包括信号和槽

public:
	// 构造函数，parent 参数指定父 QWidget
	ChatView(QWidget* parent = Q_NULLPTR);

	// 尾部插入聊天项（例如：新的消息通常添加到列表底部）
	void appendChatItem(QWidget* item);

	// 头部插入聊天项（例如：加载历史消息时可能用到）
	void prependChatItem(QWidget* item);

	// 在指定聊天项之前插入新聊天项
	void insertChatItem(QWidget* before, QWidget* item);

	// 移除所有聊天项
	void removeAllItem();

protected:
	// 事件过滤器，用于拦截和处理发送给特定对象的事件
	// 在这里可能用于处理滚动区域的鼠标滚轮事件、大小改变事件等，以实现自定义行为
	bool eventFilter(QObject* o, QEvent* e) override;

	// 绘图事件处理函数，当需要重绘控件时调用
	// 可能用于绘制背景、边框或其他自定义视觉元素
	void paintEvent(QPaintEvent* event) override;

private slots:
	// 自定义槽函数，用于响应垂直滚动条移动事件
	// min 和 max 可能表示滚动条的范围或当前值
	// 实际的 QScrollBar::valueChanged 信号通常只带一个 int 参数，这里可能是自定义处理逻辑
	void onVScrollBarMoved(int min, int max);

private:
	// 初始化样式表，可能用于设置 ChatView 的外观（背景、边框等）
	void initStyleSheet();

private:
	// QWidget *m_pCenterWidget; // 注释掉的成员变量，可能曾用于中心部件，但目前未使用

	QVBoxLayout* pVl;          // 垂直布局管理器，用于排列聊天项
	QScrollArea* pScrollArea;  // 滚动区域，包含聊天项，并提供滚动功能
	bool isAppended;           // 一个布尔标志，可能用于控制滚动行为（例如，是否自动滚动到底部）
};