#include "CG_Polyline.h"
#include <float.h>

void IsChianIntersect(const TChain& chain1,const TChain& chain2,Tline_Intersect &inter_info)
{
	//���������������������β��ཻ��ֱ�ӷ���
	if (!CG_Envelope::Intersects(chain1.box,chain2.box))
	{
		inter_info.nLineNum = 0;
		inter_info.poLines = NULL;
		return;
	}

	bool bAxisX = false;		//ɨ�����Ƿ�ֱX��
	TSweep *pSweep = new TSweep[(chain1.nCount+chain2.nCount)*2];
	double dbWidth = max(chain1.box.GetWidth(),chain2.box.GetWidth());
	double dbHeight = max(chain1.box.GetHeight(),chain2.box.GetHeight());
	if (dbWidth >= dbHeight)
	{
		bAxisX = true;
	}

	//��ǰɨ��ĵ�����
	int nCurSweep = 1;		//1��ʾ�ڵ�һ�����ϣ�2��ʾ�ڵڶ�������
	if (chain1.box.minX > chain2.box.minX)
	{
		nCurSweep = 2;
	}

	pSweep[0].nIndex = 0;
	pSweep[0].bIsFirstLine = 1;
	int j = 0;
	for (int i = 1,j = 1; i < chain1.nCount-1; i ++,j+=2)
	{
		pSweep[j].bIsFirstLine = true;
		pSweep[j].nIndex = -(i-1);
		pSweep[j+1].bIsFirstLine = true;
		pSweep[j+1].nIndex = i;
	}
	pSweep[j+1].nIndex = 0;
	pSweep[j+1].bIsFirstLine = 1;
}

double Point2Segment(const SPOINT &point,SPOINT& pt0,SPOINT& pt1)
{
	SPOINT vecD;
	vecD.x = pt1.x-pt0.x;
	vecD.y = pt1.y-pt0.y;		//�߶ε�����
	SPOINT vecP;
	vecP.x = point.x-pt0.x;
	vecP.y = point.y-pt0.y;//�㵽�߶���ʼ�������
	double valueD = sqrt(vecD.x*vecD.x+vecD.y*vecD.y);
	double valueP = sqrt(vecP.x*vecP.x+vecP.y*vecP.y);
	double dotMultiplay = vecD.x*vecP.x+vecD.y*vecP.y;

	double t = dotMultiplay/valueD;	 //����������ͶӰ

	//����߶ο�ʼ��ӽ���point
	if (t <= 0)
	{
		return valueP;
	}

	//����߶ν�����ӽ���point
	if (t >= valueD)
	{
		SPOINT vecP;
		vecP.x = point.x-pt1.x;
		vecP.y = point.y-pt1.y;
		return sqrt(vecP.x*vecP.x+vecP.y*vecP.y);
	}

	//���ش������
	return valueP - t*t/valueD;
}

double PointDisPolyline(const SPOINT& point,const SPOINT* poString,int nCount)
{
	if (NULL == poString)
	{
		return 0;
	}
	if (1 >= nCount)
	{
		return 0;
	}
	double dbDistance = DBL_MAX;
	for (int i = 0; i < nCount-1; i ++)
	{
		SPOINT pt0 = poString[i];
		SPOINT pt1 = poString[i+1];

		//�˴����������Ϊ������һ������
		CG_Envelope envSearch;
		envSearch.minX = point.x-dbDistance;
		envSearch.maxX = point.x+dbDistance;
		envSearch.minY = point.y-dbDistance;
		envSearch.maxY = point.y+dbDistance;
		CG_Envelope envSegment;	//�߶����ڵľ���
		envSegment.minX = min(pt0.x,pt1.x);
		envSegment.maxX = max(pt0.x,pt1.x);
		envSegment.minY = min(pt0.y,pt1.y);
		envSegment.maxY = max(pt0.y,pt1.y);

		//�����ڻ��������������ཻ���߶βſ��������
		if (envSearch.Contains(envSegment) || 
			envSearch.InterSects(envSegment))
		{
			double dist = Point2Segment(point,pt0,pt1);
			if (dbDistance >= dist)
			{
				dbDistance = dist;
			}
		}
	}

	return dbDistance;
}

