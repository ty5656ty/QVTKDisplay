#ifndef QVTKDISPLAY_H
#define QVTKDISPLAY_H

#include <vtk-8.1\vtkGenericOpenGLRenderWindow.h>
#include <vtk-8.1\vtkSmartPointer.h>
#include <vtk-8.1\vtkRenderer.h>
#include <vtk-8.1\vtkDataSet.h>
#include <vtk-8.1\vtkRenderer.h>
#include <vtk-8.1\vtkActor.h>
#include <vtk-8.1\vtkProperty.h>
#include <vtk-8.1\vtkCamera.h>
#include <vtk-8.1\vtkVolumeProperty.h>
#include <vtk-8.1\vtkSmartVolumeMapper.h>
#include <vtk-8.1\vtkVolume.h>
#include <vtk-8.1\vtkImageCast.h>
#include <vtk-8.1\vtkImageData.h>
#include <vtk-8.1\vtkInformation.h>
#include <vtk-8.1\vtkBmpReader.h>
#include <vtk-8.1\vtkImageAppend.h>
#include <vtk-8.1\vtkPiecewiseFunction.h>
#include <vtk-8.1\vtkColorTransferFunction.h>
#include <vtk-8.1\vtkMatrix4x4.h>
#include <vtk-8.1\vtkImageReslice.h>
#include <vtk-8.1\vtkAutoInit.h>
#include <vtk-8.1\QVTKOpenGLWidget.h>

#pragma comment(lib, "vtkalglib-8.1.lib")
#pragma comment(lib, "vtkChartsCore-8.1.lib")
#pragma comment(lib, "vtkCommonColor-8.1.lib")
#pragma comment(lib, "vtkCommonComputationalGeometry-8.1.lib")
#pragma comment(lib, "vtkCommonCore-8.1.lib")
#pragma comment(lib, "vtkCommonDataModel-8.1.lib")
#pragma comment(lib, "vtkCommonExecutionModel-8.1.lib")
#pragma comment(lib, "vtkCommonMath-8.1.lib")
#pragma comment(lib, "vtkCommonMisc-8.1.lib")
#pragma comment(lib, "vtkCommonSystem-8.1.lib")
#pragma comment(lib, "vtkCommonTransforms-8.1.lib")
#pragma comment(lib, "vtkDICOMParser-8.1.lib")
#pragma comment(lib, "vtkDomainsChemistry-8.1.lib")
#pragma comment(lib, "vtkDomainsChemistryOpenGL2-8.1.lib")
#pragma comment(lib, "vtkexoIIc-8.1.lib")
#pragma comment(lib, "vtkexpat-8.1.lib")
#pragma comment(lib, "vtkFiltersAMR-8.1.lib")
#pragma comment(lib, "vtkFiltersCore-8.1.lib")
#pragma comment(lib, "vtkFiltersExtraction-8.1.lib")
#pragma comment(lib, "vtkFiltersFlowPaths-8.1.lib")
#pragma comment(lib, "vtkFiltersGeneral-8.1.lib")
#pragma comment(lib, "vtkFiltersGeneric-8.1.lib")
#pragma comment(lib, "vtkFiltersGeometry-8.1.lib")
#pragma comment(lib, "vtkFiltersHybrid-8.1.lib")
#pragma comment(lib, "vtkFiltersHyperTree-8.1.lib")
#pragma comment(lib, "vtkFiltersImaging-8.1.lib")
#pragma comment(lib, "vtkFiltersModeling-8.1.lib")
#pragma comment(lib, "vtkFiltersParallel-8.1.lib")
#pragma comment(lib, "vtkFiltersParallelImaging-8.1.lib")
#pragma comment(lib, "vtkFiltersPoints-8.1.lib")
#pragma comment(lib, "vtkFiltersProgrammable-8.1.lib")
#pragma comment(lib, "vtkFiltersSelection-8.1.lib")
#pragma comment(lib, "vtkFiltersSMP-8.1.lib")
#pragma comment(lib, "vtkFiltersSources-8.1.lib")
#pragma comment(lib, "vtkFiltersStatistics-8.1.lib")
#pragma comment(lib, "vtkFiltersTexture-8.1.lib")
#pragma comment(lib, "vtkFiltersTopology-8.1.lib")
#pragma comment(lib, "vtkFiltersVerdict-8.1.lib")
#pragma comment(lib, "vtkfreetype-8.1.lib")
#pragma comment(lib, "vtkGeovisCore-8.1.lib")
#pragma comment(lib, "vtkgl2ps-8.1.lib")
#pragma comment(lib, "vtkglew-8.1.lib")
#pragma comment(lib, "vtkGUISupportMFC-8.1.lib")
#pragma comment(lib, "vtkGUISupportQt-8.1.lib")
#pragma comment(lib, "vtkGUISupportQtOpenGL-8.1.lib")
#pragma comment(lib, "vtkGUISupportQtSQL-8.1.lib")
#pragma comment(lib, "vtkhdf5-8.1.lib")
#pragma comment(lib, "vtkhdf5_hl-8.1.lib")
#pragma comment(lib, "vtkImagingColor-8.1.lib")
#pragma comment(lib, "vtkImagingCore-8.1.lib")
#pragma comment(lib, "vtkImagingFourier-8.1.lib")
#pragma comment(lib, "vtkImagingGeneral-8.1.lib")
#pragma comment(lib, "vtkImagingHybrid-8.1.lib")
#pragma comment(lib, "vtkImagingMath-8.1.lib")
#pragma comment(lib, "vtkImagingMorphological-8.1.lib")
#pragma comment(lib, "vtkImagingSources-8.1.lib")
#pragma comment(lib, "vtkImagingStatistics-8.1.lib")
#pragma comment(lib, "vtkImagingStencil-8.1.lib")
#pragma comment(lib, "vtkInfovisCore-8.1.lib")
#pragma comment(lib, "vtkInfovisLayout-8.1.lib")
#pragma comment(lib, "vtkInteractionImage-8.1.lib")
#pragma comment(lib, "vtkInteractionStyle-8.1.lib")
#pragma comment(lib, "vtkInteractionWidgets-8.1.lib")
#pragma comment(lib, "vtkIOAMR-8.1.lib")
#pragma comment(lib, "vtkIOCore-8.1.lib")
#pragma comment(lib, "vtkIOEnSight-8.1.lib")
#pragma comment(lib, "vtkIOExodus-8.1.lib")
#pragma comment(lib, "vtkIOExport-8.1.lib")
#pragma comment(lib, "vtkIOExportOpenGL2-8.1.lib")
#pragma comment(lib, "vtkIOGeometry-8.1.lib")
#pragma comment(lib, "vtkIOImage-8.1.lib")
#pragma comment(lib, "vtkIOImport-8.1.lib")
#pragma comment(lib, "vtkIOInfovis-8.1.lib")
#pragma comment(lib, "vtkIOLegacy-8.1.lib")
#pragma comment(lib, "vtkIOLSDyna-8.1.lib")
#pragma comment(lib, "vtkIOMINC-8.1.lib")
#pragma comment(lib, "vtkIOMovie-8.1.lib")
#pragma comment(lib, "vtkIONetCDF-8.1.lib")
#pragma comment(lib, "vtkIOParallel-8.1.lib")
#pragma comment(lib, "vtkIOParallelXML-8.1.lib")
#pragma comment(lib, "vtkIOPLY-8.1.lib")
#pragma comment(lib, "vtkIOSQL-8.1.lib")
#pragma comment(lib, "vtkIOTecplotTable-8.1.lib")
#pragma comment(lib, "vtkIOVideo-8.1.lib")
#pragma comment(lib, "vtkIOXML-8.1.lib")
#pragma comment(lib, "vtkIOXMLParser-8.1.lib")
#pragma comment(lib, "vtkjpeg-8.1.lib")
#pragma comment(lib, "vtkjsoncpp-8.1.lib")
#pragma comment(lib, "vtklibharu-8.1.lib")
#pragma comment(lib, "vtklibxml2-8.1.lib")
#pragma comment(lib, "vtkLocalExample-8.1.lib")
#pragma comment(lib, "vtklz4-8.1.lib")
#pragma comment(lib, "vtkmetaio-8.1.lib")
#pragma comment(lib, "vtkNetCDF-8.1.lib")
#pragma comment(lib, "vtknetcdfcpp-8.1.lib")
#pragma comment(lib, "vtkoggtheora-8.1.lib")
#pragma comment(lib, "vtkParallelCore-8.1.lib")
#pragma comment(lib, "vtkpng-8.1.lib")
#pragma comment(lib, "vtkproj4-8.1.lib")
#pragma comment(lib, "vtkRenderingAnnotation-8.1.lib")
#pragma comment(lib, "vtkRenderingContext2D-8.1.lib")
#pragma comment(lib, "vtkRenderingContextOpenGL2-8.1.lib")
#pragma comment(lib, "vtkRenderingCore-8.1.lib")
#pragma comment(lib, "vtkRenderingFreeType-8.1.lib")
#pragma comment(lib, "vtkRenderingGL2PSOpenGL2-8.1.lib")
#pragma comment(lib, "vtkRenderingImage-8.1.lib")
#pragma comment(lib, "vtkRenderingLabel-8.1.lib")
#pragma comment(lib, "vtkRenderingLOD-8.1.lib")
#pragma comment(lib, "vtkRenderingOpenGL2-8.1.lib")
#pragma comment(lib, "vtkRenderingQt-8.1.lib")
#pragma comment(lib, "vtkRenderingVolume-8.1.lib")
#pragma comment(lib, "vtkRenderingVolumeOpenGL2-8.1.lib")
#pragma comment(lib, "vtksqlite-8.1.lib")
#pragma comment(lib, "vtksys-8.1.lib")
#pragma comment(lib, "vtkTestingGenericBridge-8.1.lib")
#pragma comment(lib, "vtkTestingIOSQL-8.1.lib")
#pragma comment(lib, "vtkTestingRendering-8.1.lib")
#pragma comment(lib, "vtktiff-8.1.lib")
#pragma comment(lib, "vtkverdict-8.1.lib")
#pragma comment(lib, "vtkViewsContext2D-8.1.lib")
#pragma comment(lib, "vtkViewsCore-8.1.lib")
#pragma comment(lib, "vtkViewsInfovis-8.1.lib")
#pragma comment(lib, "vtkViewsQt-8.1.lib")
#pragma comment(lib, "vtkzlib-8.1.lib")

VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);

#ifdef QVTKDISPLAY_LIB
# define QVTKDISPLAY_EXPORT Q_DECL_EXPORT
#else
# define QVTKDISPLAY_EXPORT Q_DECL_IMPORT
#endif

class QVTKDISPLAY_EXPORT QVTKDisplay : public QVTKOpenGLWidget
{
	Q_OBJECT

private:
	unsigned int extentX;
	unsigned int extentY;
	unsigned int extentZ;
	double spaceX;
	double spaceY;
	double spaceZ;
	double volumeX;
	double volumeY;
	double volumeZ;
	unsigned int dataIndex;

	bool Q3DResliceIsShow;
	QWidget* Q3DReslice;

	vtkBMPReader* data;
	vtkImageData *dataset;
	vtkCamera* camera;
	vtkGenericOpenGLRenderWindow *window;
	vtkRenderer* renderer;

	vtkVolume *volume;
	vtkVolumeProperty *property;
	vtkSmartVolumeMapper *volumeMapper;

	void mouseDoubleClickEvent(QMouseEvent * event);

public:
	QVTKDisplay(QWidget *parent = 0);
	~QVTKDisplay();

	void setOpacity(vtkPiecewiseFunction* opacity);
	void setColor(vtkColorTransferFunction* color);
	void initData(unsigned int x, unsigned int y, unsigned int z, double x1, double y1, double z1);
	void freeData();
	void addVolume(vtkBMPReader* frame);
	void addImage(unsigned char* singledata);
	void removeVolume();
	bool getXYReslice(double index, void* ptr);
	bool getXZReslice(double index, void* ptr);
	bool getYZReslice(double index, void* ptr);
	void enableReslice();
	void disableReslice();

protected slots:
	void XYReslice(double index, void* ptr);
	void XZReslice(double index, void* ptr);
	void YZReslice(double index, void* ptr);

signals:
	void sendXYReslice();
	void sendXZReslice();
	void sendYZReslice();
};

#endif // QVTKDISPLAY_H
