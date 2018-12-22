/**
* @file              SysUtilFunc.h
* @brief             һЩ�������������������ڲ�
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��20��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSUTILFUNC_H_76F82CCF_3283_4567_8EEC_5745D04370C7__
#define __SYSUTILFUNC_H_76F82CCF_3283_4567_8EEC_5745D04370C7__

#include <vector>
#include <GL/glew.h>

#include "SysDrawCommon.h"

namespace SysDraw
{

	class SysMap;
	class SysMapLayer;
	class SysEnvelope;

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
	void MapExtentToLayerExtent(SysMap* pMap,SysMapLayer* pLayer,SysEnvelope& envOut);

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
	void LayerExtentToMapExtent(SysMap* pMap,SysMapLayer* pLayer,SysEnvelope& envOut);

	double* GetPloygonPoints(GeoPolygon* pPolygon,int& nPointCountOut,std::vector<GLsizei> &vecCounts,
		std::vector<std::vector<GLuint> >& vecIndices);

	void DrawGeometryHighLight(GeoGeometry* pGeometry);

	/**
	* @brief �����ַ����������ַָ�
	* @param[in] const char* pszFieldValue
	* @param[in] std::vector<std::string> &vecAllFieldValue
	* @return void
	* @author �����
	* @date 2015��10��20��
	* @note 
	*/
	void SplitLabelStr(const char* pszFieldValue,std::vector<std::string> &vecAllFieldValue);
}

#endif // end of __SYSUTILFUNC_H_76F82CCF_3283_4567_8EEC_5745D04370C7__
