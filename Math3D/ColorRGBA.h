#ifndef MATH3D_COLORRGBA_INCLUDE_H_4FG56FL
#define MATH3D_COLORRGBA_INCLUDE_H_4FG56FL

#include "Math3DCommon.h"

NS_MATH3D_BEGIN

class MATH3D_API ColorRGBA
{
public:
	ColorRGBA ();

	ColorRGBA (float fR, float fG, float fB,float fA = 1.0f);

	ColorRGBA (float afTuple[4]);

	~ColorRGBA(void);

	//operator����ڲ�����
	operator const float* () const;
	operator float* ();

	//���ػ�÷���
	float operator[] (int i) const;
	float& operator[] (int i);

	//���ؼӼ��˳�
	ColorRGBA operator *(float kScale) const;

	ColorRGBA operator /(float kScale) const;

	ColorRGBA operator -() const; 

	ColorRGBA operator + (const ColorRGBA& other) const;

	ColorRGBA operator - (const ColorRGBA& other) const;

	ColorRGBA operator = (const ColorRGBA& other) const;

	friend ColorRGBA operator*(const ColorRGBA &a,const ColorRGBA &b);

	ColorRGBA& operator += (const ColorRGBA& other);

	//member func
	float GetR () const;
	float& GetR ();
	float GetG () const;
	float& GetG ();
	float GetB () const;
	float& GetB ();
	float GetA () const;
	float& GetA ();

	ColorRGBA Multiply(const ColorRGBA& color) const;

private:
	mutable float m_pfValues[4];			//RGB˳��

	void SetRGBA(float fRed,float fGreen,float fBlue,float fAlpha);

public:
	static const ColorRGBA& ZERO;		//�ĸ���������0
	static const ColorRGBA& Black;		//��ɫ
	static const ColorRGBA& White;		//��ɫ
	static const ColorRGBA& Red;			//��ɫ
	static const ColorRGBA& Green;		//��ɫ
	static const ColorRGBA& Blue;		//��ɫ
};

NS_MATH3D_END

#endif
