#include "QVTKDisplay.h"
#include "QVTKReslice.h"

static double axialElements[16] = {//xy
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1 };


static double coronalElements[16] = {//xz
	1, 0, 0, 0,
	0, 0, 1, 0,
	0, -1, 0, 0,
	0, 0, 0, 1 };

static double sagittalElements[16] = {//yz
	0, 0, -1, 0,
	1, 0, 0, 0,
	0, -1, 0, 0,
	0, 0, 0, 1 };

QVTKDisplay::QVTKDisplay(QWidget *parent) : QVTKOpenGLWidget(parent)
{
	Q3DReslice = nullptr;

	volume = vtkVolume::New();
	volumeMapper = vtkSmartVolumeMapper::New();
	volumeMapper->SetRequestedRenderMode(vtkSmartVolumeMapper::GPURenderMode);
	property = vtkVolumeProperty::New();
	property->ShadeOn();
	property->SetInterpolationTypeToLinear();
	property->SetAmbient(0.2);
	property->SetDiffuse(0.9);
	property->SetSpecular(0.2);
	property->SetSpecularPower(10);

	camera = vtkCamera::New();
	camera->SetViewUp(0, 1, 0);
	camera->SetPosition(0, 0, 10);
	camera->SetFocalPoint(0, 0, 0);

	renderer = vtkRenderer::New();
	renderer->SetActiveCamera(camera);
	renderer->SetBackground(0.5, 0.5, 0.5);

	window = vtkGenericOpenGLRenderWindow::New();
	window->AddRenderer(renderer);
	SetRenderWindow(window);

	data = nullptr;
	dataset = nullptr;
	dataIndex = 0;
}


QVTKDisplay::~QVTKDisplay()
{
	removeVolume();

	freeData();

	window->Delete();
	renderer->Delete();
	camera->Delete();

	property->Delete();
	volumeMapper->Delete();
	volume->Delete();

	if (Q3DReslice != nullptr)
	{
		Q3DReslice->close();
		delete Q3DReslice;
		Q3DReslice = nullptr;
	}
}

void QVTKDisplay::setOpacity(vtkPiecewiseFunction* opacity)
{
	property->SetScalarOpacity(opacity);
}

void QVTKDisplay::setColor(vtkColorTransferFunction* color)
{
	property->SetColor(color);
}


void QVTKDisplay::initData(unsigned int x, unsigned int y, unsigned int z, double x1, double y1, double z1)
{
	vtkInformation* info;

	extentX = x;
	extentY = y;
	extentZ = z;
	spaceX = x1;
	spaceY = y1;
	spaceZ = z1;
	volumeX = (x - 1) * x1 + 1;
	volumeY = (y - 1) * y1 + 1;
	volumeZ = (z - 1) * z1 + 1;
	dataset = vtkImageData::New();
	info = dataset->GetInformation();
	dataset->SetDimensions(x, y, z);
	dataset->SetSpacing(x1, y1, z1);
	dataset->SetScalarType(VTK_UNSIGNED_CHAR, info);
	dataset->AllocateScalars(info);
}

void QVTKDisplay::freeData()
{
	if (dataset != nullptr)
	{
		dataset->Delete();
		dataset = nullptr;
	}
}

void QVTKDisplay::addVolume(vtkBMPReader* frame)
{
	removeVolume();

	volumeMapper->SetInputConnection(frame->GetOutputPort());

	volume->SetMapper(volumeMapper);
	volume->SetProperty(property);

	renderer->AddVolume(volume);
	renderer->ResetCamera();

	data = frame;
	renderVTK();
}

void QVTKDisplay::addImage(unsigned char* singledata)
{
	unsigned char *ptr;

	if (dataset != nullptr)
	{
		ptr = (unsigned char *)dataset->GetScalarPointer();
		ptr = ptr + dataIndex * extentX * extentY;
		memcpy(ptr, singledata, extentX * extentY);
		if (++dataIndex == extentZ)
		{
			removeVolume();

			volumeMapper->SetInputData(dataset);
			volume->SetMapper(volumeMapper);
			volume->SetProperty(property);

			renderer->AddVolume(volume);
			renderer->ResetCamera();

			renderVTK();
		}
	}
}

void QVTKDisplay::removeVolume()
{
	vtkProp *prop = renderer->GetVolumes()->GetLastProp();
	if (prop != nullptr)
		renderer->RemoveVolume(prop);

	volumeMapper->RemoveAllInputs();

	if (data != nullptr)
	{
		data->Delete();
		data = nullptr;
	}

	dataIndex = 0;

	renderVTK();
}


bool QVTKDisplay::getXYReslice(double index, void* ptr)
{
	if (index < 0 || index > volumeZ)
		return false;

	if (ptr == nullptr)
		return false;

	if (dataset == nullptr)
		return false;

	vtkMatrix4x4* resliceAxes = vtkMatrix4x4::New();
	resliceAxes->DeepCopy(axialElements);
	resliceAxes->SetElement(0, 3, 0);
	resliceAxes->SetElement(1, 3, 0);
	resliceAxes->SetElement(2, 3, index);
	vtkImageReslice* reslice = vtkImageReslice::New();
	reslice->SetInputData(dataset);
	reslice->SetOutputDimensionality(2);
	reslice->SetResliceAxes(resliceAxes);
	reslice->SetInterpolationModeToLinear();
	reslice->Update();
	vtkImageData* data = reslice->GetOutput();
	memcpy(ptr, data->GetScalarPointer(), extentX * extentY * sizeof(unsigned char));

	reslice->Delete();
	resliceAxes->Delete();
	return true;
}

bool QVTKDisplay::getXZReslice(double index, void* ptr)
{
	if (index < 0 || index > volumeY)
		return false;

	if (ptr == nullptr)
		return false;

	if (dataset == nullptr)
		return false;

	vtkMatrix4x4* resliceAxes = vtkMatrix4x4::New();
	resliceAxes->DeepCopy(coronalElements);
	resliceAxes->SetElement(0, 3, 0);
	resliceAxes->SetElement(1, 3, index);
	resliceAxes->SetElement(2, 3, 0);
	vtkImageReslice* reslice = vtkImageReslice::New();
	reslice->SetInputData(dataset);
	reslice->SetOutputDimensionality(2);
	reslice->SetResliceAxes(resliceAxes);
	reslice->SetInterpolationModeToLinear();
	reslice->Update();
	vtkImageData* data = reslice->GetOutput();
	memcpy(ptr, data->GetScalarPointer(), extentX * extentZ * sizeof(unsigned char));

	reslice->Delete();
	resliceAxes->Delete();
	return true;
}

bool QVTKDisplay::getYZReslice(double index, void* ptr)
{
	if (index < 0 || index > volumeX)
		return false;

	if (ptr == nullptr)
		return false;

	if (dataset == nullptr)
		return false;

	vtkMatrix4x4* resliceAxes = vtkMatrix4x4::New();
	resliceAxes->DeepCopy(sagittalElements);
	resliceAxes->SetElement(0, 3, index);
	resliceAxes->SetElement(1, 3, 0);
	resliceAxes->SetElement(2, 3, 0);
	vtkImageReslice* reslice = vtkImageReslice::New();
	reslice->SetInputData(dataset);
	reslice->SetOutputDimensionality(2);
	reslice->SetResliceAxes(resliceAxes);
	reslice->SetInterpolationModeToLinear();
	reslice->Update();
	vtkImageData* data = reslice->GetOutput();
	memcpy(ptr, data->GetScalarPointer(), extentY * extentZ * sizeof(unsigned char));

	reslice->Delete();
	resliceAxes->Delete();
	return true;
}

void QVTKDisplay::enableReslice()
{
	Q3DReslice = new QVTKReslice();
}

void QVTKDisplay::disableReslice()
{
	if (Q3DReslice != nullptr)
	{
		delete Q3DReslice;
		Q3DReslice = nullptr;
	}
}

void QVTKDisplay::mouseDoubleClickEvent(QMouseEvent * event)
{
	QVTKReslice *window;
	if (Q3DReslice != nullptr)
	{
		window = (QVTKReslice*)Q3DReslice;
		window->initData(extentX, extentY, extentZ, spaceX, spaceY, spaceZ);
		connect(window, SIGNAL(getXYReslice(double, void*)), this, SLOT(XYReslice(double, void*)));
		connect(window, SIGNAL(getXZReslice(double, void*)), this, SLOT(XZReslice(double, void*)));
		connect(window, SIGNAL(getYZReslice(double, void*)), this, SLOT(YZReslice(double, void*)));

		connect(this, SIGNAL(sendXYReslice()), window, SLOT(XYReslice()));
		connect(this, SIGNAL(sendXZReslice()), window, SLOT(XZReslice()));
		connect(this, SIGNAL(sendYZReslice()), window, SLOT(YZReslice()));
		window->show();

	}
	return QVTKOpenGLWidget::mouseDoubleClickEvent(event);
}

void QVTKDisplay::XYReslice(double index, void* ptr)
{
	getXYReslice(index, ptr);
	emit sendXYReslice();
}

void QVTKDisplay::XZReslice(double index, void* ptr)
{
	getXZReslice(index, ptr);
	emit sendXZReslice();
}

void QVTKDisplay::YZReslice(double index, void* ptr)
{
	getYZReslice(index, ptr);
	emit sendYZReslice();
}