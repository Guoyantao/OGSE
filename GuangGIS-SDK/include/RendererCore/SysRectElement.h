/**
* @file              SysRectElement.h
* @brief             ����Ԫ��
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��4��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSRECTELEMENT_H_4ECB21C5_D6B3_4DA2_9EB8_E65A50F4E926__
#define __SYSRECTELEMENT_H_4ECB21C5_D6B3_4DA2_9EB8_E65A50F4E926__

#include "SysGraphElement.h"

namespace SysDraw
{
	class SysCoordinate;

	class SYSDRAW_API SysRectElement : public SysGraphElement
	{
	public:
		SysRectElement(void);

		~SysRectElement(void);

		void Init(double x1,double x2,double y1,double y2);

		virtual bool Move(double dx, double dy);

		virtual SysEnvelope& GetEnvelope(void) const;

		virtual bool PointInArea(double x,double y) const;

		virtual void GetCenterPoint(double &x,double &y) const;

		virtual double GetPerimeter() const;

		virtual double GetArea() const;

		double GetMinX() const;

		double GetMaxX() const;

		double GetMinY() const;

		double GetMaxY() const;

	private:
		SysCoordinate* m_pLeftTop;			//���ϵ�
		SysCoordinate* m_pRightBottom;		//���µ�

	};

}

#endif // end of __SYSRECTELEMENT_H_4ECB21C5_D6B3_4DA2_9EB8_E65A50F4E926__
