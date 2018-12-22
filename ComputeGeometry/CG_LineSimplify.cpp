
#include <math.h>
#include <float.h>
#include "CG_LineSimplify.h"
#include "CG_BaseCal.h"

void FindSplit(CG_Point *poPoints, int i, int j, int *pIndex, double *pDist)
{
	//�м������������
	double tempDist = 0;
	*pDist = 0;
	*pIndex = 0;

	for(int k = i+1; k< j; k ++)
	{
		tempDist = PointToLine(poPoints[k],poPoints[i],poPoints[j]);  //����㵽�ߵľ���

		//�������Ƚ�
		if (tempDist >= *pDist)
		{
			*pDist = tempDist;
			*pIndex = k;		//��ǰ��Ϊ���ѵ�
		}
	}
}

void DouglasPeucker(CG_Point *poPoints, bool* pFlags, int nCount, 
					int nStart, int nEnd, double dbEps,
					std::vector<CG_Point> &vecPoint)
{
	//���ȼ����м�����㵽��β����ֱ�ߵľ��룬���������
	double dbDist = DBL_MAX;
	int nIndex = 0;
	FindSplit(poPoints,nStart,nEnd,&nIndex,&dbDist);

	/*�������������ݲ���Ա��������������㣬
	���������Ϊ���ѵ��Ϊ���Σ�Ȼ��ݹ�ض��������ظ����л���	*/
	
	if (dbDist <= dbEps)	  //ֱ������Ϊ0����ֹͣ�ݹ�
	{
		//ֱ������β������Ϊ���ߵĽ���
 		pFlags[nStart] = 1;
		pFlags[nEnd] = 1;
		//return;
	}
	else if (dbDist > dbEps)
	{
		pFlags[nIndex] = 1;
		DouglasPeucker(poPoints,pFlags,nCount,nStart,nIndex,dbEps,vecPoint);	//��ǰ��ν��д���
		DouglasPeucker(poPoints,pFlags,nCount,nIndex,nEnd,dbEps,vecPoint);		//�Ժ��ν��д���
	}

	//��󽫱��ΪTRUE�ĵ��������
	for (int i = 0; i < nCount; i ++)
	{
		if (pFlags[i])
		{
			vecPoint.push_back(poPoints[i]);
		}
	}
}
