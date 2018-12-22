/**
* @file              SysSimpleLineSymbol.h
* @brief             ���߷���
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��14��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSSIMPLELINESYMBOL_H_840FA1AF_1D69_459A_8651_A800881C9A19__
#define __SYSSIMPLELINESYMBOL_H_840FA1AF_1D69_459A_8651_A800881C9A19__

#include "SysLineSymbol.h"

namespace SysDraw
{
	enum SysLineStyle
	{
		Solid_line,			//ʵ��
		Dashed_Line,		//
		Dotted_Line,
		DashDot_Line
	};

	class SYSDRAW_API SysSimpleLineSymbol : public SysLineSymbol
	{
	public:
		SysSimpleLineSymbol(void);

		~SysSimpleLineSymbol(void);

		void SetLineStyle(SysLineStyle eStyle);

		virtual SysSymbolType GetSymbolType() const ;

		virtual void RenderFeature(const SysFeature* pFeature,SysRenderContext* pContext, bool bHighLight);

	private:
		SysLineStyle m_eLineStyle;
	};

}

#endif // end of __SYSSIMPLELINESYMBOL_H_840FA1AF_1D69_459A_8651_A800881C9A19__
