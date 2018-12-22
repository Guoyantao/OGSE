/**
* @file              SysGraphLayer.h
* @brief             ������ͼԪ��ͼ��
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��5��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSGRAPHLAYER_H_FCE6CCD4_0971_4F3C_AA5D_D4F87485AD63__
#define __SYSGRAPHLAYER_H_FCE6CCD4_0971_4F3C_AA5D_D4F87485AD63__

#include "SysMapLayer.h"

namespace SysDraw
{
	class SysGraphElement;

	class SYSDRAW_API SysGraphLayer : public SysMapLayer
	{
	public:
		explicit SysGraphLayer(std::string strLyrName);

		~SysGraphLayer(void);

		/**
		* @brief ���ͼԪ
		* @param[in] SysGraphElement* pElement
		* @return void
		* @author �����
		* @date 2015��8��11��
		* @note 
		*/
		void AddGraphicElement(SysGraphElement* pElement);

		/**
		* @brief ��õ�nIndex��ͼԪ
		* @param[in] int nIndex
		* @return SysGraphElement*
		* @author �����
		* @date 2015��8��11��
		* @note 
		*/
		SysGraphElement* GetGraphicElement(int nIndex) const;

		/**
		* @brief ���ͼԪ����
		* @return size_t
		* @author �����
		* @date 2015��8��11��
		* @note 
		*/
		size_t GetGraphicElementCount() const;

		/**
		* @brief ɾ����nIndex��ͼԪ
		* @param[in] int nIndex
		* @return bool
		* @author �����
		* @date 2015��8��11��
		* @note 
		*/
		bool RemoveGraphicElement(int nIndex);

		/**
		* @brief �Ƴ�����Ԫ��
		* @return void
		* @author �����
		* @date 2015��8��11��
		* @note 
		*/
		void RemoveAllGraphicElement();

		/**
		* @brief ��������ͼԪ
		* @param[in] SysRenderContext* rendererContext
		* @return bool
		* @author �����
		* @date 2015��8��11��
		* @note 
		*/
		bool Draw( SysRenderContext* rendererContext ) ;

		/**
		* @brief ���Ƶ�nIndex��ͼԪ
		* @param[in] int nIndex
		* @param[in] SysRenderContext* rendererContext
		* @return bool
		* @author �����
		* @date 2015��8��11��
		* @note 
		*/
		bool DrawElement(int nIndex, SysRenderContext* rendererContext ) const;

	private:
		std::vector<SysGraphElement*> m_vecGraphicElement; 
	};

}

#endif // end of __SYSGRAPHLAYER_H_FCE6CCD4_0971_4F3C_AA5D_D4F87485AD63__
