/*******************************************************************************
@ ��Ȩ����(C) ����ʡ�ռ���Ϣ�����о����� 2013
@ �ļ�����	: CG_LineSmoothing.h
@ ��ǰ�汾	: 1.0.0.1
@ ��    ��	: guang (zhouxuguang236@126.com)
@ �������	: 2013��12��7��
@ ����ժҪ	: ���߹⻬�㷨
@ �޸ļ�¼	: 
@ ��    ��		��    ��		�޸���		�޸�ժҪ

********************************************************************************/
#ifndef __CG_LINESMOOTHING_H_0C56DAAD_1FF2_49F2_BA92_7AEF8559D6B7__
#define __CG_LINESMOOTHING_H_0C56DAAD_1FF2_49F2_BA92_7AEF8559D6B7__

#include "CG_Common.h"

//���Ե����⻬����Ĩ�Ƿ���
COMPUTEGEOMETRY_API void WipeAngleMethod(SPOINT* pPoints,int nCount,int k);

//���⻬
COMPUTEGEOMETRY_API bool FivePointsSmoothing(const SPOINT* poPoints,int nCount,double dbEps,std::vector<SPOINT>& vecResult);

//�������������߹⻬
COMPUTEGEOMETRY_API bool OrthoaxisParabolaSmoothing(const SPOINT* poPoints,int nCount,double dbEps,std::vector<SPOINT>& vecResult);

#endif // end of __CG_LINESMOOTHING_H_0C56DAAD_1FF2_49F2_BA92_7AEF8559D6B7__
