/**
* @file              SysFillSymbol.h
* @brief             ��������
* @details           
* @author            �����(zhouxuguang@aeroimginfo.com)
* @date              2015��11��27��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSFILLSYMBOL_H_7324BA8C_F436_42F2_B87D_012518A65717__
#define __SYSFILLSYMBOL_H_7324BA8C_F436_42F2_B87D_012518A65717__

#include "SysSymbol.h"

namespace SysDraw
{

	class SYSDRAW_API SysFillSymbol : public SysSymbol
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
		SysFillSymbol(void);

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
		~SysFillSymbol(void);

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

#endif // end of __SYSFILLSYMBOL_H_7324BA8C_F436_42F2_B87D_012518A65717__
