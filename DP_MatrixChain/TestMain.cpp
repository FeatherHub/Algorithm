#include <iostream>
using namespace std;

#include "MCMP.h"
#include "Matrix.h"

int main()
{
	const int MAT_NUM = 4;
	Matrix* matArray[MAT_NUM];
	for (int i = 0; i < MAT_NUM; i++)
	{
		int j = i + 3;
		matArray[i] = new Matrix(j, j+1);
	}

	MCMP mcmp;
	int tdRes = mcmp.TopDown(matArray, 0, MAT_NUM - 1);
	cout << "TopDown Result : " << tdRes << endl;

	int mmRes = mcmp.Memo(matArray, MAT_NUM);
	cout << "BottomUp Result : " << mmRes << endl;

	int buRes = mcmp.Memo(matArray, MAT_NUM);
	cout << "BottomUp Result : " << buRes << endl;

	return 0;
}