/*******************************************************************************
* ��Ȩ����(C) ����ʡ�ռ���Ϣ�����о����� 2012
* �ļ�����	: CG_LineSimplify.h
* ��ǰ�汾	: 1.0.0.1
* ��    ��	: ����� (zhouxuguang236@126.com)
* �������	: 2012��10��21��
* ����ժҪ	: ���߻����㷨
* �޸ļ�¼	: 
* ��    ��		��    ��		�޸���		�޸�ժҪ

********************************************************************************/
#ifndef __CGLINESIMPLIFY_H_1DFB73A5_0295_4682_9A13_FAC2D641BB22__
#define __CGLINESIMPLIFY_H_1DFB73A5_0295_4682_9A13_FAC2D641BB22__

#include <vector>
#include "CG_Common.h"

#ifdef  __cplusplus
extern "C" {
#endif

	//������˹-�տ��㷨
	COMPUTEGEOMETRY_API void DouglasPeucker(
		CG_Point *poPoints, 
		bool* pFlags, 
		int nCount, 
		int nStart, 
		int nEnd, 
		double dbEps,
		std::vector<CG_Point> &vecPoint);

#ifdef  __cplusplus
}
#endif

#endif
