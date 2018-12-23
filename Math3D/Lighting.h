

#if !defined(AFX_LIGHTING_H__4E9D1F90_7696_4D33_999F_6417C555CB36__INCLUDED_)
#define AFX_LIGHTING_H__4E9D1F90_7696_4D33_999F_6417C555CB36__INCLUDED_

//���ռ�����

#include "ColorRGBA.h"

class Vector3;
class Light;
class Material;

class MATH3D_API Lighting  
{
public:

	Lighting();

	Lighting(int);

	~Lighting();

	void SetLightNumber(int nLightNum);//���ù�Դ����

	//�������
	ColorRGBA ComputeLight(const Vector3& viewPoint,const Vector3& point,const Vector3& normal,Material *pMaterial);

public:
	int mLightNum;//��Դ����
	Light *m_pLights;//��Դ����
	ColorRGBA mAmbient;//������
};

#endif // !defined(AFX_LIGHTING_H__4E9D1F90_7696_4D33_999F_6417C555CB36__INCLUDED_)
