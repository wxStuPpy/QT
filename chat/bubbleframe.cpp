#include "bubbleframe.h"
#include <QPainter>

const int WIDTH_SANJIAO = 8;  //三角宽
BubbleFrame::BubbleFrame(ChatRole role, QWidget* parent)
	:QFrame(parent)
	, _role(role)
	, _margin(3)
{
	_pHLayout = new QHBoxLayout();
	if (_role == ChatRole::Self)
		_pHLayout->setContentsMargins(_margin, _margin, WIDTH_SANJIAO + _margin, _margin);
	else
		_pHLayout->setContentsMargins(WIDTH_SANJIAO + _margin, _margin, _margin, _margin);

	this->setLayout(_pHLayout);
}

void BubbleFrame::setWidget(QWidget* w)
{
	if (_pHLayout->count() > 0)
		return;
	else {
		_pHLayout->addWidget(w);
	}
}

void BubbleFrame::paintEvent(QPaintEvent* e)
{
	// 1. 初始化 QPainter
	QPainter painter(this); // 创建一个 QPainter 对象，并指定绘图设备为当前 QWidget (BubbleFrame)。
	// 所有的绘图操作都将在这个 QPainter 上进行。

	painter.setPen(Qt::NoPen); // 设置画笔为“无笔”，意味着后续的形状绘制将没有边框，只有填充色。

	// 2. 根据聊天角色判断绘图方向和颜色
	if (_role == ChatRole::Other) // 如果当前气泡是对方发出的消息 (例如，显示在左侧)
	{
		// 3. 绘制对方气泡的背景 (白色矩形)
		QColor bk_color(Qt::white); // 定义背景颜色为白色。
		painter.setBrush(QBrush(bk_color)); // 设置画刷，用于填充形状，这里用白色填充。

		// 计算气泡矩形区域
		// WIDTH_SANJIAO 应该是三角形的宽度或相关尺寸，用于给三角形留出空间。
		// QRect(x, y, width, height)
		// x: 从 WIDTH_SANJIAO 处开始，为左侧的小三角留出空间。
		// y: 0，从顶部开始。
		// width: 整个 BubbleFrame 的宽度减去小三角的宽度，是矩形气泡的实际宽度。
		// height: 整个 BubbleFrame 的高度。
		QRect bk_rect = QRect(WIDTH_SANJIAO, 0, this->width() - WIDTH_SANJIAO, this->height());
		// 绘制圆角矩形气泡，圆角半径为 5。
		painter.drawRoundedRect(bk_rect, 5, 5);

		// 4. 绘制对方气泡的小三角形
		// 定义三角形的三个顶点坐标
		QPointF points[3] = {
			// 第一个点：矩形左边缘，Y坐标 12 (可能对应气泡上边距或特定垂直位置)
			QPointF(bk_rect.x(), 12),
			// 第二个点：矩形左边缘，Y坐标 10 + 三角形宽度 + 2 (确保三角形底部与气泡相连)
			QPointF(bk_rect.x(), 10 + WIDTH_SANJIAO + 2),
			// 第三个点：向左偏移一个三角形宽度，Y坐标在中间位置，形成尖角
			QPointF(bk_rect.x() - WIDTH_SANJIAO, 10 + WIDTH_SANJIAO - WIDTH_SANJIAO / 2),
		};
		// 使用画刷（白色）填充这个三角形。
		painter.drawPolygon(points, 3); // 绘制并填充多边形（三角形）。
	}
	else // 如果当前气泡是我方发出的消息 (例如，显示在右侧)
	{
		// 5. 绘制我方气泡的背景 (绿色矩形)
		QColor bk_color(158, 234, 106); // 定义背景颜色为浅绿色。
		painter.setBrush(QBrush(bk_color)); // 设置画刷，用绿色填充。

		// 计算气泡矩形区域
		// x: 0，从左侧开始。
		// y: 0，从顶部开始。
		// width: 整个 BubbleFrame 的宽度减去小三角的宽度，因为小三角现在在右侧。
		// height: 整个 BubbleFrame 的高度。
		QRect bk_rect = QRect(0, 0, this->width() - WIDTH_SANJIAO, this->height());
		// 绘制圆角矩形气泡，圆角半径为 5。
		painter.drawRoundedRect(bk_rect, 5, 5);

		// 6. 绘制我方气泡的小三角形
		// 定义三角形的三个顶点坐标
		QPointF points[3] = {
			// 第一个点：矩形右边缘，Y坐标 12 (与对方气泡 Y 坐标对称)
			QPointF(bk_rect.x() + bk_rect.width(), 12),
			// 第二个点：矩形右边缘，Y坐标 12 + 三角形宽度 + 2
			QPointF(bk_rect.x() + bk_rect.width(), 12 + WIDTH_SANJIAO + 2),
			// 第三个点：向右偏移一个三角形宽度，Y坐标在中间位置，形成尖角
			QPointF(bk_rect.x() + bk_rect.width() + WIDTH_SANJIAO, 10 + WIDTH_SANJIAO - WIDTH_SANJIAO / 2),
		};
		// 使用画刷（绿色）填充这个三角形。
		painter.drawPolygon(points, 3); // 绘制并填充多边形（三角形）。
	}

	// 7. 调用基类的 paintEvent
	// 这一行非常重要！它确保了 QFrame (如果 BubbleFrame 继承自 QFrame) 或 QWidget
	// 能够执行其默认的绘图逻辑，例如绘制子控件等。
	// 如果不调用基类的 paintEvent，可能导致子控件无法正常显示。
	return QFrame::paintEvent(e);
}