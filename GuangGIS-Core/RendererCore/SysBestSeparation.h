/**
* @file              SysBestSeparation.h
* @brief             ���ŷָ�ּ�����
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��11��3��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSBESTSEPARATION_H_B76ACF87_A19F_494B_9587_050DADBA0875__
#define __SYSBESTSEPARATION_H_B76ACF87_A19F_494B_9587_050DADBA0875__

namespace SysDraw
{
	
	/**
	* @brief ���Ŷ��ָ�
	* @param[in] double* pMatError �����󣬼����ƽ���;���
	* @param[in] int nCount �����ά��������������
	* @param[in] int nMaxM	���ķּ�����ֵ������С�ڵ���nCount-1
	* @param[out] int &nIndex �ָ�������
	* @return double �ָ�����С���ƽ����
	* @author �����
	* @date 2015��11��3��
	* @note 
	*/
	double BestTwoSegment(double* pMatError,int nCount,int nMaxM,int &nIndex);

	/**
	* @brief ����K�ָ�
	* @param[in] double* pMatError �����󣬼����ƽ���;���
	* @param[in] int nCount �����ά��������������
	* @param[in] int nClassNum �ּ���
	* @param[in] int *pIndex �ּ�������
	* @return void
	* @author �����
	* @date 2015��11��3��
	* @note 
	*/
	void BestKSegment(double* pMatError,int nCount,int nClassNum, int *pIndex);

}

#endif // end of __SYSBESTSEPARATION_H_B76ACF87_A19F_494B_9587_050DADBA0875__
