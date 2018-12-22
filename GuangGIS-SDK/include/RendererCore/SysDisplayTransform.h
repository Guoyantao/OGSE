/**
* @file              SysDisplayTransform.h
* @brief             ����������豸����֮���ת��
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��6��26��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSDISPLAYTRANSFORM_H_030BA0AA_9D1B_4E49_9ABF_DEAB0333BAFD__
#define __SYSDISPLAYTRANSFORM_H_030BA0AA_9D1B_4E49_9ABF_DEAB0333BAFD__

#include "SysDrawCommon.h"
#include "SysDrawDef.h"
#include "SysEnvelope.h"


namespace SysDraw
{

	class SYSDRAW_API SysDisplayTransform
	{
	public:
		/**
		* @brief SysDisplayTransform
		* @return 
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		SysDisplayTransform();

		/**
		* @brief SysDisplayTransform
		* @param[in] double dbMinx	//�ɼ�����Χ��Сx
		* @param[in] double dbMaxx
		* @param[in] double dbMiny
		* @param[in] double dbMaxy
		* @param[in] double dbMapUnitsPerPixel	//ÿ�����ش����ʵ�ʵ�����
		* @return 
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		SysDisplayTransform(
			double dbMinx,
			double dbMaxx,
			double dbMiny,
			double dbMaxy,
			double dbMapUnitsPerPixel);

		/**
		* @brief SysDisplayTransform
		* @param[in] SysDraw::SysEnvelope& VisualBounds �ɼ�����Χ
		* @param[in] double dbMapUnitsPerPixel ÿ�����ش����ʵ�ʵ�����
		* @return 
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		SysDisplayTransform(SysDraw::SysEnvelope& VisualBounds,double dbMapUnitsPerPixel);

		SysDisplayTransform(const SysDisplayTransform& OtherTran);

		SysDisplayTransform& operator=(const SysDisplayTransform& OtherTran);

		~SysDisplayTransform(void);

		void GetBounds(SysDraw::SysEnvelope& Bounds) const;

		void SetBounds(const SysDraw::SysEnvelope& Bounds);

		void GetVisibleBounds(SysDraw::SysEnvelope& Bounds) const;

		void SetVisibleBounds(SysDraw::SysEnvelope& Bounds);

		void SetVisibleBoundsExt(const SysDraw::SysEnvelope& Bounds);

		void GetExportFrame(RECT& rtFrame) const;

		void SetExportFrame(const RECT& rtFrame);

		void GetExportFrameSize(double& width,double& height) const;

		void SetExportFrameSize(double width,double height);

		void SetViewRect(const RECT& viewRect);

		/**
		* @brief SetMapUnitsPerPixel
		* @param[in] double dbMapUnitsPerPixel
		* @return void
		* @author �����
		* @date 2015��7��16��
		* @note 
		*/
		void SetMapUnitsPerPixel(double dbMapUnitsPerPixel);

		/**
		* @brief GetMapUnitsPerPixel
		* @return double
		* @author �����
		* @date 2015��7��16��
		* @note 
		*/
		double GetMapUnitsPerPixel() const;

		/**
		* @brief  �豸����ת��Ϊ��������
		* @param[in] long lX
		* @param[in] long lY
		* @param[out] double& x
		* @param[out] double& y
		* @return void 
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		void  ToMapPoint(long lX, long lY, double& x, double& y) const;

		/**
		* @brief �豸����ת��Ϊ��������
		* @param[in] const POINT& screenPoint ��Ļ����
		* @param[out] SysCoordinate &geoPoint ת����ĵ�������
		* @return void 
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		void  ToMapPoint(const POINT& screenPoint, SysCoordinate &geoPoint) const;

		/**
		* @brief ��Ļ��Χת��Ϊ����Χ
		* @param[in] const RECT& viewRect
		* @param[out] SysEnvelope& envGeo
		* @return void 
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		void  ToMapRect(const RECT& viewRect, SysEnvelope& envGeo) const;

		/**
		* @brief  ��������ת��Ϊ�豸����
		* @param[in] double dbGeoX
		* @param[in] double dbGeoY
		* @param[out] long& lX
		* @param[out] long& lY
		* @return long 
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		bool ToScreenPoint(double dbGeoX, double dbGeoY,long& lX, long& lY) const;

		/**
		* @brief ��������ת��Ϊ�豸����
		* @param[in] const SysCoordinate& geoPoint ��������
		* @param[out] POINT& screenPoint ת�������Ļ����
		* @return bool
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		bool ToScreenPoint(const SysCoordinate& geoPoint,POINT& screenPoint) const;

		/**
		* @brief ����Χת��Ϊ��Ļ��Χ
		* @param[in] const SysEnvelope &envGeo
		* @param[in] RECT &rectView
		* @return long 
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		bool ToScreenRect(const SysEnvelope &envGeo,RECT &rectView) const;

		/**
		* @brief ����Χת��Ϊ��Ļ��Χ
		* @param[in] const SysEnvelope &envGeo
		* @param[in] RECTD &rectView
		* @return bool
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		bool ToScreenRect(const SysEnvelope &envGeo,RECTD &rectView) const;

		/**
		* @brief ����ӿڵĿ��
		* @return long
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		long GetViewWidth() const;

		/**
		* @brief ����ӿڵĸ߶�
		* @return long
		* @author �����
		* @date 2015��6��26��
		* @note 
		*/
		long GetViewHeight() const;

	private:
		SysDraw::SysEnvelope  m_Bounds;						//ȫͼ�������귶Χ
		SysDraw::SysEnvelope  m_VisibleBounds;				//���ɼ����������귶Χ

		RECT	  m_ViewRect;						//�ӿڵķ�Χ����Ļ��ͼ������
		RECT	  m_DeviceFrame;					//���ɼ�������Χ���豸���귶Χ
		double	  m_dbDegree;						//��ת�Ƕ�
		double	  m_dbMapUnitsPerPixel;				//ÿ�����ش����ʵ�ʵ�����
		double	  m_dbPixelsPerMapUnit;				//ÿ����λ��������������ظ���
		double    m_dbDeviceWidth;
		double    m_dbDeviceHeight;

		long		m_lViewWidth;					//�ӿڵĿ��
		long		m_lViewHeight;					//�ӿڵĸ߶�

		void CalculateVisibleExtents();
	};

}

#endif // end of __SYSDISPLAYTRANSFORM_H_030BA0AA_9D1B_4E49_9ABF_DEAB0333BAFD__
