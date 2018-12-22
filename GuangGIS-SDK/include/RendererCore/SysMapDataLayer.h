/**
* @file              SysMapDataLayer.h
* @brief             ����ͼ����
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��6��26��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSMAPDATALAYER_H_FB417015_743C_4A9B_BC55_2D45657BC406__
#define __SYSMAPDATALAYER_H_FB417015_743C_4A9B_BC55_2D45657BC406__

#include "SysMapLayer.h"

namespace SysDraw
{


	class SYSDRAW_API SysMapDataLayer : public SysMapLayer
	{
	public:
		SysMapDataLayer(SysMapLayer::LayerType type, std::string strLyrName);
		virtual ~SysMapDataLayer(void);
	};


}


#endif // end of __SYSMAPDATALAYER_H_FB417015_743C_4A9B_BC55_2D45657BC406__
