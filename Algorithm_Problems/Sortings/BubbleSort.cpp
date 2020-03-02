#include "BubbleSort.h"
#include "Utility.h"

void BubbleSort(int* arr, int n)
{
	//range expr (0, n-1] 
	//i: [(n-1) -> 0)
	for (int i = n-1; i > 0; i--)
	{
		//range expr [0, i)
		//j: [0 -> i)
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}