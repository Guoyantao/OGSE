/**
* @file              SysFeatureLabel.h
* @brief             Ҫ���ı���ע����ͻ���
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��10��16��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSFEATURELABEL_H_39598E62_04D0_4A4E_96A5_95BE1C89F48B__
#define __SYSFEATURELABEL_H_39598E62_04D0_4A4E_96A5_95BE1C89F48B__

#include "SysDrawCommon.h"

namespace SysDraw
{
	class SysFeature;
	class SysDrawText;
	class SysCoordinate;
	class SysRenderContext;
	class SysFeatureLabelAttribute;
	class SysLineString;
	class SysPolygon;
	class SysEnvelope;

	class SYSDRAW_API SysFeatureLabel
	{
	public:

		struct LabelPoint		//��ע��
		{
			double m_dGeoX;
			double m_dGeoY;
			double m_dAngle;
		};

		SysFeatureLabel(void);

		~SysFeatureLabel(void);

		/**
		* @brief ���Ʊ�ע
		* @param[in] SysRenderContext *pRenderContext
		* @param[in] SysFeature *pFeature
		* @param[in] bool bSelected
		* @param[in] SysFeatureLabelAttribute *pLabelAttributes
		* @return void
		* @author �����
		* @date 2015��10��16��
		* @note 
		*/
		void RenderFeature( 
						SysRenderContext *pRenderContext, 
						SysFeature *pFeature, 
						bool bSelected, 
						SysFeatureLabelAttribute *pLabelAttributes = NULL 
			);

		/**
		* @brief �������ڱ�ע���ֶ�����
		* @param[in] int nFieldIndex
		* @return void
		* @author �����
		* @date 2015��10��16��
		* @note 
		*/
		void SetFieldIndex(int nFieldIndex);

		/**
		* @brief ������ڱ�ע�ֶε�����
		* @return int
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		int GetFieldIndex() const;

		/**
		* @brief ���û��Ʊ�עʱ������
		* @param[in] SysFeatureLabelAttribute *pLabelAttributes
		* @return void
		* @author �����
		* @date 2015��10��19��
		* @note 
		*/
		void SetLabelAttribute(SysFeatureLabelAttribute *pLabelAttributes);

		/**
		* @brief  ��ñ�עʱ������
		* @return SysFeatureLabelAttribute
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		SysFeatureLabelAttribute *GetLabelAttribute() const;

	private:

		void GetLabelPoint( std::vector<LabelPoint>& points, SysFeature * pFeature );

		unsigned char* GetLabelPoint( std::vector<LabelPoint>& vecPoints, unsigned char* pWkbBuf, size_t nWkbLen );

		void RenderLabel( SysRenderContext *pRenderContext,
							double dGeoX,double dGeoY,
							std::string strText, SysDrawText &drawFont,
							double dXoffset, double dYoffset,
							double dAng,
							int nWidth, int nHeight, int nAlignment = 0 );

		/**
		* @brief ������ߵı�ע��λ
		* @param[in] SysLineString* pLine
		* @param[in] const char* pszFieldValue  �ֶ�ֵ
		* @param[out] std::vector<LabelPoint>& points �õ��ı�ע��
		* @param[in] const SysEnvelope& envView ��ͼ��Χ
		* @param[out] std::vector<std::string>& vecLabelStr �õ��ı�ע���ַ�������
		* @param[in] double dbScale ��ͼ���ű���ϵ��
		* @return void
		* @author �����
		* @date 2015��10��21��
		* @note 
		*/
		void GetLineStringLabelPoint(SysLineString* pLine, const char* pszFieldValue,const SysEnvelope& envView, 
			std::vector<LabelPoint>& points, std::vector<std::string>& vecLabelStr,double dbScale);

		/**
		* @brief ��ö���εı�ע��λ
		* @param[in] ysPolygon* pPolygon
		* @param[in] const char* pszFieldValue �ֶ�ֵ
		* @param[in] const SysEnvelope& envView
		* @param[in] std::vector<LabelPoint>& points �õ��ı�ע��
		* @param[in] std::vector<std::string>& vecLabelStr �õ��ı�ע���ַ�������
		* @param[in] double dbScale
		* @return void
		* @author �����
		* @date 2015��10��22��
		* @note 
		*/
		void GetPolygonLabelPoint(
						SysPolygon* pPolygon, 
						const char* pszFieldValue,
						const SysEnvelope& envView, 
						std::vector<LabelPoint>& points, 
						std::vector<std::string>& vecLabelStr,
						double dbScale);

		void GetLabelPoint( SysFeature * pFeature, const SysEnvelope& envView, std::vector<LabelPoint>& points, std::vector<std::string> &vecLabelStr );

		int m_nFieldIndex;			//��ע���ֶ�����

		SysFeatureLabelAttribute* m_pLabelAttributes;		//��ע�ı�����
	};

}

#endif // end of __SYSFEATURELABEL_H_39598E62_04D0_4A4E_96A5_95BE1C89F48B__
