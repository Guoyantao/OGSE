/*******************************************************************************
* ��Ȩ����(C) pyhcx 2012
* �ļ�����	: ConvexHull.h
* ��ǰ�汾	: 1.0.0.1
* ��    ��	: ����� (zhouxuguang236@126.com)
* �������	: 2012��10��21��
* ����ժҪ	: 
* �޸ļ�¼	: 
* ��    ��		��    ��		�޸���		�޸�ժҪ

********************************************************************************/
#ifndef __CONVEXHULL_H_73C855BC_30C3_4EC4_9374_C03505F2CC11__
#define __CONVEXHULL_H_73C855BC_30C3_4EC4_9374_C03505F2CC11__

/**********************************  ͷ�ļ� ************************************/

//#include "CG_Common.h"
#include "CG_BaseCal.h"

COMPUTEGEOMETRY_API void Graham_scan(SPOINT *poPoints,SPOINT *ch,int nCount,int &len);

#endif // end of __CONVEXHULL_H_73C855BC_30C3_4EC4_9374_C03505F2CC11__
