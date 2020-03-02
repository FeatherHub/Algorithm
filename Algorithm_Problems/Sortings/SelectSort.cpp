#include "SelectSort.h"
#include "Utility.h"

void SelectSort(int* arr, int n)
{
	int minIdx = 0;

	// | 0 | 1 | ... | n-2 | n-1 |
	// i -> [0, n-1) = i -> [0, n-2]
	// j -> [i+1, n) = j -> [i+1, n-1]
	
	// termination condition(boundary condition)
	// enter: i = n-2, j = n-1
	// exit: i = n-2, j = n-1
	// enter then exit subloop pattern
	
	for (int i = 0; i < n-1; i++)
	{
		minIdx = i;

		for (int j = i+1; j < n; j++)
		{
			if (arr[minIdx] > arr[j])
			{
				minIdx = j;
			}
		}

		Swap(&arr[minIdx], &arr[i]);
	}
}
