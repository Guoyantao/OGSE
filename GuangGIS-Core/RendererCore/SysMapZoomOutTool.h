/**
* @file              SysMapZoomOutTool.h
* @brief             ��ͼ������С����
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��5��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSMAPZOOMOUTTOOL_H_A77A470D_7B73_40FF_A8A1_24B6E8313226__
#define __SYSMAPZOOMOUTTOOL_H_A77A470D_7B73_40FF_A8A1_24B6E8313226__

#include "SysMapTool.h"

namespace SysDraw
{

	class SysMapZoomOutTool : public SysMapTool
	{
	public:
		explicit SysMapZoomOutTool(const std::string &strName);

		~SysMapZoomOutTool(void);

		virtual SysMapTool* Clone() const;

		virtual void OnMousePress(MOUSE_BUTTON eMouse,int x,int y);

		virtual void OnMouseRelease(MOUSE_BUTTON eMouse,int x,int y);

		virtual void OnMouseMove(MOUSE_BUTTON eMouse,int x,int y);

	private:
		int m_nStartX;
		int m_nStartY;

		double m_dbGeoX1;
		double m_dbGeoY1;

		double m_dbGeoX2;
		double m_dbGeoY2; 
	};

}

#endif // end of __SYSMAPZOOMOUTTOOL_H_A77A470D_7B73_40FF_A8A1_24B6E8313226__
