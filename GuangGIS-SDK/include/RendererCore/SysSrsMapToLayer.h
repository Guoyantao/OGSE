/**
* @file              SysSrsMapToLayer.h
* @brief             ��ͼ��SRS��ͼ���SRS֮���໥ת��
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��11��16��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSSRSMAPTOLAYER_H_318B24D5_439B_45CB_A341_71138322AB32__
#define __SYSSRSMAPTOLAYER_H_318B24D5_439B_45CB_A341_71138322AB32__

#include "SysDrawCommon.h"

namespace SysSRS
{
	class CCoordTransformation;
}

namespace SysDraw
{
	class SysMap;
	class SysMapLayer;
	class SysEnvelope;

	class SYSDRAW_API SysSrsMapToLayer
	{
	public:
		/**
		* @brief ��ͼ�ľ���ת��Ϊͼ��ľ���
		* @param[in] SysMap* pMap
		* @param[in] SysMapLayer* pLayer
		* @param[out] SysEnvelope& envOut
		* @return void
		* @author �����
		* @date 2015��8��20��
		* @note 
		*/
		static void MapToLayerExtent(SysMap* pMap,SysMapLayer* pLayer,SysEnvelope& envOut);

		/**
		* @brief ��ͼ�ľ���ת��Ϊͼ��ľ���
		* @param[in] SysMap* pMap
		* @param[in] const SysEnvelope& envIn
		* @param[in] SysMapLayer* pLayer
		* @param[in] SysEnvelope& envOut
		* @return void
		* @author �����
		* @date 2015��11��16��
		* @note 
		*/
		static void MapToLayerExtent(SysMap* pMap,const SysEnvelope& envIn,SysMapLayer* pLayer,SysEnvelope& envOut);

		/**
		* @brief ͼ��ľ���ת��Ϊ��ͼ�ľ���
		* @param[in] SysMap* pMap
		* @param[in] SysMapLayer* pLayer
		* @param[out] SysEnvelope& envOut
		* @return void
		* @author �����
		* @date 2015��8��20��
		* @note 
		*/
		static void LayerToMapExtent(SysMap* pMap,SysMapLayer* pLayer,SysEnvelope& envOut);

		/**
		* @brief ͼ��ľ���ת��Ϊ��ͼ�ľ���
		* @param[in] SysMap* pMap
		* @param[in] const SysEnvelope& envIn
		* @param[in] SysMapLayer* pLayer
		* @param[in] SysEnvelope& envOut
		* @return void
		* @author �����
		* @date 2015��11��16��
		* @note 
		*/
		static void LayerToMapExtent(SysMap* pMap,const SysEnvelope& envIn, SysMapLayer* pLayer,SysEnvelope& envOut);

		static void TransExtent(SysSRS::CCoordTransformation* pTran,SysEnvelope& envOut);
	};

}


#endif // end of __SYSSRSMAPTOLAYER_H_318B24D5_439B_45CB_A341_71138322AB32__
