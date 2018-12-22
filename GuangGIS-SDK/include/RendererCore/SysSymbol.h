/**
* @file              SysSymbol.h
* @brief             ���Ż���
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��14��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSSYMBOL_H_DC0A9E7A_AF2D_41B9_AB88_B461B20BFBA4__
#define __SYSSYMBOL_H_DC0A9E7A_AF2D_41B9_AB88_B461B20BFBA4__

#include "SysDrawCommon.h"


namespace SysDraw
{
	enum SysSymbolType
	{
		PointSymbol,		//�����
		LineSymbol,			//��״����
		FillSymbol			//������
	};

	enum SysUnitType
	{
		Point_Unit,			//���ص�
		CentiMeter_Unit,	//����
		MiliMeter_Unit		//����
	};

	class SysFeature;
	class SysRGBAColor;
	class SysRenderContext;

	class SYSDRAW_API SysSymbol
	{
	public:
		SysSymbol(void);

		virtual ~SysSymbol(void);

		/**
		* @brief GetSymbolType
		* @return SysSymbolType
		* @author �����
		* @date 2015��10��10��
		* @note 
		*/
		virtual SysSymbolType GetSymbolType() const = 0;

		/**
		* @brief GetUnitType
		* @return SysUnitType
		* @author �����
		* @date 2015��10��10��
		* @note 
		*/
		SysUnitType GetUnitType() const;

		/**
		* @brief SetUnitType
		* @param[in] SysUnitType eUnitType
		* @return void
		* @author �����
		* @date 2015��10��10��
		* @note 
		*/
		void SetUnitType(SysUnitType eUnitType);

		/**
		* @brief GetOutLineColor
		* @return SysRGBAColor&
		* @author �����
		* @date 2015��10��10��
		* @note 
		*/
		SysRGBAColor& GetOutLineColor() const;

		/**
		* @brief SetOutLineColor
		* @param[in] const SysRGBAColor& color
		* @return void
		* @author �����
		* @date 2015��10��10��
		* @note 
		*/
		void SetOutLineColor(const SysRGBAColor& color);

		/**
		* @brief GetColor
		* @return SysRGBAColor&
		* @author �����
		* @date 2015��10��10��
		* @note 
		*/
		SysRGBAColor& GetColor() const;

		/**
		* @brief SetColor
		* @param[in] const SysRGBAColor& color
		* @return void
		* @author �����
		* @date 2015��10��10��
		* @note 
		*/
		void SetColor(const SysRGBAColor& color);

		/**
		* @brief GetOutLineWidth
		* @return float
		* @author �����
		* @date 2015��10��10��
		* @note 
		*/
		float GetOutLineWidth() const;

		/**
		* @brief SetOutLineWidth
		* @param[in] float fWidth
		* @return void
		* @author �����
		* @date 2015��10��10��
		* @note 
		*/
		void SetOutLineWidth(float fWidth);

		/**
		* @brief ����Ҫ��
		* @param[in] const SysFeature* pFeature
		* @param[in] SysRenderContext* pContext
		* @param[in] bool bHighLight �Ƿ������ʾ
		* @return void
		* @author �����
		* @date 2015��10��10��
		* @note 
		*/
		virtual void RenderFeature(const SysFeature* pFeature,SysRenderContext* pContext, bool bHighLight){};

	protected:
		SysUnitType m_UnitType;
		SysRGBAColor *m_pOutLineColor;		//��߿���ɫ
		SysRGBAColor *m_pColor;				//�ڲ����ɫ
		float m_fOutLineWidth;				//��߿���
	};

}

#endif // end of __SYSSYMBOL_H_DC0A9E7A_AF2D_41B9_AB88_B461B20BFBA4__
