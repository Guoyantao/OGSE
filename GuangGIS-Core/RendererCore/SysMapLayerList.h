/**
* @file              SysMapLayerList.h
* @brief             ͼ���б���Ҫ����ͼ�����
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��7��12��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSMAPLAYERLIST_H_6BB9FD79_8671_4CB6_ACB6_ABA52882410B__
#define __SYSMAPLAYERLIST_H_6BB9FD79_8671_4CB6_ACB6_ABA52882410B__

#include <list>
#include "SysDrawCommon.h"

namespace SysSRS
{
	class CSpatialReference;
}

namespace SysDraw
{

	class SysMapLayer;

	typedef std::list<SysMapLayer *> LayerList;

	class SysMapLayerList
	{
	public:
		SysMapLayerList(void);
		~SysMapLayerList(void);

		bool AddMapLayer(SysMapLayer* pMapLayer);

		bool RemoveMapLayer(const std::string& strName);

		bool RemoveMapLayer(const SysMapLayer* pLayer);

		size_t GetLayerCount() const;

		void RemoveAllMapLayers();

		SysSRS::CSpatialReference* GetSpatialRef() const
		{
			return m_pCRS;
		}

		void ResetIterator();

		SysMapLayer* GetNextLayer();

	private:
		LayerList m_vecMapLayers;
		SysSRS::CSpatialReference* m_pCRS;			//��ͼ�Ŀռ�ο�ϵͳ

		LayerList::iterator m_pCurIter;
		LayerList::iterator m_pEndIter;
	};

}

#endif // end of __SYSMAPLAYERLIST_H_6BB9FD79_8671_4CB6_ACB6_ABA52882410B__
