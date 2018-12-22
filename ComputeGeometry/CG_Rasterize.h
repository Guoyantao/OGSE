
/*******************************************************************************
@ ��Ȩ����(C) ����ʡ�ռ���Ϣ�����о����� 2013
@ �ļ�����	: CG_Rasterize.h
@ ��ǰ�汾	: 1.0.0.1
@ ��    ��	: guang (zhouxuguang236@126.com)
@ �������	: 2013��11��4��
@ ����ժҪ	: ʸ��դ���㷨
@ �޸ļ�¼	: 
@ ��    ��		��    ��		�޸���		�޸�ժҪ

********************************************************************************/
#ifndef __CG_RASTERIZE_H_BF9B7E8F_69F3_44C4_8CB5_FD344EA626DD__
#define __CG_RASTERIZE_H_BF9B7E8F_69F3_44C4_8CB5_FD344EA626DD__

#include "CG_Common.h"

#ifdef  __cplusplus
extern "C" {
#endif

	COMPUTEGEOMETRY_API bool LineRasterize(
		SPOINT* poPoints,
		double dbMinx,
		double dbMaxy,
		double dx,
		double dy,
		unsigned short *podata,
		int nWidth,
		int nHeight);

#ifdef  __cplusplus
}
#endif


#endif // end of __CG_RASTERIZE_H_BF9B7E8F_69F3_44C4_8CB5_FD344EA626DD__
