#include "CG_Common.h"
#include "CG_Buffer.h"
#include "CG_Angle.h"
#include "CG_Vector2.h"

void LineBuffer(SPOINT* poPoints,int nPointCount,double dbBuffer,std::vector<SPOINT>& vecResult)
{
	std::vector<SPOINT> vecLeftBuf;			//��໺����
	std::vector<SPOINT> vecRightBuf;		//�Ҳ໺����

	double dbAng1 = 0;
	double dbAng2 = 0;

	//��ʼ����Բ���ֺ�
	CG_Point ptBegin;
	CG_Point ptEnd;
	dbAng1 = CG_Angle::angle(poPoints[0],poPoints[1]);
	dbAng2 = dbAng1;
	ptBegin.x = poPoints[0].x+dbBuffer*cos(dbAng1+M_PI_2+M_PI);
	ptBegin.y = poPoints[0].y+dbBuffer*sin(dbAng1+M_PI_2+M_PI);
	ptEnd.x = poPoints[0].x+dbBuffer*cos(dbAng2+M_PI_2);
	ptEnd.y = poPoints[0].y+dbBuffer*sin(dbAng2+M_PI_2);

	//˳ʱ�뷽��Բ�����
	double dbThea = acos(1.0-1.0/30.0);
	std::vector<CG_Point> vecArcPoints;
	ArcCycle(poPoints[0].x,poPoints[0].y,dbBuffer,dbThea,true,
		dbAng1-M_PI_2,dbAng2-M_PI_2-M_PI,vecArcPoints);

	//ȡ����һ������Ϊ�������߽�ıպϵ�
	SPOINT ptClose = vecArcPoints.front();

	size_t nIndex = 0;
	for (;nIndex < vecArcPoints.size(); nIndex ++)
	{
		vecLeftBuf.push_back(vecArcPoints[nIndex]);
	}

	//�ӵڶ��㿪ʼÿ������Ϊһ������Ԫ
	int i = 1;
	for (;i < nPointCount-1;i ++)
	{
		//������X��������ķ����
		dbAng1 = CG_Angle::angle(poPoints[i],poPoints[i-1]);
		dbAng2 = CG_Angle::angle(poPoints[i],poPoints[i+1]);
		double xp = 0;
		double yp = 0;
		xp = dbBuffer*(cos(dbAng1)+cos(dbAng2))/sin(dbAng1-dbAng2);
		yp = dbBuffer*(sin(dbAng1)+sin(dbAng2))/sin(dbAng1-dbAng2);

		dbAng1 = CG_Angle::angle(poPoints[i-1],poPoints[i]);
		dbAng2 = CG_Angle::angle(poPoints[i],poPoints[i+1]);

		//����ʸ��������ж�ǰ������ʱ��Ϊ˳ʱ�����ʱ��
		CG_Vector2 vec1(poPoints[i-1],poPoints[i]);
		CG_Vector2 vec2(poPoints[i],poPoints[i+1]);
		double dbS = CG_Vector2::crossProduct(vec1,vec2);
		if (dbS >= 0)		//�������ʱ�룬���Ҳ���͹�㣬����һ����Բ����ϣ�����
		{
			SPOINT pt1(poPoints[i].x+xp,poPoints[i].y+yp);
			vecLeftBuf.push_back(pt1);

			//�����߶�ƽ�����ϵĵ�
			ptBegin.x = poPoints[i].x - dbBuffer*sin(dbAng1+dbAng2);
			ptBegin.y = poPoints[i].y + dbBuffer*cos(dbAng1+dbAng2);
			ptEnd.x = poPoints[i].x + dbBuffer*sin(dbAng2);
			ptEnd.y = poPoints[i].y - dbBuffer*cos(dbAng2);

			//��ʱ�뷽��Բ�����
			double dbThea = acos(1.0-1.0/30.0);
			std::vector<CG_Point> vecArcPoints;
			ArcCycle(poPoints[i].x,poPoints[i].y,dbBuffer,dbThea,false,
				dbAng1-M_PI_2,dbAng2-M_PI_2,vecArcPoints);

			size_t nIndex = 0;
			//vecRightBuf.push_back(ptBegin);
			for (;nIndex < vecArcPoints.size(); nIndex ++)
			{
				vecRightBuf.push_back(vecArcPoints[nIndex]);
			}
			//vecRightBuf.push_back(ptEnd);
		}
		else if (dbS < 0)	//�����˳ʱ�룬�������͹�㣬����һ����Բ����ϣ�͹��
		{
			SPOINT pt2(poPoints[i].x-xp,poPoints[i].y-yp);
			vecRightBuf.push_back(pt2);

			//�����߶�ƽ�����ϵĵ�
			ptBegin.x = poPoints[i].x + dbBuffer*sin(dbAng1+dbAng2);
			ptBegin.y = poPoints[i].y - dbBuffer*cos(dbAng1+dbAng2);
			ptEnd.x = poPoints[i].x - dbBuffer*sin(dbAng2);
			ptEnd.y = poPoints[i].y + dbBuffer*cos(dbAng2);

			//˳ʱ�뷽��Բ�����
			double dbThea = acos(1.0-1.0/30.0);
			std::vector<CG_Point> vecArcPoints;
			ArcCycle(poPoints[i].x,poPoints[i].y,dbBuffer,dbThea,true,
				dbAng1+M_PI_2,dbAng2+M_PI_2,vecArcPoints);

			size_t nIndex = 0;
			//vecLeftBuf.push_back(ptBegin);
			for (;nIndex < vecArcPoints.size(); nIndex ++)
			{
				vecLeftBuf.push_back(vecArcPoints[nIndex]);
			}
			//vecLeftBuf.push_back(ptEnd);
		}

	}

	//���һ������Բ���ֺ�
	dbAng1 = CG_Angle::angle(poPoints[nPointCount-2],poPoints[nPointCount-1]);
	dbAng2 = dbAng1;
	ptBegin.x = poPoints[nPointCount-1].x+dbBuffer*cos(dbAng1+M_PI_2);
	ptBegin.y = poPoints[nPointCount-1].y+dbBuffer*sin(dbAng1+M_PI_2);
	ptEnd.x = poPoints[nPointCount-1].x+dbBuffer*cos(dbAng2-M_PI_2);
	ptEnd.y = poPoints[nPointCount-1].y+dbBuffer*sin(dbAng2-M_PI_2);

	//��ʱ�뷽��Բ�����
	dbThea = acos(1.0-1.0/30.0);
	vecArcPoints.clear();
	ArcCycle(poPoints[nPointCount-1].x,poPoints[nPointCount-1].y,dbBuffer,dbThea,true,
		dbAng1+M_PI_2,dbAng2-M_PI_2,vecArcPoints);

	nIndex = 0;
	for (;nIndex < vecArcPoints.size(); nIndex ++)
	{
		vecLeftBuf.push_back(vecArcPoints[nIndex]);
	}

	vecResult.resize(vecLeftBuf.size()/*+vecRightBuf.size()*/);
	std::copy(vecLeftBuf.begin(),vecLeftBuf.end(),vecResult.begin());
	for (int i = vecRightBuf.size()-1; i >= 0; i --)
	{
		vecResult.push_back(vecRightBuf[i]);
	}

	vecResult.push_back(ptClose);
}

void ArcCycle(double x0, double y0, double dbRadius, double dbThea,bool bClockWise,
			  double ang1, double ang2, std::vector<CG_Point>& vecResult)
{
	//����ƽ�Բ�Ķ���εı����ͽǶ�����ֵ
	int N = (int)fabs(ang2-ang1)/dbThea;
	if (bClockWise)		//˳ʱ��Ƕȵݼ�
	{
		dbThea = -dbThea;
	}

	//��ʼѭ������ÿ�����������
	CG_Point ptPoint;
	int i = 0;
	while (i <= N+1)
	{
		double w = ang1 + i * dbThea;
		ptPoint.x = x0 + dbRadius*cos(w);
		ptPoint.y = y0 + dbRadius*sin(w);

		vecResult.push_back(ptPoint);
		i ++;
	}
}

