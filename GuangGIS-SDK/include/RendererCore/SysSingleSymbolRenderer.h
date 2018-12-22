/**
* @file              SysSingleSymbolRenderer.h
* @brief             ��һ������Ⱦ
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��7��27��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSSINGLESYMBOLRENDERER_H_9A782E36_0E98_450F_95E2_EE93DDF114D1__
#define __SYSSINGLESYMBOLRENDERER_H_9A782E36_0E98_450F_95E2_EE93DDF114D1__

#include "SysFeatureRenderer.h"

namespace SysDraw
{
	class SysSymbol;

	class SYSDRAW_API SysSingleSymbolRenderer : public SysFeatureRenderer
	{
		friend SysFeatureRenderer* CreateFeatureRenderer(Render_Type eType);

	private:
		SysSingleSymbolRenderer(void);

		~SysSingleSymbolRenderer(void);

	public:

		/**
		* @brief �����Ⱦ��������
		* @return std::string 
		* @author �����
		* @date 2015��7��27��
		* @note 
		*/
		virtual std::string GetRendererName() const;

		/**
		* @brief �����Ⱦ��������
		* @return std::string 
		* @author �����
		* @date 2015��7��27��
		* @note 
		*/
		virtual std::string GetRendererChsName() const;

		/**
		* @brief ������Ⱦ������
		* @return Render_Type
		* @author �����
		* @date 2015��7��27��
		* @note 
		*/
		virtual Render_Type GetRendererType() const;

		/**
		* @brief ��¡��ǰ��Ⱦ��
		* @return SysFeatureRenderer*
		* @author �����
		* @date 2015��7��27��
		* @note 
		*/
		virtual SysFeatureRenderer* Clone() const;

		virtual void BeginRender( SysRenderContext* pCcontext, const SysFeatureLayer *vlayer );

		/**
		* @brief ��÷����б�
		* @return virtualconst 
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		virtual const SysSymbolList GetSymbols() const;

		/**
		* @brief GetSymbol
		* @param[in] SysFeature* pFeature
		* @return SysSymbol*
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		virtual SysSymbol* GetSymbol(SysFeature* pFeature) const;

		/**
		* @brief ���÷���
		* @param[in] SysSymbol* pSymbol
		* @return void
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		void SetSymbol(SysSymbol* pSymbol);

	private:
		SysSymbol* m_pSymbol;

		unsigned int m_nVertexBuffer;
	};

}

#endif // end of __SYSSINGLESYMBOLRENDERER_H_9A782E36_0E98_450F_95E2_EE93DDF114D1__
