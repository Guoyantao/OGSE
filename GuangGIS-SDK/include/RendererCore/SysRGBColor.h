/**
* @file              SysRGBColor.h
* @brief             RGBA��ɫ��װ�࣬��Ӧ���ƽ̨
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��6��29��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSRGBCOLOR_H_196793B0_415A_45A4_94AD_E48A1AB62395__
#define __SYSRGBCOLOR_H_196793B0_415A_45A4_94AD_E48A1AB62395__

#include "SysDrawCommon.h"


namespace SysDraw
{


	class SYSDRAW_API SysRGBAColor
	{
	public:
		SysRGBAColor();

		/**
		* @brief ʹ���ĸ�����������RGB��ɫ����������������0-1֮�䣬������Χ�ض� 
		* @param[in] float fRed
		* @param[in] float fGreen
		* @param[in] float fBlue
		* @param[in] float fAlpha
		* @return 
		* @author �����
		* @date 2015��6��29��
		* @note 
		*/
		SysRGBAColor(float fRed,float fGreen,float fBlue,float fAlpha = 1.0);

		/**
		* @brief SysRGBAColor
		* @param[in] const SysRGBAColor& rhs
		* @return 
		* @author �����
		* @date 2015��6��29��
		* @note 
		*/
		SysRGBAColor(const SysRGBAColor& rhs);

		/**
		* @brief operator = 
		* @param[in] const SysRGBAColor& rhs
		* @return SysRGBAColor& 
		* @author �����
		* @date 2015��6��29��
		* @note 
		*/
		SysRGBAColor& operator = (const SysRGBAColor& rhs);

		/**
		* @brief operator + 
		* @param[in] const SysRGBAColor& rhs
		* @return SysRGBAColor& 
		* @author �����
		* @date 2015��6��29��
		* @note 
		*/
		SysRGBAColor& operator + (const SysRGBAColor& rhs);

		/**
		* @brief operator * 
		* @param[in] const SysRGBAColor& rhs
		* @return SysRGBAColor& 
		* @author �����
		* @date 2015��6��29��
		* @note 
		*/
		SysRGBAColor& operator * (const SysRGBAColor& rhs);

		~SysRGBAColor(void);

		/**
		* @brief ������ɫ�еĺ�ɫ���֣���0-1����
		* @return float
		* @author �����
		* @date 2015��6��29��
		* @note 
		*/
		float GetRed() const;

		/**
		* @brief ������ɫ�е���ɫ���֣���0-1����
		* @return float
		* @author �����
		* @date 2015��6��29��
		* @note 
		*/
		float GetGreen() const;

		/**
		* @brief ������ɫ�е���ɫ���֣���0-1����
		* @return float
		* @author �����
		* @date 2015��6��29��
		* @note 
		*/
		float GetBlue() const;

		/**
		* @brief ������ɫ�е�alpha���֣���0-1����
		* @return float
		* @author �����
		* @date 2015��6��29��
		* @note 
		*/
		float GetAlpha() const;

		/**
		* @brief ʹ���ĸ�����������RGB��ɫ����������������0-1֮�䣬������Χ�ض�
		* @param[in] float fRed
		* @param[in] float fGreen
		* @param[in] float fBlue
		* @param[in] float fAlpha
		* @return void
		* @author �����
		* @date 2015��6��29��
		* @note 
		*/
		void SetRGBA(float fRed,float fGreen,float fBlue ,float fAlpha = 1.0);

	private:
		float m_fRed;
		float m_fGreen;
		float m_fBlue;
		float m_fAlpha;
	};


}

#endif // end of __SYSCOLOR_H_196793B0_415A_45A4_94AD_E48A1AB62395__