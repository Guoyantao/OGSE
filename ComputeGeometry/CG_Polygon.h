/*******************************************************************************
@ ��Ȩ����(C) ����ʡ�ռ���Ϣ�����о����� 2013
@ �ļ�����	: CG_Polygon.h
@ ��ǰ�汾	: 1.0.0.1
@ ��    ��	: guang (zhouxuguang236@126.com)
@ �������	: 2013��11��4��
@ ����ժҪ	: ������㷨
@ �޸ļ�¼	: 
@ ��    ��		��    ��		�޸���		�޸�ժҪ

********************************************************************************/
#ifndef __CG_POLYGON_H_BF9B7E8F_69F3_44C4_8CB5_FD344EA626DD__
#define __CG_POLYGON_H_BF9B7E8F_69F3_44C4_8CB5_FD344EA626DD__

#ifdef  __cplusplus
extern "C" {
#endif

/*******************************************************************************
@ ��������	: IsIntersectAnt
@ ��������	: ��Y�������ߣ���ָ�����
@ �Ρ�����	: double x
@ �Ρ�����	: double y
@ �Ρ�����	: double X1
@ �Ρ�����	: double Y1
@ �Ρ�����	: double X2
@ �Ρ�����	: double Y2
@ �� �� ֵ	: int
@ ��������	: guang
@ �������	: 2013��11��4��
@ �޸�����		   �޸���		  �޸�����
*******************************************************************************/
int IsIntersectAnt(double x,double y,double X1,double Y1,double X2,double Y2);


/*******************************************************************************
@ ��������	: PointInPolygon
@ ��������	: �жϵ������ι�ϵ���򵥶���Σ�
@ �Ρ�����	: const SPOINT& poPoint
@ �Ρ�����	: const SPOINT* lpPoints
@ �Ρ�����	: int nCnt
@ �Ρ�����	: int &PtCount
@ �� �� ֵ	: int 
@ ��������	: guang
@ �������	: 2013��11��4��
@ �޸�����		   �޸���		  �޸�����
*******************************************************************************/
COMPUTEGEOMETRY_API int PointInPolygon(const SPOINT& poPoint,const SPOINT* lpPoints,int nCnt,int &PtCount);


/*******************************************************************************
@ ��������	: PointInPolyPolygon
@ ��������	: �жϵ������ι�ϵ����������Σ�
@ �Ρ�����	: const SPOINT& poPoint
@ �Ρ�����	: const SPOINT* lpPoints
@ �Ρ�����	: const int *lpPolyCounts
@ �Ρ�����	: int nCount
@ �� �� ֵ	: int
@ ��������	: guang
@ �������	: 2013��11��4��
@ �޸�����		   �޸���		  �޸�����
*******************************************************************************/
COMPUTEGEOMETRY_API int PointInPolyPolygon(const SPOINT& poPoint,const SPOINT* lpPoints,
										   const int *lpPolyCounts,int nCount);


/*******************************************************************************
@ ��������	: PolyCentroid
@ ��������	: �����������ĵ�
@ �Ρ�����	: const SPOINT* points
@ �Ρ�����	: int nCount
@ �Ρ�����	: double *xCentroid ���ĵ�x����
@ �Ρ�����	: double *yCentroid ���ĵ�y����
@ �� �� ֵ	: void
@ ��������	: guang
@ �������	: 2013��11��4��
@ �޸�����		   �޸���		  �޸�����
*******************************************************************************/
COMPUTEGEOMETRY_API void PolyCentroid(const SPOINT* points,int nCount,double *xCentroid,double *yCentroid);

//������Ƿ����ཻ
COMPUTEGEOMETRY_API int IsPolygonSelfIntersect(const SPOINT* points,int nCount);


#ifdef  __cplusplus
}
#endif


#endif // end of __CG_POLYGON_H_BF9B7E8F_69F3_44C4_8CB5_FD344EA626DD__
