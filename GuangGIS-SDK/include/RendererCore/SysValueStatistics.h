/**
* @file              SysValueStatistics.h
* @brief             ��������ֵͳ�Ʒ���
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��28��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSVALUESTATISTICS_H_9D78A9E6_6083_4D08_9494_0F0B42B7EFD2__
#define __SYSVALUESTATISTICS_H_9D78A9E6_6083_4D08_9494_0F0B42B7EFD2__

#include "SysDrawCommon.h"

namespace SysDraw
{
	enum ClassBreak_Type
	{
		NanualBreaks,					//�ֹ�����
		EqualInterval,			//�ȼ������
		NaturalBreaks,			//��Ȼ���ѷ�����
		OptimalBreaks,			//���ŷָ�ּ�
		FuzzyBreaks,			//ģ������ּ�
		StandardDeviationBreaks		//��׼�����
	};


	/**
	* @brief ��û���ͳ��ֵ
	* @param[in] const double* pValues
	* @param[in] int nCount
	* @param[out] double *pMin
	* @param[out] double *pMax
	* @param[out] double *pSum
	* @param[out] double *pMean
	* @param[out] double *pMedian
	* @param[out] double *pStdDev
	* @return void
	* @author �����
	* @date 2015��8��28��
	* @note 
	*/
	SYSDRAW_API void GetValueStatistics(
								const double* pValues,
								int nCount,
								double *pMin,
								double *pMax,
								double *pSum,
								double *pMean,
								double *pMedian,
								double* pStdDev);

	/**
	* @brief ��÷ּ��ļ��ֵ����
	* @param[in] double* pValues ��������ֵ
	* @param[in] int nCount
	* @param[in] onst double dMinValue ��Сֵ
	* @param[in] const double dMaxValue ���ֵ
	* @param[in] int nClassNum �ּ���Ŀ
	* @param[in] ClassBreak_Type eBreaksMethods �ּ�����
	* @param[out] double* pIntervalValues �ּ��ļ��ֵ���У����鳤�ȴ��ڵ���nClassNum+1��������n����ֵ������pIntervalValues[n]��pIntervalValues[n+1]							
	* @return bool
	* @author �����
	* @date 2015��10��30��
	* @note 
	*/
	SYSDRAW_API bool GetBreakValues(
								double* pValues,
								int nCount,
								const double dMinValue ,
								const double dMaxValue ,
								int nClassNum,
								ClassBreak_Type eBreaksMethods,
								double* pIntervalValues);

	/**
	* @brief ���ݷּ����ֵ���л�����ڵķּ�����
	* @param[in] const double dValue
	* @param[in] double* pIntervalValues
	* @param[in] int nClassNum
	* @return int�ҵ���������ֵ���Ҳ�������-1
	* @author �����
	* @date 2015��11��2��
	* @note 
	*/
	SYSDRAW_API int GetValueIntervalIndex(const double dValue, double* pIntervalValues,int nClassNum);

}

#endif // end of __SYSVALUESTATISTICS_H_9D78A9E6_6083_4D08_9494_0F0B42B7EFD2__



