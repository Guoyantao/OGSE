
#include "Material.h"

NS_MATH3D_BEGIN

Material::Material()
{
	M_Ambient = ColorRGBA(0.2,0.2,0.2);//���ʶԻ�����ķ�����
	M_Diffuse = ColorRGBA(0.8,0.8,0.8);//���ʶ��������ķ�����
	M_Specular = ColorRGBA(0.0,0.0,0.0);//���ʶԾ��淴���ķ�����
	M_Emit = ColorRGBA(0.0,0.0,0.0);//��������ɢ����ɫ
	M_n = 1.0;//�߹�ָ��
}

Material::~Material()
{

}

void Material::SetAmbient(const ColorRGBA& c)
{
	M_Ambient = c;
}

void Material::SetDiffuse(const ColorRGBA& c)
{
	M_Diffuse = c;
}

void Material::SetSpecular(const ColorRGBA& c)
{
	M_Specular = c;
}

void Material::SetEmit(const ColorRGBA& emi)
{
	M_Emit = emi;
}

void Material::SetExp(Real n)
{
	M_n = n;
}

NS_MATH3D_END