#include "LCSProblem.h"

int LCSProblem::TopDown(const char* str1, int str1Idx, const char* str2, int str2Idx)
{
	if (str1Idx < 0 || str2Idx < 0)
		return 0;

	int lcsLen = 0;
	if (str1[str1Idx] == str2[str2Idx])
		lcsLen = 1 + TopDown(str1, str1Idx - 1, str2, str2Idx - 1);
	else
		lcsLen = max(TopDown(str1, str1Idx-1, str2, str2Idx), 
					TopDown(str1, str1Idx, str2, str2Idx-1));

	return lcsLen;
}

int LCSProblem::Memo(const char* str1, int str1Idx, const char* str2, int str2Idx)
{
	//create 2d array table for memo
	int** memo = new int*[str1Idx+1];
	for (int i = 0; i <= str1Idx; i++)
	{
		memo[i] = new int[str2Idx+1];
	}

	//initialize str1Idx x str2Idx table with NOT_CALCED
	for (int i = 0; i <= str1Idx; i++)
	{
		for (int j = 0; j <= str2Idx; j++)
		{
			memo[i][j] = NOT_CALCED;
		}
	}

	int res = _Memo(memo, str1, str1Idx, str2, str2Idx);

	//delete table
	for (int i = 0; i <= str1Idx; i++)
	{
		delete[] memo[i];
	}
	delete[] memo;

	return res;
}

int LCSProblem::_Memo(int** memo, const char* str1, int str1Idx, const char* str2, int str2Idx)
{
	if (str1Idx < 0 || str2Idx < 0)
		return 0;

	if (memo[str1Idx][str2Idx] != NOT_CALCED)
		return memo[str1Idx][str2Idx];

	int lcsLen = 0;
	if (str1[str1Idx] == str2[str2Idx])
		lcsLen = 1 + _Memo(memo, str1, str1Idx - 1, str2, str2Idx - 1);
	else
		lcsLen = max(_Memo(memo, str1, str1Idx - 1, str2, str2Idx),
					_Memo(memo, str1, str1Idx, str2, str2Idx - 1));

	memo[str1Idx][str2Idx] = lcsLen;

	return lcsLen;
}

//index 관점에서 접근했을 때 루프의 boundary 처리가 가독성이 떨어졌다
//교재의 length 관점에서 접근했을 때 루프의 코드가 가독성이 좋았다
int LCSProblem::BottomUp(const char* str1, int str1Idx, const char* str2, int str2Idx)
{
	//create 2d array table for iteration
	//first +1 is for [0, strIdx], second +1 is for dummy area 
	int** table = new int*[str1Idx+1+1];
	for (int i = 0; i <= str1Idx+1; i++)
	{
		table[i] = new int[str2Idx+1+1];
	}

	//initialize str1Idx x str2Idx table with zero
	for (int i = 0; i <= str1Idx+1; i++)
	{
		for (int j = 0; j <= str2Idx+1; j++)
		{
			table[i][j] = 0;
		}
	}

	for (int curStr1Idx = 0; curStr1Idx <= str1Idx; curStr1Idx++)
	{
		for (int curStr2Idx = 0; curStr2Idx <= str2Idx; curStr2Idx++)
		{
			if (str1[curStr1Idx] == str2[curStr2Idx])
			{
				table[curStr1Idx + 1][curStr2Idx + 1] =
					max(1 + table[curStr1Idx][curStr2Idx],
						table[curStr1Idx + 1][curStr2Idx + 1]);
			}
			//else로 해도 되는 이유??
			//왜냐하면 현재 칸의 값이 다음 계산에 사용될 수 있으니까 
			else
			{
				table[curStr1Idx + 1][curStr2Idx] =
					max(table[curStr1Idx][curStr2Idx],
						table[curStr1Idx + 1][curStr2Idx]);

				table[curStr1Idx][curStr2Idx + 1] =
					max(table[curStr1Idx][curStr2Idx],
						table[curStr1Idx][curStr2Idx + 1]);
			}
		}
	}

	int res = 0;
	for (int rowIdx = 0; rowIdx <= str1Idx+1; rowIdx++)
	{
		res = max(res, table[rowIdx][str2Idx+1]);
	}

	for (int colIdx = 0; colIdx <= str2Idx+1; colIdx++)
	{
		res = max(res, table[str1Idx+1][colIdx]);
	}

	//delete table
	for (int i = 0; i <= str1Idx; i++)
	{
		delete[] table[i];
	}
	delete[] table;

	return res;
}
