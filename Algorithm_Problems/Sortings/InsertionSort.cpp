#include "InsertionSort.h"

void InsertionSort(int* arr, int n)
{
	// i -> [0, n-1)
	// j -> [0, i], arr[i+1] inserts into [0, i]
	
	//termination condition
	// ... | n-2 | n-1 | 
	// i = n - 2
	// i+1 = n - 1 
	// j -> [0, n-2]

	int curVal = 0;
	for (int i = 0; i < n - 1; i++)
	{
		curVal = arr[i + 1];
		for (int j = 0; j <= i; j++)
		{
			if (arr[j] > curVal)
			{
				//#1. push back
				// k -> [i, j]
				for (int k = i; k >= j; k--)
				{
					arr[k + 1] = arr[k];
				}

				//#2. inserts curVal into arr[j]
				arr[j] = curVal;

				break;
			}
		}
	}
}
