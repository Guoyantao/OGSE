#include "SysMapLayerList.h"
#include "SysMapLayer.h"


namespace SysDraw
{

	SysMapLayerList::SysMapLayerList(void)
	{
		m_vecMapLayers.clear();
		m_pCRS = NULL;
		m_pCurIter = m_vecMapLayers.begin();
		m_pEndIter = m_vecMapLayers.end();
	}

	SysMapLayerList::~SysMapLayerList(void)
	{
		RemoveAllMapLayers();
		if (m_pCRS != NULL)
		{
			delete m_pCRS;
			//SysSRS::CSpatialReference::DestroySpatialReference(m_pCRS);
			m_pCRS = NULL;
		}
	}

	bool SysMapLayerList::AddMapLayer(SysMapLayer* pMapLayer)
	{
		if (NULL == pMapLayer)
		{
			return false;
		}

		//�����ͼ��������һ����ͼ�㣬�򲻼���
		std::list<SysMapLayer *>::iterator iter = m_vecMapLayers.begin();
		std::list<SysMapLayer *>::iterator iterEnd = m_vecMapLayers.end();

		for (; iter != iterEnd; ++iter)
		{
			SysMapLayer* pCurLayer = *iter;
			if (pMapLayer->GetLayerName() == pCurLayer->GetLayerName())
			{
				iter = m_vecMapLayers.begin();
				return false;
			}
		}

		//��Ҫ��������ָ��ʼ
		iter = m_vecMapLayers.begin();

		if (iterEnd == iter)
		{
			//���Ϊ�գ����һ���ӽ����Ŀռ�ο�ϵͳʱ��ͼ�Ĳο�ϵͳ
			SysSRS::CSpatialReference* pTmSrs = pMapLayer->GetSpatialRef();
			if (pTmSrs != NULL)
			{
				std::string strWkt;
				pTmSrs->ExportToWkt(strWkt);
				m_pCRS = new SysSRS::CSpatialReference;
				if (!m_pCRS->ImportFromWkt(strWkt))
				{
					delete m_pCRS;
					m_pCRS = NULL;
				}
			}
		}

		/*for (; iter != iterEnd ; ++iter)
		{
			if (*iter == pMapLayer)
			{
				continue;
			}
				
		}*/


		m_vecMapLayers.push_back(pMapLayer);

		return true;
	}

	bool SysMapLayerList::RemoveMapLayer(const std::string& strName)
	{
		bool bFalg = false;
		std::list<SysMapLayer *>::iterator iter = m_vecMapLayers.begin();
		std::list<SysMapLayer *>::iterator iterEnd = m_vecMapLayers.end();

		for (; iter != iterEnd ; ++iter)
		{
			if ((*iter)->GetLayerName() != strName)
			{
				continue;
			}
			else
			{
				//����Ҫdelete��ͼ��
				SysMapLayer* pLayer = *iter;
				delete pLayer;
				pLayer = NULL;
				m_vecMapLayers.erase(iter);
				int nCount = m_vecMapLayers.size();
				if (0 == nCount)
				{
					if (m_pCRS != NULL)
					{
						//����������
						delete m_pCRS;
						m_pCRS = NULL;
					}
				}

				bFalg = true;
				break;
			}
		}

		return bFalg;
	}

	bool SysMapLayerList::RemoveMapLayer(const SysMapLayer* pLayer)
	{
		if (NULL == pLayer)
		{
			return false;
		}
		return RemoveMapLayer(pLayer->GetLayerName());

	}

	size_t SysMapLayerList::GetLayerCount() const
	{
		return m_vecMapLayers.size();
	}

	void SysMapLayerList::RemoveAllMapLayers()
	{
		//size_t nCount = m_vecMapLayers.size();

		std::list<SysMapLayer *>::iterator iter = m_vecMapLayers.begin();
		std::list<SysMapLayer *>::iterator iterEnd = m_vecMapLayers.end();

		for (; iter != iterEnd ; ++iter)
		{
			delete (*iter);
			(*iter) = NULL;
		}

		m_vecMapLayers.clear();
	}

	void SysMapLayerList::ResetIterator()
	{
		m_pCurIter = m_vecMapLayers.begin();
	}

	SysMapLayer* SysMapLayerList::GetNextLayer()
	{
		SysMapLayer* pLayer = NULL;
		if (m_pCurIter != m_pEndIter)
		{
			pLayer = *m_pCurIter;
			++m_pCurIter;
		}

		return pLayer;
		
	}

}
