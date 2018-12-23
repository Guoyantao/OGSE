
#ifndef AFX_MATERIAL_H__1161180E_9A92_4DAE_AB2E_757671AB6E12__INCLUDED_
#define AFX_MATERIAL_H__1161180E_9A92_4DAE_AB2E_757671AB6E12__INCLUDED_

#include "ColorRGBA.h"

NS_MATH3D_BEGIN

class MATH3D_API Material  
{
public:
	Material();

	~Material();

	void SetAmbient(const ColorRGBA&);//���ò��ʶԻ�����ķ�����

	void SetDiffuse(const ColorRGBA&);//���ò��ʶ��������ķ�����

	void SetSpecular(const ColorRGBA&);//���ò��ʶԾ��淴���ķ�����

	void SetEmit(const ColorRGBA&);//���ò�������������ɫ

	void SetExp(Real);//���ò��ʵĸ߹�ָ��	
public:
	ColorRGBA M_Ambient;//���ʶԻ�����ķ�����
	ColorRGBA M_Diffuse;//���ʶ��������ķ�����
	ColorRGBA M_Specular;//���ʶԾ��淴���ķ�����
	ColorRGBA M_Emit;//��������������ɫ
	Real M_n;//���ʵĸ߹�ָ��
};

NS_MATH3D_END

#endif // 
