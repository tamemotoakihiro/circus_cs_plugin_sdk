
////////////////////////////////////////////////////////////////////////////////////////
//
//
//		LibCircusCS : library for CIRCUS CS plug-in development 
//
//			loadDicomDump.h : Load DICOM dump file (.ini format)
//
//			main coder: Y. Nomura
//
//			update history
//
//			2011.03.23	start coding
//
//
////////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>

#include "../SimpleIni/SimpleIni.h"

#ifndef LOAD_DICOM_DUMP_H

typedef struct DcmDumpData
{
	 CSimpleIniA* data;
}CircusCS_DCMDUMPDATA;

typedef struct basicDcmTagValues
{
	char           modality[16];
	char           studyDate[32];
	char           studyTime[32];
	char           seriesDate[32];
	char           seriesTime[32];
	char           sex[8];
	int            age;
	float          size;
	float          weight;
	VOL_INTSIZE3D* matrixSize;
	VOL_SIZE3D*    voxelSize_mm;
	float          sliceThickness_mm;
	float          sliceLocationOrigin_mm;
	float          sliceLocationPitch_mm;
	double		   rescaleSlope;
	double         rescaleIntercept;
}CircusCS_BASICDCMTAGVALUES;


CircusCS_DCMDUMPDATA*	CircusCS_NewDcmDumpData();
void				    CircusCS_DeleteDcmDumpData(CircusCS_DCMDUMPDATA* dumpData);

CircusCS_DCMDUMPDATA*	CircusCS_LoadDcmDumpFile(char* fileName);

CircusCS_BASICDCMTAGVALUES* CircusCS_NewBasicDcmTagValues(char* fileName, int sliceNum=0);
void                        CircusCS_DeleteBasicDcmTagValues(CircusCS_BASICDCMTAGVALUES* values);

std::string CircusCS_GetDcmTagElementOfDumpData(CircusCS_DCMDUMPDATA* dumpData,
												int sliceNum,
												unsigned short groupWord,
												unsigned short elementWord);

std::string CircusCS_GetDcmTagElementOfDumpDataFromTagStr(CircusCS_DCMDUMPDATA* dumpData,
														  int sliceNum,
														  char* tagStr);

int	 CircusCS_GetModalityOfDumpData(CircusCS_DCMDUMPDATA* dumpData, char* modality, int sliceNum=0);
int	 CircusCS_GetPatientSexOfDumpData(CircusCS_DCMDUMPDATA* dumpData, char* sex, int sliceNum=0);
int	 CircusCS_GetPatientAgeOfDumpData(CircusCS_DCMDUMPDATA* dumpData, int* age, int sliceNum=0);
int	 CircusCS_GetPatientSizeOfDumpData(CircusCS_DCMDUMPDATA* dumpData, float* size, int sliceNum=0);
int	 CircusCS_GetPatientWeightOfDumpData(CircusCS_DCMDUMPDATA* dumpData, float* weight, int sliceNum=0);

int	 CircusCS_GetImageNumberOfDumpData(CircusCS_DCMDUMPDATA* dumpData, int* imageNum, int sliceNum=0);
int	 CircusCS_GetAcquisitionNumberOfDumpData(CircusCS_DCMDUMPDATA* dumpData, int* acquisitionNum, int sliceNum=0);

int	 CircusCS_GetMatrixSizeOfDumpData(CircusCS_DCMDUMPDATA* dumpData, VOL_INTSIZE2D* matrixSize, int sliceNum=0);
int	 CircusCS_GetFieldOfViewOfDumpData(CircusCS_DCMDUMPDATA* dumpData, float* fov, int sliceNum=0);
int	 CircusCS_GetSliceThicknessOfDumpData(CircusCS_DCMDUMPDATA* dumpData, float* thickness, int sliceNum=0);
int	 CircusCS_GetDistanceBetweenSlicesOfDumpData(CircusCS_DCMDUMPDATA* dumpData, float* dbs, int sliceNum=0);
int	 CircusCS_GetSliceLocationOfDumpData(CircusCS_DCMDUMPDATA* dumpData, float* sliceLoc, int sliceNum=0);
int	 CircusCS_GetImageOrientationOfDumpData(CircusCS_DCMDUMPDATA* dumpData, VOL_VECTOR* imageOrientation, int sliceNum=0);
int	 CircusCS_GetImagePositionOfDumpData(CircusCS_DCMDUMPDATA* dumpData, VOL_VECTOR3D* imagePos, int sliceNum=0);
int	 CircusCS_GetPixelSpacingOfDumpData(CircusCS_DCMDUMPDATA* dumpData, VOL_SIZE2D* pixelSpacing, int sliceNum=0);
int  CircusCS_GetVoxelSizeOfDumpData(CircusCS_DCMDUMPDATA* dumpData, VOL_SIZE3D* voxelSize_mm, int sliceNum=0);

int	 CircusCS_GetRescaleInterceptOfDumpData(CircusCS_DCMDUMPDATA* dumpData, double* intercept, int sliceNum=0);
int	 CircusCS_GetRescaleSlopeOfDumpData(CircusCS_DCMDUMPDATA* dumpData, double* slope, int sliceNum=0);

int	 CircusCS_GetRadionuclideTotalDoseOfDumpData(CircusCS_DCMDUMPDATA* dumpData, double* totalDose, int sliceNum=0);


unsigned char*
CircusCS_GetDcmPrivateTagElementOfDumpDataAsUint8Array(CircusCS_DCMDUMPDATA* dumpData,
												       int sliceNum,
												       unsigned short groupWord,
												       unsigned short elementWord);

std::vector<std::string> CircusCS_GetDcmPrivateTagElementOfDumpDataAsStringArray(CircusCS_DCMDUMPDATA* dumpData,
																				 int sliceNum,
																				 unsigned short groupWord,
																				 unsigned short elementWord);

std::vector<short> CircusCS_GetDcmPrivateTagElementOfDumpDataAsSint16Array(CircusCS_DCMDUMPDATA* dumpData,
																		   int sliceNum,
																		   unsigned short groupWord,
																		   unsigned short elementWord);
std::vector<unsigned short> CircusCS_GetDcmPrivateTagElementOfDumpDataAsUint16Array(CircusCS_DCMDUMPDATA* dumpData,
																					int sliceNum,
																					unsigned short groupWord,
																					unsigned short elementWord);
std::vector<int> CircusCS_GetDcmPrivateTagElementOfDumpDataAsSint32Array(CircusCS_DCMDUMPDATA* dumpData,
																		 int sliceNum,
																		 unsigned short groupWord,
																		 unsigned short elementWord);
std::vector<unsigned int> CircusCS_GetDcmPrivateTagElementOfDumpDataAsUint32Array(CircusCS_DCMDUMPDATA* dumpData,
																				  int sliceNum,
																				  unsigned short groupWord,
																				  unsigned short elementWord);
std::vector<float> CircusCS_GetDcmPrivateTagElementOfDumpDataAsFloatArray(CircusCS_DCMDUMPDATA* dumpData,
																		  int sliceNum,
																		  unsigned short groupWord,
																		  unsigned short elementWord);
std::vector<double> CircusCS_GetDcmPrivateTagElementOfDumpDataAsDoubleArray(CircusCS_DCMDUMPDATA* dumpData,
																			int sliceNum,
																			unsigned short groupWord,
																			unsigned short elementWord);


std::string CircusCS_GetDcmPrivateTagElementOfDumpDataAsString(CircusCS_DCMDUMPDATA* dumpData,
															   int            sliceNum,
															   unsigned short groupWord,
															   unsigned short elementWord,
															   unsigned int   pos = 0);

int CircusCS_GetDcmPrivateTagElementOfDumpDataAsSint16(CircusCS_DCMDUMPDATA* dumpData,
													   int sliceNum,
													   unsigned short groupWord,
													   unsigned short elementWord,
													   short* value,
													   unsigned int pos = 0);
int CircusCS_GetDcmPrivateTagElementOfDumpDataAsUint16(CircusCS_DCMDUMPDATA* dumpData,
													   int sliceNum,
													   unsigned short groupWord,
													   unsigned short elementWord,
													   unsigned short* value,
													   unsigned int pos = 0);
int CircusCS_GetDcmPrivateTagElementOfDumpDataAsSint32(CircusCS_DCMDUMPDATA* dumpData,
													   int sliceNum,
													   unsigned short groupWord,
													   unsigned short elementWord,
													   int* value,
													   unsigned int pos = 0);
int CircusCS_GetDcmPrivateTagElementOfDumpDataAsUint32(CircusCS_DCMDUMPDATA* dumpData,
													   int sliceNum,
													   unsigned short groupWord,
													   unsigned short elementWord,
													   unsigned int* value,
													   unsigned int pos = 0);
int CircusCS_GetDcmPrivateTagElementOfDumpDataAsFloat(CircusCS_DCMDUMPDATA* dumpData,
													  int            sliceNum,
													  unsigned short groupWord,
													  unsigned short elementWord,
													  float*         value,
													  unsigned int   pos = 0);
int CircusCS_GetDcmPrivateTagElementOfDumpDataAsDouble(CircusCS_DCMDUMPDATA* dumpData,
													   int            sliceNum,
													   unsigned short groupWord,
													   unsigned short elementWord,
													   double*        value,
													   unsigned int   pos = 0);

#endif

#define LOAD_DICOM_DUMP_H
