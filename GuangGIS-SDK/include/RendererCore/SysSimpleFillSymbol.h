/**
* @file              SysSimpleFillSymbol.h
* @brief             ��������
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��14��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSSIMPLEFILLSYMBOL_H_8DD0247A_78B5_411D_A8DD_1E16ED34A265__
#define __SYSSIMPLEFILLSYMBOL_H_8DD0247A_78B5_411D_A8DD_1E16ED34A265__

#include "SysFillSymbol.h"

namespace SysDraw
{
	class SysSymbol;

	class SYSDRAW_API SysSimpleFillSymbol : public SysFillSymbol
	{
	public:
		SysSimpleFillSymbol(void);

		~SysSimpleFillSymbol(void);

		virtual SysSymbolType GetSymbolType() const ;

		virtual void RenderFeature(const SysFeature* pFeature,SysRenderContext* pContext, bool bHighLight);

	private:

		SysSymbol* m_pOutLineSymbol;
	};

}

#endif // end of __SYSSIMPLEFILLSYMBOL_H_8DD0247A_78B5_411D_A8DD_1E16ED34A265__

