/**
* @file              SysFeatureRenderer.h
* @brief             ʸ��������Ⱦ������
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��7��27��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSFEATURERENDERER_H_C54B6C89_5768_41FF_BB9D_E11F210F6C18__
#define __SYSFEATURERENDERER_H_C54B6C89_5768_41FF_BB9D_E11F210F6C18__

#include "SysDrawCommon.h"

namespace SysDraw
{
	enum Render_Type
	{
		SINGLE_SYMBOL_RENDERER,			//��һ������Ⱦ
		UNIQUE_VALUE_RENDERER,			//Ψһֵ��Ⱦ
		CLASS_BREAK_RENDERER			//�ּ�������Ⱦ
	};

	typedef list<void*> SysSymbolList;

	class SysRenderContext;
	class SysFeatureLayer;
	class SysSymbol;
	class SysFeature;

	class SYSDRAW_API SysFeatureRenderer
	{
	public:
		SysFeatureRenderer(void);

		virtual ~SysFeatureRenderer(void);

		/**
		* @brief ���Ĭ�ϵ���Ⱦ��
		* @param[in] int nGeomType
		* @return SysFeatureRenderer*
		* @author �����
		* @date 2015��7��27��
		* @note 
		*/
		static SysFeatureRenderer* GetDefaultRenderer( int nGeomType );

		/**
		* @brief ���Ĭ�ϵķ���
		* @param[in] int nGeomType
		* @return SysSymbol*
		* @author �����
		* @date 2015��7��27��
		* @note 
		*/
		static SysSymbol* GetDefaultSymbol(int nGeomType);

		/**
		* @brief �����Ⱦ��������
		* @return std::string 
		* @author �����
		* @date 2015��7��27��
		* @note 
		*/
		virtual std::string GetRendererName() const = 0;

		/**
		* @brief �����Ⱦ������������
		* @return std::string 
		* @author �����
		* @date 2015��7��27��
		* @note 
		*/
		virtual std::string GetRendererChsName() const = 0;

		/**
		* @brief ������Ⱦ������
		* @return Render_Type
		* @author �����
		* @date 2015��7��27��
		* @note 
		*/
		virtual Render_Type GetRendererType() const = 0;

		/**
		* @brief ��¡��ǰ��Ⱦ��
		* @return SysFeatureRenderer*
		* @author �����
		* @date 2015��7��27��
		* @note 
		*/
		virtual SysFeatureRenderer* Clone() const = 0;

		/**
		* @brief ��ʼ��Ⱦ����
		* @param[in]  SysRenderContext* pCcontext
		* @param[in] const SysFeatureLayer *vlayer
		* @return virtualvoid 
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		virtual void BeginRender( SysRenderContext* pCcontext, const SysFeatureLayer *vlayer ){};

		/**
		* @brief ������Ⱦ
		* @param[in] SysRenderContext* pCcontext
		* @return virtualvoid 
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		virtual void EndRender( SysRenderContext* pCcontext ) {};

		/**
		* @brief ��÷����б�
		* @return virtualconst 
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		virtual const SysSymbolList GetSymbols() const = 0;

		/**
		* @brief ����FID���Ҫ���Ƶ�ʸ������
		* @param[in] SysFeature* pFeature
		* @return SysSymbol*
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		virtual SysSymbol* GetSymbol(SysFeature* pFeature) const = 0;
	};


	/**
	* @brief ������Ⱦ��
	* @param[in] Render_Type eType
	* @return SysFeatureRenderer*
	* @author �����
	* @date 2015��7��27��
	* @note 
	*/
	SYSDRAW_API SysFeatureRenderer* CreateFeatureRenderer(Render_Type eType);

	/**
	* @brief ������Ⱦ��
	* @param[in] SysFeatureRenderer* pRender
	* @return void
	* @author �����
	* @date 2015��7��27��
	* @note 
	*/
	SYSDRAW_API void DestroyFeatureRenderer(SysFeatureRenderer* pRender);

}

#endif // end of __SYSFEATURERENDERER_H_C54B6C89_5768_41FF_BB9D_E11F210F6C18__
