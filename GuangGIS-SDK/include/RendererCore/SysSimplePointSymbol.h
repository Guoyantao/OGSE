/**
* @file              SysSimplePointSymbol.h
* @brief             �򵥵������
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��14��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSSIMPLEPOINTSYMBOL_H_60360038_7D7B_473A_BE11_5B837FBA7B8D__
#define __SYSSIMPLEPOINTSYMBOL_H_60360038_7D7B_473A_BE11_5B837FBA7B8D__

#include "SysPointSymbol.h"

namespace SysDraw
{
	enum SIMPLEPOINTSYMBOL_TYPE
	{
		CYCLE_POINT,
		SQUARE_POINT,
		CROSS_POINT,
		DIAMOND_POINT
	};

	class SysPoint;

	class SYSDRAW_API SysSimplePointSymbol : public SysPointSymbol
	{
	public:
		SysSimplePointSymbol(void);

		~SysSimplePointSymbol(void);

		virtual SysSymbolType GetSymbolType() const ;

		virtual void RenderFeature(const SysFeature* pFeature,SysRenderContext* pContext, bool bHighLight);

	private:
		float m_fSize;		//���Ŵ�С
		float m_fAngle;		//��ת�Ƕ�
		float m_fXOffset;	//X����ƫ��
		float m_fYOffset;	//Y����ƫ��
		bool m_bUseOutLine;		//�Ƿ��ñ߿�

		SIMPLEPOINTSYMBOL_TYPE m_eType;

		void Init();

		void RenderSimplePoint(SysPoint* pPoint,SysRenderContext* pContext);
	};

}

#endif // end of __SYSSIMPLEPOINTSYMBOL_H_60360038_7D7B_473A_BE11_5B837FBA7B8D__
