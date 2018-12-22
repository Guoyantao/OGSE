/**
* @file              SysRasterSource.h
* @brief             �ļ�����Դ
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��7��17��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSRASTERSOURCE_H_C303AC83_FE87_4B23_BE82_9C3DD026428A__
#define __SYSRASTERSOURCE_H_C303AC83_FE87_4B23_BE82_9C3DD026428A__

#include "SysDrawCommon.h"

namespace SysDraw
{

	class SysRasterSource
	{
	public:
		SysRasterSource(void);
		~SysRasterSource(void);

		void SetDataSource(SysDataSource::IDataLayerPtr pDataLayer);
		
		SysDataSource::IDataLayerPtr GetDataSource() const;


	private:
		SysDataSource::IDataLayerPtr m_pDataLayer;

		SysRasterSource(const SysRasterSource& rhs);
		SysRasterSource& operator= (const SysRasterSource& rhs);
	};

}

#endif // end of __SYSRASTERSOURCE_H_C303AC83_FE87_4B23_BE82_9C3DD026428A__
