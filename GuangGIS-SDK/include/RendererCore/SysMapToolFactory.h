/**
* @file              SysMapToolFactory.h
* @brief             ��ͼ�������߹���
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��8��2��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSMAPTOOLFACTORY_H_F050F55C_36CF_49BD_B40C_6023A9984CA6__
#define __SYSMAPTOOLFACTORY_H_F050F55C_36CF_49BD_B40C_6023A9984CA6__

#include "SysDrawCommon.h"

namespace SysDraw
{

	class SysMapTool;

	class SYSDRAW_API SysMapToolFactory
	{
	public:
		typedef SysMapTool* (*CreateMapToolFun)(const std::string& );			//��������ص�����

		typedef void (*DestroyMapToolFun)(SysMapTool *);			//�ͷŶ���Ļص�����

		/**
		* @brief ע���ͼ��������
		* @param[in] const std::string& strName
		* @param[in] CreateMapToolFun pCallBackFun
		* @param[in] DestroyMapToolFun pDestroyFun
		* @return void
		* @author �����
		* @date 2015��8��2��
		* @note 
		*/
		static void RegisterMapTool(
			const std::string& strName,
			CreateMapToolFun pCallBackFun,
			DestroyMapToolFun pDestroyFun);

		/**
		* @brief ��ע���ͼ��������
		* @param[in] const std::string& strName ���ߵ�����
		* @return void
		* @author �����
		* @date 2015��8��2��
		* @note 
		*/
		static void UnRegisterMapTool(const std::string& strName);

		/**
		* @brief ����Ψһʵ��
		* @return SysMapToolFactory* 
		* @author �����
		* @date 2015��8��2��
		* @note 
		*/
		static SysMapToolFactory* GetInstance();

		/**
		* @brief ������ͼ��������
		* @param[in] const std::string& strName
		* @return SysMapTool*
		* @author �����
		* @date 2015��8��2��
		* @note 
		*/
		static SysMapTool* CreateMapTool(const std::string& strName);

		/**
		* @brief ���ٵ�ͼ��������
		* @param[in] const std::string& strName
		* @param[in] SysMapTool* pTool
		* @return void
		* @author �����
		* @date 2015��8��2��
		* @note 
		*/
		static void DestroyMapTool(const std::string& strName,SysMapTool* pTool);

	private:
		SysMapToolFactory(void);
		~SysMapToolFactory(void);
		SysMapToolFactory(const SysMapToolFactory& rhs);
		SysMapToolFactory& operator=(const SysMapToolFactory& rhs);

		typedef std::map<std::string,CreateMapToolFun> CreateCallBackMap;
		typedef std::map<std::string,DestroyMapToolFun> DestroyCallBackMap;
		static CreateCallBackMap m_mapCreateMap;						//�ص�����map
		static DestroyCallBackMap m_mapDestroyMap;
	};

}

#endif // end of __SYSMAPTOOLFACTORY_H_F050F55C_36CF_49BD_B40C_6023A9984CA6__
