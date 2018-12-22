/**
* @file              SysUniqueValueRenderer.h
* @brief             Ψһֵ��Ⱦ��
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��18��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSUNIQUEVALUERENDERER_H_16D1BF80_6064_4BF9_BAE0_7A7064B06C56__
#define __SYSUNIQUEVALUERENDERER_H_16D1BF80_6064_4BF9_BAE0_7A7064B06C56__

#include "SysFeatureRenderer.h"

namespace SysDraw
{
	class SysSymbol;

	class SYSDRAW_API SysUniqueValueRenderer : public SysFeatureRenderer
	{
		friend SysFeatureRenderer* CreateFeatureRenderer(Render_Type eType);

	private:
		SysUniqueValueRenderer(void);

		~SysUniqueValueRenderer(void);

	public:

		/**
		* @brief �����Ⱦ��������
		* @return std::string 
		* @author �����
		* @date 2015��7��27��
		* @note 
		*/
		virtual std::string GetRendererName() const ;

		/**
		* @brief �����Ⱦ������������
		* @return std::string 
		* @author �����
		* @date 2015��7��27��
		* @note 
		*/
		virtual std::string GetRendererChsName() const ;

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
		virtual SysFeatureRenderer* Clone() const ;

		/**
		* @brief ��Ⱦ����
		* @param[in]  SysRenderContext* pContext
		* @param[in] const SysFeatureLayer *pLayer
		* @return virtualvoid 
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		virtual void BeginRender( SysRenderContext* pContext, const SysFeatureLayer *pLayer );

		virtual void EndRender( SysRenderContext* pContext );

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
		* @return virtualSysSymbol* 
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		virtual SysSymbol* GetSymbol(SysFeature* pFeature) const ;

		/**
		* @brief ���÷�����ֶ�����
		* @param[in] int nFieldIndex
		* @return void
		* @author �����
		* @date 2015��8��19��
		* @note 
		*/
		void SetClassificationField( int nFieldIndex );

		/**
		* @brief ��÷�����ֶ�����
		* @return int
		* @author �����
		* @date 2015��8��19��
		* @note 
		*/
		int GetClassificationField() const;

		/**
		* @brief ����Ψһֵ�Ͷ�Ӧ�ķ���
		* @param[in]  std::string strValue
		* @param[in] SysSymbol* pSymbol
		* @return void
		* @author �����
		* @date 2015��8��19��
		* @note 
		*/
		void InsertValue( std::string strValue, SysSymbol* pSymbol );

	private:
		int								m_nFieldIndex;			//������ֶ�����
		std::map<std::string,SysSymbol* >	m_mapSymbols;	//Ψһֵ��Ӧ�ķ���

		unsigned int m_nVertexBuffer;
	};

}

#endif // end of __SYSUNIQUEVALUERENDERER_H_16D1BF80_6064_4BF9_BAE0_7A7064B06C56__
