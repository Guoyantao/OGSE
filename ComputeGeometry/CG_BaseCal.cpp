#include "CG_BaseCal.h"

void GetEnvelope(const SPOINT* points,int nCount,CG_Envelope& env)
{
	assert(points != NULL);
	double minx,maxx,miny,maxy;
	if (nCount == 0)
	{
		return;
	}
	minx = maxx = points[0].x;
	miny = maxy = points[0].y;
	for (int iPoint = 1; iPoint < nCount; iPoint ++)
	{
		if (maxx < points[iPoint].x)
		{
			maxx = points[iPoint].x;
		}
		if (minx > points[iPoint].x)
		{
			minx = points[iPoint].x;
		}
		if (maxy < points[iPoint].y)
		{
			maxy = points[iPoint].y;
		}
		if (miny > points[iPoint].y)
		{
			miny = points[iPoint].y;
		}
	}

	env.minX = minx;
	env.maxX = maxx;
	env.minY = miny;
	env.maxY = maxy;
}

double Distance(const SPOINT &p1,const SPOINT &p2)                // ��������֮��ŷ�Ͼ��� 
{ 
	return( sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) ) ); 
} 

double DirectionAngle(const SPOINT &p1,const SPOINT &p2)
{
	double dx = p2.x - p1.x;
	double dy = p2.y - p1.y;

	double dbAngle = 0;

	if (dx == 0 && dy > 0)
	{
		dbAngle = M_PI_2;
	}

	else if (dx == 0 && dy < 0)
	{
		dbAngle = M_PI_2 + M_PI;
	}

	else if (dx > 0 && dy >= 0)
	{
		dbAngle = atan2(dy,dx);
	}

	else if (dx > 0 && dy < 0)
	{
		dbAngle = atan2(dy,dx) + M_PI * 2;
	}

	else if (dx < 0)
	{
		dbAngle = atan2(dy,dx) + M_PI;
	}


	return dbAngle;
}

/************************************************************************/
/* �ж��������Ƿ���ͬ                                                   */
/************************************************************************/
bool Equal_point(SPOINT p1,SPOINT p2)           // �ж��������Ƿ��غ�  
{ 
	return ( (fabs(p1.x-p2.x)<EPS) && (fabs(p1.y-p2.y)<EPS) ); 
} 

/****************************************************************************** 
r=multiply(sp,ep,op),�õ�(sp-op)��(ep-op)�Ĳ�� 
r>0��ep��ʸ��opsp����ʱ�뷽�� 
r=0��opspep���㹲�ߣ� 
r<0��ep��ʸ��opsp��˳ʱ�뷽�� 
*******************************************************************************/ 
double Multiply(SPOINT sp,SPOINT ep,SPOINT op) 
{ 
	CG_Vector2 vecs(op,sp);
	CG_Vector2 vece(op,ep);

	double dbCross = CG_Vector2::crossProduct(vecs,vece);
	//return((sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y)); 
	return dbCross;
} 

bool IsPointOnLine(const SPOINT &point,const SEGMENT& lineSeg)
{
	if (point.x <= min(lineSeg.start.x,lineSeg.end.x) 
		|| point.x >= max(lineSeg.start.x,lineSeg.end.x)
		|| point.y <= min(lineSeg.start.y,lineSeg.end.y)
		|| point.y >= max(lineSeg.start.y,lineSeg.end.y))
	{
		return false;
	}

	return (fabs(Multiply(lineSeg.start,lineSeg.end,point)) <=EPS);

}

bool IsPointOnLineEx(const SPOINT &point,const SPOINT& p1,const SPOINT& p2)
{
	if (point.x < min(p1.x,p2.x) 
		|| point.x > max(p1.x,p2.x)
		|| point.y < min(p1.y,p2.y)
		|| point.y > max(p1.y,p2.y))
	{
		return false;
	}

	return (fabs(Multiply(p1,p2,point)) <=EPS);
}

void SplitLine(const SPOINT& p1,const SPOINT& p2,double dbDist, SPOINT& ptResult)
{
	if (dbDist <= 0)
	{
		return ;
	}

	//�����ڲ�������
	double dbLen = sqrt(pow(p2.x-p1.x,2) + pow(p2.y-p1.y,2));
	ptResult.x = p1.x + (p2.x-p1.x)*dbDist/dbLen;
	ptResult.y = p1.y + (p2.y-p1.y)*dbDist/dbLen;
}

bool IsLineIntersect(const SEGMENT& lineSeg1,const SEGMENT& lineSeg2)
{
	//�����ж������߶ε�MBR�Ƿ��ཻ
	bool bIsIntersect = CG_Envelope::Intersects(lineSeg1.start,lineSeg1.end,
		lineSeg2.start,lineSeg2.end);
	if (!bIsIntersect)
	{
		return false;
	}

	//����ʵ��
	CG_Vector2 q1p1(lineSeg2.start,lineSeg1.start);
	CG_Vector2 q1p2(lineSeg2.start,lineSeg1.end);
	CG_Vector2 q1q2(lineSeg2.start,lineSeg2.end);
	CG_Vector2 p1q1(lineSeg1.start,lineSeg2.start);
	CG_Vector2 p1q2(lineSeg1.start,lineSeg2.end);
	CG_Vector2 p1p2(lineSeg1.start,lineSeg1.end);

	double dbFlag1 = CG_Vector2::crossProduct(q1p1,q1q2)*CG_Vector2::crossProduct(q1q2,q1p2);
	double dbFalg2 = CG_Vector2::crossProduct(p1q1,p1p2)*CG_Vector2::crossProduct(p1p2,p1q2);

	if (dbFlag1 >= 0 && dbFalg2 >= 0)
	{
		return true;
	}
	return false;
}

void GetCrossPoint(const SPOINT& p1,const SPOINT& p2,const SPOINT& q1,const SPOINT& q2,SPOINT &stResult)
{
	//�����ཻ����Ĳ����߶εĽ��㣬��������ĳ������ͨ�õ�  

	//assert(IsSegIntersect(p1,p2,q1,q2));  

	/*��������ʽ��Ϊ��׼ʽ�����������Է�����*/ 


	double tempLeft = 0;
	double tempRight = 0;

	//��x����  
	tempLeft = (q2.x - q1.x) * (p1.y - p2.y) - (p2.x - p1.x) * (q1.y - q2.y);  

	tempRight = (p1.y - q1.y) * (p2.x - p1.x) * (q2.x - q1.x) + 
		q1.x * (q2.y - q1.y) * (p2.x - p1.x) - p1.x * (p2.y - p1.y) * (q2.x - q1.x);  

	stResult.x = (double)tempRight / (double)tempLeft;  

	//��y����   
	tempLeft = (p1.x - p2.x)*(q2.y - q1.y) - (p2.y - p1.y) * (q1.x - q2.x);  

	tempRight = p2.y * (p1.x - p2.x) * (q2.y - q1.y) + 
		(q2.x- p2.x) * (q2.y - q1.y) * (p1.y - p2.y) - 
		q2.y * (q1.x - q2.x) * (p2.y - p1.y);  

	stResult.y =(double)tempRight / (double)tempLeft;  

	//turn crossPoint; 
}

double Heron(double a,double b,double c)
{
	//�߳���С�ڵ���0��
	if(a <= 0 || b <= 0 || c <= 0)
	{
		return 0;
	}

	//����֮��С�ڵ�����
	if(a + b <= c || a + c <= b || b+c <= a)
	{
		return 0;
	}

	//����֮����ڵ�����
	if(fabs(a - b) > c || fabs(a-c) > b || fabs(b- c) > a)
	{
		return 0;
	}

	double s = 0.0;
	double p = (a+b+c)/2.0;
	s = sqrt(p*(p-a)*(p-b)*(p-c));
	return s;
}

double PointToLine(const SPOINT &pt, const SPOINT &startPt, const SPOINT &endPt)
{
	double h = 0.0;
	//�����߳�
	double a = sqrt(pow(pt.x-startPt.x,2)+pow(pt.y-startPt.y,2));
	double b = sqrt(pow(pt.x-endPt.x,2)+pow(pt.y-endPt.y,2));
	double c = sqrt(pow(startPt.x-endPt.x,2)+pow(startPt.y-endPt.y,2));

	//���൱��ƽ���ı��εĸ�

	return 2*Heron(a,b,c)/c;
}

