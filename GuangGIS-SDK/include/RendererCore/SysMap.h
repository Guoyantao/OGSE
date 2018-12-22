/**
* @file              SysMap.h
* @brief             ��ͼ�࣬�����ͼͼ��
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��6��26��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSMAP_H_8EE9B95C_8995_4B83_B6CD_A9747D717433__
#define __SYSMAP_H_8EE9B95C_8995_4B83_B6CD_A9747D717433__

#include "SysEnvelope.h"

namespace SysSRS
{
	class CSpatialReference;
}

namespace SysDraw
{

	class SysMapLayer;
	class SysGraphLayer;
	class SysMapLayerList;

	class SYSDRAW_API SysMap
	{
	public:
		explicit SysMap(const std::string& strMapName);

		~SysMap(void);

		/**
		* @brief ���ͼ��
		* @param[in] SysMapLayer* pMapLayer
		* @return void
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		void AddMapLayer(SysMapLayer* pMapLayer);

		/**
		* @brief ��������ɾ��ͼ��
		* @param[in] const std::string& strName
		* @return bool
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		bool RemoveMapLayer(const std::string& strName);

		/**
		* @brief ɾ��ָ��ͼ��ָ���ͼ��
		* @param[in] const SysMapLayer* pLayer
		* @return bool
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		bool RemoveMapLayer(const SysMapLayer* pLayer);

		/**
		* @brief ���ص�ͼ������
		* @return std::string
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		std::string GetMapName() const;

		/**
		* @brief �ж�ͼ���Ƿ����
		* @param[in] const SysMapLayer* pLayer
		* @return bool
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		bool FindMapLayer(const SysMapLayer* pLayer) const;

		/**
		* @brief �ж�ͼ���Ƿ����
		* @param[in] const std::string& strName
		* @return bool
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		bool FindMapLayer(const std::string& strName) const;

		/**
		* @brief ���ͼ��ĸ���
		* @return size_t
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		inline size_t GetLayerCount() const;

		/**
		* @brief ��õ�ǰͼ��
		* @return SysMapLayer*
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		const SysMapLayer* GetCurrentLayer() const;

		/**
		* @brief ��õ�ǰͼ��
		* @return SysMapLayer*
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		SysMapLayer* GetCurrentLayer();

		/**
		* @brief ���õ�ǰͼ��
		* @param[in] const SysMapLayer* pLayer
		* @return void
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		void SetCurrentLayer(const SysMapLayer* pLayer);

		/**
		* @brief ��õ�ͼ�Ŀռ�ο�ϵͳ
		* @return SysSRS::CSpatialReference*
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		SysSRS::CSpatialReference* GetSpatialRef() const;

		/**
		* @brief ��õ�ͼ�Ŀ��ӷ�Χ
		* @return SysEnvelope 
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		const SysEnvelope &GetVisualExtent() const;

		/**
		* @brief ��õ�ͼ�Ŀ��ӷ�Χ
		* @return SysEnvelope
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		SysEnvelope &GetVisualExtent();

		/**
		* @brief ���õ�ͼ�Ŀ��ӷ�Χ
		* @param[in] const SysEnvelope & env
		* @return void
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		void SetVisualExtent(const SysEnvelope & env);

		/**
		* @brief ��õ�ͼ��ȫͼ��Χ
		* @return SysEnvelope
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		const SysEnvelope &GetFullExtent() const;

		/**
		* @brief ��õ�ͼ��ȫͼ��Χ
		* @return SysEnvelope
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		SysEnvelope &GetFullExtent();

		/**
		* @brief ����ͼ���б�
		* @return void
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		void Reset();

		/**
		* @brief �����һ��ͼ��
		* @return SysMapLayer*
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		SysMapLayer* GetNextLayer() const;

		/**
		* @brief ��õ�ͼ�����ʱ��
		* @return SysGraphLayer*
		* @author �����
		* @date 2015��8��13��
		* @note 
		*/
		SysGraphLayer* GetBrowseLayer() const;

		/**
		* @brief ��ñ��ͼ��
		* @return SysGraphLayer*
		* @author �����
		* @date 2015��8��13��
		* @note 
		*/
		SysGraphLayer* GetMarkLayer() const;

	private:
		SysMapLayerList* m_pLayerList;	//ͼ���б�
		SysMapLayer* m_pCurLayer;		//��ǰͼ��
		SysEnvelope m_VisualExtent;		//��ǰ�ɼ��ĵ���Χ
		SysEnvelope m_FullExtent;		//ȫͼ�ĵ���Χ,��Ҫ��ͬһ���ռ�ο���	

		SysGraphLayer* m_pBrowseLayer;		//��ͼ������ͼ��	
		SysGraphLayer* m_pMarkLayer;		//����

		std::string m_strMapName;		//��ͼ������

		void RemoveAllMapLayers();

		/**
		* @brief ���¼���ȫͼ�ķ�Χ
		* @return void
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		void ReCaclFullExtent();
	};


}

#endif // end of __SYSMAP_H_8EE9B95C_8995_4B83_B6CD_A9747D717433__
