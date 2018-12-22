/**
* @file              SysPolygonElement.h
* @brief             �����ͼԪ����
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��11��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSPOLYGONELEMENT_H_C4A49E91_9D0E_4A13_91C5_99C872CE595A__
#define __SYSPOLYGONELEMENT_H_C4A49E91_9D0E_4A13_91C5_99C872CE595A__

#include "SysGraphElement.h"

namespace SysDraw
{

	class SysLineElement;

	class SYSDRAW_API SysPolygonElement : public SysGraphElement
	{
	public:
		SysPolygonElement(void);

		~SysPolygonElement(void);

		/**
		* @brief ������ε��⻷��ӽڵ�
		* @param[in] double dx
		* @param[in] double dy
		* @return void
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		void AddPoint(double dx,double dy);

		/**
		* @brief ����ڵ�
		* @param[in] SysLineElement* pLineRing
		* @return void
		* @author �����
		* @date 2015��8��11��
		* @note 
		*/
		void AddIsLand(SysLineElement* pLineRing);

		/**
		* @brief ͼԪ���ƶ�(�����ƶ�)
		* @param[in] double dx
		* @param[in] double dy
		* @return bool
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual bool Move(double dx, double dy);

		/**
		* @brief �ƶ�����(ֻ֧���ƶ��⻷�Ľڵ�)
		* @param[in] int nIndex
		* @param[in] double dx
		* @param[in] double dy
		* @return bool
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual bool MovePoint(int nIndex, double dx, double dy);

		/**
		* @brief ���⻷��ĳ���ڵ��ƶ���ĳ������(ֻ֧���ƶ��⻷�Ľڵ�)
		* @param[in] int nIndex
		* @param[in] double dbX
		* @param[in] double dbY
		* @return bool
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual bool MovePointTo(int nIndex, double dbX, double dbY);

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
		* @brief PointInArea
		* @param[in] double x
		* @param[in] double y
		* @return bool
		* @author �����
		* @date 2015��8��11��
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
		* @brief /��ȡ�ܳ�()
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
		* @brief ����ڵ��ĸ���
		* @return int
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		int GetIsLandCount() const;

		/**
		* @brief ��õڼ����ڵ�
		* @param[in] int nIndex
		* @return SysLineElement*
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		SysLineElement* GetIsLand(int nIndex) const;

		/**
		* @brief ��ö�����⻷
		* @return SysLineElement*
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		SysLineElement* GetExteriorRing() const;

	private:
		SysLineElement* m_pExteriorRing;						//�⻷		
		std::vector<SysLineElement* > m_vecIsLands;			//�ڵ�
	};

}

#endif // end of __SYSPOLYGONELEMENT_H_C4A49E91_9D0E_4A13_91C5_99C872CE595A__
