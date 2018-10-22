#include "QVTKLine.h"

QVTKLine::QVTKLine(QWidget* parent) : QFrame(parent)
{
	isMove = false;
	setStyleSheet("background-color:white;");
	setCursor(Qt::CrossCursor);
}


QVTKLine::~QVTKLine()
{
}

void QVTKLine::setDirection(QVTKLineDirection d)
{
	Direction = d;
}

void QVTKLine::setGeometry(int loc, int w, int h)
{
	if (Direction == QVTKLineDirection::horizontal)
	{
		return QFrame::setGeometry(0, loc - 1, w, 2);
	}
	else
	{
		return QFrame::setGeometry(loc - 1, 0, 2, h);
	}
}

void QVTKLine::setGeometry(int x, int y, int w, int h)
{
	return QFrame::setGeometry(x, y, w, h);
}

void QVTKLine::setGeometry(const QRect &x)
{
	return QFrame::setGeometry(x);
}

void QVTKLine::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		isMove = true;
		start = event->globalPos();
		status = geometry();
	}
	return QFrame::mousePressEvent(event);
}

void QVTKLine::mouseMoveEvent(QMouseEvent *event)
{
	if (isMove)
	{
		moving = event->globalPos();
		if (Direction == QVTKLineDirection::horizontal)
		{
			curSelect = moving.y() - start.y() + status.y();
			fixed = status;
			fixed.setY(curSelect);
			fixed.setHeight(2);
			setGeometry(fixed);
		}
		else
		{
			curSelect = moving.x() - start.x() + status.x();
			fixed = status;
			fixed.setX(curSelect);
			fixed.setWidth(2);
			setGeometry(fixed);
		}
		emit sendSelect(curSelect);
	}
	return QFrame::mouseMoveEvent(event);
}

void QVTKLine::mouseReleaseEvent(QMouseEvent *event)
{
	if (isMove)
	{
		isMove = false;
		stop = event->globalPos();
		if (Direction == QVTKLineDirection::horizontal)
		{
			curSelect = stop.y() - start.y() + status.y();
			fixed = status;
			fixed.setY(curSelect);
			fixed.setHeight(2);
			setGeometry(fixed);
		}
		else
		{
			curSelect = stop.x() - start.x() + status.x();
			fixed = status;
			fixed.setX(curSelect);
			fixed.setWidth(2);
			setGeometry(fixed);
		}
		emit sendSelect(curSelect);
	}
	return QFrame::mouseReleaseEvent(event);
}