/**
* @file              SysRasterTile.h
* @brief             դ���ļ�tile��������ʾ����256*256
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��7��31��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSRASTERTILE_H_01C56D2A_F45A_493D_B3B0_E96522650C49__
#define __SYSRASTERTILE_H_01C56D2A_F45A_493D_B3B0_E96522650C49__

#include <GL/glew.h>
#include "SysDisplayTransform.h"

namespace SysDraw
{

	class SysRasterTile
	{
	public:
		SysRasterTile(const SysDisplayTransform &dispTran,const SysEnvelope& env);
		~SysRasterTile(void);

		//����
		void Draw() const;

		//����һ��������
		void UpdateSubDate(int nXoffset,int nYoffset,int nWidth,int nHeight,const void* pPixels);

		void SetDispTran(const SysDisplayTransform &dispTran);

		void SetEnvlope(const SysEnvelope& env);

	private:

		GLuint m_nTexId;			//����ID
		SysEnvelope m_TileEnv;		//��ǰTILE�ĵ���Χ
		SysDisplayTransform m_DispTran;
	};

}

#endif // end of __SYSRASTERTILE_H_01C56D2A_F45A_493D_B3B0_E96522650C49__
