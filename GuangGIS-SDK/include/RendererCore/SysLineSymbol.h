/**
* @file              SysLineSymbol.h
* @brief             ��״������
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��11��27��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSLINESYMBOL_H_F8F3CF0F_150A_417F_8729_F206BCCCFA87__
#define __SYSLINESYMBOL_H_F8F3CF0F_150A_417F_8729_F206BCCCFA87__

#include "SysSymbol.h"

namespace SysDraw
{

	class SYSDRAW_API SysLineSymbol : public SysSymbol
	{
	public:
		/**
		* @brief ���캯��
		* @return 
		* @author �����
		* @date 2015��11��27��
		* @par Sample code
		* @code @endcode
		* @par Output
		* @see 
		* @note 
		*/
		SysLineSymbol(void);

		/**
		* @brief ��������
		* @return 
		* @author �����
		* @date 2015��11��27��
		* @par Sample code
		* @code @endcode
		* @par Output
		* @see 
		* @note 
		*/
		~SysLineSymbol(void);

		/**
		* @brief ��÷�������
		* @return SysSymbolType
		* @author �����
		* @date 2015��11��27��
		* @par Sample code
		* @code @endcode
		* @par Output
		* @see 
		* @note 
		*/
		SysSymbolType GetSymbolType() const;
	};

}

#endif // end of __SYSLINESYMBOL_H_F8F3CF0F_150A_417F_8729_F206BCCCFA87__
