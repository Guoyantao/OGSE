#ifndef MATH3D_TRIANGLE3D_INCLUDE_H_
#define MATH3D_TRIANGLE3D_INCLUDE_H_

#include "Plane3D.h"

NS_MATH3D_BEGIN

//��ά�����Σ���������ײ���
class MATH3D_API Triangle3D
{
public:
	Triangle3D(void);

	Triangle3D(const Vector3& v1, const Vector3& v2, const Vector3& v3);

	~Triangle3D(void);

	//��÷���������õķ�������һ���ǵ�λ����
	Vector3 GetNormal(void) const;

	//������������ڵ�ƽ��
	Plane3D GetPlane(void) const;

	//�������
	Real GetArea(void) const;

	//�жϵ��Ƿ����������ڣ���Ҫע����ǵ�������������ͬһ��ƽ����
	bool IsPointInside(const Vector3& p) const;

	Vector3 mPointA;
	Vector3 mPointB;
	Vector3 mPointC;
};

NS_MATH3D_END

#endif
