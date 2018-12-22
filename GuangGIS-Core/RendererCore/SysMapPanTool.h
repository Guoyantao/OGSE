/**
* @file              SysMapPanTool.h
* @brief             ��ͼƽ�ƹ���
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��3��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSMAPPANTOOL_H_E6D5E6D3_7617_4731_B099_C07FD325A60D__
#define __SYSMAPPANTOOL_H_E6D5E6D3_7617_4731_B099_C07FD325A60D__

#include "SysMapTool.h"

namespace SysDraw
{

	class SysMapPanTool : public SysMapTool
	{
	public:
		explicit SysMapPanTool(const std::string& strName );

		~SysMapPanTool(void);

		SysMapTool* Clone() const;

		void OnMousePress(MOUSE_BUTTON eMouse,int x,int y);

		void OnMouseRelease(MOUSE_BUTTON eMouse,int x,int y);

		void OnMouseMove(MOUSE_BUTTON eMouse,int x,int y);

	private:
		int m_nStartX;
		int m_nStartY;
	};

}

#endif // end of __SYSMAPPANTOOL_H_E6D5E6D3_7617_4731_B099_C07FD325A60D__
