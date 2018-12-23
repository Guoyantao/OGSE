#include "ClipLine.h"
#include <math.h>

void EndCode(float x,float y,
			 float Window[4],
			 std::bitset<4>& bitCode)
{
	//bitset�����ұ��ǵ�һλ
	//���
	if (x < Window[0])
	{
		bitCode[3] = 1;
	}
	else
	{
		bitCode[3] = 0;
	}

	//�ұ�
	if (x > Window[1])
	{
		bitCode[2] = 1;
	}
	else
	{
		bitCode[2] = 0;
	}

	//�±�
	if (y < Window[2])
	{
		bitCode[1] = 1;
	}
	else
	{
		bitCode[1] = 0;
	}

	//�ϱ�
	if (y > Window[3])
	{
		bitCode[0] = 1;
	}
	else
	{
		bitCode[0] = 0;
	}
}

int Logical(const std::bitset<4> &pCode1,const std::bitset<4> &pCode2)
{
	int nInter = 0;
	for (int i = 0; i < 4; i ++)
	{
		nInter += (int)((pCode1[i]+pCode2[i])/2);
	}

	return nInter;
}

int CodeSum(const std::bitset<4> &pCode)
{
	int nSum = 0;
	for (int i = 0; i < 4; i ++)
	{
		nSum += pCode[i];
	}

	return nSum;
}

VisibleFlag IsVisible(const std::bitset<4> &pCode1,
					  const std::bitset<4> &pCode2,
					  int nSum1,
					  int nSum2)
{
	//��ʼ��Ϊ���ֿɼ�
	VisibleFlag Vflag = PartVisible;
	if (nSum1 == 0 && nSum2 == 0)
	{
		Vflag = Visible;
	}

	else
	{
		int nInter = Logical(pCode1,pCode2);
		if (nInter != 0)
		{
			Vflag = NoVisible;
		}
	}

	//�߶ο��ܲ��ֿɼ�
	return Vflag;
}

VisibleFlag CoSutherLineClip(float &x1,float &y1,float &x2,float &y2,
					  float Window[4])
{
	std::bitset<4> pCode1,pCode2;
	EndCode(x1,y1,Window,pCode1);
	EndCode(x2,y2,Window,pCode2);
	int nSum1 = CodeSum(pCode1);
	int nSum2 = CodeSum(pCode2);
	VisibleFlag vFlag = IsVisible(pCode1,pCode2,nSum1,nSum2);
	if (vFlag == Visible)
	{
		return Visible;
	}

	if (vFlag == NoVisible)
	{
		return NoVisible;
	}

	//����б��
	int nFlag = 1;
	float fSlope = 0;
	if (fabs(x1 - x2) < 0.0001)
	{
		nFlag = -1;		//��ֱ��
	}

	else if (fabs( y1 - y2) < 0.0001)
	{
		nFlag = 0;		//ˮƽ��
	}

	else
	{
		fSlope = (y2 - y1) / (x2 - x1);
	}

	float fInvSlope = 1.0/fSlope;

	//�����߲ü�
	while (vFlag == PartVisible)
	{
		for (int i = 0; i < 4; i ++)
		{
			if (pCode1[3-i] != pCode2[3-i])
			{
				//���P1�ڴ����ڣ�����p1p2
				if(pCode1[3-i] == 0)
				{
					float tmp = x1;
					x1 = x2;
					x2 = tmp;
					tmp = y1;
					y1 = y2;
					y2 = tmp;
					std::swap(pCode1,pCode2);

					int nTmp = nSum1;
					nSum1 = nSum2;
					nSum2 = nTmp;
				}

				//���㽻��
				if (nFlag != -1 && i <= 1)
				{
					y1 = fSlope*(Window[i] - x1) + y1;
					x1 = Window[i];
					EndCode(x1,y1,Window,pCode1);
					nSum1 = CodeSum(pCode1);
				}

				if (nFlag != 0 && i > 2)
				{
					if (nFlag != -1)
					{
						x1 = fInvSlope*(Window[i]-y1) + x1;
					}
					y1 = Window[i];
					EndCode(x1,y1,Window,pCode1);
					nSum1 = CodeSum(pCode1);
				}

				//���¼���ɼ���
				vFlag = IsVisible(pCode1,pCode2,nSum1,nSum2);
				if (vFlag == Visible || vFlag == NoVisible)
				{
					break;
				}
			}
		}
	}

	return PartVisible;
}

struct LinePoint
{
	float x;
	float y;
};

VisibleFlag MidPointLineClip(float &x1,float &y1,float &x2,float &y2, float Window[4])
{
	std::bitset<4> pCode1,pCode2;
	EndCode(x1,y1,Window,pCode1);
	EndCode(x2,y2,Window,pCode2);
	int nSum1 = CodeSum(pCode1);
	int nSum2 = CodeSum(pCode2);
	VisibleFlag vFlag = IsVisible(pCode1,pCode2,nSum1,nSum2);
	if (vFlag == Visible)
	{
		return vFlag;
	}

	if (vFlag == NoVisible)
	{
		return vFlag;
	}

	float saveX1 = 0;
	float saveY1 = 0;
	float saveX2 = 0;
	float saveY2 = 0;

	float mx = 0;
	float my = 0;
	float tempX = 0;
	float tempY = 0;

	std::bitset<4> pSaveCode1;

	//�ֱ��p1p2ѭ��
	int nError = 1;
	for (int i = 1; i <= 2; i ++)
	{
		//���P1����P2�ڴ����ڣ�ֻ��Ҫѭ��һ�μ���
		if (i == 1 && nSum1 == 0)
		{
			saveX2 = x1;
			saveY2 = y1;

			float tmp = x1;
			x1 = x2;
			x2 = tmp;
			tmp = y1;
			y1 = y2;
			y2 = tmp;
			
			continue;
		}

		if (i == 1 && nSum2 == 0)
		{
			float tmp = x1;
			x1 = x2;
			x2 = tmp;
			tmp = y1;
			y1 = y2;
			y2 = tmp;

			saveX2 = x1;
			saveY2 = y1;

			continue;
		}

		saveX1 = x1;
		saveY1 = y1;
		int nTmpSum1 = nSum1;
		pSaveCode1 = pCode1;

		//�ж��Ƿ������ֵ
		while (fabs(x2 - x1) > nError || fabs(y2 - y1) > nError)
		{
			mx = (x1 + x2)*0.5;
			my = (y1 + y2)*0.5;
			tempX = x1;
			tempY = y1;
			x1 = mx;
			y1 = my;

			EndCode(x1,y1,Window,pCode1);
			nSum1 = CodeSum(pCode1);
			vFlag = IsVisible(pCode1,pCode2,nSum1,nSum2);
			if (vFlag == NoVisible) //����p2pm
			{
				x1 = tempX;		//�ص�p1
				y1 = tempY;
				x2 = mx;		//p2���߶���Զ��
				y2 = my;
				pCode2 = pCode1;
				nSum2 = nSum1;
				EndCode(x1,y1,Window,pCode1);
				nSum1 = CodeSum(pCode1);
			}
		}

		if (i == 1)
		{
			saveX2 = mx;
			saveY2 = my;
			x1 = mx;
			y1 = my;
			x2 = saveX1;
			y2 = saveY1;
			nSum2 = nTmpSum1;
			pCode2 = pSaveCode1;
		}
		else
		{
			x1 = mx;
			y1 = my;
			x2 = saveX2;
			y2 = saveY2;
		}

		EndCode(x1,y1,Window,pCode1);
		EndCode(x2,y2,Window,pCode2);
		nSum1 = CodeSum(pCode1);
		nSum2 = CodeSum(pCode2);
		vFlag = IsVisible(pCode1,pCode2,nSum1,nSum2);
	}

	/*int nInter = Logical(pCode1,pCode2);
	if (nInter == 0)
	{
	}*/
	return vFlag;
}
