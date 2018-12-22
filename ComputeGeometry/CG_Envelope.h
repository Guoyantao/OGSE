/*******************************************************************************
* ��Ȩ����(C) ����ʡ�ռ���Ϣ�����о����� 2012
* �ļ�����	: GeoEnvelope.h
* ��ǰ�汾	: 1.0.0.1
* ��    ��	: ����� (zhouxuguang@126.com)
* �������	: 2011��10��6��
* ����ժҪ	: ��С��Χ��
* �޸ļ�¼	:
* ��    ��		��    ��		�޸���		�޸�ժҪ

********************************************************************************/
#ifndef __G_ENVELOPE_H_118FB5E8_C3C6_42F6_BE56_D37A882316F8__
#define __G_ENVELOPE_H_118FB5E8_C3C6_42F6_BE56_D37A882316F8__

/**********************************  ͷ�ļ� ************************************/

#include "CG_Common.h"


class COMPUTEGEOMETRY_API CG_Envelope
{
public:
	//Ĭ�Ϲ��캯��
	CG_Envelope();

	//�������Ĺ��캯��
	CG_Envelope(double minX,double maxX,double minY,double maxY);

	//�������캯��
	CG_Envelope(const CG_Envelope& envelope);

	//������������ʼ��
	CG_Envelope(const SPOINT &coord1,const SPOINT & coord2);

	~CG_Envelope(void);

	//�ж�������С��������Ƿ��ཻ(��������ڻ�����)
	int InterSects(const CG_Envelope & otherEvp);

	// �жϾ����Ƿ�Ϊ��
	bool IsNull(void) const;

	// ��ȡ��С������εĿ��
	double GetWidth(void) const;

	// ��ȡ��С�����εĸ߶�
	double GetHeight(void) const;

	// ��þ��ε����ĵ�����
	SPOINT &Center() const;

	bool Center(double *pX,double *pY) const;

	//�����Ƿ������һ��MBR
	bool Contains(const CG_Envelope &env) const;

	//�ж�һ�����Ƿ��ڸþ�����
	bool Contains(const SPOINT &pt) const;

	//�Ƿ���������
	bool Contains(double x, double y) const;

	//�ж�һ�����Ƿ��ھ�����
	bool IsPointInRect(double x,double y) const;

	//�������������ཻ�Ĳ���
	CG_Envelope& Intersection(const CG_Envelope& env);

	//���㵽��һ��MBR�ľ���
	double DistanceTo(CG_Envelope &env);

	//�������
	double Area() const;

	//�����ܳ�
	double Perimeter() const;

	//��̬����

	//�ж�p1,p2���ɵľ��κ�q1,q2���ɵľ����Ƿ��ཻ
	static bool Intersects(const SPOINT &p1, const SPOINT &p2, 
		const SPOINT &q1, const SPOINT &q2);

	static bool Intersects(const CG_Envelope &env1, const CG_Envelope &env2);

public:
	double minX;	//��С������ε���Сxֵ
	double maxX;	//��С������ε����xֵ
	double minY;	//��С������ε���Сyֵ
	double maxY;	//��С������ε����yֵ
};

#endif // end of __GEOENVELOPE_H_E9CBC39A_81BD_4AC7_BD29_EB1D0D58CF03__

