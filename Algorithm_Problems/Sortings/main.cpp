#include "SortTest.h"
#include "BubbleSort.h"
#include "SelectSort.h"
#include "InsertionSort.h"

int main()
{
	SortTest st;
//	st.TestAlgorithm(BubbleSort, "BubbleSort");
//	st.TestAlgorithm(SelectSort, "SelectSort");
	st.TestAlgorithm(InsertionSort, "InsertionSort");

	return 0;
}