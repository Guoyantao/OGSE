/**
* @file              SysEnvelope.h
* @brief             ����ռ�����࣬���Ա�Ｘ������������С������
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2012��1��8��
* @version           1.0.0.1
* @par               Copyright (c):����� 2012
* @par               History:
*/
#ifndef __SYSENVELOPE_H_33EFCD04_B733_480C_A506_AF7BB60CD0BB__
#define __SYSENVELOPE_H_33EFCD04_B733_480C_A506_AF7BB60CD0BB__

#include "SysDrawCommon.h"

namespace SysDraw
{

	class SysCoordinate;

	class SYSDRAW_API SysEnvelope
	{
	public:
		/**
		* @brief Ĭ�Ϲ��캯��
		* @return 
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		SysEnvelope();

		/**
		* @brief �������Ĺ��캯��
		* @param[in] double minX
		* @param[in] double maxX
		* @param[in] double minY
		* @param[in] double maxY
		* @return 
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		SysEnvelope(double minX,double maxX,double minY,double maxY);

		/**
		* @brief �������캯��
		* @param[in] const SysEnvelope& envelope
		* @return 
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		SysEnvelope(const SysEnvelope& envelope);

		/**
		* @brief ���ظ�ֵ�����
		* @param[in] const SysEnvelope& other
		* @return SysEnvelope
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		SysEnvelope &operator=(const SysEnvelope& other);

		/**
		* @brief ������������ʼ��
		* @param[in] SysCoordinate *coord1
		* @param[in] SysCoordinate *coord2
		* @return 
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		SysEnvelope(SysCoordinate *coord1,SysCoordinate *coord2);

		~SysEnvelope(void);

		/**
		* @brief ��ʼ������
		* @param[in] double x1
		* @param[in] double x2
		* @param[in] double y1
		* @param[in] double y2
		* @return void
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		void Init(double x1,double x2,double y1,double y2);


		/**
		* @brief �жϾ����Ƿ�Ϊ��
		* @param[in] void
		* @return bool
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		bool IsNull(void) const;

		/**
		* @brief ���þ���Ϊ��
		* @param[in] void
		* @return void
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		void SetNull(void);

		/**
		* @brief ��ȡ��С������εĿ��
		* @param[in] void
		* @return double
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		double GetWidth(void) const;

		/**
		* @brief ��ȡ��С�����εĸ߶�
		* @param[in] void
		* @return double
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		double GetHeight(void) const;

		/**
		* @brief ��þ��ε����ĵ�����
		* @param[out] SysCoordinate &coord
		* @return bool
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		bool Center(SysCoordinate &coord) const;

		/**
		* @brief ��þ��ε����ĵ�����
		* @param[out] double &x
		* @param[out] double &y
		* @return bool
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		bool Center(double &x,double &y) const;

		/**
		* @brief �����Ƿ������һ��MBR
		* @param[in] const SysEnvelope &env
		* @return bool
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		bool Contains(const SysEnvelope &env) const;

		/**
		* @brief �ж�һ�����Ƿ��ڸþ�����
		* @param[in] const SysCoordinate &pt
		* @return bool
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		bool Contains(const SysCoordinate &pt) const;

		/**
		* @brief �Ƿ���������
		* @param[in] double x
		* @param[in] double y
		* @return bool
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		bool Contains(double x, double y) const;

		/**
		* @brief �ж�һ�����Ƿ��ھ�����
		* @param[in] double x
		* @param[in] double y
		* @return bool
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		bool IsPointInRect(double x,double y) const;

		/**
		* @brief �������������ཻ�Ĳ���
		* @param[in] const SysEnvelope& env
		* @param[out] SysEnvelope &envResult
		* @return bool
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		bool Intersection(const SysEnvelope& env,SysEnvelope &envResult) const;

		/**
		* @brief �������������Ƿ��ཻ
		* @param[in] const SysEnvelope *pOther
		* @return bool
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		bool Intersects(const SysEnvelope *pOther) const;

		/**
		* @brief �������������Ƿ��ཻ
		* @param[in] const SysEnvelope &env
		* @return bool
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		bool Intersects(const SysEnvelope &env) const;

		/**
		* @brief ��������
		* @param[in] double x
		* @param[in] double y
		* @return void
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		void ExpandToInclude(double x, double y);

		/**
		* @brief ��������
		* @param[in] const SysCoordinate &pt
		* @return void
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		void ExpandToInclude(const SysCoordinate &pt);

		/**
		* @brief ��������
		* @param[in] const SysEnvelope &other
		* @return void
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		void ExpandToInclude(const SysEnvelope &other);

		/**
		* @brief ��������
		* @param[in] const SysEnvelope *other
		* @return void
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		void ExpandToInclude(const SysEnvelope *other);

		/**
		* @brief ���㵽��һ��MBR�ľ���
		* @param[in] const SysEnvelope &env
		* @return double
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		double DistanceTo(const SysEnvelope &env) const;

		/**
		* @brief �������
		* @return double
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		double GetArea() const;

		/**
		* @brief �����ܳ�
		* @return double
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		double Perimeter() const;

		/**
		* @brief �任��ƽ��
		* @param[in] double transX
		* @param[in] double transY
		* @return void
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		void Translate(double transX, double transY);

		/**
		* @brief �ж�p1,p2���ɵľ��κ�q1,q2���ɵľ����Ƿ��ཻ
		* @param[in] const SysCoordinate &p1
		* @param[in] const SysCoordinate &p2
		* @param[in] const SysCoordinate &q1
		* @param[in] const SysCoordinate &q2
		* @return staticbool 
		* @author �����
		* @date 2012��1��8��
		* @note 
		*/
		static bool Intersects(const SysCoordinate &p1, const SysCoordinate &p2, const SysCoordinate &q1, const SysCoordinate &q2);

	public:
		double minX;	//��С������ε���Сxֵ
		double maxX;	//��С������ε����xֵ
		double minY;	//��С������ε���Сyֵ
		double maxY;	//��С������ε����yֵ
	};

}

#endif // end of 
