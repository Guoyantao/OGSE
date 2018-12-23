#ifndef MATH32_DIB_INCLUDE
#define MATH32_DIB_INCLUDE



#include <windows.h>

DECLARE_HANDLE(HDIB);



class CDIB
{
public:
	CDIB(void);

public:
	~CDIB(void);

private:

	HDIB			hDib;				//ͼ����
	long			m_lWidth;			//ͼ����
	long			m_lHeight;			//ͼ��߶�
	long			m_lColor;			//ͼ����ɫ��

public:

	BOOL            m_bBackTrans;
	COLORREF		m_ColorPix;
	BYTE            m_TransLevel;

	HBITMAP m_hBitmap;	//λͼ���
	unsigned char* m_poData;

	BITMAPINFO bitinfo;

public:

	BOOL Create(long lWidth, long lHeight, long lColors);

	void SetBackTrans(BOOL bBackTrans, COLORREF color) { m_bBackTrans = bBackTrans; m_ColorPix = color;}

	BOOL Free();

	void GetSize(long lWidth, long lHeight);

	void GetColors(long lColors);

	//ͨ���Ű��졢�̡���(1,2,3)��˳������
	BOOL SetImgData(long lChanelIndex, long lRow, long lCol, long lWidth, long lHeight, unsigned char *pData);

	BOOL GetImgData(long lChannelNum, long lRow, long lCol, long lWidth, long lHeight, unsigned char *pData);

	//��ɫ��
	BOOL SetPalette(unsigned char *pucRed, unsigned char *pucGreen, unsigned char *pucBlue);

	BOOL GetPalette(unsigned char *pucRed, unsigned char *pucGreen, unsigned char *pucBlue);

	//ͨ���Ű��졢�̡���(1,2,3)��˳������
	BOOL SetPixelBW(long lChannelNum, long lRow, long lCol, unsigned char ucValue);

	BOOL GetPixelBW(long lChannelNum, long lRow, long lCol, unsigned char *pucValue);

	//����
	BOOL Draw(HDC hDC, long lRow, long lCol, long lWidth, long lHeight, RECT rctDest);

	BOOL Draw(HDC hDC,tagRECT tagPosRect,long lRow, long lCol, long lWidth, long lHeight, RECT rctDest);
};



#endif