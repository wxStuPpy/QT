#pragma once
#include "bubbleframe.h"
#include <QHBoxLayout>
#include <QPixmap>
class PictureBubble : public BubbleFrame
{
	Q_OBJECT
public:
	PictureBubble(const QPixmap& picture, ChatRole role, QWidget* parent = nullptr);
};