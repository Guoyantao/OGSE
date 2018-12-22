/**
* @file              SysPointSymbol.h
* @brief             ��״������
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��11��27��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSPOINTSYMBOL_H_F4D34DAD_2548_44E5_81D9_35F54D82ABC0__
#define __SYSPOINTSYMBOL_H_F4D34DAD_2548_44E5_81D9_35F54D82ABC0__

#include "SysSymbol.h"

namespace SysDraw
{

	class SYSDRAW_API SysPointSymbol : public SysSymbol
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
		SysPointSymbol(void);

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
		~SysPointSymbol(void);

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

#endif // end of __SYSPOINTSYMBOL_H_F4D34DAD_2548_44E5_81D9_35F54D82ABC0__
