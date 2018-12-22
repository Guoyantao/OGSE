/**
* @file              SysGraphElement.h
* @brief             ͼԪ�Ļ���
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��3��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSGRAPHELEMENT_H_6E918BE8_BEEF_496E_9ECA_3103A339E181__
#define __SYSGRAPHELEMENT_H_6E918BE8_BEEF_496E_9ECA_3103A339E181__

#include "SysDrawCommon.h"
#include "SysDrawDef.h"

namespace SysDraw
{
	class SysEnvelope;

	class SYSDRAW_API SysGraphElement
	{
	public:
		explicit SysGraphElement(GraphicsElementType eGraType);

		virtual ~SysGraphElement(void);

		/**
		* @brief Clone
		* @return SysGraphElement*
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual SysGraphElement* Clone() const;

		/**
		* @brief GetType
		* @return GraphicsElementType
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		GraphicsElementType GetElementType() const;

		/**
		* @brief ͼԪ���ƶ�(�����ƶ�)
		* @param[in] double dx
		* @param[in] double dy
		* @return bool
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual bool Move(double dx, double dy) = 0;

		/**
		* @brief �ƶ�����
		* @param[in] int nIndex
		* @param[in] double dx
		* @param[in] double dy
		* @return bool
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual bool MovePoint(int nIndex, double dx, double dy);

		/**
		* @brief MovePointTo
		* @param[in] int nIndex
		* @param[in] double dbX
		* @param[in] double dbY
		* @return bool
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual bool MovePointTo(int nIndex, double dbX, double dbY);

		/**
		* @brief �����С�������
		* @param[in] void
		* @return SysEnvelope&
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual SysEnvelope& GetEnvelope(void) const = 0;

		/**
		* @brief SetAlpha
		* @param[in] int nAlpha
		* @return void
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		void SetAlpha(int nAlpha);

		/**
		* @brief GetAlpha
		* @return int
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		int GetAlpha() const;

		/**
		* @brief PointInArea
		* @param[in] double x
		* @param[in] double y
		* @return bool
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual bool PointInArea(double x,double y) const;

		/**
		* @brief ��ȡ���ĵ�
		* @param[out] double &x
		* @param[out] double &y
		* @return void
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual void GetCenterPoint(double &x,double &y) const;

		/**
		* @brief /��ȡ�ܳ�()
		* @return double
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual double GetPerimeter() const;

		/**
		* @brief ��ȡ���(��Է��ͼԪ)
		* @return double
		* @author �����
		* @date 2015��8��3��
		* @note 
		*/
		virtual double GetArea() const;

	private:
		GraphicsElementType m_GraphicType;				//ͼԪ������
		int m_nAlphaPrecent;							//͸����
	};

	SYSDRAW_API SysGraphElement* CreateGraphElement(GraphicsElementType eGraphicType);

	SYSDRAW_API void DestroyGraphElement(SysGraphElement* pGraphElem);

}

#endif // end of __SYSGRAPHELEMENT_H_6E918BE8_BEEF_496E_9ECA_3103A339E181__
