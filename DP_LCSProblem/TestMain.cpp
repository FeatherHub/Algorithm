#include "LCSProblem.h"

#include <iostream>
using namespace std;

int main()
{
	char str1[]{ "abcbdab" };
	char str2[]{ "bdcaba" };

	//null-포함 문자 크기 : s 
	//null-미포함 문자 크기 : s-1 <- strlen(...), size(...) 등의 결과
	//null-미포함 마지막 문자 인덱스 : s-2

	int tdRes = LCSProblem::TopDown(str1, strlen(str1) - 1,
									str2, strlen(str2) - 1);

	cout << tdRes << endl;

	int mmRes = LCSProblem::Memo(str1, strlen(str1) - 1,
									str2, strlen(str2) - 1);

	cout << mmRes << endl;

	int buRes = LCSProblem::BottomUp(str1, strlen(str1) - 1,
										str2, strlen(str2) - 1);

	cout << buRes << endl;

	return 0;
}