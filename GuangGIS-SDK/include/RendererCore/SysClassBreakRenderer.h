/**
* @file              SysClassBreakRenderer.h
* @brief             �ּ���Ⱦ��
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��24��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSCLASSBREAKRENDERER_H_4602B3A4_CA3A_4E66_B8DD_8DD9FF1E38E4__
#define __SYSCLASSBREAKRENDERER_H_4602B3A4_CA3A_4E66_B8DD_8DD9FF1E38E4__

#include "SysFeatureRenderer.h"
#include "SysValueStatistics.h"

namespace SysDraw
{

	class SYSDRAW_API SysClassBreakRenderer : public SysFeatureRenderer
	{
		friend SysFeatureRenderer* CreateFeatureRenderer(Render_Type eType);

	private:
		SysClassBreakRenderer(void);

		~SysClassBreakRenderer(void);

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
		* @return void
		* @author �����
		* @date 2015��10��10��
		* @note 
		*/
		virtual void BeginRender( SysRenderContext* pContext, const SysFeatureLayer *pLayer );

		virtual void EndRender( SysRenderContext* pContext );

		/**
		* @brief ��÷����б�
		* @return virtualconst 
		* @author �����
		* @date 2015��8��19��
		* @note 
		*/
		virtual const SysSymbolList GetSymbols() const;

		/**
		* @brief GetSymbolByFid
		* @param[in] int nFid
		* @return SysSymbol*
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
		* @brief SetMinClassNum
		* @param[in] int nMinClassNum
		* @return void
		* @author �����
		* @date 2015��8��26��
		* @note 
		*/
		void SetMinClassNum(int nMinClassNum);

		/**
		* @brief GetMinClassNum
		* @return int
		* @author �����
		* @date 2015��8��26��
		* @note 
		*/
		int GetMinClassNum() const;

		/**
		* @brief ���÷�����Ŀ
		* @param[in] int nClassNum
		* @return void
		* @author �����
		* @date 2015��8��26��
		* @note 
		*/
		void SetClassNum(int nClassNum);

		/**
		* @brief ��÷�����Ŀ
		* @return int
		* @author �����
		* @date 2015��8��26��
		* @note 
		*/
		int GetClassNum() const;

		/**
		* @brief SortClassAscending
		* @return int
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		int SortClassAscending() const;

		/**
		* @brief ��÷ּ���ʽ
		* @return ClassBreak_Type
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		ClassBreak_Type GetClassBreakType() const;

		/**
		* @brief ���÷ּ���ʽ
		* @param[in] ClassBreak_Type eBreakType
		* @return void
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		void SetClassBreakType(ClassBreak_Type eBreakType);

		/**
		* @brief ���ÿһ���ּ������޺�����
		* @param[in] double* pValues
		* @param[in] int nCount
		* @return void
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		void GetClassIntervals(double* pValues,int nCount) const;

		/**
		* @brief ��÷ּ��ļ��ֵ
		* @return constdouble* 
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		const double* GetIntervalValues() const;

		/**
		* @brief �Էּ�����Сֵ��Ϊ��ֵ�����Ƿ��ڷ����б���
		* @param[in] double dbKey
		* @return bool
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		bool FindKey(double dbKey) const;

		/**
		* @brief �������
		* @param[in] double dbMinValue
		* @param[in] SysSymbol* pSymbol
		* @return void
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		void InsertSymbol(double dbMinValue,SysSymbol* pSymbol);

	private:
		int								m_nClassFieldIndex;				//�ּ����ֶ�
		int								m_nMinClassNum;					//��С�ķּ���Ŀ
		int								m_nClassNum;					//�ּ�������
		ClassBreak_Type					m_eBreakType;					//�ּ��ķ�ʽ

		mutable double *				m_pIntervals;					//���ֵ���ּ��м�ļ��ֵ���������˵�������Сֵ

		typedef std::map<double,SysSymbol *> BreakSymbolMap;			//��ֵ�Ƿּ�������
		BreakSymbolMap					m_mapSymbols;

	};

}

#endif // end of __SYSCLASSBREAKRENDERER_H_4602B3A4_CA3A_4E66_B8DD_8DD9FF1E38E4__
