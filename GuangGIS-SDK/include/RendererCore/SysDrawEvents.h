/**
* @file              SysDrawEvents.h
* @brief             �����¼�����
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��10��14��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSDRAWEVENTS_H_72D2E6C1_932A_4377_B9A6_760299318C72__
#define __SYSDRAWEVENTS_H_72D2E6C1_932A_4377_B9A6_760299318C72__

#include "SysDrawCommon.h"

namespace SysDraw
{

	class SysMapLayer;

	SYSDRAW_EXTERNC_START

	/**
	* @brief ͼ�����ʱ�Ļص���������
	* @param[in] SysMapLayer*
	* @param[in] void*
	* @return typedefvoid 
	* @author �����
	* @date 2015��10��14��
	* @note 
	*/
	typedef void (SYSDRAW_STD_CALL* OnMapLayerAdd)(SysMapLayer* ,void* );  

	/**
	* @brief ͼ��ɾ��ʱ�Ļص���������
	* @param[in] SysMapLayer*
	* @param[in] void*
	* @return typedefvoid 
	* @author �����
	* @date 2015��10��14��
	* @note 
	*/
	typedef void (SYSDRAW_STD_CALL* OnMapLayerRemove)(SysMapLayer* ,void* );  

	SYSDRAW_EXTERNC_END

	class SYSDRAW_API SysDrawEvents
	{
	private:
		SysDrawEvents(void);

		SysDrawEvents(const SysDrawEvents& rhs);

		SysDrawEvents& operator =(const SysDrawEvents& rhs);

		~SysDrawEvents(void);

	public:
		static SysDrawEvents* GetInstance();

		/**
		* @brief ע��ͼ������¼�
		* @param[in] OnMapLayerAdd pEventFunc
		* @return void
		* @author �����
		* @date 2015��10��15��
		* @note 
		*/
		void RegisterMapLayerAddEvent(OnMapLayerAdd pEventFunc);

		/**
		* @brief ע��ͼ��ɾ���¼�
		* @param[in] OnMapLayerRemove pEventFunc
		* @return void
		* @author �����
		* @date 2015��10��15��
		* @note 
		*/
		void RegisterMapLayerRemoveEvent(OnMapLayerRemove pEventFunc);

		/**
		* @brief ����ͼ������¼�
		* @param[in] SysMapLayer*
		* @param[in] void*
		* @return void
		* @author �����
		* @date 2015��10��15��
		* @note 
		*/
		void ActiveMapLayerAddEvents(SysMapLayer* ,void* ) const;

		/**
		* @brief ����ͼ��ɾ���¼�
		* @param[in] SysMapLayer*
		* @param[in] void*
		* @return void
		* @author �����
		* @date 2015��10��15��
		* @note 
		*/
		void ActiveMapLayerRemoveEvents(SysMapLayer* ,void* ) const;

	private:
		std::vector<OnMapLayerAdd> m_vecLayerAddFuncs;		//ͼ�����ʱ�Ļص�����
		std::vector<OnMapLayerRemove> m_vecLayerRemoveFuncs;		//ͼ��ɾ��ʱ�Ļص�����

	};

}

#endif // end of __SYSDRAWEVENTS_H_72D2E6C1_932A_4377_B9A6_760299318C72__
