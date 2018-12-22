#include "SysMap.h"
#include "SysMapLayerList.h"
#include "SysMapLayer.h"
#include "SysGraphLayer.h"



namespace SysDraw
{

	/*SysMap::SysMap(void)
	{
		
	}*/

	SysMap::SysMap(const std::string& strMapName)
	{
		m_pLayerList = new SysMapLayerList;
		m_VisualExtent.SetNull();
		m_FullExtent.SetNull();

		m_strMapName = strMapName;

		m_pCurLayer = NULL;
		m_pBrowseLayer = new SysGraphLayer(_T("browse_layer"));
		m_pMarkLayer = new SysGraphLayer(_T("MarkLayer"));
	}

	SysMap::~SysMap(void)
	{

		if (m_pLayerList != NULL)
		{
			delete m_pLayerList;
			m_pLayerList = NULL;
		}

		if (m_pBrowseLayer != NULL)
		{
			delete m_pBrowseLayer;
			m_pBrowseLayer = NULL;
		}

		if (m_pMarkLayer != NULL)
		{
			delete m_pMarkLayer;
			m_pMarkLayer = NULL;
		}

		m_VisualExtent.SetNull();
		m_FullExtent.SetNull();
		m_pCurLayer = NULL;
		m_strMapName.clear();
	}

	void SysMap::AddMapLayer(SysMapLayer* pMapLayer)
	{
		if (NULL == pMapLayer)
		{
			return;
		}

		if (!m_pLayerList->AddMapLayer(pMapLayer))
		{
			return;
		}

		//��ǰ��ͼ��û��ͼ��ʱ���¼ӽ�����ͼ�������Ϊ��ǰͼ��
		if (1 == GetLayerCount())
		{
			m_VisualExtent.SetNull();
			m_pCurLayer = pMapLayer;
		}

		SysEnvelope CurEnv;

		//���õ�ǰͼ�㣬�Լ���ǰ��ʾ��Χ��ȫͼ��ʾ��Χ
		SysSRS::CSpatialReference* pMapSrs = GetSpatialRef();
		if (pMapSrs == NULL)
		{
			m_VisualExtent = pMapLayer->GetLayerExtent();
			CurEnv = m_VisualExtent;
		}

		else if (pMapSrs != NULL )
		{
			pMapSrs->MorphToESRI();
			SysSRS::CSpatialReference* pLyrSrs = pMapLayer->GetSpatialRef();
			if (pLyrSrs == NULL)
			{
				CurEnv = pMapLayer->GetLayerExtent();
				m_VisualExtent = CurEnv;
			}
			else if (pLyrSrs != NULL)
			{
				pLyrSrs->MorphToESRI();
				if (pLyrSrs->IsSame(*pMapSrs))		//һ����ֱ�ӽ���Χ��ֵ,��������ָ������أ�������������������
				{
					CurEnv = pMapLayer->GetLayerExtent();
					if (1 == m_pLayerList->GetLayerCount())
					{
						m_VisualExtent.ExpandToInclude(CurEnv);
					}
				}

				else if (!pLyrSrs->IsSame(*pMapSrs))		//��̬ͶӰ
				{
					SysSRS::CCoordTransformation ForwardTran;
					ForwardTran.InitCoordTransform(pLyrSrs,pMapSrs);
					SysSRS::CCoordTransformation InverseTran; 
					InverseTran.InitCoordTransform(pMapSrs,pLyrSrs);

					pMapLayer->SetForwardCoordTran(pLyrSrs,pMapSrs);
					pMapLayer->SetInverseCoordTran(pLyrSrs,pMapSrs);

					//��ͶӰת����ķ�Χת��Ϊ��ǰ�ĵ�ͼ��Χ����Ϊ��ǰ��ʾ��Χ
					SysEnvelope env = pMapLayer->GetLayerExtent();
					double dbExtent[4];
					dbExtent[0] = env.minX;
					dbExtent[1] = env.maxX;
					dbExtent[2] = env.minY;
					dbExtent[3] = env.maxY;
					geos::geom::Envelope envResult;
					ForwardTran.TransformBoundingBox(dbExtent,envResult);
					CurEnv.minX = envResult.getMinX();
					CurEnv.maxX = envResult.getMaxX();
					CurEnv.minY = envResult.getMinY();
					CurEnv.maxY = envResult.getMaxY();
				}
			}

			//����ȫͼ��Χ
			m_FullExtent.ExpandToInclude(CurEnv);

			double dbXSpan = fabs(m_FullExtent.maxX - m_FullExtent.minX)/60.0;
			double dbYSpan = fabs(m_FullExtent.maxY - m_FullExtent.minY)/60.0;

			m_FullExtent.minX -= dbXSpan;
			m_FullExtent.maxX += dbXSpan;
			m_FullExtent.minY -= dbYSpan;
			m_FullExtent.maxY += dbYSpan;
		}
	}

	inline size_t SysMap::GetLayerCount() const
	{
		return m_pLayerList->GetLayerCount();
	}

	const SysMapLayer* SysMap::GetCurrentLayer() const
	{
		return m_pCurLayer;
	}

	SysMapLayer* SysMap::GetCurrentLayer()
	{
		return m_pCurLayer;
	}

	void SysMap::SetCurrentLayer(const SysMapLayer* pLayer)
	{
		m_pCurLayer = (SysMapLayer*)pLayer;
	}

	bool SysMap::RemoveMapLayer(const std::string& strName)
	{
		return m_pLayerList->RemoveMapLayer(strName);

		//if (m_pLayerList->RemoveMapLayer(pLayer))
		//{
		//	if (pLayer == m_pCurLayer)		//���ɾ����ͼ��ʱ��ǰͼ�㣬�ͽ���һ��ͼ������Ϊ��ǰͼ��
		//	{
		//		m_pCurLayer = GetNextLayer();
		//	}

		//	return true;
		//}

		//return false;
	}

	bool SysMap::RemoveMapLayer(const SysMapLayer* pLayer)
	{
		if (m_pLayerList->RemoveMapLayer(pLayer))
		{
			if (pLayer == m_pCurLayer)		//���ɾ����ͼ��ʱ��ǰͼ�㣬�ͽ���һ��ͼ������Ϊ��ǰͼ��
			{
				m_pCurLayer = GetNextLayer();
			}

			//����ȫͼ��Χ
			ReCaclFullExtent();

			return true;
		}

		return false;
	}

	void SysMap::RemoveAllMapLayers()
	{
		m_pLayerList->RemoveAllMapLayers();
		m_VisualExtent.SetNull();
		m_FullExtent.SetNull();

		m_pCurLayer = NULL;

		//ReCaclFullExtent();
	}

	SysSRS::CSpatialReference* SysMap::GetSpatialRef() const
	{
		return m_pLayerList->GetSpatialRef();
	}

	const SysEnvelope& SysMap::GetVisualExtent() const
	{
		return m_VisualExtent;
	}

	SysEnvelope& SysMap::GetVisualExtent()
	{
		return m_VisualExtent;
	}

	void SysMap::SetVisualExtent(const SysEnvelope & env)
	{
		m_VisualExtent = env;
	}

	const SysEnvelope &SysMap::GetFullExtent() const
	{
		return m_FullExtent;
	}

	SysEnvelope& SysMap::GetFullExtent()
	{
		return m_FullExtent;
	}

	void SysMap::ReCaclFullExtent()
	{
		Reset();

		m_FullExtent.SetNull();

		//��Ҫ���Ƕ�̬ͶӰ
		SysSRS::CSpatialReference* pMapSrs = GetSpatialRef();

		SysMapLayer* pLayer = NULL;
		while ( (pLayer = GetNextLayer()) != NULL)
		{
			SysEnvelope lyrEnv = pLayer->GetLayerExtent();

			//���û��ͶӰ��ֱ�ӿ��ž���
			if (NULL == pMapSrs)
			{
				m_FullExtent.ExpandToInclude(lyrEnv);
			}

			//�����ͶӰ�����⿼��
			else if (NULL != pMapSrs)
			{
				SysSRS::CSpatialReference* pLyrSrs = pLayer->GetSpatialRef();

				//���ͼ����ͶӰ����ֱ�Ӽ���
				if (NULL == pLyrSrs)
				{
					m_FullExtent.ExpandToInclude(lyrEnv);
				}

				else if (NULL != pLyrSrs)
				{
					pLyrSrs->MorphToESRI();
					pMapSrs->MorphToESRI();
					if (pLyrSrs->IsSame(*pMapSrs))
					{
						m_FullExtent.ExpandToInclude(lyrEnv);
					}

					else
					{
						//pLyrSrs->TransformRect(*pMapSrs,)
						SysSRS::CCoordTransformation ForwardTran;
						ForwardTran.InitCoordTransform(pLyrSrs,pMapSrs);

						double dbExtent[4];
						dbExtent[0] = lyrEnv.minX;
						dbExtent[1] = lyrEnv.maxX;
						dbExtent[2] = lyrEnv.minY;
						dbExtent[3] = lyrEnv.maxY;
						geos::geom::Envelope envResult;
						ForwardTran.TransformBoundingBox(dbExtent,envResult);

						SysEnvelope CurEnv;
						CurEnv.minX = envResult.getMinX();
						CurEnv.maxX = envResult.getMaxX();
						CurEnv.minY = envResult.getMinY();
						CurEnv.maxY = envResult.getMaxY();

						m_FullExtent.ExpandToInclude(CurEnv);
					}
					
				}//else if NULL != pLyrSrs
			}//else if (NULL != pMapSrs)
			
		}//while

		double dbXSpan = fabs(m_FullExtent.maxX - m_FullExtent.minX)/60.0;
		double dbYSpan = fabs(m_FullExtent.maxY - m_FullExtent.minY)/60.0;

		m_FullExtent.minX -= dbXSpan;
		m_FullExtent.maxX += dbXSpan;
		m_FullExtent.minY -= dbYSpan;
		m_FullExtent.maxY += dbYSpan;
		
	}

	void SysMap::Reset()
	{
		m_pLayerList->ResetIterator();
	}

	SysMapLayer* SysMap::GetNextLayer() const
	{
		return m_pLayerList->GetNextLayer();
	}

	SysGraphLayer* SysMap::GetBrowseLayer() const
	{
		return m_pBrowseLayer;
	}

	SysGraphLayer* SysMap::GetMarkLayer() const
	{
		return m_pMarkLayer;
	}

	bool SysMap::FindMapLayer( const SysMapLayer* pLayer ) const
	{
		m_pLayerList->ResetIterator();
		SysMapLayer* pMapLayer = NULL;

		while ((pMapLayer = m_pLayerList->GetNextLayer()) != NULL)
		{
			if (pLayer == pMapLayer)
			{
				return true;
			}
		}

		return false;
	}

	bool SysMap::FindMapLayer( const std::string& strName ) const
	{
		m_pLayerList->ResetIterator();
		SysMapLayer* pMapLayer = NULL;

		while ((pMapLayer = m_pLayerList->GetNextLayer()) != NULL)
		{
			if (strName == pMapLayer->GetLayerName())
			{
				return true;
			}
		}

		return false;
	}

	std::string SysMap::GetMapName() const
	{
		return m_strMapName;
	}

}
