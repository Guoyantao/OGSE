/*******************************************************************************
* ��Ȩ����(C) ����ʡ�ռ���Ϣ�����о����� 2013
* �ļ�����	: CG_Delaunay.h
* ��ǰ�汾	: 1.0.0.1
* ��    ��	: ����� (zhouxuguang236@126.com)
* �������	: 2013��10��26��
* ����ժҪ	: DELAUNAY�������㷨
* �޸ļ�¼	: 
* ��    ��		��    ��		�޸���		�޸�ժҪ

********************************************************************************/
#ifndef __CG_DELAUNAY_H_B667D47E_F4E2_4DE6_8F7F_B3C138F473D6__
#define __CG_DELAUNAY_H_B667D47E_F4E2_4DE6_8F7F_B3C138F473D6__

#include "CG_Common.h"

typedef struct D_Triangle D_Triangle;

//DELAUNAY�������Ķ���ṹ
struct D_Vertex 
{
	int vertexID;
	double x;
	double y;
	double z;
};

//DELAUNAY�������ı߽ṹ
struct D_Edge
{
	int edgeID;		//
	D_Vertex* pBeginVertex;		//��ʼ��
	D_Vertex* pEndVertex;		//������
	D_Triangle* pLTria;			//������������,ֻ��������ߵĻ��ұߵ�
	D_Edge* pREdge;				//����Ӧ�ķ����
};

//DELAUNAY�������������νṹ
struct D_Triangle
{
	int triangleID;
	D_Edge* ppEdge[3];		//������
};
COMPUTEGEOMETRY_API bool CreateDelaunayNet(const CG_Point* pPoints,int nCount);

#endif // end of __CG_DELAUNAY_H_B667D47E_F4E2_4DE6_8F7F_B3C138F473D6__

