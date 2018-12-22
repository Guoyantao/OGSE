#include "CG_BaseCal.h"
#include "CG_Polygon.h"

//��Y�������ߣ���ָ�����
int IsIntersectAnt(double x,double y,double X1,double Y1,double X2,double Y2)
{
	//�����߶ε���С���������ֵ
	double minX,maxX,minY,maxY;

	minX = min(X1,X2);
	minY = min(Y1,Y2);
	maxX = max(X1,X2);
	maxY = max(Y1,Y2);

	//��������޽���Ŀ����ж�
	if (y<minY || y>maxY || x<minX)
	{
		return 0;
	}

	//�����ˮƽ�߶Σ����߶��Ϸ���-1�����򷵻�0
	if (fabs(maxY - minY) < EPS)
	{
		return (x >= minX && x <= maxX)? (-1):0;
	}

	//���������������ֱ�ߵĽ���ĺ�����
	double x0 = X1 + (double)(y - Y1)*(X2 - X1)/(Y2 - Y1);

	//�����������Ҳ࣬���ཻ
	if (x0 > x)
	{
		return 0;
	}
	//��������������ͬ
	if (fabs(x-x0)< EPS)
	{
		return -1;
	}
	//�����¶˵�Ҳ������
	if (fabs(y-minY) < EPS)
	{
		return 0;
	}
	return 1;

}

int PointInPolygon(const SPOINT& poPoint,const SPOINT* poPoints,int nCnt,int &PtCount)
{
	//����㲻�ڶ���ε���С��Ӿ����У���һ�����ڶ������
	CG_Envelope env;
	GetEnvelope(poPoints,nCnt,env);
	if (!env.IsPointInRect(poPoint.x,poPoint.y))
	{
		return 0;
	}

	//����õ������������������ߵĽ������
	int nCount = 0;
	double X = poPoint.x;
	double Y = poPoint.y;
	int nFlag = 0;

	for (int i = 0; i < nCnt-1; i ++)
	{
		nFlag = IsIntersectAnt(X,Y,poPoints[i].x,poPoints[i].y,
			poPoints[i+1].x,poPoints[i+1].y);
		if (nCount < 0) 
		{
			return 2;	//���ڱ���
		}
		nCount += nFlag;
	}

	if (nCount % 2 == 1)   //���ڶ������
	{
		return 1;
	}
	else
		return 0;
}

int PointInPolyPolygon(const SPOINT& poPoint,const SPOINT* lpPoints,
				   const int *lpPolyCounts,int nCount)
{
	if (lpPolyCounts == NULL || lpPoints == NULL || nCount == 0)
	{
		return 0;
	}
	int nSumCount = 0;		//�ܽ������
	int nPtCount = 0;		//ÿ������ν���ĸ���

	/*PointInPolygon(poPoint,lpPoints,lpPolyCounts[0],nPtCount);
	lpPoints += lpPolyCounts[0];
	nSumCount += nPtCount;*/

	for (int i = 0; i < nCount; i ++)
	{
		PointInPolygon(poPoint,lpPoints,lpPolyCounts[i],nPtCount);
		lpPoints += lpPolyCounts[i];
		nSumCount += nPtCount;
	}

	if (nSumCount % 2 == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}

	return 0;
}

void PolyCentroid(const SPOINT* points,int nCount,double *xCentroid,double *yCentroid)
{
	assert(points != NULL);
	if (nCount < 3)
	{
		return;
	}

	int i = 0;
	int j = 0;
	double ai = 0;
	double aTmp = 0;
	double xTmp = 0;
	double yTmp = 0;

	for (i = nCount-1,j = 0; j < nCount; i = j,j ++)
	{
		ai = points[i].x * points[j].y - points[j].x * points[i].y;
		aTmp += ai;
		xTmp += (points[i].x + points[j].x) * ai;
		yTmp += (points[i].y + points[j].y) * ai;
	}

	if (aTmp != 0)
	{
		*xCentroid = xTmp / (3 * aTmp);
		*yCentroid = yTmp / (3 * aTmp);
	}
}

int IsPolygonSelfIntersect(const SPOINT* points,int nCount)
{
	//

	return 0;
}
