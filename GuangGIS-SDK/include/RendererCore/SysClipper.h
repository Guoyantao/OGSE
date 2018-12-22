/**
* @file              SysClipper.h
* @brief             �ü�������Ҫ���ڴ��ڲü�
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��10��19��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSCLIPPER_H_88DD2E77_D966_497A_8091_363AECAEED31__
#define __SYSCLIPPER_H_88DD2E77_D966_497A_8091_363AECAEED31__

#include "SysDrawCommon.h"

namespace SysDraw
{
	class SysEnvelope;
	class SysGeometry;
	class SysPolygon;
	class SysCoordinate;

	class SYSDRAW_API SysClipper
	{
	public:
		SysClipper(void);

		~SysClipper(void);

		/**
		* @brief ���һ�����괮��ָ�����������㣬����ֵ
		* @param[in] ysCoordinate * poPoints
		* @param[in] int nPointCount
		* @param[in] double dfDistance
		* @param[in] SysCoordinate * pPoint
		* @param[in] double *pAngle
		* @return void
		* @author �����
		* @date 2015��10��22��
		* @note 
		*/
		static void GetValuePoint( 
								SysCoordinate * poPoints, 
								int nPointCount, 
								double dfDistance, 
								SysCoordinate * pPoint ,
								double *pAngle);

		static double GetLineStringLength(SysCoordinate * poPoints, int nPointCount);

		/**
		* @brief ���߲ü�
		* @param[in] ysCoordinate* poPoints
		* @param[in] int nCount
		* @param[in] SysEnvelope& rect
		* @param[out] std::vector<int> &vecIndex
		* @param[out] std::vector<SysCoordinate> &outPoints
		* @return bool
		* @author �����
		* @date 2015��10��19��
		* @note 
		*/
		static bool PolylineClip(
								SysCoordinate* poPoints,
								int nCount,SysEnvelope& rect,
								std::vector<int> &vecIndex,
								std::vector<SysCoordinate> &outPoints);

		/**
		* @brief ���߲ü�
		* @param[in] ouble* poCoords xyxy����
		* @param[in] int nCount
		* @param[in] SysEnvelope& rect
		* @param[out] std::vector<int> &vecIndex
		* @param[out] std::vector<double> &outPoints
		* @return bool
		* @author �����
		* @date 2015��10��19��
		* @note 
		*/
		static bool PolylineClipEx(
								double* poCoords,
								int nCount,SysEnvelope& rect,
								std::vector<int> &vecIndex,
								std::vector<double> &outPoints);

		/**
		* @brief ����βü�
		* @param[in] SysPolygon* pPolygon
		* @param[in] SysEnvelope& rect
		* @return SysGeometry*
		* @author �����
		* @date 2015��10��22��
		* @note 
		*/
		static SysGeometry* PolygonClip(SysPolygon* pPolygon,SysEnvelope& rect);

	};

}

#endif // end of __SYSCLIPPER_H_88DD2E77_D966_497A_8091_363AECAEED31__
