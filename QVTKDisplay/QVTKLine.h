#pragma once
#include <QtWidgets\qframe.h>
#include <QtGui\qevent.h>

enum QVTKLineDirection
{
	horizontal = 0,
	vertical
};

class QVTKLine : public QFrame
{
	Q_OBJECT

public:
	QVTKLine(QWidget* parent = 0);
	~QVTKLine();
	void setDirection(QVTKLineDirection d);
	void setGeometry(int loc, int w, int h);
	void setGeometry(int x, int y, int w, int h);
	void setGeometry(const QRect &);

protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

private:
	int curSelect;
	int Direction;
	bool isMove;
	QPoint start;
	QPoint moving;
	QPoint stop;
	QRect status;
	QRect fixed;

signals:
	void sendSelect(int p);
};

