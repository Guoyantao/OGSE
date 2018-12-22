/**
* @file              SysFeatureLabelAttribute.h
* @brief             ���Ʊ�עʱ����������
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��10��16��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSFEATURELABELATTRIBUTE_H_89C0CCDE_DB24_4225_A021_8B4DEF17E715__
#define __SYSFEATURELABELATTRIBUTE_H_89C0CCDE_DB24_4225_A021_8B4DEF17E715__


#include "SysRGBColor.h"

namespace SysDraw
{
	class SysRGBAColor;

	class SYSDRAW_API SysFeatureLabelAttribute
	{
	public:
		SysFeatureLabelAttribute(void);

		SysFeatureLabelAttribute& operator = (const SysFeatureLabelAttribute& rhs);

		~SysFeatureLabelAttribute(void);

		/* ��λ���� */
		enum Units
		{
			MapUnits = 0,
			PointUnits
		};

		static std::string GetUnitsName( int nUnits );
		static int GetUnitsCode( const std::string &strName );

		/* Text */
		void SetText( const std::string & text );
		const std::string GetText( void ) const;

		/* ���� */
		void SetFamily( const std::string & family );
		const std::string GetFamily( void ) const;

		//����
		void SetBold( bool enable );
		bool IsBold( void ) const;

		//б��
		void SetItalic( bool enable );
		bool IsItalic( void ) const;

		//�»���
		void SetUnderline( bool enable );
		bool IsUnderline( void ) const;

		/* strikeout  */
		void SetStrikeOut( bool enable );
		bool IsStrikeOut( void ) const;

		void   SetSize( double size, int type );
		int    GetSizeType( void ) const;
		double size( void ) const;

		void  SetColor( const SysRGBAColor &color );
		const SysRGBAColor & GetColor( void ) const;

		/* ƫ���� */
		void   SetOffSet( double x, double y, int type );
		int    GetOffSetType( void ) const;
		double GetXOffSet( void ) const;
		double GetYOffSet( void ) const;

		/* �Ƕ� */
		void   SetAngle( double angle );
		double GetAngle( void ) const;

		bool   AngleIsAuto( void ) const;
		void   SetAutoAngle( bool state );

		/* ���뷽ʽ */
		void SetAlignment( int alignment );
		int  GetAlignment( void ) const;

		/* Buffer */
		bool   bufferEnabled() const;
		void   SetBufferEnabled( bool useBufferFlag );
		void   SetBufferSize( double size, int type );
		int    GetBufferSizeType( void ) const;
		double GetBufferSize( void ) const;

		//void  SetBufferColor( const QColor &color );
		//QColor bufferColor( void ) const;

		//void  SetBufferStyle( Qt::BrushStyle style );
		//Qt::BrushStyle bufferStyle( void ) const;

		/* Border */
		//void  SetBorderColor( const QColor &color );
		//QColor borderColor( void ) const;

		void  SetBorderWidth( int width );
		int   GetBorderWidth( void ) const;

		//void  SetBorderStyle( Qt::PenStyle style );
		//Qt::PenStyle   borderStyle( void ) const;

		bool  MultilineEnabled() const;
		void  SetMultilineEnabled( bool useMultiline );

		/* label only selected features
		* added in 1.5
		*/
		bool  SelectedOnly() const;
		void  SetSelectedOnly( bool selectedonly );

	protected:
		/* Text */
		std::string m_strText;

		/** Font (family, weight, italic, underline, strikeout) */
		bool m_bFamily;
		bool m_bBold;
		bool m_bItalic;
		bool m_bUnderline;
		bool m_bStrikeOut;

		/** Font size, size type */
		int  mSizeType;
		double mSize;

		/** Color */
		SysRGBAColor m_Color;

		/** OffSet */
		int    m_nOffSetType;
		double m_dXOffSet;
		double m_dYOffSet;

		/** Angle (degrees) */
		double mAngle;

		/** Alignment */
		int  mAlignment;

		/** Buffer enablement */
		bool mBufferEnabledFlag;
		/** Buffer size, size type */
		int    mBufferSizeType;
		double mBufferSize;
	};

}

#endif // end of __SYSFEATURELABELATTRIBUTE_H_89C0CCDE_DB24_4225_A021_8B4DEF17E715__
