#include "QVTKReslice.h"
#include <Windows.h>
#include <opencv2\opencv.hpp>
#pragma comment(lib, "opencv_world300d.lib")

QVTKReslice::QVTKReslice(QWidget* parent) : QWidget(parent)
{
	ui.setupUi(this);
	//ui.widget->setStyleSheet("background-color:black;");
	ui.selectX->setDirection(QVTKLineDirection::vertical);
	ui.selectY->setDirection(QVTKLineDirection::horizontal);
	ui.selectXZ->setDirection(QVTKLineDirection::horizontal);
	ui.selectYZ->setDirection(QVTKLineDirection::vertical);
	connect(ui.selectX, SIGNAL(sendSelect(int)), this, SLOT(getCurSelectX(int)));
	connect(ui.selectY, SIGNAL(sendSelect(int)), this, SLOT(getCurSelectY(int)));
	connect(ui.selectXZ, SIGNAL(sendSelect(int)), this, SLOT(getCurSelectXZ(int)));
	connect(ui.selectYZ, SIGNAL(sendSelect(int)), this, SLOT(getCurSelectYZ(int)));

	//ui.XY->setStyleSheet("background-color:red;");
	//ui.XZ->setStyleSheet("background-color:green;");
	//ui.YZ->setStyleSheet("background-color:blue;");
	widthX = 0;
	heightY = 0;
	widthZ = 0;
	heightZ = 0;

	XYBuffer = nullptr;
	XZBuffer = nullptr;
	YZBuffer = nullptr;

	isMouseLock = false;
}


QVTKReslice::~QVTKReslice()
{
	freeData();
}

void QVTKReslice::initData(unsigned int x, unsigned int y, unsigned int z, double x1, double y1, double z1)
{
	int w, h;
	w = width();
	h = height();

	freeData();

	extentX = x;
	extentY = y;
	extentZ = z;
	spaceX = x1;
	spaceY = y1;
	spaceZ = z1;
	curX_XZ = extentX * spaceX / (extentX * spaceX + extentZ * spaceZ);
	curY_YZ = extentY * spaceY / (extentY * spaceY + extentZ * spaceZ);

	widthX = w * 0.9 * curX_XZ;
	heightY = h * curY_YZ;
	widthZ = w * 0.9 - widthX;
	heightZ = h - heightY;
	ui.XY->setGeometry(0, 0, widthX, heightY);
	ui.XZ->setGeometry(0, heightY, widthX, heightZ);
	ui.YZ->setGeometry(widthX, 0, widthZ, heightY);

	curSelectX = 0.5;
	curSelectY = 0.5;
	curSelectZ = 0.5;
	ui.selectX->setGeometry(widthX * curSelectX, w * 0.9, h);
	ui.selectY->setGeometry(heightY * curSelectY, w * 0.9, h);
	ui.selectXZ->setGeometry(heightZ * curSelectZ + heightY, w * 0.9, h);
	ui.selectYZ->setGeometry(widthZ * curSelectZ + widthX, w * 0.9, h);

	XYBuffer = new unsigned char[extentX * extentY];
	XZBuffer = new unsigned char[extentX * extentZ];
	YZBuffer = new unsigned char[extentY * extentZ];

	memset(XYBuffer, 0, extentX * extentY);
	memset(XZBuffer, 0, extentX * extentZ);
	memset(YZBuffer, 0, extentY * extentZ);
}

void QVTKReslice::freeData()
{
	if (XYBuffer != nullptr)
	{
		delete[] XYBuffer;
		XYBuffer = nullptr;
	}

	if (XZBuffer != nullptr)
	{
		delete[] XZBuffer;
		XZBuffer = nullptr;
	}

	if (YZBuffer != nullptr)
	{
		delete[] YZBuffer;
		YZBuffer = nullptr;
	}
}

void QVTKReslice::XYReslice()
{
	cv::Mat img(extentX, extentY, CV_8UC1, XYBuffer);
	cv::Mat tmp;
	cv::resize(img, tmp, cv::Size(ui.XY->width(), ui.XY->height()));
	QPixmap pixmap = QPixmap::fromImage(QImage((unsigned char*)tmp.data, tmp.cols, tmp.rows, tmp.cols, QImage::Format_Grayscale8));
	ui.XY->setPixmap(pixmap);
}

void QVTKReslice::XZReslice()
{
	cv::Mat img(extentZ, extentX, CV_8UC1, XZBuffer);
	cv::Mat tmp;
	cv::resize(img, tmp, cv::Size(ui.XZ->width(), ui.XZ->height()));
	QPixmap pixmap = QPixmap::fromImage(QImage((unsigned char*)tmp.data, tmp.cols, tmp.rows, tmp.cols, QImage::Format_Grayscale8));
	ui.XZ->setPixmap(pixmap);
}

void QVTKReslice::YZReslice()
{
	cv::Mat img(extentZ, extentY, CV_8UC1, YZBuffer);
	cv::Mat tmp;
	cv::resize(img, tmp, cv::Size(ui.YZ->height(), ui.YZ->width()));
	transpose(tmp, tmp);
	//flip(tmp, tmp, 1);
	QPixmap pixmap = QPixmap::fromImage(QImage((unsigned char*)tmp.data, tmp.cols, tmp.rows, tmp.cols, QImage::Format_Grayscale8));
	ui.YZ->setPixmap(pixmap);
}

void QVTKReslice::getCurSelectX(int p)
{	
	curSelectX = p * 1.0 / widthX;
	emit getYZReslice(curSelectX * extentX * spaceX, YZBuffer);
}

void QVTKReslice::getCurSelectY(int p)
{
	curSelectY =  p * 1.0 / heightY;
	emit getXZReslice(curSelectY * extentY * spaceY, XZBuffer);
}

void QVTKReslice::getCurSelectXZ(int p)
{
	int w, h;
	w = width();
	h = height();
	curSelectZ = (p - heightY) * 1.0 / heightZ;
	ui.selectYZ->setGeometry(widthZ * curSelectZ + widthX, w * 0.9, h);
	emit getXYReslice(curSelectZ * extentZ * spaceZ, XYBuffer);
}

void QVTKReslice::getCurSelectYZ(int p)
{
	int w, h;
	w = width();
	h = height();
	curSelectZ = (p - widthX) * 1.0 / widthX;
	ui.selectXZ->setGeometry(heightZ * curSelectZ + heightY, w * 0.9, h);
	emit getXYReslice(curSelectZ * extentZ * spaceZ, XYBuffer);
}


void QVTKReslice::showEvent(QShowEvent* size)
{
	emit getYZReslice(curSelectX * extentX * spaceX, YZBuffer);
	emit getXZReslice(curSelectY * extentY * spaceY, XZBuffer);
	emit getXYReslice(curSelectZ * extentZ * spaceZ, XYBuffer);
}

void QVTKReslice::resizeEvent(QResizeEvent* event)
{
	int w, h;
	w = width();
	h = height();
	ui.widget->setGeometry(0, 0, w * 0.9, h);
	ui.pushButton->setGeometry(w * 0.91, 0, w * 0.08, h * 0.06);

	widthX = w * 0.9 * curX_XZ;
	heightY = h * curY_YZ;
	widthZ = w * 0.9 - widthX;
	heightZ = h - heightY;
	ui.XY->setGeometry(0, 0, widthX, heightY);
	ui.XZ->setGeometry(0, heightY, widthX, heightZ);
	ui.YZ->setGeometry(widthX, 0, widthZ, heightY);
	ui.selectX->setGeometry(widthX * curSelectX, w * 0.9, h);
	ui.selectY->setGeometry(heightY * curSelectY, w * 0.9, h);
	ui.selectXZ->setGeometry(heightZ * curSelectZ + heightY, w * 0.9, h);
	ui.selectYZ->setGeometry(widthZ * curSelectZ + widthX, w * 0.9, h);

	XYReslice();
	XZReslice();
	YZReslice();
	return QWidget::resizeEvent(event);
}

void QVTKReslice::closeEvent(QCloseEvent* event)
{
	freeData();
}

void QVTKReslice::mousePressEvent(QMouseEvent* event)
{
	int x, y;
	int x1, x2, y1, y2;
	QPoint q;
	RECT rect;

	q = event->pos();
	x = q.x();
	y = q.y();
	x1 = ui.XY->width();
	y1 = ui.XY->height();
	x2 = ui.XZ->width() + x1;
	y2 = ui.YZ->height() + y1;
	if (x < x2 && y < y2)
	{
		isMouseLock = true;
		if (x < x1 && y < y1)
		{
			rect.left = 0 + geometry().x();
			rect.top = 0 + geometry().y();
			rect.right = x1 + geometry().x();
			rect.bottom = y1 + geometry().y();
		}
		if (x < x1 && y > y1)
		{
			rect.left = 0 + geometry().x();;
			rect.top = y1 + 1 + geometry().y();
			rect.right = x1 + geometry().x();
			rect.bottom = y2 + geometry().y();
		}
		if (x > x1 && y < y1)
		{
			rect.left = x1 + 1 + geometry().x();;
			rect.top = 0 + geometry().y();
			rect.right = x2 + geometry().x();;
			rect.bottom = y1 + geometry().y();
		}
		if (x > x1 && y > y1)
		{
			rect.left = x1 + 1 + geometry().x();
			rect.top = y1 + 1+ geometry().y();
			rect.right = x2 + geometry().x();;
			rect.bottom = y2 + geometry().y();
		}
		ClipCursor(&rect);
	}

	return QWidget::mousePressEvent(event);
}

void QVTKReslice::mouseMoveEvent(QMouseEvent *event)
{
	return QWidget::mouseMoveEvent(event);
}

void QVTKReslice::mouseReleaseEvent(QMouseEvent *event)
{
	isMouseLock = false;
	ClipCursor(NULL);
	return QWidget::mouseReleaseEvent(event);
}