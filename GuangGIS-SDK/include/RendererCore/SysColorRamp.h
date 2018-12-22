/**
* @file              SysColorRamp.h
* @brief             ��ɫ������Ҫʵ����ɫ�Ľ����㷨��
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��27��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSCOLORRAMP_H_71A8A3B6_79FB_41CB_A7C1_18437FFCFAF8__
#define __SYSCOLORRAMP_H_71A8A3B6_79FB_41CB_A7C1_18437FFCFAF8__

#include "SysDrawCommon.h"
#include "SysDrawDef.h"

namespace SysDraw
{
	class SysRGBAColor;

	class SYSDRAW_API SysColorRamp
	{
	public:
		/**
		* @brief SysColorRamp
		* @param[in] const SysRGBAColor& startColor ��ʼ����ɫ
		* @param[in] const SysRGBAColor& endColor ��������ɫ
		* @return 
		* @author �����
		* @date 2015��8��27��
		* @note 
		*/
		SysColorRamp(const SysRGBAColor& startColor,const SysRGBAColor& endColor);

		/**
		* @brief SysColorRamp
		* @param[in] const SysColorItem& startColor ��ʼ����ɫ
		* @param[in] const SysColorItem& endColor ��������ɫ
		* @return 
		* @author �����
		* @date 2015��8��27��
		* @note 
		*/
		SysColorRamp(const SysColorItem& startColor,const SysColorItem& endColor);

		~SysColorRamp(void);

		/**
		* @brief ������ɫ����ý������ɫֵ����
		* @param[in] SysRGBAColor* pColors
		* @param[in] int nCount
		* @return void
		* @author �����
		* @date 2015��8��27��
		* @note 
		*/
		void GetColors(SysRGBAColor* pColors,int nCount) const;

		/**
		* @brief ������ɫ����ý������ɫֵ����
		* @param[in] SysColorItem* pColors
		* @param[in] int nCount
		* @return void
		* @author �����
		* @date 2015��8��27��
		* @note 
		*/
		void GetColors(SysColorItem* pColors,int nCount) const;

	private:
		SysRGBAColor* m_pStartColor;			//��ʼ����ɫ
		SysRGBAColor* m_pEndColor;				//��������ɫ
	};

}


#endif // end of __SYSCOLORRAMP_H_71A8A3B6_79FB_41CB_A7C1_18437FFCFAF8__