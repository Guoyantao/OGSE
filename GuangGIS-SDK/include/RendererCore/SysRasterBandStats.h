/**
* @file              SysRasterBandStats.h
* @brief             դ��ͼ�񵥸�����ͳ����Ϣ
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��9��28��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSRASTERBANDSTATS_H_8B326131_D709_4491_A378_82BB6A2C9FBD__
#define __SYSRASTERBANDSTATS_H_8B326131_D709_4491_A378_82BB6A2C9FBD__

#include "SysDrawCommon.h"

namespace SysDraw
{

	class SYSDRAW_API SysRasterBandStats
	{
	public:
		SysRasterBandStats(void)
		{			
			m_dbMinimumValue = DBL_MAX;
			m_dbMaximumValue = -DBL_MAX;
			m_dbRange = 0.0;
			m_dbMean = 0.0;
			m_dbSumOfSquares = 0.0;
			m_dbStdDev = 0.0;
			m_dbSum = 0.0;
			m_nElementCount = 0;
			memset(m_pHistogramArray,0,sizeof(eDouble)*256);
		}

		eInt32 m_nBandNumber;		//�������

		eUInt32 m_nElementCount;	//�ܵ���Ԫ����

		eDouble m_dbMaximumValue;	//���ֵ

		eDouble m_dbMinimumValue;	//��Сֵ

		eDouble m_dbMean;			//��ֵ

		eDouble m_dbRange;			//ֵ��

		eDouble m_dbStdDev;			//��׼��

		eDouble m_dbSum;				//�ܺ�

		eDouble m_dbSumOfSquares;	//ƽ����

		eDouble m_pHistogramArray[256];	//ֱ��ͼ����
	};

}

#endif // end of __SYSRASTERBANDSTATS_H_8B326131_D709_4491_A378_82BB6A2C9FBD__
