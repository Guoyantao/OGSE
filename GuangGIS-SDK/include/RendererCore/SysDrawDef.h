/**
* @file              SysDrawDef.h
* @brief             �������ͺ�ö�ٶ���
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��6��26��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSDRAWDEF_H_88E767D9_174D_4A95_98CC_AF04365CB3EF__
#define __SYSDRAWDEF_H_88E767D9_174D_4A95_98CC_AF04365CB3EF__


#if !defined(WIN32)

//���ھ��ζ���
typedef struct tagRECT
{
	long    left;
	long    top;
	long    right;
	long    bottom;
} RECT;

//�������궨��
/*typedef struct tagPOINT
{
	long  x;
	long  y;
} POINT;*/

//���ڴ�С����
typedef struct tagSIZE
{
	long        cx;
	long        cy;
} SIZE;

#endif

typedef struct tagRECTD
{
	double    left;
	double    top;
	double    right;
	double    bottom;
} RECTD, *PRECTD;

//��ɫ���һ��
struct SysColorItem
{
	short  c1;   //��
    
	short  c2;    //��

	short  c3;    //��

	short  c4;    //alpha
} ;

//�����ǻ��Ƶ�һЩö������

#define WIDTHBYTES(bits)    (((bits) + 31) / 32 * 4) 

#define HIST_SIZE 256.0


/** 
* Ӱ�����췽ʽ
*/
enum StretchType
{
	NoStretch = 0,							//û������
	StretchPercentOne,						//1%��������
	StretchPercentTwo,						//2%��������
	StretchPercentFive,						//5%��������
	StretchToMinimumMaximum,				//���-��Сֵ����
	StretchStandardDeviations,				//��׼������
	StretchOptimizedLinear,					//�Ż���������(ENVIĬ����ʾ��ʽ) 
	UserDefinedStretch						//�û��Զ�������
};

enum DrawStyle	//Ӱ����Ʒ�ʽ
{
	UndefinedDrawingStyle,
	SingleBandGray,                 // �����ΰ��ҶȻ���
	SingleBandPseudoColor,          // �����μٲ�ɫ����
	PalettedColor,                  // ͨ����ɫ�����
	MultiBandColor,                  //�ನ��RGB����
};


// ͼԪ����
enum GraphicsElementType
{
	type_SimplePoint,	// �򵥵�
	type_PolyLine,		// ���պ�����
	type_CurveLine,		// ��������
	type_CloseLine,		// �պ�����
	type_Ploygon,		// �������
	type_FakeCor,		// α��ɫͼ��
	type_Symbol,			// ����ͼ��
	type_Cycle,			// Բ��
	type_Rect,			// ����
	type_Text,			// �ı�
	type_Arc,			// Բ�λ���
	type_Ellipse,		// ��Բ
	type_MultiElement,	// �༸����ͼԪ
	type_MultiLine,		// ������
	type_MultiPolygon,	// ������
	type_Contour			// ��ֵ��
};

// ����ģʽ
enum enSwipeMode
{
	swipe_none = 0,		// ��
	swipe_horiz_left,	// �������������
	swipe_horiz_right,	// �������������
	swipe_vert_up,		// �������������
	swipe_vert_down		// �������������
};


#endif // end of __SYSDRAWDEF_H_88E767D9_174D_4A95_98CC_AF04365CB3EF__
