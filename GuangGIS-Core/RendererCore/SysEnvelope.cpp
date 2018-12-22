
//#include <math.h>
//#include <algorithm>

#include "SysEnvelope.h"
#include "SysCoordinate.h"

namespace SysDraw
{

	using namespace std;

	SysEnvelope::SysEnvelope()
	{
		minX = 0;
		minY = -2;
		maxX = 0;
		maxY = -2;
	}

	//�������Ĺ��캯��
	SysEnvelope::SysEnvelope(double minX,double maxX,double minY,double maxY)
	{
		//��Ҫ�Ƚ������С��Ȼ���ٽ����ж�
		if (minX > maxX)
		{
			this->minX = maxX;
			this->maxX = minX;
		}
		else
		{
			this->minX = minX;
			this->maxX = maxX;
		}

		if (minY > maxY)
		{
			this->minY = maxY;
			this->maxY = minY;
		}
		else
		{
			this->minY = minY;
			this->maxY = maxY;
		}
	}

	//�������캯��
	SysEnvelope::SysEnvelope(const SysEnvelope& envelope)
	{
		this->minX = envelope.minX;
		this->maxX = envelope.maxX;
		this->minY = envelope.minY;
		this->maxY = envelope.maxY;
	}

	SysEnvelope &SysEnvelope::operator =(const SysEnvelope& other)
	{
		if ( &other != this ) // �Լ��
		{
			minX = other.minX;
			maxX = other.maxX;
			minY = other.minY;
			maxY = other.maxY;
		}
		return *this;
	}

	//������������ʼ��
	SysEnvelope::SysEnvelope(SysCoordinate *coord1,SysCoordinate *coord2)
	{
		if (coord1->x < coord2->x)
		{
			minX = coord1->x;
			maxX = coord2->x;
		}
		else
		{
			minX = coord2->x;
			maxX = coord1->x;
		}

		if (coord1->y < coord2->y)
		{
			minY = coord1->y;
			maxY = coord2->y;
		}
		else
		{
			minY = coord2->y;
			maxY = coord1->y;
		}
	}

	//��������
	SysEnvelope::~SysEnvelope(void)
	{
	}

	void SysEnvelope::Init(double x1,double x2,double y1,double y2)
	{
		if (x1 > x2)
		{
			minX = x2;
			maxX = x1;
		}
		else
		{
			minX = x1;
			maxX = x2;
		}

		if (y1 > y2)
		{
			minY = y2;
			maxY = y1;
		}
		else
		{
			minY = y1;
			maxY = y2;
		}
	}

	bool SysEnvelope::Intersects(const SysEnvelope *otherEvp) const
	{
		//���������ĸ�����
		//if (maxX < otherEvp.minX || minX > otherEvp.maxX ||
		//	maxY < otherEvp.minY || minY > otherEvp.maxY)
		//{
		//	return 0;
		//}

		////�ĸ��ԽǷ���
		//if (maxX < otherEvp.minX && maxY < otherEvp.minY)
		//{
		//	return 0;
		//}
		//if (maxX < otherEvp.minX && minY > otherEvp.maxY)
		//{
		//	return 0;
		//}

		////�ھ�����
		//if (minX >= otherEvp.minX && maxX <= otherEvp.maxX &&
		//	minY >= otherEvp.minY && maxY <= otherEvp.maxY)
		//{
		//	return 1;
		//}
		//
		//return 1;	//�ཻ

		if (NULL == otherEvp)
		{
			return false;
		}

		if ( IsNull() || otherEvp->IsNull() ) 
		{
			return false;
		}

		return !(otherEvp->minX > maxX ||
			otherEvp->maxX < minX ||
			otherEvp->minY > maxY ||
			otherEvp->maxY < minY);
	}

	bool SysEnvelope::Intersects(const SysEnvelope &env) const
	{
		return Intersects(&env);
	}

	void SysEnvelope::ExpandToInclude(double x, double y)
	{
		if (IsNull())
		{
			minX = x;
			maxX = x;
			minY = y;
			maxY = y;
		}

		else 
		{
			if (x < minX) 
			{
				minX = x;
			}
			if (x > maxX) 
			{
				maxX = x;
			}
			if (y < minY) 
			{
				minY = y;
			}
			if (y > maxY) 
			{
				maxY = y;
			}
		}
	}

	void SysEnvelope::ExpandToInclude(const SysCoordinate &pt)
	{
		ExpandToInclude(pt.x,pt.y);
	}

	void SysEnvelope::ExpandToInclude(const SysEnvelope *other)
	{
		if (NULL == other)
		{
			return;
		}
		if (other->IsNull())
		{
			return;
		}

		if (IsNull())
		{
			minX = other->minX;
			maxX = other->maxX;
			minY = other->minY;
			maxY = other->maxY;
		}

		else
		{
			if (other->minX < minX)
			{
				minX = other->minX;
			}
			if (other->maxX > maxX)
			{
				maxX = other->maxX;
			}
			if (other->minY < minY)
			{
				minY = other->minY;
			}
			if (other->maxY > maxY)
			{
				maxY = other->maxY;
			}
		}
	}

	void SysEnvelope::ExpandToInclude(const SysEnvelope &other)
	{
		ExpandToInclude(&other);
	}

	// �жϾ����Ƿ�Ϊ��
	/*inline*/ bool SysEnvelope::IsNull(void) const
	{
		if (maxX <= minX || maxY <= minY)
		{
			return true;
		} 
		return false;
	}

	void SysEnvelope::SetNull(void)
	{
		minX = 1;
		minY = 1;
		maxX = 0;
		maxY = 0;
	}

	// ��ȡ��С������εĿ��
	double SysEnvelope::GetWidth(void) const
	{
		if (IsNull())
		{
			return 0;
		}
		return fabs(maxX - minX);
	}

	// ��ȡ��С�����εĸ߶�
	double SysEnvelope::GetHeight(void) const
	{
		if (IsNull())
		{
			return 0;
		}
		return fabs(maxY - minY);
	}

	// ��þ��ε����ĵ�����
	bool SysEnvelope::Center(SysCoordinate &coord) const
	{
		if (IsNull())
		{
			return false;
		}

		coord.x = minX + GetWidth() / 2.0;
		coord.y = minY + GetHeight() / 2.0;

		return true;
	}

	bool SysEnvelope::Center(double &x,double &y) const
	{
		if (IsNull())
		{
			return false;
		}

		x = minX + GetWidth() / 2.0;
		y = minY + GetHeight() / 2.0;

		return true;
	}

	//�����Ƿ������һ��MBR
	bool SysEnvelope::Contains(const SysEnvelope &env) const
	{
		if (IsNull() || env.IsNull())
		{
			return false;
		}
		return env.minX > minX &&
			env.maxX < maxX &&
			env.minY > minY &&
			env.maxY < maxY;
	}

	//�ж�һ�����Ƿ��ڸþ�����
	bool SysEnvelope::Contains(const SysCoordinate &pt) const
	{
		if (IsNull())
		{
			return false;
		}

		if (pt.x > minX && pt.x < maxX && pt.y > minY && pt.y < maxY)
		{
			return 1;
		}
		return 0;
	}

	//�ھ����ⷵ��0�����򷵻�1
	bool SysEnvelope::IsPointInRect(double x,double y) const
	{
		if (IsNull())
		{
			return false;
		}

		if (x > minX && x < maxX && y > minY && y < maxY)
		{
			return 1;
		}
		return 0;
	}

	//�������������ཻ�Ĳ���
	bool SysEnvelope::Intersection(const SysEnvelope& env,SysEnvelope &envResult) const
	{
		if (IsNull() || env.IsNull() || ! Intersects(env))
		{
			//envResult.s
			return false;
		}

		double intMinX = minX > env.minX ? minX : env.minX;
		double intMinY = minY > env.minY ? minY : env.minY;
		double intMaxX = maxX < env.maxX ? maxX : env.maxX;
		double intMaxY = maxY < env.maxY ? maxY : env.maxY;
		envResult.Init(intMinX, intMaxX, intMinY, intMaxY);

		return true;
	}

	//���㵽��һ��MBR�ľ���
	double SysEnvelope::DistanceTo(const SysEnvelope &env) const
	{
		//����ཻ��������Ϊ0
		if (Intersects(env))
		{
			return 0;
		}
		double dx = 0;
		if (maxX < env.minX)
		{
			dx = env.minX - maxX;
		}
		if (minX > env.maxX)
		{
			dx = minX - env.maxX;
		}

		double dy = 0;
		if (maxY < env.minY)
		{
			dy = env.minY - maxY;
		}
		if (minY > env.maxY)
		{
			dy = minY - env.maxY;
		}

		//�������֮һΪ0�������ˮƽ���ߴ�ֱ����
		if (0.0 == dx)
		{
			return dy;
		}
		if (0.0 == dy)
		{
			return dx;
		}
		return sqrt(dx*dx + dy*dy);
	}

	//�������
	double SysEnvelope::GetArea() const
	{
		if (IsNull())
		{
			return 0;
		}
		return GetHeight()*GetWidth();
	}

	//�����ܳ�
	double SysEnvelope::Perimeter() const
	{
		if (IsNull())
		{
			return 0;
		}
		return GetWidth()*2 + GetHeight()*2;
	}

	void SysEnvelope::Translate(double transX, double transY)
	{
		if (IsNull())
		{
			return;
		}
		minX += transX;
		maxX += transX;
		minY += transY;
		maxY += transY;
	}

	//�����Ƿ����
	bool SysEnvelope::Contains(double x, double y) const
	{
		if (IsNull()) 
			return false;

		return x >= minX &&
			x <= maxX &&
			y >= minY &&
			y <= maxY;
	}

	//�ж�p1,p2���ɵľ��κ�q1,q2���ɵľ����Ƿ��ཻ
	bool SysEnvelope::Intersects(const SysCoordinate &p1, const SysCoordinate &p2, const SysCoordinate &q1, const SysCoordinate &q2)
	{
		double minq = min(q1.x, q2.x);
		double maxq = max(q1.x, q2.x);
		double minp = min(p1.x, p2.x);
		double maxp = max(p1.x, p2.x);

		if( minp >= maxq )
			return false;
		if( maxp <= minq )
			return false;

		minq = min(q1.y, q2.y);
		maxq = max(q1.y, q2.y);
		minp = min(p1.y, p2.y);
		maxp = max(p1.y, p2.y);

		if( minp >= maxq )
			return false;
		if( maxp <= minq )
			return false;
		return true;
	}

}
