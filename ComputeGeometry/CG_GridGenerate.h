/*******************************************************************************
* ��Ȩ����(C) ����ʡ�ռ���Ϣ�����о����� 2013
* �ļ�����	: CG_GridGenerate.h
* ��ǰ�汾	: 1.0.0.1
* ��    ��	: ����� (zhouxuguang236@126.com)
* �������	: 2012��10��21��
* ����ժҪ	: �ռ��ֵ�㷨�������ݵ�����
* �޸ļ�¼	: 
* ��    ��		��    ��		�޸���		�޸�ժҪ

********************************************************************************/

#ifndef __CG_GRIDGENERATE_H_60C8CA6D_A89B_417E_9E1F_9997AC3E50BA__
#define __CG_GRIDGENERATE_H_60C8CA6D_A89B_417E_9E1F_9997AC3E50BA__

#include "CG_Common.h"

#ifdef  __cplusplus
extern "C" {
#endif

/** ��ֵ�㷨 */
typedef enum {
   GGA_InverseDistanceToAPower = 1,
   GGA_MovingAverage = 2,
   GGA_MovingFitting = 3,
   GGA_NearestNeighbor = 4,
   GGA_MetricMinimum = 5,
   GGA_MetricMaximum = 6,
   GGA_MetricRange = 7,
   GGA_MetricCount = 8,
   GGA_MetricAverageDistance = 9,
   GGA_MetricAverageDistancePts = 10
} GridAlgorithm;

/** ���Ⱦ���Ȩ���㷨���� */
typedef struct
{
    double  dbPower;		/*! Ȩ���ݷ�. */
    double  dbSmoothing;	 /*! ƽ������. */
    double  dbRadius1;
    double  dbRadius2;
    double  dbAngle;
    unsigned int nMaxPoints;
    unsigned int nMinPoints;
    double  dbNoDataValue;	 /*! ��Чֵ. */
} GridInverseDistanceToAPowerOptions;

/** �ƶ�ƽ����������Ϣ */
typedef struct
{
    double  dbRadius1;		//X����������뾶
    double  dbRadius2;		//Y����������뾶
    double  dbAngle;		//��Բ��ת�Ƕ�,˳ʱ��,ʮ���ƶ�
    unsigned int nMinPoints;	//���ٵ�ĸ���
    double  dbNoDataValue;		//��Чֵ
} GridMovingAverageOptions;

/** �ƶ�������Ϸ�������Ϣ */
typedef struct
{
	double  dbRadius;		//�����뾶
	double  dbNoDataValue;		//��Чֵ
} GridMovingFittingOptions;

/** Nearest neighbor method control options */
typedef struct
{
    /*! The first radius (X axis if rotation angle is 0) of search ellipse. */
    double  dbRadius1;
    /*! The second radius (Y axis if rotation angle is 0) of search ellipse. */
    double  dbRadius2;
    /*! Angle of ellipse rotation in degrees.
     *
     * Ellipse rotated counter clockwise.
     */
    double  dbAngle;
    /*! No data marker to fill empty points. */
    double  dbNoDataValue;
} GridNearestNeighborOptions;



 COMPUTEGEOMETRY_API int GridInterpolation( GridAlgorithm eAlgorithmType, const void *poOptions,
			   unsigned int nPointCount,
			   const double *padfX, const double *padfY, const double *padfZ,
			   double dbXMin, double dbXMax, double dbYMin, double dbYMax,
			   unsigned int nXSize, unsigned int nYSize, float *pData,
			   /*GDALProgressFunc pfnProgress,*/ void *pProgressArg );

 COMPUTEGEOMETRY_API int  GridInverseDistanceToAPowerNoSearch( const void *poOptions, unsigned int nPoints,
										const double *padfX, const double *padfY,
										const double *padfZ,
										double dfXPoint, double dfYPoint,
										double *pdfValue,
										void* hExtraParamsIn ) ;

 COMPUTEGEOMETRY_API int GridMovingAverage( const void *poOptions, unsigned int nPoints,
	 const double *padfX, const double *padfY,
	 const double *padfZ,
	 double dfXPoint, double dfYPoint, double *pdfValue,
	 void* hExtraParamsIn );

 COMPUTEGEOMETRY_API int GridMovingFitting( const void *poOptions, unsigned int nPoints,
	 const double *padfX, const double *padfY,
	 const double *padfZ,
	 double dfXPoint, double dfYPoint, double *pdfValue,
	 void* hExtraParamsIn );

 COMPUTEGEOMETRY_API int GridTrendSurface( const void *poOptions, unsigned int nPoints,
	 const double *padfX, const double *padfY,
	 const double *padfZ,
	 double dfXPoint, double dfYPoint, double *pdfValue,
	 void* hExtraParamsIn );


#ifdef  __cplusplus
}
#endif

#endif
