//
//#include "Vector3.h"
//#include "Lighting.h"
//#include "Light.h"
//#include "Material.h"
//
//Lighting::Lighting()
//{
//	mLightNum = 1;
//	m_pLights = new Light[mLightNum];
//	mAmbient = ColorRGBA(1.0,1.0,1.0);//������㶨����
//}
//
//Lighting::~Lighting()
//{
//    DELETEARRAY(m_pLights);
//}
//void Lighting::SetLightNumber(int lnum)
//{
//    DELETEARRAY(m_pLights);
//	mLightNum = lnum;
//	m_pLights = new Light[lnum];
//}
//
//Lighting::Lighting(int lnum)
//{
//	mLightNum = lnum;
//	m_pLights = new Light[lnum];
//	mAmbient = ColorRGBA(0.3,0.3,0.3);	
//}
//
//ColorRGBA Lighting::ComputeLight(const Vector3& viewPoint,const Vector3& point,
//								 const Vector3& normal,Material *pMaterial)
//{
//	ColorRGBA LastC = pMaterial->M_Emit;//��������ɢɫΪ��ʼֵ
//	for(int i=0; i<mLightNum; i++)//���Թ�Դ
//	{
//		if(m_pLights[i].mOnOff)
//		{
//			ColorRGBA InitC(0,0,0);
//			Vector3 VL(point,m_pLights[i].mPosition);//ָ���Դ��ʸ��
//			double d = VL.Length();//�⴫���ľ��룬����ʸ��VL��ģ
//
//			VL.Normalize();
//			Vector3 VN = normal;
//			VN.Normalize();//��λ����ʸ��
//
//			//��1���������������
//			if(m_pLights[i].m_bDiffuse)
//			{
//				double CosTheta = std::max(VL.DotProduct(VN),0.0f);
//				InitC += m_pLights[i].mDiffuse.Multiply(pMaterial->M_Diffuse) * CosTheta;
//			}
//
//			//��2�������뾵�淴���
//			if(m_pLights[i].m_bSpecular)
//			{
//				Vector3 VV(point,viewPoint);//VVΪ��ʸ��
//				VV.Normalize();//��λ����ʸ��
//				Vector3 VH = (VL + VV)/(VL+VV).Length();//ƽ��ʸ��
//				double nHN = pow(std::max(VH.DotProduct(VN),0.0f),pMaterial->M_n);
//				InitC += m_pLights[i].mSpecular.Multiply(pMaterial->M_Specular) * nHN;	
//			}
//
//			//��3������ǿ˥��
//			double c0 = m_pLights[i].L_C0;//c0Ϊ����˥������
//			double c1 = m_pLights[i].L_C1;//c1����˥������
//			double c2 = m_pLights[i].L_C2;//c2����˥������
//			double f = (1.0/(c0+c1*d+c2*d*d));//��ǿ˥������
//			f = std::min(1.0,f);
//			LastC += InitC * f;
//		}
//		else
//		{
//			//LastC += point.c;//����������ɫ
//		}
//	}
//	//��4�������뻷����
//	if(m_pLights[0].m_bAmbient)
//	{
//		LastC += mAmbient*pMaterial->M_Ambient;
//	}
//	//��5������ɫ��һ����[0,1]����
//	//LastC.Normalize();
//	//��6�������������㶥��Ĺ�ǿ��ɫ
//	return LastC;
//}
