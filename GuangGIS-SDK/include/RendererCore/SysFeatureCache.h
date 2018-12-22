/**
* @file              SysFeatureCache.h
* @brief             ʸ��Ҫ�صĻ���
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��11��17��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSFEATURECACHE_H_96AC063E_EE20_4F3F_80BC_8B4A01160F01__
#define __SYSFEATURECACHE_H_96AC063E_EE20_4F3F_80BC_8B4A01160F01__

#include "SysDrawCommon.h"

namespace SysDraw
{

	class SysFeature;

	class SYSDRAW_API SysFeatureCache
	{
	public:
		SysFeatureCache(void);

		~SysFeatureCache(void);

		/**
		* @brief ��û�������Ҫ�ظ���
		* @return int
		* @author �����
		* @date 2015��11��17��
		* @note 
		*/
		int GetMaxFeatureCount() const;

		/**
		* @brief ���û�������Ҫ�ظ���
		* @param[in] int nMaxCount
		* @return void
		* @author �����
		* @date 2015��11��17��
		* @note 
		*/
		void SetMaxFeatureCount(int nMaxCount);

		/**
		* @brief ����һ��FID��Ҫ�ص�������
		* @param[in] long nFid
		* @param[in] SysFeature *pFeature
		* @return bool
		* @author �����
		* @date 2015��11��17��
		* @note 
		*/
		bool InsertFeature(long nFid,SysFeature *pFeature);

		/**
		* @brief �ӻ�����ɾ��FIDΪnFid��Ҫ�أ�������Ҫ����ռ���ڴ�
		* @param[in] long nFid
		* @return bool
		* @author �����
		* @date 2015��11��17��
		* @note 
		*/
		bool EraseFeature(long nFid);

		/**
		* @brief ����FIDΪnFid��Ҫ���Ƿ��ڻ�����,����ɹ�pFeature�����ص�Ҫ��
		* @param[in] long nFid
		* @param[out] SysFeature*& pFeature
		* @return bool
		* @author �����
		* @date 2015��11��17��
		* @note 
		*/
		bool FindFeature(long nFid,SysFeature*& pFeature) const;

	private:
		typedef std::map<long,SysFeature *> mapFeatureCache;		//ʸ��Ҫ�ػ���
		mapFeatureCache m_mapFeaCache;								//ʸ������map
		int				m_nMaxCount;								//���Ҫ�ظ���
	};

}

#endif // end of __SYSFEATURECACHE_H_96AC063E_EE20_4F3F_80BC_8B4A01160F01__
