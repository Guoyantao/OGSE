#include "CG_ConvexHull.h"


/********************************************** 
Ѱ��͹����grahamɨ�跨 
**********************************************/ 
void Graham_scan(SPOINT *PointSet,SPOINT *ch,int n,int &len) 
{ 
	int i = 0;
	int j = 0;
	int k = 0;
	int top = 2; 
	SPOINT tmp; 

	// ѡȡPointSet��y������С�ĵ�PointSet[k]����������ĵ��ж������ȡ����ߵ�һ�� 
	for(i=1; i<n; i++) 
	{
		if ( PointSet[i].y < PointSet[k].y 
			|| (PointSet[i].y == PointSet[k].y) 
			&& (PointSet[i].x < PointSet[k].x) ) 
		{
			k = i;
		}
	}

	tmp = PointSet[0]; 
	PointSet[0] = PointSet[k]; 
	PointSet[k] = tmp; // ����PointSet��y������С�ĵ���PointSet[0] 

	for (i=1;i<n-1;i++) /* �Զ��㰴�����PointSet[0]�ļ��Ǵ�С����������򣬼�����ͬ�İ��վ���PointSet[0]�ӽ���Զ�������� */ 
	{ 
		k = i; 
		for (j=i+1;j<n;j++) 
		{
			if ( Multiply(PointSet[j],PointSet[k],PointSet[0])>0 ||  // ���Ǹ�С    
				(Multiply(PointSet[j],PointSet[k],PointSet[0])==0) && /* ������ȣ�������� */        
				 Distance(PointSet[0],PointSet[j]) < Distance(PointSet[0],PointSet[k])
				) 
			{
				k = j; 
			}
		}
		tmp = PointSet[i]; 
		PointSet[i] = PointSet[k]; 
		PointSet[k] = tmp; 
	} 

	ch[0] = PointSet[0]; 
	ch[1] = PointSet[1]; 
	ch[2] = PointSet[2]; 
	for (i=3; i<n; i++) 
	{ 
		while (Multiply(PointSet[i],ch[top],ch[top-1])>=0) 
		{
			top--; 
		}

		ch[++top] = PointSet[i]; 
	} 
	len = top + 1; 
} 