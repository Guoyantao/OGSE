#ifndef MATH3D_PLANE3D_INCLUDE_H_02FG458HK6T5UIK
#define MATH3D_PLANE3D_INCLUDE_H_02FG458HK6T5UIK

#include "Vector3.h"
#include "GeometryObject.h"

NS_MATH3D_BEGIN

//��άƽ����ķ�װ Ax + By + Cz + D = 0

class MATH3D_API Plane3D 
{
public:

	enum Side
	{
		NEGATIVE_SIDE,//����
		POSITIVE_SIDE,//��
		NO_SIDE
	};

	Plane3D(const Vector3& rkNormal,Real fConstant);

	Plane3D(Real a,Real b,Real c,Real d);

	Plane3D(const Vector3& rkPoint1, const Vector3& rkPoint2,
		const Vector3& rkPoint3);

	Plane3D(const Plane3D& rhs);

	~Plane3D(void);

	Plane3D& operator = (const Plane3D& rhs);

	//��㵽ƽ��ľ���
	Real GetDistance(const Vector3& rkPoint) const;

	//�жϵ��ƽ��Ĺ�ϵ
	Plane3D::Side GetSide(const Vector3& rkPoint) const;

	//�����������ߵĵ㶨��ƽ�淽��
	void ReDefine(const Vector3& rkPoint1, const Vector3& rkPoint2,const Vector3& rkPoint3);

	//�淶��
	Real Normalise(void);

	//�̳����ĺ���

	bool Hit(const Ray3D& ray, double& t, ShadeRec& s) const;

private:
	Vector3 m_Normal;		//��������
	Real m_fD;				//����

	static const Real kEpsilon;
};

NS_MATH3D_END

#endif
