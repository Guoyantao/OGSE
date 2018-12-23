#pragma once

#include "../Math3DCommon.h"
#include <bitset>

enum VisibleFlag
{
	Visible,		//�ɼ�
	NoVisible,		//��ȫ���ɼ�
	PartVisible		//���ֿɼ�
};

//�߶ζ˵����
void EndCode(float x,float y,
			 float Window[4],
			 std::bitset<4>& bitCode);

//�������˵������߼�������Ƿ�Ϊ0
int Logical(const std::bitset<4> &pCode1,const std::bitset<4> &pCode2);

//��ö����Ʊ����λ�ĺ�
int CodeSum(const std::bitset<4> &pCode);

VisibleFlag IsVisible(const std::bitset<4> &pCode1,
					  const std::bitset<4> &pCode2,
					  int nSum1,
					  int nSum2);

//�߶βü��������п��ܸ���
MATH3D_API VisibleFlag CoSutherLineClip(float &x1,float &y1,float &x2,float &y2,
					  float Window[4]);


//�е�ָ��㷨
MATH3D_API VisibleFlag MidPointLineClip(float &x1,float &y1,float &x2,float &y2,
											 float Window[4]);
