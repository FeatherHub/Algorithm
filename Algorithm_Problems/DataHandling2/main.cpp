#include <iostream>

int main()
{
	int arrSize = 0; // arrSize > 0
	int key = 0; // key > 0

	// set data
	std::cin >> arrSize >> key;

	int* arr = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		std::cin >> arr[i]; // arr[i] > 0
	}

	// erase not-target data
	// target data: arr[i] < key
	for (int i = 0; i < arrSize; i++)
	{
		if (!(arr[i] < key))
		{
			arr[i] = -1;
		}
		/*
		if( TestData(data) == NOT_TARGET_DATA )
		{
			DeleteData(data);
		}
		*/
	}

	// print target data
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] != -1)
		{
			std::cout << arr[i] << " ";
		}
		/*
		if ( IsTargetData(data) )
		{
			ProcessData(data);	
		}
		*/
	}

	delete[] arr;

	return 0;
}