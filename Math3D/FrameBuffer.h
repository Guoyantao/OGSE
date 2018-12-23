#ifndef MATH3D_FRAMEBUFFER_INCLUDE_H
#define MATH3D_FRAMEBUFFER_INCLUDE_H

#include "Math3DCommon.h"

NS_MATH3D_BEGIN

class ColorRGBA;

class FrameBuffer
{
public:
	FrameBuffer(void);

	~FrameBuffer(void);

	void SetBufferSize(unsigned int nWidth,unsigned int nHeight);

	void SetColor(unsigned int nX,unsigned int nY,const ColorRGBA& color);

	void SetDepth(unsigned int nX,unsigned int nY,float fDepth);

private:
	unsigned char* m_pColorBuf;		//��ɫ����
	float *m_pfDepthBuf;				//��Ȼ���
	int m_nWidth;					//���
	int m_nHeight;					//�߶�

	void ClearBuffer();
};

FrameBuffer* GetFrameBuffer();

NS_MATH3D_END

#endif
