#include "SysImagePreProcess.h"

#include <GL/glew.h>

#include <float.h>


void CreateOptimizedStretch( float* pHist,float &dbMin,float &dbMax,int nPixelCount )
{
	if (nPixelCount <= 0 || NULL == pHist)
	{
		return;
	}

	double fHistCumulative[256]; 
	memset(fHistCumulative,0,sizeof(double)*256);

	//1 ����Ƶ��ֱ��ͼ
	for (int i = 0; i < 256; i ++)
	{
		fHistCumulative[i] = pHist[i] / float(nPixelCount/**0.62*/);
	}

	// 2 �����ۻ�Ƶ��ֱ��ͼ
	for (int i = 1; i < 256 ; i ++)
	{
		fHistCumulative[i] += fHistCumulative[i-1];
	}

	double fMinPercent =  0.025f;
	double fMaxPercent =  0.99f;
	double fMinAdjustPercent =  0.1f; 
	double fMaxAdjustPercent = 0.5f; 

	//Ѱ���ۻ�Ƶ����fMinPercent��fMaxPercent������ֵ,��Ѱ�Һ���һ����ӽ�
	double fMinInterval = DBL_MAX;
	double fMaxInterval = DBL_MAX;
	int nIndex1 = 0;
	int nIndex2 = 0;
	for (int i = 0; i < 256; i ++)
	{
		double fInterval = fabs(fMinPercent - fHistCumulative[i]);
		if (fInterval < fMinInterval)
		{
			fMinInterval = fInterval;
			nIndex1 = i;
		}

		fInterval = fabs(fMaxPercent - fHistCumulative[i]);
		if (fInterval < fMaxInterval)
		{
			fMaxInterval = fInterval;
			nIndex2 = i;
		}
	}

	double fValueInterval = (dbMax - dbMin)/256;

	//��þ�ȷ�ķָ��
	double fScale1 = nIndex1 - fMinInterval;
	double fScale2 = nIndex2 + fMaxInterval;

	double fTmp1 = dbMin;
	double fTmp2 = dbMax;
	dbMin = fTmp1 + fScale1*fValueInterval;
	dbMax = fTmp1 + fScale2*fValueInterval;
	fTmp1 = dbMin - fMinAdjustPercent*(dbMax - dbMin);
	fTmp2 = dbMax + fMaxAdjustPercent*(dbMax - dbMin);
	dbMin = fTmp1;
	dbMax = fTmp2;
}

void CreateLinearStretch( float* pHist,float &dbMin,float &dbMax,int nPixelCount,int nPercent )
{
	if (nPixelCount <= 0 || NULL == pHist)
	{
		return;
	}

	double fHistCumulative[256]; 
	memset(fHistCumulative,0,sizeof(double)*256);

	//1 ����Ƶ��ֱ��ͼ
	for (int i = 0; i < 256; i ++)
	{
		fHistCumulative[i] = pHist[i] / float(nPixelCount/**0.62*/);
	}

	// 2 �����ۻ�Ƶ��ֱ��ͼ
	for (int i = 1; i < 256 ; i ++)
	{
		fHistCumulative[i] += fHistCumulative[i-1];
	}

	double fMinPercent =  nPercent/100.f;
	double fMaxPercent =  (100 - nPercent)/100.f;

	//Ѱ���ۻ�Ƶ����fMinPercent��fMaxPercent������ֵ,��Ѱ�Һ���һ����ӽ�
	double fMinInterval = DBL_MAX;
	double fMaxInterval = DBL_MAX;
	int nIndex1 = 0;
	int nIndex2 = 0;
	for (int i = 0; i < 256; i ++)
	{
		double fInterval = fabs(fMinPercent - fHistCumulative[i]);
		if (fInterval < fMinInterval)
		{
			fMinInterval = fInterval;
			nIndex1 = i;
		}

		fInterval = fabs(fMaxPercent - fHistCumulative[i]);
		if (fInterval < fMaxInterval)
		{
			fMaxInterval = fInterval;
			nIndex2 = i;
		}
	}

	double fValueInterval = (dbMax - dbMin)/256;

	//��þ�ȷ�ķָ��
	double fScale1 = nIndex1 - fMinInterval;
	double fScale2 = nIndex2 + fMaxInterval;

	double fTmp1 = dbMin;
	dbMin = fTmp1 + fScale1*fValueInterval;
	dbMax = fTmp1 + fScale2*fValueInterval;
}

void BrightnessContrast(unsigned char* poData,size_t nLen, size_t nExcludeIndex)
{
	if (0 == nExcludeIndex)
	{
		#pragma omp parallel for
		for (int i = 0;i < nLen; i ++)
		{
			poData[i] = 255 - poData[i];
		}
	}

	else
	{
		#pragma omp parallel for
		for (int i = 0;i < nLen; i ++)
		{
			if (0 != (i + 1) % nExcludeIndex)
			{
				poData[i] = 255 - poData[i];
			}
		}
	}
}

unsigned char BrightnessStretch(unsigned char uDst,float fBrightNess)
{
	int nData = uDst;

	if (0 == fBrightNess)
	{
		return uDst;
	}

	if (fBrightNess > 0)
	{
		if (fabs(fBrightNess - 1.0) < 0.0001)
		{
			return 255;
		}

		nData = uDst + uDst * (1 / (1 - fBrightNess) - 1);
	}

	if (fBrightNess < 0)
	{
		nData = uDst + uDst * fBrightNess;
	}

	if (nData < 0)
	{
		nData = 0;
	}
	if (nData > 255)
	{
		nData = 255;
	}

	return nData;
}

unsigned char ContrastStretch(unsigned char uSrc,int nPara)
{
	/*��1���������ֵΪ0ʱ��ͼ�񱣳�ԭ���ĶԱȶȣ�

	��2���������ֵС��0ʱ�����ٶԱȶȡ����ٶԱȶȱ仯�ķ���Ϊ��

		g=f*(255-2*n/255)-n  n<0

		�����ļ����Ƕ�ÿ���졢�̡������������������С�Ѵ�(0.255)���ٵ�(-n,255+n)

	��3���������ֵ����0ʱ�����ӶԱȶȡ����ӶԱȶȱ仯�ķ���Ϊ��

		g=      0                                f<n��n>0

		255                            f>255-n��n>0

		(f-n)*(255/255-2*n)    n<f<255-n��n>0;

	fΪԴͼ�������ֵ��gΪ�ı���Ӧ�ķ���ֵ������Ľ���Ƕ�ÿ���졢�̡���������������������(n,255-n)���ӵ�(0,255)*/
	if (0 == nPara)
	{
		return uSrc;
	}
	int nData = 0;
	if (nPara < 0)
	{
		nData = uSrc * (255 - 2 * nPara / 255.0) - nPara;
		//nData = uSrc + (uSrc - 0) * nPara / 255.0;
	}

	else if (nPara > 0 && nPara < 255)
	{
		/*int nContrast = 255 * 255.0 / (255 - nPara) - 255;
		nData = uSrc + (uSrc - 0) * nContrast / 255.0;*/
		if (uSrc > nPara)
		{
			if (uSrc > 255 - nPara)
			{
				nData = 255;
			}

			else if (uSrc < 255 - nPara)
			{
				nData = (uSrc - nPara) * (255.0 / (255 - 2 * nPara)); 
			}
		}

		if (nData > 255)
		{
			nData = 255;
		}
	}

	if (nData < 0)
	{
		nData = 0;
	}

	/*if (nData > 255)
	{
		nData = 255;
	}*/

	return nData;

}

void ScreenToWorld(double winx, double winy, double *objx, double *objy, double *objz)
{
	GLfloat winX, winY, winZ; 

	//glTranslated(10,20,30);

	//��õ�ǰ��ģ�ͱ任����
	double dbModelMatrixs[16];
	glGetDoublev(GL_MODELVIEW_MATRIX,dbModelMatrixs);
	//���ͶӰ�任�ľ���
	double dbProjectionMartixs[16];
	glGetDoublev(GL_PROJECTION_MATRIX,dbProjectionMartixs);
	//����ӿ�����
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT,viewport);

	//���opengl��������
	winX = (float)winx;  
	winY = (float)viewport[3] - (float)winy;

	//���opengl���������Ϣ
	glReadPixels(winX,(GLint)winY,1,1,GL_DEPTH_COMPONENT,GL_FLOAT,&winZ);

	//���opengl����������
	gluUnProject(winX,winY,winZ,dbModelMatrixs,dbProjectionMartixs,viewport,objx,objy,objz);
}

void BrightnessAdjust( unsigned char* poData, int nBitPlanes, int nImgWidth, int nImgHeight, 
					  int nStartX, int nStartY, int nWidth, int nHeight ,float fBrightNess)
{
	if (nStartX < 0 || nStartX >= nImgWidth || nStartY < 0 || nStartY >= nImgHeight)
	{
		return;
	}

	if (nStartX + nWidth > nImgWidth || nStartY + nHeight > nImgHeight)
	{
		return;
	}

	for (int nRow = nStartY; nRow < nStartY + nHeight; nRow ++)
	{
		for (int nCol = nStartX; nCol < nStartX + nWidth; nCol ++)
		{
			int nOffset = nRow * nImgWidth * nBitPlanes + nCol * nBitPlanes;
			for (int i = 0; i < nBitPlanes; i ++)
			{
				BrightnessStretch(poData[nOffset+i],fBrightNess);
			}
		}
	}
}

bool Rgb2Ihs(unsigned char R,unsigned char G,unsigned char B,float &i,float &h,float &s)
{
	float rValue = (float)R;
	float gValue = (float)G;
	float bValue = (float)B;

	i = (float)(rValue + gValue + bValue);    

	if(i == 0)    i = 1.0;		//��ֹ����Ϊ0

	float theta = 0.0;

	float numerator = ((rValue-gValue)+(rValue-bValue))*0.5;	//����
	float denominator = sqrt(pow(rValue-gValue,2)+(rValue-bValue)*(gValue-bValue));	//��ĸ
	denominator += 0.00000001;	//����һ����С��������ֹ����Ϊ0
	theta = acos(numerator/denominator);
	if (B<=G)
	{
		h = theta/(2*3.1415926);
	}
	else if (B>G)
	{
		h = (2*3.1415926-theta)/(2*3.1415926);
	}

	s = 1.0f - 3 * min(min(rValue,gValue),bValue)/i;

	i = i/3;

	return true;

}

void HIS2RGB(float fh, float fi, float fs, unsigned char& r, unsigned char& g, unsigned char& b)
{
	int R, G, B;

	float pi2 = M_PI*2;
	fh *= pi2;		//��H��ԭ��0-360��

	//ע�����Ǻ����Ĳ����ǻ�����

	//H��0-120��֮��
	if((fh < pi2/3.0) && (fh >= 0.0))
	{
		B = fi*(1-fs);
		R = fi*(1.0 + fs * cos(fh)/cos(pi2/6.0-fh));
		G = 3*fi - (R + B);
	}

	//H��120-240��֮��
	else if((fh < 2*pi2/3.0) && (fh >= pi2/3.0))
	{
		fh -= pi2/3.0;
		R = fi*(1-fs);
		G = fi*(1.0 + fs * cos(fh)/cos(pi2/6.0-fh));
		B = 3*fi - (R + G);
	}

	//H��240-360��֮��
	else
	{
		fh -= 2*pi2/3.0;
		G = fi*(1-fs);
		B = fi*(1.0 + fs * cos(fh)/cos(pi2/6.0-fh));
		R = 3*fi - (B + G);
	}
	r = R > 255 ? 255 : R; 
	g = G > 255 ? 255 : G; 
	b = B > 255 ? 255 : B;

}
