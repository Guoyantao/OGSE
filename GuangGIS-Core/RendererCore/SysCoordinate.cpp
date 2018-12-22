#include "SysCoordinate.h"
#include <math.h>

namespace SysDraw
{

	SysCoordinate::SysCoordinate(void)
	{
		x = 0;
		y = 0;
	}

	SysCoordinate::SysCoordinate(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	SysCoordinate::SysCoordinate(const SysCoordinate& coord)
	{
		this->x = coord.x;
		this->y = coord.y;
	}

	SysCoordinate::~SysCoordinate(void)
	{
	}

	//���㵽��һ������ľ���
	double SysCoordinate::Distance(const SysCoordinate &coord) const
	{
		double dx = x - coord.x;
		double dy = y - coord.y;
		return sqrt(dx*dx + dy*dy);
	}

	void SysCoordinate::SetX(double x)
	{
		this->x = x;
	}

	void SysCoordinate::SetY(double y)
	{
		this->y = y;
	}

}
