/**
* @file              SysMapLayer.h
* @brief             ��ͼͼ����
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��6��25��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSMAPLAYER_H_C355D47F_C869_4D3B_B313_4C9947B6D4BC__
#define __SYSMAPLAYER_H_C355D47F_C869_4D3B_B313_4C9947B6D4BC__

#include "SysEnvelope.h"

//ǰ������

namespace SysSRS
{
	class CSpatialReference;
	class CCoordTransformation;
}

namespace SysDraw
{

	class SysRenderContext;

	class SYSDRAW_API SysMapLayer 
	{

	public:
		enum LayerType
		{
			VectorLayer,		//ʸ��ͼ��
			RasterLayer,		//դ��ͼ��
			WMTSLayer,			//��Ƭͼ��
			GraphicsLayer		//���ͼ��
		};

		friend class SysMap;

		SysMapLayer( SysMapLayer::LayerType type, std::string strLyrName);

		virtual ~SysMapLayer();

		/**
		* @brief ���ͼ�������
		* @return SysMapLayer::LayerType
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		SysMapLayer::LayerType GetLayerType() const;

		/**
		* @brief ����ͼ�������
		* @param[in] const std::string & strName
		* @return void
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		void SetLayerName( const std::string & strName );

		/**
		* @brief & ���ͼ�������
		* @return std::stringconst 
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		std::string const & GetLayerName() const;

		/**
		* @brief ����ļ��������ļ���׺��
		* @return std::string
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		std::string GetFileName() const;

		/**
		* @brief ���ƣ�ȫ����Χ
		* @param[in] SysRenderContext* rendererContext
		* @return virtual bool 
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		virtual bool Draw( SysRenderContext* rendererContext ) = 0;

		/**
		* @brief ���ƣ����ַ�Χ
		* @param[in]  SysRenderContext* rendererContext
		* @param[in] const SysEnvelope& envView
		* @return virtual bool 
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		virtual bool Draw( SysRenderContext* rendererContext ,const SysEnvelope& envView){return false;}

		/**
		* @brief ���Ʊ�ע��ȫ����Χ
		* @param[in] SysRenderContext* rendererContext
		* @return virtualvoid 
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		virtual void DrawLabels( SysRenderContext* rendererContext ){}

		/**
		* @brief ���Ʊ�ע�����ַ�Χ
		* @param[in]  SysRenderContext* rendererContext
		* @param[in] const SysEnvelope& envView
		* @return virtualvoid 
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		virtual void DrawLabels( SysRenderContext* rendererContext ,const SysEnvelope& envView ){}

		/**
		* @brief ���ͼ��ķ�Χ
		* @return constSysEnvelope& 
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		const SysEnvelope& GetLayerExtent() const;

		/**
		* @brief ���ͼ��ķ�Χ
		* @return SysEnvelope&
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		SysEnvelope& GetLayerExtent();

		/**
		* @brief ����ͼ��ķ�Χ
		* @param[in] const SysEnvelope& layerExtent
		* @return void
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		void SetLayerExtent(const SysEnvelope& layerExtent);


		/**
		* @brief �Ƿ���Ч
		* @return bool
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		bool IsValid() const;

		/**
		* @brief �Ƿ���Ա༭
		* @return virtualbool 
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		virtual bool IsEditable() const {return 0;}; 

		/**
		* @brief �Ƿ�ɼ�
		* @return bool
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		bool IsVisible() const;

		/**
		* @brief �����Ƿ�ɼ�
		* @param[in] bool bVisible
		* @return void
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		void SetVisible(bool bVisible);

		/**
		* @brief ����������߷�ĸ
		* @return float
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		float GetMaxScale() const;

		/**
		* @brief �����������߷�ĸ
		* @param[in] float fMaxScale
		* @return void
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		void SetMaxScale(float fMaxScale);

		/**
		* @brief �����С�����߷�ĸ
		* @return float
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		float GetMinScale() const;

		/**
		* @brief ������С�����߷�ĸ
		* @param[in] float fMinScale
		* @return void
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		void SetMinScale(float fMinScale);

		/**
		* @brief ��ÿռ�ο�ϵͳ
		* @return SysSRS::CSpatialReference*
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		SysSRS::CSpatialReference* GetSpatialRef() const;

		/**
		* @brief ���ÿռ�ο�ϵͳ
		* @param[in] const std::string& strWkt
		* @return void
		* @author �����
		* @date 2015��7��9��
		* @note 
		*/
		void SetSpatialRef(const std::string& strWkt);

		/**
		* @brief ������������ת���������Ӹ�ͼ�㵽��ǰ��ͼ��ת��
		* @return SysSRS::CCoordTransformation* ����ת����
		* @author �����
		* @date 2015��12��2��
		* @par Sample code
		* @code @endcode
		* @par Output
		* @see 
		* @note 
		*/
		SysSRS::CCoordTransformation *GetForwardCoordTran() const;

		/**
		* @brief ��÷��������ת���������ӵ�ǰ��ͼ����ͼ��ת��
		* @return SysSRS::CCoordTransformation* ����ת����
		* @author �����
		* @date 2015��12��2��
		* @par Sample code
		* @code @endcode
		* @par Output
		* @see 
		* @note 
		*/
		SysSRS::CCoordTransformation *GetInverseCoordTran() const;

		
	private:
		unsigned int m_TransparencyLevel;

		SysEnvelope m_LayerExtent;		//ͼ��ķ�Χ

		bool m_bValid;					//�Ƿ���Ч

		std::string m_strLayerName;			//ͼ�������

		SysMapLayer::LayerType m_LayerType;		//ͼ�������

		bool m_bVisible;						//�Ƿ�ɼ�

		float m_fMinScale;						//��������
		float m_fMaxScale;						//��С������
		bool m_bScaleBasedVisibility;

		SysSRS::CSpatialReference* m_pCRS;		//�ռ�ο�ϵͳ
		SysSRS::CCoordTransformation *m_pForwardTran;		//����任
		SysSRS::CCoordTransformation *m_pInverseTran;		//����任

	private:

		SysMapLayer( SysMapLayer const & );

		SysMapLayer & operator=( SysMapLayer const & );

		void SetForwardCoordTran(SysSRS::CSpatialReference* pSrcSrs,SysSRS::CSpatialReference* pDstSrs);

		void SetInverseCoordTran(SysSRS::CSpatialReference* pSrcSrs,SysSRS::CSpatialReference* pDstSrs);

	};

	class SysRasterLayer;
	class SysFeatureLayer;

	SYSDRAW_API SysRasterLayer* OpenRaster(std::string strFileName,DrawProgressFunc ProgressFunc = NULL, void* pProgressArg = NULL);

	SYSDRAW_API SysFeatureLayer* OpenFeature(std::string strFileName);

}



#endif // end of __SYSMAPLAYER_H_C355D47F_C869_4D3B_B313_4C9947B6D4BC__
