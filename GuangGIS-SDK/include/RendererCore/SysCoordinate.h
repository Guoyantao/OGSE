/**
* @file              SysCoordinate.h
* @brief             ��ά����������
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2012��1��3��
* @version           1.0.0.1
* @par               Copyright (c):����� 2012
* @par               History:
*/
#ifndef __SYSCOORDINATE_H_64B3BC5B_4C4E_4F4F_AD1D_54E8D3DC7712__
#define __SYSCOORDINATE_H_64B3BC5B_4C4E_4F4F_AD1D_54E8D3DC7712__


#include "SysDrawCommon.h"

namespace SysDraw
{

	class SYSDRAW_API SysCoordinate
	{
	public:
		//Ĭ�Ϲ��캯��
		SysCoordinate(void);

		//�������Ĺ��캯��
		SysCoordinate(double x,double y);

		//�������캯��
		SysCoordinate(const SysCoordinate& coord);

		//��������
		~SysCoordinate(void);

		//���㵽��һ����þ���
		double Distance(const SysCoordinate &coord) const;

		//����X��Y����
		void SetX(double x);
		void SetY(double y);

	public:
		double x;	//������
		double y;	//������
		//double z;	//z����
	};

}

#endif // end of __GEOCOORDINATE_H_FFF7BBFB_E6D0_439F_A6CE_561AD1EE0958__
