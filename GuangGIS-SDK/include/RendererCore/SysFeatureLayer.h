/**
* @file              SysFeatureLayer.h
* @brief             ʸ��ͼ��
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��7��1��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSFEATURELAYER_H_78C57375_349B_49C6_A5B0_B35ADF7CF255__
#define __SYSFEATURELAYER_H_78C57375_349B_49C6_A5B0_B35ADF7CF255__

#include "SysMapLayer.h"

namespace SysDataSource
{
	class IDataLayer;
	class IFeatureDataLayer;
}

namespace SysDraw
{
	class SysEnvelope;
	class SysRasterSource;
	class SysFeature;
	class SysFeatureLabel;
	class SysFeatureRenderer;
	class SysSpatialIndex;
	class SysFeatureCache;

	enum VertexMarkType
	{
		Square,		//������
		Cross,		//ʮ��˿
	};

	class SYSDRAW_API SysFeatureLayer : public SysMapLayer
	{
	public:
		explicit SysFeatureLayer(std::string strLyrName);

		~SysFeatureLayer(void);

		/**
		* @brief ��������Դ
		* @param[in] SysDataSource::IDataLayer* pDatalayer
		* @return bool
		* @author �����
		* @date 2015��7��10��
		* @note 
		*/
		bool SetDataSource(SysDataSource::IDataLayer* pDatalayer);

		/**
		* @brief �������Դ
		* @return SysDataSource::IDataLayer*
		* @author �����
		* @date 2015��7��10��
		* @note 
		*/
		SysDataSource::IFeatureDataLayer* GetDataSource() const;

		/**
		* @brief ���ʸ��Ҫ����Ⱦ��
		* @return SysFeatureRenderer*
		* @author �����
		* @date 2015��8��14��
		* @note 
		*/
		SysFeatureRenderer* GetFeatureRenderer() const;

		/**
		* @brief ����ʸ��Ҫ����Ⱦ��
		* @param[in] SysFeatureRenderer* pRenderer
		* @return void
		* @author �����
		* @date 2015��8��14��
		* @note 
		*/
		void SetFeatureRenderer(SysFeatureRenderer* pRenderer);

		/**
		* @brief ����ʸ��ͼ��
		* @param[in] SysDataSource::IDataLayer* pDatalayer
		* @return SysRasterLayer* ���ش�����ͼ��ָ��
		* @author �����
		* @date 2015��7��1��
		* @note 
		*/
		static SysFeatureLayer* CreateFeatureLayer(SysDataSource::IDataLayer* pDatalayer);

		/**
		* @brief ����ͼ��
		* @param[in] SysRasterLayer* pVecLayer
		* @return void 
		* @author �����
		* @date 2015��7��1��
		* @note 
		*/
		static void DestroyFeatureLayer(SysFeatureLayer* pVecLayer);

		/**
		* @brief Draw
		* @param[in] SysRenderContext* rendererContext
		* @return bool
		* @author �����
		* @date 2015��8��16��
		* @note 
		*/
		virtual bool Draw( SysRenderContext* rendererContext );

		/**
		* @brief DrawLabels
		* @param[in] SysRenderContext* rendererContext
		* @return void
		* @author �����
		* @date 2015��8��16��
		* @note 
		*/
		virtual void DrawLabels( SysRenderContext* rendererContext );

		void ResetRead();

		/**
		* @brief �����һ��Ҫ��
		* @return SysFeature*
		* @author �����
		* @date 2015��8��16��
		* @note 
		*/
		SysFeature* GetNextFeature() const;

		/**
		* @brief ���Ҫ�ظ���
		* @return int
		* @author �����
		* @date 2015��8��16��
		* @note 
		*/
		int GetFeatureCount() const;

		/**
		* @brief ����FID���Ҫ��
		* @param[in] int nIndex
		* @return SysFeature*
		* @author �����
		* @date 2015��8��16��
		* @note 
		*/
		SysFeature* GetFeatureByFID(int nIndex) const;

		/**
		* @brief ���ÿռ����
		* @param[in] const SysEnvelope& envFilter
		* @return void
		* @author �����
		* @date 2015��8��16��
		* @note 
		*/
		void SetSpatialFilter(const SysEnvelope& envFilter);

		/**
		* @brief ���ݾ���ѡ��Ҫ��
		* @param[in] const SysEnvelope& envFilter
		* @return std::vector<long>
		* @author �����
		* @date 2015��11��16��
		* @note 
		*/
		std::vector<long> SelectFeatures(const SysEnvelope& envFilter);

		/**
		* @brief �����ռ�����
		* @param[in] DrawProgressFunc pProgressFunc = NULL
		* @param[in] void* pProgressArg = NULL
		* @return bool
		* @author �����
		* @date 2015��11��16��
		* @note 
		*/
		bool BuildSpatialIndex(DrawProgressFunc pProgressFunc = NULL, void* pProgressArg = NULL);

		/**
		* @brief GetSpatialIndex
		* @return SysSpatialIndex*
		* @author �����
		* @date 2015��11��19��
		* @par Sample code
		* @code @endcode
		* @note 
		*/
		SysSpatialIndex* GetSpatialIndex() const;

		/**
		* @brief GetFeatureCache
		* @return SysFeatureCache*
		* @author �����
		* @date 2015��11��19��
		* @par Sample code
		* @code @endcode
		* @par Output
		* @note 
		*/
		SysFeatureCache* GetFeatureCache() const;

		/**
		* @brief ����ѡ�л���δѡ�е�FID
		* @param[in] long nFid
		* @param[in] bool bSelected
		* @return bool
		* @author �����
		* @date 2015��8��16��
		* @par Sample code
		* @code
		    char **path = NULL;
		    int count = 0;
		    test_get_paths(&path, &count);
		    //use the path
		    free(path);
		    path = NULL; @endcode
		* @see BuildSpatialIndex
		*/
		bool InsertSelectedFID(long nFid,bool bSelected = true) const;

		/**
		* @brief IsSelected
		* @param[in] long nFid
		* @return bool
		* @author �����
		* @date 2015��8��16��
		* @note 
		*/
		bool IsSelected(long nFid) const;

		/**
		* @brief RemoveSelected
		* @return void
		* @author �����
		* @date 2015��8��16��
		* @note 
		*/
		void RemoveSelected() /*const*/;

		/**
		* @brief ��ñ�ע��Ⱦ��
		* @return SysFeatureLabel *
		* @author �����
		* @date 2015��10��20��
		* @note 
		*/
		SysFeatureLabel *GetFeatureLabel() const;

		/**
		* @brief ���ñ�ע��Ⱦ��
		* @param[in] SysFeatureLabel *pLabel
		* @return void
		* @author �����
		* @date 2015��11��13��
		* @note 
		*/
		void SetFeatureLabel(SysFeatureLabel *pLabel);

		/**
		* @brief ���ƶ���ı�־
		* @param[in]  double x
		* @param[in] double y
		* @param[in] double dbScale
		* @param[in] VertexMarkType eType
		* @param[in] int nVertexSize
		* @return void
		* @author �����
		* @date 2015��10��26��
		* @note 
		*/
		static void DrawVertexMarker( double x, double y, double dbScale, VertexMarkType eType, int nVertexSize );

	private:
		SysDataSource::IFeatureDataLayer* m_pDatalayer;		//��Ӧ������ͼ��
		SysRasterSource* m_pDataSource;
		SysFeatureRenderer* m_pRenderer;				//��Ӧ��ʸ����Ⱦ��

		typedef std::map<long,bool> SysSelectedFIDs;		//Ҫ��ѡ���ID����
		mutable SysSelectedFIDs m_mapSelectIds;	

		bool m_bLabeled;								//�Ƿ���Ʊ�ע
		SysFeatureLabel *m_pLabel;						//�ı���ע��Ⱦ��

		bool m_bUseIndex;							//�Ƿ�ʹ������
		SysSpatialIndex *m_pSpatialIndex;				//�ռ�����

	public:
		typedef std::map<long,SysFeature *> mapFeatureCache;		//ʸ��Ҫ�ػ���
		mapFeatureCache m_mapFeaCache;								//ʸ������map

	private:

		SysFeatureCache* m_pFeatureCache;			//Ҫ�ػ���

		void Init();		//��ʼ��

		void UnInit();		//����ʼ����������Դ
	};

}

#endif // end of __SYSFEATURELAYER_H_78C57375_349B_49C6_A5B0_B35ADF7CF255__
