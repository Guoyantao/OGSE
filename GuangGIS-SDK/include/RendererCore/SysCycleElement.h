/**
* @file              SysCycleElement.h
* @brief             ԲͼԪ����
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��9��17��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSCYCLEELEMENT_H_2370AD9F_30EC_429F_90C7_431C2BE219EE__
#define __SYSCYCLEELEMENT_H_2370AD9F_30EC_429F_90C7_431C2BE219EE__

#include "SysGraphElement.h"

namespace SysDraw
{

	class SysCoordinate;

	class SYSDRAW_API SysCycleElement : public SysGraphElement
	{
	public:
		SysCycleElement(void);

		~SysCycleElement(void);

		virtual bool Move(double dx, double dy);

		/**
		* @brief �����С�������
		* @param[in] void
		* @return SysEnvelope&
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual SysEnvelope& GetEnvelope(void) const;

		/**
		* @brief ���Ƿ���Բ��
		* @param[in] double x
		* @param[in] double y
		* @return bool
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual bool PointInArea(double x,double y) const;

		/**
		* @brief ��ȡ���ĵ�
		* @param[out] double &x
		* @param[out] double &y
		* @return void
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual void GetCenterPoint(double &x,double &y) const;

		/**
		* @brief ��ȡ�ܳ�
		* @return double
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual double GetPerimeter() const;

		/**
		* @brief ��ȡ���(��Է��ͼԪ)
		* @return double
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual double GetArea() const;

		/**
		* @brief �������ĵ�����
		* @param[in] const double dbX
		* @param[in] const double dbY
		* @return void
		* @author �����
		* @date 2015��9��17��
		* @note 
		*/
		void SetCenterPoint(const double dbX,const double dbY);

		/**
		* @brief ����Բ�İ뾶
		* @param[in] const double dbRadius
		* @return void
		* @author �����
		* @date 2015��9��17��
		* @note 
		*/
		void SetRadius(const double dbRadius);

	private:
		SysCoordinate *m_pCenterPoint;			//Բ��Բ��
		double m_dbRadius;						//�뾶
	};

}

#endif // end of __SYSCYCLEELEMENT_H_2370AD9F_30EC_429F_90C7_431C2BE219EE__
