#pragma once

//Longest common subsequence problem

/* Dynamic progarmming
 *
 * 1. recursive
 *	include case vs not include case
 *	if include, no need to check not include case
 * 2. memoization
 *	memo the reusable case  
 * 3. bottom up
 *  fill the table 
 *	referencing the tree node mechanism of the recursion
*/

class LCSProblem 
{
public:
	static int TopDown(const char* str1, int str1Idx, const char* str2, int str2Idx);
	static int Memo(const char* str1, int str1Idx, const char* str2, int str2Idx);
	static int BottomUp(const char* str1, int str1Idx, const char* str2, int str2Idx);

private:
	static int _Memo(int** memo, const char* str1, int str1Idx, const char* str2, int str2Idx);

	static int max(int a, int b) { return a > b ? a : b; }

	enum { NOT_CALCED = -1 };
};