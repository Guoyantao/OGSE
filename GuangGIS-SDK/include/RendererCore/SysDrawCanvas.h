/**
* @file              SysDrawCanvas.h
* @brief             ��ͼ��ͼ����
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��7��10��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSDRAWCANVAS_H_9AA51398_0D4D_4776_B255_78D1D83A0FF8__
#define __SYSDRAWCANVAS_H_9AA51398_0D4D_4776_B255_78D1D83A0FF8__

#include "SysDrawCommon.h"

namespace SysDraw
{

	class SysMap;
	class SysMapLayer;
	class SysEnvelope;
	class SysRenderContext;

	class SYSDRAW_API SysDrawCanvas
	{
	public:
		explicit SysDrawCanvas(SysRenderContext* pRenderContext);
		~SysDrawCanvas(void);

		/**
		* @brief ���ڴ�С�ı亯��
		* @param[in] eUInt32 nType
		* @param[in] int cx ���
		* @param[in] int cy	�߶�
		* @return void
		* @author �����
		* @date 2015��7��10��
		* @note 
		*/
		void OnSize(eUInt32 nType, int cx, int cy);

		/**
		* @brief ���õ�ǰ����Ⱦ����
		* @param[in] SysRenderContext* pRenderContext ��ǰ����Ⱦ����
		* @return void
		* @author �����
		* @date 2015��7��10��
		* @note 
		*/
		void SetRenderContext(SysRenderContext* pRenderContext);

		/**
		* @brief ���Ƶ�ͼ
		* @param[in] SysMap* pMap ��ǰ��ͼ
		* @return void
		* @author �����
		* @date 2015��7��10��
		* @note 
		*/
		void DrawMap(SysMap* pMap) const;

		/**
		* @brief ���Ƶ�ͼ,�ֲ���Χ
		* @param[in] SysMap* pMap
		* @param[in] const SysEnvelope& envDraw ���Ƶķ�Χ
		* @return void
		* @author �����
		* @date 2015��7��10��
		* @note 
		*/
		void DrawMap(SysMap* pMap,const SysEnvelope& envDraw) const;

		/**
		* @brief ����ͼ��
		* @param[in] SysMap* pMap ��ǰ��ͼ
		* @param[in] SysMapLayer* pLayer ��ǰͼ��
		* @return void
		* @author �����
		* @date 2015��7��10��
		* @note 
		*/
		void DrawLayer(SysMap* pMap,SysMapLayer* pLayer) const;

		/**
		* @brief ����ͼ��,�ֲ���Χ
		* @param[in] SysMap* pMap
		* @param[in] SysMapLayer* pLayer
		* @param[in] const SysEnvelope& envDraw ���Ƶķ�Χ
		* @return void
		* @author �����
		* @date 2015��7��10��
		* @note 
		*/
		void DrawLayer(SysMap* pMap,SysMapLayer* pLayer,const SysEnvelope& envDraw) const;

		/**
		* @brief 
		* @param[in] SysMap* pMap
		* @return void
		* @author �����
		* @date 2015��9��17��
		* @note 
		*/
		void DrawGraphicLayers(SysMap* pMap) const;

		/**
		* @brief ���Ƶ�ͼ������ͼ��
		* @param[in] SysMap* pMap
		* @return void
		* @author �����
		* @date 2015��7��10��
		* @note 
		*/
		void DrawBrowseLayer(SysMap* pMap) const;

		/**
		* @brief ���Ʊ���
		* @param[in] SysMap* pMap
		* @param[in] bool bDrawAll
		* @param[in] int nIndex
		* @return void
		* @author �����
		* @date 2015��8��13��
		* @note 
		*/
		void DrawMarkLayer(SysMap* pMap,bool bDrawAll = true, int nIndex = -1) const;

		/**
		* @brief ��ÿͻ������
		* @return int
		* @author �����
		* @date 2015��7��10��
		* @note 
		*/
		int GetViewWidth() const;

		/**
		* @brief ��ÿͻ����߶�
		* @return int
		* @author �����
		* @date 2015��7��10��
		* @note 
		*/
		int GetViewHeight() const;

	private:
		SysRenderContext *m_pRenderContext;
		int m_nViewWidth;					//�ͻ������
		int m_nViewHeight;					//�ͻ����߶�
	};

}

#endif // end of __SYSDRAWCANVAS_H_9AA51398_0D4D_4776_B255_78D1D83A0FF8__
