
#include "CG_Matrix.h"

/*************************************************
����:         ����ת��
����:         ����m1��ת�õľ��󣬲���m,n�ֱ�Ϊ�����������
�����        ����m2ת�ú�ľ���
*************************************************/
void MatrixTranspose(const double *m1,double *m2,int m,int n) //����ת��
{ 
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			m2[j*m+i]=m1[i*n+j];
	return;
}

/*************************************************
����:         ����ת��(ԭ��ת��),�����Ƿ���
����:         ����m1��ת�õľ���
�����        ����m1ת�ú�ľ���
*************************************************/
void MatrixTransposeEx(double *m1, int n)
{
	for (int i = 0; i < n; i ++)
	{
		for (int j = i; j < n; j ++)
		{
			double temp = m1[i*n+j];
			m1[i*n+j] = m1[j*n+i];
			m1[j*n+i] = temp;
		}
	}
}

/*************************************************
����:         ������������
����:         a������ľ���ָ�룬����һά����������ά���飬nΪ����������
�����        void
*************************************************/
void MatrixInverse(double *a,int n)
{ 
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			if(i!=k)
				*(a+i*n+k)=-*(a+i*n+k)/(*(a+k*n+k));
		}
		*(a+k*n+k)=1/(*(a+k*n+k));
		for(i=0;i<n;i++)
		{
			if(i!=k)
			{
				for(j=0;j<n;j++)
				{
					if(j!=k)
						*(a+i*n+j)+=*(a+k*n+j)* *(a+i*n+k);
				}
			}
		}
		for(j=0;j<n;j++)
		{
			if(j!=k)
				*(a+k*n+j)*=*(a+k*n+k);
		}
	}
}

/*************************************************
����:         �������
����:         m1,m2Ϊ�������resultΪ��˺�Ľ������i_1,j_12��j_2�ֱ�
              ǰ�������m1�������������������άm2��������
�����        void
*************************************************/
void MatrixMult(const double *m1,const double *m2,double *result, int i_1, int j_12, int j_2)
{ 
	int i,j,k; 
	for(i=0;i<i_1;i++)
	{
		for(j=0;j<j_2;j++)
		{
			result[i*j_2+j]=0.0;
			for(k=0;k<j_12;k++)
			{
				result[i*j_2+j]+=m1[i*j_12+k]*m2[j+k*j_2];
			}
		}
	}

	return;
}

double MatrixTrace(const double *m1,int m)
{
	double dbTrace = 0;
	for (int i = 0; i < m; i ++)
	{
		dbTrace += m1[i*m+i];
	}

	return dbTrace;
}