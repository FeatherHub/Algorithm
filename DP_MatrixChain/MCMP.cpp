#include "MCMP.h"
#include "Matrix.h"
#include <limits>

int MCMP::TopDown(Matrix** matArr, int beginIdx, int endIdx)
{
	//행렬 한 개에 대해서는 곱셈이 정의될 수 없다
	//= 종료조건
	if (beginIdx == endIdx)
	{
		return 0;
	}

	int minCalcCnt = INT_MAX;

	//beginIdx + 1 -> access to invalid index error
	for (int endOfLeftIdx = beginIdx; endOfLeftIdx < endIdx; endOfLeftIdx++)
	{
		int res = 
			//left calc count
			TopDown(matArr, beginIdx, endOfLeftIdx) +
			//right calc count
			TopDown(matArr, endOfLeftIdx + 1, endIdx) +
			//left * right calc count
			(matArr[beginIdx]->Row() * matArr[endOfLeftIdx]->Col() * matArr[endIdx]->Col());
	
		minCalcCnt = min(minCalcCnt, res);
	}
	
	return minCalcCnt;
}

int MCMP::Memo(Matrix** matArr, int matNum)
{
	//make 2d square array for memo
	//[i,j] means (Ai * Ai+1 ... * Aj) result
	int** memo = new int*[matNum];
	for (int i = 0; i < matNum; i++)
	{
		memo[i] = new int[matNum];
	}

	//initialize 2d array
	//if i==j, 0
	//else, NOT_CALCED
	for (int i = 0; i < matNum; i++)
	{
		for (int j = 0; j < matNum; j++)
		{
			if (i == j)
			{
				memo[i][j] = 0;
			}
			else
			{
				memo[i][j] = NOT_CALCED;
			}
		}
	}

	int res = _Memo(matArr, memo, 0, matNum-1);

	//free memo array
	for (int i = 0; i < matNum; i++)
	{
		delete[] memo[i];
	}
	delete[] memo;

	return res;
}

int MCMP::_Memo(Matrix** matArr, int** memo, int sIdx, int eIdx)
{
	if (sIdx == eIdx)
	{
		return 0;
	}

	if (memo[sIdx][eIdx] != NOT_CALCED)
	{
		return memo[sIdx][eIdx];
	}

	int minCalcCnt = INT_MAX;

	for (int endOfLeftIdx = sIdx; endOfLeftIdx < eIdx; endOfLeftIdx++)
	{
		int res = _Memo(matArr, memo, sIdx, endOfLeftIdx) +
			_Memo(matArr, memo, endOfLeftIdx + 1, eIdx) +
			(matArr[sIdx]->Row() * matArr[endOfLeftIdx]->Col() * matArr[eIdx]->Col());

		minCalcCnt = min(res, minCalcCnt);
	}

	memo[sIdx][eIdx] = minCalcCnt;

	return minCalcCnt;
}

int MCMP::BottomUp(Matrix** matArr, int matNum)
{
	//make 2d square array for table
	//[i,j] means (Ai * Ai+1 ... * Aj) result
	int** table = new int*[matNum];
	for (int i = 0; i < matNum; i++)
	{
		table[i] = new int[matNum];
	}

	//initialize 2d array
	//if i==j, 0
	//else, NOT_CALCED
	for (int i = 0; i < matNum; i++)
	{
		for (int j = 0; j < matNum; j++)
		{
			if (i == j)
			{
				table[i][j] = 0;
			}
			else
			{
				table[i][j] = NOT_CALCED;
			}
		}
	}

	for (int beginIdx = matNum - 2; beginIdx > 0; beginIdx--)
	{
		for (int endIdx = beginIdx + 1; endIdx < matNum; endIdx++)
		{
			int minCalcCnt = INT_MAX;
			for (int endOfLeftIdx = beginIdx; endOfLeftIdx < matNum; endOfLeftIdx++)
			{
				int res = table[beginIdx][endOfLeftIdx] + 
					table[endOfLeftIdx+1][endIdx] +
				(matArr[beginIdx]->Row() * matArr[endOfLeftIdx]->Col() * matArr[endIdx]->Col());

				minCalcCnt = min(res, minCalcCnt);
			}

			table[beginIdx][endIdx] = minCalcCnt;
		}
	}
	
	int res = table[0][matNum - 1];

	//free table array
	for (int i = 0; i < matNum; i++)
	{
		delete[] table[i];
	}
	delete[] table;

	return res;
}
