#include "SysDrawText.h"
#include "SysRGBColor.h"

//#include <Windows.h>
#include <iostream>
#include <GL/gl.h>
#include <ft2build.h>

#if defined _WIN32 || defined _WIN64
	#include <freetype/freetype.h>
	#include <freetype/ftglyph.h>
	#include <freetype/ftoutln.h>
	#include <freetype/fttrigon.h>

#elif defined linux
	#include <freetype2/freetype.h>
	#include <freetype2/ftglyph.h>
	#include <freetype2/ftoutln.h>
	#include <freetype2/fttrigon.h>
#endif


using namespace std;
using namespace SysDraw;

#define MAX_NO_TEXTURES 1

#define CUBE_TEXTURE 0

GLuint texture_id[MAX_NO_TEXTURES];

struct xCharTexture
{
	GLuint  m_texID;
	wchar_t m_chaID;
	int     m_Width;
	int     m_Height;

	int     m_adv_x;
	int     m_adv_y;
	int     m_delta_x;
	int     m_delta_y;
public:
	xCharTexture()
	{
		m_texID  = 0;
		m_chaID  = 0;
		m_Width  = 0;
		m_Height = 0;
	}
}g_TexID[65536];


class xFreeTypeLib
{
	FT_Library m_FT2Lib;
	FT_Face    m_FT_Face;

public:
	int   m_w;
	int   m_h;
	void load(const char* font_file , int _w , int _h);
	GLuint loadChar(wchar_t ch, unsigned char uRed, unsigned char uGreen, unsigned char uBlue);
};

void xFreeTypeLib::load(const char* font_file , int _w , int _h)
{
	FT_Library library;
	if (FT_Init_FreeType( &library) ) 
		return;
	//����һ������,ȡĬ�ϵ�Face,һ��ΪRegualer
	if (FT_New_Face( library, font_file, 0, &m_FT_Face )) 
		return;
	//ѡ���ַ���
	FT_Select_Charmap(m_FT_Face, FT_ENCODING_UNICODE);
	m_w = _w ; m_h = _h;
	m_FT_Face->num_fixed_sizes;
	//��СҪ��64.���ǹ涨�������Ϳ����ˡ�
	FT_Set_Char_Size( m_FT_Face , 0 , m_w << 6, 96, 96);
	//�������ָ���ַ���Ⱥ͸߶ȵ��ض�����
	FT_Set_Pixel_Sizes(m_FT_Face,m_w, m_h);
}

GLuint xFreeTypeLib::loadChar(wchar_t ch, unsigned char uRed, unsigned char uGreen, unsigned char uBlue)
{
	if(g_TexID[ch].m_texID)
	return g_TexID[ch].m_texID;

	/* װ������ͼ�����βۣ�����Ĩ����ǰ������ͼ�� */
	if(FT_Load_Char(m_FT_Face, ch, /*FT_LOAD_RENDER|*/FT_LOAD_FORCE_AUTOHINT|
		(TRUE ? FT_LOAD_TARGET_NORMAL : FT_LOAD_MONOCHROME | FT_LOAD_TARGET_MONO) )   )
	{
		return 0;
	}

	xCharTexture& charTex = g_TexID[ch];
 
	//�õ���ģ
	FT_Glyph glyph;
	//������ͼ������β۸��Ƶ��µ�FT_Glyph����glyph�С������������һ�������벢������glyph��
	if(FT_Get_Glyph( m_FT_Face->glyph, &glyph ))
		return 0;

 	//ת����λͼ
 	FT_Render_Glyph( m_FT_Face->glyph,   FT_RENDER_MODE_NORMAL );//FT_RENDER_MODE_NORMAL  ); 
 	FT_Glyph_To_Bitmap( &glyph, ft_render_mode_normal, 0, 1 );
 	FT_BitmapGlyph bitmap_glyph = (FT_BitmapGlyph)glyph;

	//ȡλͼ����
	FT_Bitmap& bitmap = bitmap_glyph->bitmap;

	//��λͼ���ݿ����Լ��������������.�����Ϳ��Ի�����Ҫ�Ķ��������ˡ�
	int width  =  bitmap.width;
	int height =  bitmap.rows;
 
	m_FT_Face->size->metrics.y_ppem;		//�������뵽�豸�ռ�
	m_FT_Face->glyph->metrics.horiAdvance;  //ˮƽ�ı�����

	//������ת
	float lean = 3;
	FT_Matrix matrix;
	matrix.xx = 0x10000L;
	matrix.xy = lean * 0x10000L;
	matrix.yx = 0;
	matrix.yy = 0x10000L;
	/*FT_Set_Transform( m_FT_Face, &matrix, 0 );
	FT_Outline_Transform(&m_FT_Face->glyph->outline, &matrix);*/

	//����Ӵ�
	int strength = 1 << 6;
	FT_Outline_Embolden(&m_FT_Face->glyph->outline, strength);


	charTex.m_Width = width;
	charTex.m_Height = height;
	charTex.m_adv_x = m_FT_Face->glyph->advance.x / 64.0f;  //�������
	charTex.m_adv_y = m_FT_Face->size->metrics.y_ppem;		//m_FT_Face->glyph->metrics.horiBearingY / 64.0f;
	charTex.m_delta_x = (float)bitmap_glyph->left;			//left:����ԭ��(0,0)������λͼ��������ص�ˮƽ����.�����������ص���ʽ��ʾ��
	charTex.m_delta_y = (float)bitmap_glyph->top - height;	//Top: ���������β۵�bitmap_top�ֶΡ�
	glGenTextures(1,&charTex.m_texID);
	glBindTexture(GL_TEXTURE_2D,charTex.m_texID);
	char* pBuf = new char[width * height * 4];
	for(int j=0; j  < height ; j++)
	{
		for(int i=0; i < width; i++)
		{
   			unsigned char _vl =  (i>=bitmap.width || j>=bitmap.rows) ? 0 : bitmap.buffer[i + bitmap.width*j];
  			pBuf[(4*i + (height - j - 1) * width * 4)  ] = uRed;
   			pBuf[(4*i + (height - j - 1) * width * 4)+1] = uGreen;
   			pBuf[(4*i + (height - j - 1) * width * 4)+2] = uBlue;
   			pBuf[(4*i + (height - j - 1) * width * 4)+3] = _vl;
  		}
	}

	glTexImage2D( GL_TEXTURE_2D,0,GL_RGBA,width, height,0,GL_RGBA,GL_UNSIGNED_BYTE,pBuf);  //ָ��һ����ά������ͼƬ
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_CLAMP);							   //glTexParameteri():�������
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
	glTexEnvi(GL_TEXTURE_2D,GL_TEXTURE_ENV_MODE,GL_REPLACE);								//������л��

	/*gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pBuf);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
	glTexEnvi(GL_TEXTURE_2D,GL_TEXTURE_ENV_MODE,GL_REPLACE);*/
	delete[] pBuf;
	return charTex.m_chaID;
}


xFreeTypeLib g_FreeTypeLib;

xCharTexture* getTextChar(wchar_t ch, unsigned char uRed, unsigned char uGreen, unsigned char uBlue)
{
	g_FreeTypeLib.loadChar(ch, uRed, uGreen, uBlue);
	return &g_TexID[ch];
}

wchar_t* AnsiToUnicode(char* lpcstr)   //����lpcstr����Ҳ����char*
{ 
	wchar_t* Pwstr;
	/*int nLen = MultiByteToWideChar(CP_ACP,0,lpcstr,-1,NULL,0);
	Pwstr = new wchar_t[nLen]; 
	MultiByteToWideChar(CP_ACP,0,lpcstr,-1,Pwstr,nLen);*/

	return (Pwstr);
}
		
void drawText(const wchar_t* _strText,int x , int y, int maxW , int h,const SysRGBAColor& colorText)
{
	int sx = x;
	int sy = y;
	int maxH = h;
	size_t nLen = wcslen(_strText);

	//��ɫ
	unsigned char uRed = colorText.GetRed()*255;
	unsigned char uGreen = colorText.GetGreen()*255;
	unsigned char uBlue = colorText.GetBlue()*255;

	for(int i = 0 ; i < nLen ; i ++)
	{
		if(_strText[i] =='/n')
		{
			sx = x ; sy += maxH + 12;
			continue;
		}
		xCharTexture* pCharTex = getTextChar(_strText[i], uRed, uGreen, uBlue);
		glBindTexture(GL_TEXTURE_2D,pCharTex->m_texID);							//�󶨵�Ŀ������
		glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );	
		glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
		glEnable(GL_BLEND);														
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);						
		//glDisable(GL_TEXTURE_2D);
		int w = pCharTex->m_Width;
		int h = pCharTex->m_Height;

		int ch_x = sx + pCharTex->m_delta_x;
		int ch_y = sy - h - pCharTex->m_delta_y;

		if(maxH < h) maxH = h;
		glBegin ( GL_QUADS );													 // ����һ����һ��ԭʼ�Ķ���
		{
			glTexCoord2f(0.0f, 1.0f); glVertex3f(ch_x      , ch_y    ,  0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(ch_x +  w, ch_y    ,  0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(ch_x +  w, ch_y + h,  0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(ch_x     , ch_y + h,  0.0f);
		}
		glEnd();
		sx += pCharTex->m_adv_x;
		if(sx > x + maxW)
		{
			sx = x ; sy += maxH + 12;
		}
	}
}

void drawTextAnsi(char* _strText,int x , int y, int maxW , int h,const SysRGBAColor& colorText)
{
	int sx = x;
	int sy = y;
	int maxH = h;
	size_t nLen = strlen(_strText);

	//��ɫ
	unsigned char uRed = colorText.GetRed()*255;
	unsigned char uGreen = colorText.GetGreen()*255;
	unsigned char uBlue = colorText.GetBlue()*255;

	for(int i = 0 ; i < nLen ; i ++)
	{
		if(_strText[i] =='/n')
		{
			sx = x ; sy += maxH + 12;
			continue;
		}
		xCharTexture* pCharTex = getTextChar(_strText[i], uRed, uGreen, uBlue);
		glBindTexture(GL_TEXTURE_2D,pCharTex->m_texID);							//�󶨵�Ŀ������
		glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );	
		glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
		glEnable(GL_BLEND);														//�򿪻�ر�OpenGL�����⹦��
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);						//����������㷨
		//glDisable(GL_TEXTURE_2D);
		int w = pCharTex->m_Width;
		int h = pCharTex->m_Height;

		int ch_x = sx + pCharTex->m_delta_x;
		int ch_y = sy - h - pCharTex->m_delta_y;

		if(maxH < h) maxH = h;
		glBegin ( GL_QUADS );													 // ����һ����һ��ԭʼ�Ķ���
		{
			glTexCoord2f(0.0f, 1.0f); glVertex3f(ch_x      , ch_y    ,  0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(ch_x +  w, ch_y    ,  0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(ch_x +  w, ch_y + h,  0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(ch_x     , ch_y + h,  0.0f);
		}
		glEnd();
		sx += pCharTex->m_adv_x;
		if(sx > x + maxW)
		{
			sx = x ; sy += maxH + 12;
		}
	}
}

void GLDrawText(const char* _strText,int x , int y, int maxW , int h,
						  int nTextWidth,int nTextHeight,const SysRGBAColor& colorText)
{
	std::wstring strWtext = SysUtility::toWideString(_strText);
	drawText(strWtext.c_str(),x,y,maxW,h,colorText);

	//drawTextAnsi((char*)_strText,x,y,maxW,h,colorText);
}


//��������Ķ���

namespace SysDraw
{
	SysDrawText::SysDrawText(const char* pszFontFile)
	{
		m_pTextColor = new(std::nothrow) SysRGBAColor(0,0,0);
		m_pszFontFile = strdup(pszFontFile);

		m_nTextWidth = 10;
		m_nTextHeight = 10;
	}

	SysDrawText::~SysDrawText()
	{
		if (m_pTextColor != NULL)
		{
			delete m_pTextColor;
			m_pTextColor = NULL;
		}

		if (m_pszFontFile != NULL)
		{
			free(m_pszFontFile);
			m_pszFontFile = NULL;
		}

		m_nTextWidth = 0;
		m_nTextHeight = 0;
	}

	void SysDrawText::SetTextColor( const SysRGBAColor& colorText )
	{
		*m_pTextColor = colorText;
	}

	void SysDrawText::SetTextColor( float fRed,float fGreen,float fBlue )
	{
		m_pTextColor->SetRGBA(fRed,fGreen,fBlue);
	}

	SysRGBAColor& SysDrawText::GetTextColor() const
	{
		return *m_pTextColor;
	}

	void SysDrawText::SetTextWidth( int nTextWidth )
	{
		m_nTextWidth = nTextWidth;
	}

	int SysDrawText::GetTextWidth() const
	{
		return m_nTextWidth;
	}

	void SysDrawText::SetTextHeight( int nTextHeight )
	{
		m_nTextHeight = nTextHeight;
	}

	int SysDrawText::GetTextHeight() const
	{
		return m_nTextHeight;
	}

	void SysDrawText::DrawTextExt( const char* pszText,int x , int y, int nMaxWidth , int nHeight ) const
	{
		g_FreeTypeLib.load(m_pszFontFile,m_nTextWidth,m_nTextHeight);

		GLDrawText(pszText,x,y,nMaxWidth,nHeight,m_nTextWidth,m_nTextHeight,*m_pTextColor);
	}

	void SysDrawText::DrawTextExt( const wchar_t* pszText,int x , int y, int nMaxWidth , int nHeight ) const
	{
		drawText(pszText,x,y,nMaxWidth,nHeight,*m_pTextColor);
	}
}
