/**
* @file              SysMapWheelTool.h
* @brief             ��ͼ�������Ź���
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��3��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSMAPWHEELTOOL_H_6C5C2C15_F35C_4829_BE12_70229C4F8C86__
#define __SYSMAPWHEELTOOL_H_6C5C2C15_F35C_4829_BE12_70229C4F8C86__

#include "SysMapTool.h"

namespace SysDraw
{


	class SysMapWheelTool : public SysMapTool
	{
	public:
		explicit SysMapWheelTool(const std::string &strName);

		~SysMapWheelTool(void);

		void OnMouseWheel(MOUSE_BUTTON eMouse, int nDelta,int x,int y);
	};

}

#endif // end of __SYSMAPWHEELTOOL_H_6C5C2C15_F35C_4829_BE12_70229C4F8C86__