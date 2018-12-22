/**
* @file              SysRenderContext.h
* @brief             ��Ⱦ������
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��7��8��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSRENDERCONTEXT_H_52CC6321_9DCD_4983_8D2C_8AAEB9795EEF__
#define __SYSRENDERCONTEXT_H_52CC6321_9DCD_4983_8D2C_8AAEB9795EEF__

#include "SysEnvelope.h"
#include "SysDisplayTransform.h"


namespace SysDraw
{

	class SYSDRAW_API SysRenderContext
	{
	public:
		SysRenderContext(void);
		~SysRenderContext(void);

		/**
		* @brief GetExtent
		* @return const SysEnvelope& 
		* @author �����
		* @date 2015��7��8��
		* @note 
		*/
		const SysEnvelope& GetExtent() const;

		/**
		* @brief GetExtent
		* @return SysEnvelope&
		* @author �����
		* @date 2015��7��8��
		* @note 
		*/
		SysEnvelope& GetExtent();

		/**
		* @brief GetDisplayTran
		* @return const SysDisplayTransform& 
		* @author �����
		* @date 2015��7��8��
		* @note 
		*/
		const SysDisplayTransform& GetDisplayTran() const;

		/**
		* @brief GetDisplayTran
		* @return SysDisplayTransform&
		* @author �����
		* @date 2015��7��8��
		* @note 
		*/
		SysDisplayTransform& GetDisplayTran();

		/**
		* @brief SetExtent
		* @param[in] const SysEnvelope& extent
		* @return void
		* @author �����
		* @date 2015��7��8��
		* @note 
		*/
		void SetExtent(const SysEnvelope& extent);

		/**
		* @brief SetDisplayTran
		* @param[in] const SysDisplayTransform& displayTran
		* @return void
		* @author �����
		* @date 2015��7��8��
		* @note 
		*/
		void SetDisplayTran(const SysDisplayTransform& displayTran);


	private:
		SysEnvelope				m_Extent;			//���Ƶĵ���Χ
		SysDisplayTransform		m_DisplayTran;		//������ʾת������
	};

}

#endif // end of __SYSRENDERCONTEXT_H_52CC6321_9DCD_4983_8D2C_8AAEB9795EEF__
