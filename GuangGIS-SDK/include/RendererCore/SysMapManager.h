/**
* @file              SysMapManager.h
* @brief             ��ͼ�����࣬��Ҫʵ�ּ������ݣ���ͼ����Ȳ���
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��7��15��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSMAPMANAGER_H_02E5DADD_44B5_4E54_9DEB_FA46C715756E__
#define __SYSMAPMANAGER_H_02E5DADD_44B5_4E54_9DEB_FA46C715756E__

#include "SysDrawCommon.h"

//ȫ�ֵ�ͼ������
	#if defined(pManager)
		#undef pManager
	#endif
#define pManager ((SysDraw::SysMapManager *)(SysDraw::SysMapManager::GetInstance()))

struct BackImagePara		//����ͼ���������
{
	int m_nTranspancy;
	int m_nContrast;
	float m_fBrightNess;
};

namespace SysDraw
{
	class SysMap;
	class SysDrawCanvas;
	class SysRenderContext;
	class SysDisplayTransform;
	class SysRasterLayer;
	class SysFeatureLayer;
	class SysEnvelope;
	class SysMapLayer;

	//��ͼˢ����ͼ�Ļص���������
	typedef void (* UPDATE_FUN)(void*);

	class SYSDRAW_API SysMapManager
	{
	public:

		/**
		* @brief ���Ψһʵ��
		* @return SysMapManager*
		* @author �����
		* @date 2015��7��15��
		* @note 
		*/
		static SysMapManager* GetInstance();

		/**
		* @brief ��ʼ��
		* @return void
		* @author �����
		* @date 2015��7��15��
		* @note 
		*/
		void InitDraw();

		/**
		* @brief ��õ�ǰ��ͼ
		* @return SysMap* ��ǰ��ͼָ��
		* @author �����
		* @date 2015��7��15��
		* @note 
		*/
		SysMap* GetCurrentMap() const;

		/**
		* @brief ��õ�ǰ��ͼ����
		* @return int ���ص�ǰ��ͼ������û���ҵ��򷵻�-1
		* @author �����
		* @date 2015��7��22��
		* @note 
		*/
		int GetCurrentMapIndex() const;

		/**
		* @brief ���õ�ǰ��ͼ
		* @param[in] const SysMap* pMap ��ͼָ��
		* @return void
		* @author �����
		* @date 2015��7��15��
		* @note 
		*/
		void SetCurrentMap(const SysMap* pMap);

		/**
		* @brief GetDisplayTran
		* @return SysDisplayTransform&
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		SysDisplayTransform& GetDisplayTran() const;

		/**
		* @brief ��ͼ�ӿ�ӳ��
		* @param[in] int x0
		* @param[in] int y0
		* @param[in] int cx
		* @param[in] int cy
		* @return void
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		void ViewPort(int x0,int y0,int cx,int cy) /*const*/;

		/**
		* @brief StartDraw
		* @return void
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		void StartDraw(SysMap* pMap) /*const*/;

		/**
		* @brief StartDrawLayer
		* @param[in] SysMapLayer* pLayer
		* @return void
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		void StartDrawLayer(SysMapLayer* pLayer) /*const*/;

		/**
		* @brief ���Ʊ���
		* @param[in] bool bBackGround
		* @return void
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		void DrawViewGround(bool bBackGround) const;

		/**
		* @brief ��դ��Ӱ��
		* @param[in] std::string strFileName
		* @param[in] DrawProgressFunc ProgressFunc = NULL
		* @param[in] void* pProgressArg = NULL
		* @return SysRasterLayer*
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		SysRasterLayer* OpenRasterFile(std::string strFileName,DrawProgressFunc ProgressFunc = NULL, void* pProgressArg = NULL);

		/**
		* @brief ��ʸ������
		* @param[in] std::string strFileName
		* @return SysFeatureLayer*
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		SysFeatureLayer* OpenFeatureFile(std::string strFileName);

		/**
		* @brief ���ӵ�ͼ
		* @param[in] SysMap* pMap
		* @return bool
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		bool AddMap(SysMap* pMap);

		/**
		* @brief �ƶ���ͼ
		* @param[in]  double dx
		* @param[in] double dy
		* @return void
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		void MoveContent( double dx, double dy );

		/**
		* @brief ���ŵ�ͼ
		* @param[in]  int delta
		* @param[in] double x
		* @param[in] double y
		* @return void
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		void ZoomContent( int delta, double x, double y );

		/**
		* @brief ���ŵ�ĳ����Χ��������Ŵ�
		* @param[in] const SysEnvelope& envNew
		* @return void
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		void ZoomInContent(const SysEnvelope& envNew);

		/**
		* @brief ������С
		* @param[in] const SysEnvelope& envNew ��ǰ��ͼ�ķ�Χ
		* @param[in] double x ��ǰ��������ĵ�
		* @param[in] double y
		* @return void
		* @author �����
		* @date 2015��8��5��
		* @note 
		*/
		void ZoomOutContent(const SysEnvelope& envNew,double x,double y);

		/**
		* @brief ���ŵ�ȫͼ
		* @return void
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		void ZoomToWholeExtent();

		/**
		* @brief ���ŵ�ͼ��
		* @param[in] const SysMapLayer* pMapLayer
		* @return void
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		void ZoomToLayer(const SysMapLayer* pMapLayer);

		/**
		* @brief ���ŵ���ǰդ��ͼ��ͬ���ķֱ��ʣ���1:1��ʾ
		* @param[in] const SysMapLayer* pMapLayer
		* @return void
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		void ZoomActualSize(const SysMapLayer* pMapLayer);

		/**
		* @brief ˢ�µ�ͼ��ͼ
		* @param[in] bool bReDraw �Ƿ��ػ��ͼ
		* @param[in] bool bCopyBackGround �Ƿ񽫻�����ɵ�Ӱ��������
		* @return void
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		void UpDateView(bool bReDraw = true,bool bCopyBackGround = true, bool bRefresh = false);

		void UpDateView(void *pParamter,bool bReDraw = true,bool bCopyBackGround = true, bool bRefresh = false);

		void RefreshView(int nX, int nY, double dbScale = 1.0) const;

		/**
		* @brief ���õ�ͼˢ�µĻص�����
		* @param[in] UPDATE_FUN pFun
		* @param[in] void* pPara
		* @return void
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		void SetUpdateFunc(UPDATE_FUN pFun,void* pPara);

		void AddUpdateFunc(UPDATE_FUN pFun,void* pPara);

		void SetCopyStartPoint(int nXtartX,int nStartY);

		void DrawFrameBuf();

		void CopyFrameBuf();

		void CreateFrameBuf();

		void InitFrameBuf();

		void SetBackImagePara(bool bAdjustBack,const BackImagePara& backPara);

		static void InitMapTool();

		/**
		* @brief �����Ƿ��ػ�ı��
		* @param[in] bool bRedraw
		* @return void
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		void SetRedrawFlag(bool bRedraw);

		/**
		* @brief �����Ƿ�ʹ�ñ���ͼ��ı��
		* @param[in] bool bCopyBackGround
		* @return void
		* @author �����
		* @date 2015��7��18��
		* @note 
		*/
		void SetCopyBackGroundFlag(bool bCopyBackGround);

		void SetUseDrawView(bool bUseDrawView);

		void SetDarwView(const SysEnvelope& envView);

		void CopyBackToFront() const;

	private:
		SysMapManager(void);
		~SysMapManager(void);
		SysMapManager(const SysMapManager& rhs);
		SysMapManager& operator = (const SysMapManager& rhs);

		static SysMapManager* m_pInstance;

		int m_nMapCount;		//��ͼ����
		SysMap** m_poMaps;		//��ͼ����
		SysMap* m_pCurrentMap;	//��ǰ��ͼ

		SysDrawCanvas* m_pCanvas;			//����
		SysRenderContext* m_pRenderContex;		//��Ⱦ������

		//���ڴ�С�Ȳ���
		mutable int m_nStartX;
		mutable int m_nStartY;
		mutable int m_nSizeX;
		mutable int m_nSizeY;

		//���Ʊ������½ǿ������
		mutable int m_nCopyStartX;
		mutable int m_nCopyStartY;

		bool m_bReDraw;			//�Ƿ��ػ��ͼ
		bool m_bCopyBack;		//�Ƿ񿽱���̨����
		int m_nTransparency;	//���Ʊ���͸���ȣ�0-255��

		BackImagePara *m_pBackImgPara;		//����ͼ��������
		bool m_bAdjustBack;					//�Ƿ��������

		unsigned char* m_pDrawCache;			//��ͼ�Ļ���
		unsigned char* m_pDrawCacheTmp;

		unsigned int m_nBackTexture;		//����ͼ������
		unsigned int m_nFrameBuffer;		//֡������
		unsigned int m_nRenderBuffer;		//��Ⱦ������
		unsigned int m_nStencilBuffer;		//����ģ�建����

		UPDATE_FUN m_pFun;					//ˢ����ͼ�ص�����
		void* m_pPara;						//ˢ����ͼ�Ĳ���

		std::vector<UPDATE_FUN> m_vecFun;					//ˢ����ͼ�ص���������
		std::vector<void*> m_vecPara;						//ˢ����ͼ�Ĳ�������

		bool m_bUseDrawView;				//�Ƿ�ָ����������
		SysEnvelope *m_pDrawView;			//ָ���Ļ�������

		bool m_bRefresh;	

		void Init();

		void UnInit();

		void UpdateVisualExtent(const SysEnvelope& envNew);
	};

}

#endif // end of __SYSMAPMANAGER_H_02E5DADD_44B5_4E54_9DEB_FA46C715756E__
