/**
* @file              SysDisplayManager.h
* @brief             ��ʾ�����࣬��Ҫ�����ͼ����Ȳ���
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��12��15��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSDISPLAYMANAGER_H_02E5DADD_4E54_9DEB_FA46C715756E__
#define __SYSDISPLAYMANAGER_H_02E5DADD_4E54_9DEB_FA46C715756E__


namespace SysDraw
{

	class SysEnvelope;
	class SysMapLayer;

	class SysDisplayManager
	{
	public:
		SysDisplayManager(void);

		~SysDisplayManager(void);

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
		* @brief ���ŵ�ĳ����Χ��������Ŵ�,���ŵ�ȫͼ�Ȳ���
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
	};

}

#endif
