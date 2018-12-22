/**
* @file              SysDrawText.h
* @brief             ���ֻ�����
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��25��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSDRAWTEXT_H_A19326D9_F275_4C37_B0F8_484BEBF64CF0__
#define __SYSDRAWTEXT_H_A19326D9_F275_4C37_B0F8_484BEBF64CF0__

#include "SysDrawCommon.h"

namespace SysDraw
{
	class SysRGBAColor;

	class SYSDRAW_API SysDrawText
	{
	public:
		explicit SysDrawText(const char* pszFontFile);

		~SysDrawText();

		/**
		* @brief ����������ɫ
		* @param[in] const SysRGBAColor& colorText
		* @return void
		* @author �����
		* @date 2015��8��25��
		* @note 
		*/
		void SetTextColor(const SysRGBAColor& colorText);

		/**
		* @brief ����������ɫ
		* @param[in] float fRed
		* @param[in] float fGreen
		* @param[in] float fBlue
		* @return void
		* @author �����
		* @date 2015��8��25��
		* @note 
		*/
		void SetTextColor(float fRed,float fGreen,float fBlue);

		/**
		* @brief ���������ɫ
		* @return SysRGBAColor&
		* @author �����
		* @date 2015��8��25��
		* @note 
		*/
		SysRGBAColor& GetTextColor() const;

		/**
		* @brief ����������
		* @param[in] int nTextWidth
		* @return void
		* @author �����
		* @date 2015��8��25��
		* @note 
		*/
		void SetTextWidth(int nTextWidth);

		/**
		* @brief ���������
		* @return int
		* @author �����
		* @date 2015��8��25��
		* @note 
		*/
		int GetTextWidth() const;

		/**
		* @brief ��������߶�
		* @param[in] int nTextHeight
		* @return void
		* @author �����
		* @date 2015��8��25��
		* @note 
		*/
		void SetTextHeight(int nTextHeight);

		/**
		* @brief �������߶�
		* @return int
		* @author �����
		* @date 2015��8��25��
		* @note 
		*/
		int GetTextHeight() const;

		/**
		* @brief ��������
		* @param[in] const char* pszText
		* @param[in] int x
		* @param[in] int y
		* @param[in] int nMaxWidth
		* @param[in] int nHeight
		* @return void
		* @author �����
		* @date 2015��8��25��
		* @note 
		*/
		void DrawTextExt(const char* pszText,int x , int y, int nMaxWidth , int nHeight) const;

		/**
		* @brief ��������
		* @param[in] const wchar_t* pszText
		* @param[in] int x
		* @param[in] int y
		* @param[in] int nMaxWidth
		* @param[in] int nHeight
		* @return void
		* @author �����
		* @date 2015��8��25��
		* @note 
		*/
		void DrawTextExt(const wchar_t* pszText,int x , int y, int nMaxWidth , int nHeight) const;

	private:
		SysRGBAColor* m_pTextColor;			//�ı���ɫ
		char* m_pszFontFile;				//�����ļ�·��
		int m_nTextWidth;					//������
		int m_nTextHeight;					//����߶�
	};
}

#endif // end of __SYSDRAWTEXT_H_A19326D9_F275_4C37_B0F8_484BEBF64CF0__
