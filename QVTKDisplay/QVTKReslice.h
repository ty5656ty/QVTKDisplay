#ifndef QVTKRESLICE_H
#define QVTKRESLICE_H

#include <QtWidgets/qwidget.h>
#include "ui_QVTKReslice.h"

class QVTKReslice : public QWidget
{
	Q_OBJECT

public:
	QVTKReslice(QWidget* parent = 0);
	~QVTKReslice();

	void initData(unsigned int x, unsigned int y, unsigned int z, double x1, double y1, double z1);
	void freeData();

private:
	Ui::QVTKReslice ui;
	unsigned int extentX;
	unsigned int extentY;
	unsigned int extentZ;
	double spaceX;
	double spaceY;
	double spaceZ;
	double curX_XZ;
	double curY_YZ;
	unsigned int widthX;
	unsigned int heightY;
	unsigned int widthZ;
	unsigned int heightZ;
	double curSelectX;
	double curSelectY;
	double curSelectZ;
	unsigned char* XYBuffer;
	unsigned char* XZBuffer;
	unsigned char* YZBuffer;
	bool isMouseLock;
	void showEvent(QShowEvent* event);
	void resizeEvent(QResizeEvent* event);
	void closeEvent(QCloseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

public slots:
	void XYReslice();
	void XZReslice();
	void YZReslice();
	void getCurSelectX(int p);
	void getCurSelectY(int p);
	void getCurSelectXZ(int p);
	void getCurSelectYZ(int p);

signals:
	void getXYReslice(double index, void* ptr);
	void getXZReslice(double index, void* ptr);
	void getYZReslice(double index, void* ptr);
};

#endif