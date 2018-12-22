/*******************************************************************************
@ ��Ȩ����(C) ����ʡ�ռ���Ϣ�����о����� 2013
@ �ļ�����	: CG_Buffer.h
@ ��ǰ�汾	: 1.0.0.1
@ ��    ��	: guang (zhouxuguang236@126.com)
@ �������	: 2013��11��4��
@ ����ժҪ	: ����������
@ �޸ļ�¼	: 
@ ��    ��		��    ��		�޸���		�޸�ժҪ

********************************************************************************/
#ifndef __CG_BUFFER_H_685DB7DA_07E0_4E78_9BB0_BE2B5D5089B2__
#define __CG_BUFFER_H_685DB7DA_07E0_4E78_9BB0_BE2B5D5089B2__

#include <vector>

#ifdef  __cplusplus
extern "C" {
#endif


	/*******************************************************************************
	@ ��������	: LineBuffer
	@ ��������	: 
	@ �Ρ�����	: SPOINT* poPoints
	@ �Ρ�����	: int nPointCount
	@ �Ρ�����	: double dbBuffer
	@ �Ρ�����	: std::vector<SPOINT>& vecResult
	@ �� �� ֵ	: void
	@ ��������	: guang
	@ �������	: 2013��12��29��
	@ �޸�����		   �޸���		  �޸�����
	*******************************************************************************/
	COMPUTEGEOMETRY_API void LineBuffer(SPOINT* poPoints,int nPointCount,
		double dbBuffer,std::vector<SPOINT>& vecResult);

	/*******************************************************************************
	@ ��������	: ArcCycle
	@ ��������	: Բ�����
	@ �Ρ�����	: int x0
	@ �Ρ�����	: int y0
	@ �Ρ�����	: double dbRadius
	@ �Ρ�����	: double dbThea
	@ �Ρ�����	: bool bClockWise
	@ �Ρ�����	: double ang1
	@ �Ρ�����	: double ang2
	@ �Ρ�����	: std::vector<CG_Point>& vecResult
	@ �� �� ֵ	: void
	@ ��������	: guang
	@ �������	: 2013��12��29��
	@ �޸�����		   �޸���		  �޸�����
	*******************************************************************************/
	void ArcCycle(double x0, double y0, double dbRadius, double dbThea,bool bClockWise,
		double ang1, double ang2,std::vector<CG_Point>& vecResult);


#ifdef  __cplusplus
}
#endif

#endif // end of __CG_BUFFER_H_685DB7DA_07E0_4E78_9BB0_BE2B5D5089B2__

