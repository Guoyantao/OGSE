/*******************************************************************************
* ��Ȩ����(C) ����ʡ�ռ���Ϣ�����о����� 2013
* �ļ�����	: BaseCal.h
* ��ǰ�汾	: 1.0.0.1
* ��    ��	: ����� (zhouxuguang236@126.com)
* �������	: 2012��10��21��
* ����ժҪ	: ���������������
* �޸ļ�¼	: 
* ��    ��		��    ��		�޸���		�޸�ժҪ

********************************************************************************/
#ifndef __BASECAL_H_60C8CA6D_A89B_417E_9E1F_9997AC3E50BA__
#define __BASECAL_H_60C8CA6D_A89B_417E_9E1F_9997AC3E50BA__

/**********************************  ͷ�ļ� ************************************/

#include "CG_Vector2.h"
#include "CG_Envelope.h"

#ifdef  __cplusplus
extern "C" {
#endif

/*******************************************************************************
@ ��������	: GetEnvelope
@ ��������	: ����һ������С�������
@ �Ρ�����	: const SPOINT* points
@ �Ρ�����	: int nCount
@ �Ρ�����	: CG_Envelope& env
@ �� �� ֵ	: void
@ ��������	: guang
@ �������	: 2013��11��4��
@ �޸�����		   �޸���		  �޸�����
*******************************************************************************/
COMPUTEGEOMETRY_API void GetEnvelope(const SPOINT* points,int nCount,CG_Envelope& env);


/*******************************************************************************
@ ��������	: Distance
@ ��������	: �����p1��p2֮���ŷ����þ���
@ �Ρ�����	: const SPOINT &p1
@ �Ρ�����	: const SPOINT &p2
@ �� �� ֵ	: double
@ ��������	: guang
@ �������	: 2013��11��4��
@ �޸�����		   �޸���		  �޸�����
*******************************************************************************/
COMPUTEGEOMETRY_API double Distance(const SPOINT &p1,const SPOINT &p2); 


/*******************************************************************************
@ ��������	: DirectionAngle
@ ��������	: �����߶�p1p2�ķ����,����Ǵ�x���Ὺʼ��ʱ����ת�ĽǶ�
@ �Ρ�����	: const SPOINT &p1
@ �Ρ�����	: const SPOINT &p2
@ �� �� ֵ	: double
@ ��������	: guang
@ �������	: 2013��11��4��
@ �޸�����		   �޸���		  �޸�����
*******************************************************************************/
COMPUTEGEOMETRY_API double DirectionAngle(const SPOINT &p1,const SPOINT &p2);


/*******************************************************************************
@ ��������	: Equal_point
@ ��������	: �ж��������Ƿ��غ�
@ �Ρ�����	: SPOINT p1
@ �Ρ�����	: SPOINT p2
@ �� �� ֵ	: bool
@ ��������	: guang
@ �������	: 2013��11��4��
@ �޸�����		   �޸���		  �޸�����
*******************************************************************************/
COMPUTEGEOMETRY_API bool Equal_point(SPOINT p1,SPOINT p2);  


/*******************************************************************************
@ ��������	: Multiply
@ ��������	: r=multiply(sp,ep,op),�õ�(sp-op)��(ep-op)�Ĳ�� 
				r>0��ep��ʸ��opsp����ʱ�뷽�� 
				=0��opspep���㹲�ߣ� 
				r<0��ep��ʸ��opsp��˳ʱ�뷽��
@ �Ρ�����	: SPOINT sp
@ �Ρ�����	: SPOINT ep
@ �Ρ�����	: SPOINT op
@ �� �� ֵ	: double
@ ��������	: guang
@ �������	: 2013��11��4��
@ �޸�����		   �޸���		  �޸�����
*******************************************************************************/
COMPUTEGEOMETRY_API double Multiply(SPOINT sp,SPOINT ep,SPOINT op);


/*******************************************************************************
@ ��������	: IsPointOnLine
@ ��������	: �жϵ�point�Ƿ����߶�lineSeg��
@ �Ρ�����	: const SPOINT &point
@ �Ρ�����	: const SEGMENT& lineSeg
@ �� �� ֵ	: bool
@ ��������	: guang
@ �������	: 2013��11��4��
@ �޸�����		   �޸���		  �޸�����
*******************************************************************************/
COMPUTEGEOMETRY_API bool IsPointOnLine(const SPOINT &point,const SEGMENT& lineSeg);

/*******************************************************************************
@ ��������	: IsPointOnLineEx
@ ��������	: �жϵ�point�Ƿ����߶���
@ �Ρ�����	: const SPOINT &point
@ �Ρ�����	: const SPOINT& p1
@ �Ρ�����	: const SPOINT& p2
@ �� �� ֵ	: bool
@ ��������	: guang
@ �������	: 2013��11��4��
@ �޸�����		   �޸���		  �޸�����
*******************************************************************************/
COMPUTEGEOMETRY_API bool IsPointOnLineEx(const SPOINT &point,const SPOINT& p1,const SPOINT& p2);

/*******************************************************************************
@ ��������	: SplitLine
@ ��������	: ����߶�
@ �Ρ�����	: const SPOINT& p1
@ �Ρ�����	: const SPOINT& p2
@ �Ρ�����	: double dbDist
@ �� �� ֵ	: void
@ ��������	: guang
@ �������	: 2013��11��4��
@ �޸�����		   �޸���		  �޸�����
*******************************************************************************/
COMPUTEGEOMETRY_API void SplitLine(const SPOINT& p1,const SPOINT& p2,double dbDist, SPOINT& ptResult);


/*******************************************************************************
@ ��������	: IsLineIntersect
@ ��������	: �ж��߶�lineSeg1��lineSeg2�Ƿ��ཻ
@ �Ρ�����	: const SEGMENT& lineSeg1
@ �Ρ�����	: const SEGMENT& lineSeg2
@ �� �� ֵ	: bool
@ ��������	: guang
@ �������	: 2013��11��4��
@ �޸�����		   �޸���		  �޸�����
*******************************************************************************/
COMPUTEGEOMETRY_API bool IsLineIntersect(const SEGMENT& lineSeg1,const SEGMENT& lineSeg2);

//����߶εĽ�������.�߶�s1e1,s2e2�����stResult
COMPUTEGEOMETRY_API void GetCrossPoint(const SPOINT& s1,const SPOINT& e1,const SPOINT& s2,const SPOINT& e2,SPOINT &stResult);

//������������㹫ʽHeron��ʽ a b cΪ���߳�
COMPUTEGEOMETRY_API double Heron(double a,double b,double c);

//����㵽ֱ�ߵĴ������(ptΪ�㣬startPt��endPtΪֱ��)
COMPUTEGEOMETRY_API double PointToLine(const SPOINT &pt, const SPOINT &startPt, const SPOINT &endPt);

#ifdef  __cplusplus
}
#endif

#endif // end of __BASECAL_H_60C8CA6D_A89B_417E_9E1F_9997AC3E50BA__
