/**
* @file              SysLineElement.h
* @brief             ����ͼԪ���� PolyLine
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��3��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSLINEELEMENT_H_4FD9067A_420A_4C82_9F47_6E759B3A59ED__
#define __SYSLINEELEMENT_H_4FD9067A_420A_4C82_9F47_6E759B3A59ED__

#include "SysGraphElement.h"

namespace SysDraw
{
	class SysCoordinate;

	class SYSDRAW_API SysLineElement : public SysGraphElement
	{
	public:
		SysLineElement(void);

		~SysLineElement(void);

		void AddPoint(double dx,double dy);

		void RemoveAllPoints();

		bool GetPoint(int nIndex,double &dx,double &dy) const;

		SysCoordinate* GetPoints() const;

		int GetPointCount() const;

		virtual bool Move(double dx, double dy);

		virtual bool MovePoint(int nIndex, double dx, double dy);

		virtual bool MovePointTo(int nIndex, double dbX, double dbY);

		virtual SysEnvelope& GetEnvelope(void) const;

		virtual bool PointInArea(double x,double y) const;

		virtual void GetCenterPoint(double &x,double &y) const;

		virtual double GetPerimeter() const;

	private:
		SysCoordinate* m_poPoints;
		int m_nPointCount;
	};

}

#endif // end of __SYSLINEELEMENT_H_4FD9067A_420A_4C82_9F47_6E759B3A59ED__
