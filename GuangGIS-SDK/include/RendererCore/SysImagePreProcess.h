/**
* @file              SysImagePreProcess.h
* @brief             ͼ�������һЩ�����Ĵ�����Ҫ������ʾ��Ⱦ
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��7��9��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSIMAGEPREPROCESS_H_E61EE64A_5317_453B_BF59_82A884B03FFE__
#define __SYSIMAGEPREPROCESS_H_E61EE64A_5317_453B_BF59_82A884B03FFE__

#include "SysDrawCommon.h"


/**
* @brief ͼ��ı�׼������
* @param[in] onst T* poData
* @param[out] unsigned char* puBytes
* @param[in] int nLen
* @param[in] double dbDev
* @param[in] int nDevCount
* @param[in] 
* @return void
* @author �����
* @date 2015��7��9��
* @note 
*/
template <typename T>
SYSDRAW_API void StandDevStretch(
				   const T* poData,
				   unsigned char* puBytes,
				   int nLen,
				   double dbDev,
				   float fDevCount,
				   double dbMean,
				   double dbEps = FLOAT_ZERO
				   );

/**
* @brief ͼ��������С����
* @param[in] const T* poData
* @param[out] unsigned char* puBytes
* @param[in] int nLen
* @param[in] double dbMin
* @param[in] double dbMax
* @return void
* @author �����
* @date 2015��7��9��
* @note 
*/
template <typename T>
SYSDRAW_API void MinMaxStretch(const T* poData,unsigned char* puBytes,int nLen,double dbMin,double dbMax,double dbEps = FLOAT_ZERO);

/**
* @brief �������Ż���������Ĳ���
* @param[in] float* pHist
* @param[out] float &dbMin
* @param[out] float &dbMax
* @param[in] int nPixelCount
* @return void
* @author �����
* @date 2015��11��5��
* @note 
*/
SYSDRAW_API void CreateOptimizedStretch(float* pHist,float &dbMin,float &dbMax,int nPixelCount);

SYSDRAW_API void CreateLinearStretch(float* pHist,float &dbMin,float &dbMax,int nPixelCount,int nPercent);

/**
* @brief �Ҷȷ�ת
* @param[in] unsigned char* poData
* @param[in] size_t nLen
* @param[in] size_t nExcludeIndex
* @return void
* @author �����
* @date 2015��11��6��
* @note 
*/
SYSDRAW_API void BrightnessContrast(unsigned char* poData,size_t nLen, size_t nExcludeIndex);

/**
* @brief ���ȿ���
* @param[in] unsigned char uDst
* @param[in] float fBrightNess
* @return unsignedchar 
* @author �����
* @date 2015��11��6��
* @note 
*/
SYSDRAW_API unsigned char BrightnessStretch(unsigned char uDst,float fBrightNess);

/**
* @brief �Աȶȵ���(-128<nPara<128)
* @param[in] unsigned char uSrc
* @param[in] int nPara
* @return unsigned char 
* @author �����
* @date 2015��11��6��
* @note 
*/
SYSDRAW_API unsigned char ContrastStretch(unsigned char uSrc,int nPara);

SYSDRAW_API void ScreenToWorld(double winx, double winy, double *objx, double *objy, double *objz);


/**
* @brief ���ȵ��������飩
* @param[in] nsigned char* poData
* @param[in] int nBitPlanes
* @param[in] int nImgWidth
* @param[in] int nImgHeight
* @param[in] int nStartX
* @param[in] int nStartY
* @param[in] int nWidth
* @param[in] int nHeight
* @param[in] float fBrightNess
* @return void
* @author �����
* @date 2015��11��6��
* @note 
*/
SYSDRAW_API void BrightnessAdjust(
								  unsigned char* poData,
								  int nBitPlanes,
								  int nImgWidth,
								  int nImgHeight,
								  int nStartX,
								  int nStartY,
								  int nWidth,
								  int nHeight,
								  float fBrightNess);

/**
* @brief RGB��ɫ�ռ䵽HSI�ռ�ת��
* @param[in] unsigned char R
* @param[in] unsigned char G
* @param[in] unsigned char B
* @param[in] float &i
* @param[in] float &h
* @param[in] float &s
* @return bool
* @author �����
* @date 2015��11��6��
* @note 
*/
SYSDRAW_API bool Rgb2Ihs(unsigned char R,unsigned char G,unsigned char B,float &i,float &h,float &s);

/**
* @brief HSI��ɫ�ռ䵽RGB�ռ�ת��
* @param[in] float fh
* @param[in] float fi
* @param[in] float fs
* @param[in] unsigned char& r
* @param[in] unsigned char& g
* @param[in] unsigned char& b
* @return void
* @author �����
* @date 2015��11��6��
* @note 
*/
SYSDRAW_API void HIS2RGB(float fh, float fi, float fs, unsigned char& r, unsigned char& g, unsigned char& b);

#include "SysImagePrePriv.h"

#endif
