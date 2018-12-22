/*******************************************************************************
* ��Ȩ����(C) ����ʡ�ռ���Ϣ�����о����� 2013
* �ļ�����	: CG_Polyline.h
* ��ǰ�汾	: 1.0.0.1
* ��    ��	: ����� (zhouxuguang236@126.com)
* �������	: 2013��10��26��
* ����ժҪ	: ��������㷨
* �޸ļ�¼	: 
* ��    ��		��    ��		�޸���		�޸�ժҪ

********************************************************************************/
#ifndef __CG_POLYLINE_H_461DA143_4CAB_4FC8_B364_0A0A885E0B17__
#define __CG_POLYLINE_H_461DA143_4CAB_4FC8_B364_0A0A885E0B17__


#include "CG_Envelope.h"

//�������ݽṹ
struct TPolyline
{
	SPOINT* points;		//�㼯
	int nCount;			//����
	int nChainNum;		//�������ĸ���
};

//������
struct TChain
{
	SPOINT* points;		//�㼯
	int nCount;			//��ĸ���
	CG_Envelope box;	//��С�������
	bool bIncrement;	//�Ƿ��������Ϊ1������Ϊ0
	bool bAxisX;		//�Ƿ�x����
};

//�߶��ཻ�ṹ��
struct Tline_Intersect
{
	int nLineNum;		//�ͱ��߶��ཻ����Ŀ
	int* poLines;		//�߶��б�
};

//ɨ��ṹ��
struct TSweep
{
	int nIndex;				//�߶��ڵ������ϵ���ţ�������֮��
	bool bIsFirstLine;		//�Ƿ��ڵ�һ���߶��ϣ���Ϊ1������Ϊ0
};

#ifdef __cplusplus
	extern "C" {
#endif

		//�������Ƿ��ཻ
COMPUTEGEOMETRY_API void IsChianIntersect(const TChain& chain1,const TChain& chain2,Tline_Intersect &inter_info);

//�㵽�߶ε���̾���
COMPUTEGEOMETRY_API double Point2Segment(const SPOINT &point,SPOINT& pt0,SPOINT& pt1);

	//�㵽���ߵ���̾���
COMPUTEGEOMETRY_API double PointDisPolyline(const SPOINT& point,const SPOINT* poString,int nCount);


#ifdef __cplusplus
	}
#endif

#endif // end of __CG_POLYLINE_H_461DA143_4CAB_4FC8_B364_0A0A885E0B17__