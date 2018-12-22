
#include <math.h>
#include <vector>
#include "CG_GridGenerate.h"
#include "CG_Matrix.h"

// static  std::vector< std::vector<int> > vecGrid ;

struct GridIndex
{
	//ÿ������Ĵ�С
	double dbXGridSize;
	double dbYGridSize;

	//����������ʼ�ĵ�������
	double dbMinX;
	double dbMinY;

	//������������������
	int nX;
	int nY;

	//�������������
	std::vector< std::vector<int> > vecGrid ;
};

static GridIndex stGridIndex;




//�ռ��ֵ�ĺ���ָ��
typedef int (*GridInterpolationFunction)( const void *, unsigned int,
									  const double *, const double *,
									  const double *,
									  double, double, double *,
									  void* );

int GridInterpolation( GridAlgorithm eAlgorithmType, const void *poOptions,
				   unsigned int nPointCount,
				   const double *padfX, const double *padfY, const double *padfZ,
				   double dbXMin, double dbXMax, double dbYMin, double dbYMax,
				   unsigned int nXSize, unsigned int nYSize, float *pData,
				   /*GDALProgressFunc pfnProgress,*/ void *pProgressArg )
{
	GridInterpolationFunction pfGridFun = NULL;

	//������������
	{
		//����Ĵ�С
		stGridIndex.dbXGridSize = (dbXMax-dbXMin)/nXSize*300;
		stGridIndex.dbYGridSize = (dbYMax-dbYMin)/nYSize*300;
		stGridIndex.dbMinX = dbXMin;
		stGridIndex.dbMinY = dbYMin;
		stGridIndex.nX = ceil( (dbXMax-dbXMin)/stGridIndex.dbXGridSize );
		stGridIndex.nY = ceil( (dbYMax-dbYMin)/stGridIndex.dbYGridSize );
		stGridIndex.vecGrid.resize(stGridIndex.nX*stGridIndex.nY);
		for (int i = 0; i < nPointCount; i ++)
		{
			int nCol = (padfX[i]-dbXMin)/stGridIndex.dbXGridSize;
			int nRow = (padfY[i]-dbYMin)/stGridIndex.dbYGridSize;
			int nIndex = nRow*stGridIndex.nX + nCol;
			if (nIndex < stGridIndex.nX*stGridIndex.nY)
			{
				stGridIndex.vecGrid[nIndex].push_back(i);
			}
			
		}
	}

	switch (eAlgorithmType)
	{
	case GGA_InverseDistanceToAPower:
		pfGridFun = GridInverseDistanceToAPowerNoSearch;
		break;

	case GGA_MovingAverage:
		pfGridFun = GridMovingAverage;
		break;

	case GGA_MovingFitting:
		pfGridFun = GridMovingFitting;
		break;

	default:
		return 0;
	}

	//�ֱ��ʴ�С
	const double dbDeltaX = (dbXMax-dbXMin)/nXSize;
	const double dbDeltaY = (dbYMax-dbYMin)/nYSize;

	//һ�еĴ�С
	//int nLineSize = sizeof(float)*nXSize;

	double *pValues = new double[nXSize];

	for (int nY = 0; nY < nYSize; nY ++)
	{
		const double dbYCoord = dbYMin + (nY + 0.5)*dbDeltaY;
		for (int nX = 0; nX < nXSize; nX ++)
		{
			const double dbXCoord = dbXMin + (nX + 0.5)*dbDeltaX;
			if (pfGridFun != NULL)
			{
				(*pfGridFun)( poOptions, nPointCount, padfX, padfY, padfZ,
					dbXCoord, dbYCoord,pValues+nX, NULL );
			}
		}

		//����Ҫ��doubleֵ���Ƶ�pData��Ӧ��λ��
		int nYoffset = (nYSize-nY-1)*nXSize;
		for (int nX = 0; nX < nXSize; nX ++)
		{
			//nYoffset += nX;
			pData[nYoffset++] = pValues[nX];
		}
	}

	delete []pValues;

	return 0;
}

int GridInverseDistanceToAPowerNoSearch( const void *poOptions, unsigned int nPoints,
										const double *padfX, const double *padfY,
										const double *padfZ,
										double dfXPoint, double dfYPoint,
										double *pdfValue,
										void* hExtraParamsIn )
{
	GridInverseDistanceToAPowerOptions *pOtion = (GridInverseDistanceToAPowerOptions *)poOptions;
	const double    dfPowerDiv2 = pOtion->dbPower / 2;
	const double    dfSmoothing = pOtion->dbSmoothing;
	const double    dfSmoothing2 = dfSmoothing * dfSmoothing;	//ƽ��ϵ��
	double  dfNominator = 0.0, dfDenominator = 0.0;
	unsigned int i = 0;
	bool bPower2 = (1.0 == dfPowerDiv2 );		//�Ƿ�ƽ��

	if( bPower2 )
	{
		if( dfSmoothing2 > 0 )
		{
			for ( i = 0; i < nPoints; i++ )
			{
				const double dfRX = padfX[i] - dfXPoint;
				const double dfRY = padfY[i] - dfYPoint;
				const double dfR2 = dfRX * dfRX + dfRY * dfRY + dfSmoothing2;

				double dfInvR2 = 1.0 / dfR2;
				dfNominator += dfInvR2 * padfZ[i];
				dfDenominator += dfInvR2;
			}
		}
		else
		{
			for ( i = 0; i < nPoints; i++ )
			{
				const double dfRX = padfX[i] - dfXPoint;
				const double dfRY = padfY[i] - dfYPoint;
				const double dfR2 = dfRX * dfRX + dfRY * dfRY;

				if ( dfR2 < 0.0000000000001 )
				{
					break;
				}
				else
				{
					double dfInvR2 = 1.0 / dfR2;
					dfNominator += dfInvR2 * padfZ[i];
					dfDenominator += dfInvR2;
				}
			}
		}
	}
	else
	{
		for ( i = 0; i < nPoints; i++ )
		{
			const double dfRX = padfX[i] - dfXPoint;
			const double dfRY = padfY[i] - dfYPoint;
			const double dfR2 = dfRX * dfRX + dfRY * dfRY + dfSmoothing2;

			if ( dfR2 < 0.0000000000001 )
			{
				break;
			}
			else
			{
				const double dfW = pow( dfR2, dfPowerDiv2 );
				double dfInvW = 1.0 / dfW;
				dfNominator += dfInvW * padfZ[i];
				dfDenominator += dfInvW;
			}
		}
	}

	//�������ֵ�������ɢ���ر������ֱ�Ӳ�����ɢ���ϵ�Zֵ
	if( i != nPoints )
	{
		(*pdfValue) = padfZ[i];
	}
	else
		if ( 0.0 == dfDenominator )		//��ĸΪ0�������Чֵ
		{
			(*pdfValue) = pOtion->dbNoDataValue;
		}
		else
		{
			(*pdfValue) = dfNominator / dfDenominator;
		}

	return 1;
}


#define TO_RADIANS (3.14159265358979323846 / 180.0)

int GridMovingAverage( const void *poOptions, unsigned int nPoints,
					  const double *padfX, const double *padfY,
					  const double *padfZ,
					  double dfXPoint, double dfYPoint, double *pdfValue,
					  void* hExtraParamsIn )
{
	GridMovingAverageOptions *pOption = (GridMovingAverageOptions *)poOptions;
	double  dbRadius1 = pOption->dbRadius1;
	double  dbRadius2 = pOption->dbRadius2;

	dbRadius1 *= dbRadius1;
	dbRadius2 *= dbRadius2;
	double  dfR12 = dbRadius1 * dbRadius2;

	// ������תϵ��
	double  dbCoeff1 = 0.0;
	double  dbCoeff2 = 0.0;
	const double dbAngle = TO_RADIANS * pOption->dbAngle;		//ת��Ϊ����
	const bool  bRotated = ( dbAngle == 0.0 ) ? 0 : 1;
	if ( bRotated )
	{
		dbCoeff1 = cos(dbAngle);
		dbCoeff2 = sin(dbAngle);
	}

	double  dbAccumulator = 0.0;
	unsigned int i = 0, n = 0;

	while ( i < nPoints )
	{
		double  dbRX = padfX[i] - dfXPoint;
		double  dbRY = padfY[i] - dfYPoint;

		if ( bRotated )
		{
			double dfRXRotated = dbRX * dbCoeff1 + dbRY * dbCoeff2;
			double dfRYRotated = dbRY * dbCoeff1 - dbRX * dbCoeff2;

			dbRX = dfRXRotated;
			dbRY = dfRYRotated;
		}

		// �ж��Ƿ���������Բ��
		if ( dbRadius2 * dbRX * dbRX + dbRadius1 * dbRY * dbRY <= dfR12 )
		{
			dbAccumulator += padfZ[i];
			n++;
		}

		i++;
	}

	if ( n < pOption->nMinPoints || n == 0 )
	{
		(*pdfValue) = pOption->dbNoDataValue;
	}
	else
	{
		(*pdfValue) = dbAccumulator / n;
	}

	return 1;
}

int GridMovingFitting( const void *poOptions, unsigned int nPoints,
					  const double *padfX, const double *padfY,
					  const double *padfZ,
					  double dfXPoint, double dfYPoint, double *pdfValue,
					  void* hExtraParamsIn )
{
	GridMovingFittingOptions *pOption = (GridMovingFittingOptions*)poOptions;
	double dbRadius = pOption->dbRadius;

	unsigned int n = 0;

	std::vector<double> vecX;
	std::vector<double> vecY;
	std::vector<double> vecZ;
	std::vector<double> vecW;	//Ȩ������

	//�ҳ��͵�ǰ���ٽ�������
	int nCol = (dfXPoint-stGridIndex.dbMinX)/stGridIndex.dbXGridSize;
	int nRow = (dfYPoint-stGridIndex.dbMinY)/stGridIndex.dbYGridSize;
	int nIndex = nRow*stGridIndex.nX + nCol;

	std::vector<int> vecFids;
	if (nIndex < stGridIndex.nX*stGridIndex.nY)
	{
		std::vector<int> vecGird = stGridIndex.vecGrid[nIndex];

		//�������������ݷ���vecFids
		for (int i = 0; i < vecGird.size(); i ++)
		{
			vecFids.push_back(vecGird[i]);
		}

		//�����ĸ������ڵ�6����ȽϾ���
		if (vecFids.size() >= 6)
		{
			for (int i = 0; i < vecFids.size(); i ++)
			{
				// �ж��Ƿ���������Բ��
				double  dbRX = padfX[ vecFids[i] ] - dfXPoint;
				double  dbRY = padfY[ vecFids[i] ] - dfYPoint;
				const double dbWeight = dbRX * dbRX + dbRY * dbRY;
				if ( dbWeight <= pow(dbRadius,2) )
				{
					vecX.push_back(dbRX);
					vecY.push_back(dbRY);
					vecZ.push_back(padfZ[vecFids[i]]);
					vecW.push_back(1/dbWeight);
					n++;
				}
			}

			//������������ĵ�����6��������������Բ�İ뾶
			if (n < 6)
			{
				//����뾶�����������������ϳ��ߵ�����
				dbRadius += 2*max(stGridIndex.dbXGridSize, stGridIndex.dbYGridSize);

				//����ǰ��������Ҫ���б���գ�������һ���ظ�����
				vecFids.clear();

				//��ߵ�����
				int nLeftIndex = nRow*stGridIndex.nX + nCol-1;
				if (nLeftIndex < stGridIndex.nX*stGridIndex.nY)
				{
					std::vector<int> vecGird = stGridIndex.vecGrid[nLeftIndex];

					//�������������ݷ���vecFids
					for (int i = 0; i < vecGird.size(); i ++)
					{
						vecFids.push_back(vecGird[i]);
					}
				}

				//�ұߵ�����
				int nRightIndex = nRow*stGridIndex.nX + nCol+1;
				if (nRightIndex < stGridIndex.nX*stGridIndex.nY)
				{
					std::vector<int> vecGird = stGridIndex.vecGrid[nRightIndex];

					//�������������ݷ���vecFids
					for (int i = 0; i < vecGird.size(); i ++)
					{
						vecFids.push_back(vecGird[i]);
					}
				}

				//�ϱߵ�����
				int nTopIndex = (nRow+1)*stGridIndex.nX + nCol;
				if (nTopIndex < stGridIndex.nX*stGridIndex.nY)
				{
					std::vector<int> vecGird = stGridIndex.vecGrid[nTopIndex];

					//�������������ݷ���vecFids
					for (int i = 0; i < vecGird.size(); i ++)
					{
						vecFids.push_back(vecGird[i]);
					}
				}

				//�±ߵ�����
				int nBottomIndex = (nRow+1)*stGridIndex.nX + nCol;
				if (nBottomIndex < stGridIndex.nX*stGridIndex.nY)
				{
					std::vector<int> vecGird = stGridIndex.vecGrid[nBottomIndex];

					//�������������ݷ���vecFids
					for (int i = 0; i < vecGird.size(); i ++)
					{
						vecFids.push_back(vecGird[i]);
					}
				}

				for (int i = 0; i < vecFids.size(); i ++)
				{
					// �ж��Ƿ���������Բ��
					double  dbRX = padfX[ vecFids[i] ] - dfXPoint;
					double  dbRY = padfY[ vecFids[i] ] - dfYPoint;
					const double dbWeight = dbRX * dbRX + dbRY * dbRY;
					if ( dbWeight <= pow(dbRadius,2) )
					{
						vecX.push_back(dbRX);
						vecY.push_back(dbRY);
						vecZ.push_back(padfZ[ vecFids[i] ]);
						vecW.push_back(1/dbWeight);
						n++;
					}
				}
			}
		}
	}


	//����6���㣬����Чֵ���
	if (n < 6)
	{
		*pdfValue = pOption->dbNoDataValue;
	}

	//����6���㣬��ƽ��ķ�������
	else if (n >= 6)
	{
		int nCount  = vecX.size();
		double *pMatM = new double[nCount*6];		//M����
		double *pMatP = new double[nCount*nCount];	//Ȩ�ؾ���
		double *pMatZ = &vecZ[0];
		memset(pMatP,0,sizeof(double)*nCount*nCount);
		for (int i = 0; i < nCount; i ++)
		{
			pMatM[i*6] = vecX[i]*vecX[i];
			pMatM[i*6+1] = vecX[i]*vecY[i];
			pMatM[i*6+2] = vecY[i]*vecY[i];
			pMatM[i*6+3] = vecX[i];
			pMatM[i*6+4] = vecY[i];
			pMatM[i*6+5] = 1;

			pMatP[i*6+i] = vecW[i];
		}

		//���о�����㡢
		double *pMatMT = new double[nCount*6];
		double *pMatM1 = new double[nCount*6];
		double *pMatM2 = new double[nCount*nCount];
		double *pMatM3 = new double[36];
		MatrixTranspose(pMatM,pMatMT,nCount,6);
		MatrixMult(pMatMT,pMatP,pMatM1,6,nCount,nCount);
		MatrixMult(pMatM1,pMatM,pMatM3,6,nCount,6);
		MatrixInverse(pMatM3,6);
		MatrixMult(pMatM3,pMatMT,pMatM1,6,6,nCount);
		MatrixMult(pMatM1,pMatP,pMatM2,6,nCount,nCount);
		double dbCoff[6];
		MatrixMult(pMatM2,pMatZ,dbCoff,6,nCount,1);
		*pdfValue = dbCoff[5];

		delete []pMatM;
		delete []pMatP;
		delete []pMatMT;
		delete []pMatM1;
		delete []pMatM2;
		delete []pMatM3;
	}
	return 1;
}

int GridTrendSurface( const void *poOptions, unsigned int nPoints,
					 const double *padfX, const double *padfY,
					 const double *padfZ,
					 double dfXPoint, double dfYPoint, double *pdfValue,
					 void* hExtraParamsIn )
{
	return 1;
}
