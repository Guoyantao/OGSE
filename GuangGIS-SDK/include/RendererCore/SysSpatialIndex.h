/**
* @file              SysSpatialIndex.h
* @brief             �ռ�����
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��10��16��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSSPATIALINDEX_H_58054C27_FF11_4F84_B16B_D4CB5AF51176__
#define __SYSSPATIALINDEX_H_58054C27_FF11_4F84_B16B_D4CB5AF51176__

#include "SysDrawCommon.h"

namespace SpatialIndex
{
	class IStorageManager;
	class ISpatialIndex;
	class Region;
	class Point;

	namespace StorageManager
	{
		class IBuffer;
	}
}

namespace SysDraw
{
	class SysFeature;
	class SysEnvelope;
	class SysCoordinate;

	class SYSDRAW_API SysSpatialIndex
	{
	public:
		/**
		* @brief �����ڴ�ռ�����
		* @param[in] void
		* @return 
		* @author �����
		* @date 2015��11��18��
		* @note 
		*/
		SysSpatialIndex(void);

		/**
		* @brief �����ļ��ռ�����
		* @param[in] const std::string& strFileName
		* @param[in] bool bCreateNewIndex = false
		* @return explicit
		* @author �����
		* @date 2015��10��18��
		* @note 
		*/
		explicit SysSpatialIndex(const std::string& strFileName,bool bCreateNewIndex = false);

		~SysSpatialIndex(void);

		/**
		* @brief ��Ҫ�ؼ��뵽������
		* @param[in] SysFeature* pFeature
		* @return bool
		* @author �����
		* @date 2015��10��18��
		* @note 
		*/
		bool InsertFeature( SysFeature* pFeature );

		/**
		* @brief ��������ɾ��Ҫ��
		* @param[in] SysFeature* pFeature
		* @return bool
		* @author �����
		* @date 2015��10��18��
		* @note 
		*/
		bool DeleteFeature( SysFeature* pFeature );

		/**
		* @brief ���β�ѯ
		* @param[in] const SysEnvelope& rect
		* @return std::vector<long>
		* @author �����
		* @date 2015��10��18��
		* @note 
		*/
		std::vector<long> IntersectQuery( const SysEnvelope& rect ) const;

		/**
		* @brief ���ѯ
		* @param[in] double dbX
		* @param[in] double dbY
		* @return std::vector<long>
		* @author �����
		* @date 2015��10��18��
		* @note 
		*/
		std::vector<long> PointLocationQuery(double dbX,double dbY) const;

		/**
		* @brief ���ѯ
		* @param[in] const SysCoordinate& point
		* @return std::vector<long>
		* @author �����
		* @date 2015��10��18��
		* @note 
		*/
		std::vector<long> PointLocationQuery(const SysCoordinate& point) const;

		/**
		* @brief ���ڽ���ѯ
		* @param[in] double dbX
		* @param[in] double dbY
		* @param[in] int nNeighbors
		* @return std::vector<long>
		* @author �����
		* @date 2015��11��11��
		* @note 
		*/
		std::vector<long> NearestNeighbor( double dbX, double dbY, int nNeighbors ) const;

		/**
		* @brief ���ڽ���ѯ
		* @param[in]  const SysCoordinate& point
		* @param[in] int nNeighbors
		* @return std::vector<long>
		* @author �����
		* @date 2015��10��18��
		* @note 
		*/
		std::vector<long> NearestNeighbor( const SysCoordinate& point, int nNeighbors ) const;

		/**
		* @brief �������������ļ���
		* @return bool
		* @author �����
		* @date 2015��11��18��
		* @note 
		*/
		bool SaveToDisk() const;


	private:

		SpatialIndex::IStorageManager* m_pStorageManager;			//�洢������

		SpatialIndex::StorageManager::IBuffer* m_pStorage;		//������������

		SpatialIndex::ISpatialIndex* m_pRTree;					//�����е�R��

		std::string m_strIndexFile;								//�ռ������ļ�

		//void* m_pStorageManager;			//�洢������

		//void* m_pStorage;		//������������

		//void* m_pRTree;					//�����е�R��
	};

}

#endif // end of __SYSSPATIALINDEX_H_58054C27_FF11_4F84_B16B_D4CB5AF51176__
