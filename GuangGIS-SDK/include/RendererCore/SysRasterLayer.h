/**
* @file              SysRasterLayer.h
* @brief             դ��ͼ�������
* @details           
* @author            ����� (zhouxuguang@aeroimginfo.com)
* @date              2015��6��26��
* @version           1.0.0.1
* @par               Copyright (c):����� 2015
* @par               History:
*/
#ifndef __SYSRASTERLAYER_H_F506A0EA_5539_462E_BCD7_792CE362F075__
#define __SYSRASTERLAYER_H_F506A0EA_5539_462E_BCD7_792CE362F075__

#include "SysMapLayer.h"
#include "SysDrawDef.h"


namespace SysDataSource
{
	class IDataLayer;
}

namespace SysDraw
{
	class SysRasterSource;
	class SysRasterBandStats;

	typedef std::pair<double ,double> ValueInter;		//ֵ����

	class SYSDRAW_API SysRasterLayer : public SysMapLayer
	{
	public:
		explicit SysRasterLayer(std::string strLayerName);

		~SysRasterLayer(void);

		/**
		* @brief ��������Դ
		* @param[in] SysDataSource::IDataLayer* pDatalayer
		* @param[in] DrawProgressFunc ProgressFunc = NULL
		* @param[in] void* pProgressArg = NULL
		* @return bool
		* @author �����
		* @date 2015��7��10��
		* @note 
		*/
		bool SetDataSource(SysDataSource::IDataLayer* pDatalayer,
							DrawProgressFunc ProgressFunc = NULL, 
							void* pProgressArg = NULL);

		/**
		* @brief �������Դ
		* @return SysDataSource::IDataLayer*
		* @author �����
		* @date 2015��7��10��
		* @note 
		*/
		SysDataSource::IDataLayer* GetDataSource() const;

		/**
		* @brief ����դ��ͼ��
		* @param[in] ysDataSource::IDataLayer* pDatalayer
		* @param[in] DrawProgressFunc ProgressFunc = NULL
		* @param[in] void* pProgressArg = NULL
		* @return SysRasterLayer* ���ش�����ͼ��ָ��
		* @author �����
		* @date 2015��7��1��
		* @note 
		*/
		static SysRasterLayer* CreateRasterLayer(
							SysDataSource::IDataLayer* pDatalayer,
							DrawProgressFunc ProgressFunc = NULL, 
							void* pProgressArg = NULL);

		/**
		* @brief ����ͼ��
		* @param[in] SysRasterLayer* pRasLayer
		* @return void 
		* @author �����
		* @date 2015��7��1��
		* @note 
		*/
		static void DestroyRasterLayer(SysRasterLayer* pRasLayer);

		/**
		* @brief ����������
		* @param[in] float fSampleRate
		* @param[in] int nSampleType
		* @param[in] DrawProgressFunc ProgressFunc = NULL
		* @param[in] void* pProgressArg = NULL
		* @return bool
		* @author �����
		* @date 2015��7��1��
		* @note 
		*/
		bool BuildPyramid(float fSampleRate, int nSampleType, DrawProgressFunc ProgressFunc = NULL, void* pProgressArg = NULL);

		/**
		* @brief ���RGB���ε��������
		* @param[out] int& nRedIndex
		* @param[out] int& nGreenIndex
		* @param[out] int& nBlueIndex
		* @return void
		* @author �����
		* @date 2015��7��1��
		* @note 
		*/
		void GetRGBIndex(int& nRedIndex,int& nGreenIndex,int& nBlueIndex) const;

		/**
		* @brief  ����RGB���ε��������
		* @param[in] int nRedIndex
		* @param[in] int nGreenIndex
		* @param[in] int nBlueIndex
		* @return void
		* @author �����
		* @date 2015��7��1��
		* @note 
		*/
		void SetRGBIndex(const int nRedIndex,const int nGreenIndex,const int nBlueIndex);

		/**
		* @brief ��ûҶ���ʾ�Ĳ������(������α��ɫ��Ⱦ�Ĳ������)
		* @return int
		* @author �����
		* @date 2015��9��28��
		* @note 
		*/
		int GetGrayIndex() const;

		/**
		* @brief ���ûҶ���ʾ�Ĳ������
		* @param[in] const int nGrayIndex
		* @return void
		* @author �����
		* @date 2015��10��27��
		* @note 
		*/
		void SetGrayIndex(const int nGrayIndex);

		/**
		* @brief ��ò�������
		* @return int
		* @author �����
		* @date 2015��7��1��
		* @note 
		*/
		int GetBandCount() const;

		/**
		* @brief ��ø������ε���������
		* @return std::vector<SysRasDataType> �������ε���������
		* @author �����
		* @date 2015��11��23��
		* @par Sample code
		* @code @endcode
		* @par Output
		* @see 
		* @note 
		*/
		std::vector<SysRasDataType> GetBandDataType() const; 

		/**
		* @brief ����Ǽ�����׼������
		* @return float
		* @author �����
		* @date 2015��7��1��
		* @note 
		*/
		float GetStandardDeviations() const;

		/**
		* @brief ���ñ�׼������ļ�����׼�����
		* @param[in] float theStandardDeviations
		* @return void
		* @author �����
		* @date 2015��7��1��
		* @note 
		*/
		void SetStandardDeviations(float fStandardDeviations );

		/**
		* @brief ����ͼ���͸����
		* @param[in] int nTransparency
		* @return void
		* @author �����
		* @date 2015��7��24��
		* @note 
		*/
		void SetTransparency(int nTransparency);

		/**
		* @brief ���͸���ȣ�����ֵ��0-255֮��
		* @return eByte
		* @author �����
		* @date 2015��9��29��
		* @note 
		*/
		eByte GetTransparency() const;

		/**
		* @brief ��������ϵ��
		* @param[in] float fBrightness
		* @return void
		* @author �����
		* @date 2015��7��24��
		* @note 
		*/
		void SetBrightness(float fBrightness);

		/**
		* @brief ����ͼ��Աȶ�
		* @param[in] int nValue
		* @return void
		* @author �����
		* @date 2015��9��16��
		* @note 
		*/
		void SetContrastValue(int nValue);

		virtual bool Draw( SysRenderContext* rendererContext );

		virtual bool Draw( SysRenderContext* rendererContext ,const SysEnvelope& envView);

		virtual void DrawLabels( SysRenderContext* rendererContext );

		/**
		* @brief �Ƿ�����ɫ��ת
		* @return bool
		* @author �����
		* @date 2015��7��24��
		* @note 
		*/
		bool IsInvertColor() const;

		/**
		* @brief �����Ƿ���ɫ��ת
		* @param[in] bool bInvert
		* @return void
		* @author �����
		* @date 2015��7��24��
		* @note 
		*/
		void SetInvertColor(bool bInvert);

		/**
		* @brief ��û��Ʒ��,�Ҷȡ�RGB��
		* @return DrawStyle
		* @author �����
		* @date 2015��9��28��
		* @note 
		*/
		DrawStyle GetDrawStyle() const;

		/**
		* @brief ���û��Ʒ��,�Ҷȡ�RGB��
		* @param[in] DrawStyle eStyle
		* @return void
		* @author �����
		* @date 2015��9��28��
		* @note 
		*/
		void SetDrawStyle(DrawStyle eStyle);

		/**
		* @brief ���դ��ͼ������췽ʽ
		* @return StretchType
		* @author �����
		* @date 2015��9��6��
		* @note 
		*/
		StretchType GetStretchType() const;

		/**
		* @brief ����դ��ͼ������췽ʽ
		* @param[in] StretchType eType
		* @return void
		* @author �����
		* @date 2015��9��6��
		* @note 
		*/
		void SetStretchType(StretchType eType);

		/**
		* @brief ����ĳ�����ε���ϸͳ����Ϣ
		* @param[in] const int nBandIndex
		* @return void
		* @author �����
		* @date 2015��9��28��
		* @note 
		*/
		void CaclBandStatusInfo(const int nBandIndex) const;

		/**
		* @brief ���ĳ�����ε���ϸͳ����Ϣ
		* @param[in] const int nBandIndex
		* @return const SysRasterBandStats*
		* @author �����
		* @date 2015��9��28��
		* @note 
		*/
		const SysRasterBandStats* GetBandStatusInfo(const int nBandIndex) const;

		/**
		* @brief ���ͼ�����ݵ���ʾֵ(���ڵ����λҶ���ʾģʽ,��ɫ��ģʽ�Լ�α��ɫģʽ)
		* @param[in] double dbValue
		* @param[out] eByte *pRGBAValues 4��Ԫ�ص����飬����˳����RGBA
		* @return void
		* @author �����
		* @date 2015��9��29��
		* @note 
		*/
		void GetDisplayValue(double dbValue,eByte *pRGBAValues) const;

		/**
		* @brief ���ͼ�����ݵ���ʾֵ(���ڶನ�β�ɫ��ʾģʽ)
		* @param[in] std::vector<double> dbValue ͼ�����ݵ���Ԫ�飬������RGB���ε�˳��
		* @param[out] eByte *pRGBAValues 4��Ԫ�ص����飬����˳����RGBA
		* @return void
		* @author �����
		* @date 2015��9��29��
		* @note 
		*/
		void GetDisplayValue(std::vector<double> dbValue,eByte *pRGBAValues) const;

		/**
		* @brief �Ƿ���RPCģ��
		* @return bool
		* @author �����
		* @date 2015��9��29��
		* @note 
		*/
		bool HaveRPCModel() const;

		/**
		* @brief SetPseudoColorArray
		* @param[in] std::vector<SysColorItem>& vecPseudoColor
		* @return void
		* @author �����
		* @date 2015��10��26��
		* @note 
		*/
		void SetPseudoColorArray(std::vector<SysColorItem>& vecPseudoColor);

		/**
		* @brief SetPseudoColorValues
		* @param[in] std::vector<ValueInter>& vecValueInters
		* @return void
		* @author �����
		* @date 2015��10��26��
		* @note 
		*/
		void SetPseudoColorValues(std::vector<ValueInter>& vecValueInters);

	private:
		void Init();

		void SetRenderCorTable(const std::vector<SysColorItem>& CorTable);

		void CalcStatisInfo( DrawStyle eDrawStyle);

		//����ĳ�����ε�ͳ����Ϣ����Ҫ��Ϊ��Ⱦ����
		void CalcDrawStatisInfo( DrawStyle eDrawStyle,const int nBandIndex);

		void DrawImage( void * thePainter,
			SysRenderContext* rendererContext,
			const SysEnvelope& envRaster ) const;

		//���Ƶ����λҶ�Ӱ��
		void DrawSingleBandGray(
			void* thePainter,
			SysRenderContext* rendererContext,
			const RECTD& rectImage,
			const RECTD& rectView, const SysEnvelope& envDrawView) const;

		//���ƶನ��Ӱ��
		void DrawMultiBandColor(
			void* thePainter,
			SysRenderContext* rendererContext,
			const RECTD& rectImage,
			const RECTD& rectView, const SysEnvelope& envDrawView) const;

		//���Ƶ�������ɫ��Ӱ��
		void DrawPalettedSingleBandColor(
			void* thePainter,
			SysRenderContext* rendererContext,
			const RECTD& rectImage,
			const RECTD& rectView, const SysEnvelope& envDrawView) const;

		//���Ƶ����Σ�α��ɫģʽ��ʾ��
		void DrawSingleBandPseudoColor(
			void* thePainter,
			SysRenderContext* rendererContext,
			const RECTD& rectImage,
			const RECTD& rectView, const SysEnvelope& envDrawView) const;

		bool GetDrawStatisInfo(int nBandIndex,float* pfHist,float& fMax,float& fMin,float& fMean,float& fVar,int &nCount);

	private:
		mutable int m_nRedIndex;				//��ɫ��������
		mutable int m_nGreenIndex;				//��ɫ��������
		mutable int m_nBlueIndex;				//��ɫ��������

		int m_nBandCount;					//band count

		int m_nWidth;					//Ӱ����
		int m_nHeight;					//Ӱ��߶�

		int m_nGrayIndex;				//�Ҷ���ʾ�Ĳ������

		int m_nTransparency;			//͸����(0-100)
		float m_fBrightness;				//����(-1,1)
		int m_nContrast;				//�ԱȶȲ���(-128,128)

		std::vector<SysColorItem>	m_vecColorTbl;

		DrawStyle m_eDrawStyle;			//Ӱ����Ʒ�ʽ
		StretchType m_eStretchType;		//Ӱ�����췽ʽ
		bool m_bInvertColor;			//�Ƿ�ת��ʾ��ɫ
		bool m_bHasPyramids;			//�Ƿ��н�����
		bool m_bDynamicProj;			//�Ƿ�̬ͶӰ
		double m_dbNoDataValue;			//��Чֵ
		float m_fStandardDeviations;	//������׼��

		SysDataSource::IDataLayer* m_pDatalayer;		//��Ӧ������ͼ��
		SysRasterSource* m_pDataSource;

		eUInt32 m_nTexId;

		mutable std::vector<SysRasterBandStats* > m_vecBandStatus;		//�������ε�ͳ����Ϣ

		std::vector<ValueInter> m_vecValueInters;
		std::vector<SysColorItem> m_vecPseudoColor;			//�ٲ�ɫ��ɫ��

	private:

		float m_pfMin[3];
		float m_pfMax[3];
		float m_pfMean[3];
		float m_pfVar[3];

		float m_pHist[256*3];

	};

}


#endif // end of __SYSRASTERLAYER_H_F506A0EA_5539_462E_BCD7_792CE362F075__
