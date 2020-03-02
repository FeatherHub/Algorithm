#include "SortTest.h"
#include "BubbleSort.h"
#include "SelectSort.h"

int main()
{
	SortTest st;
//	st.TestAlgorithm(BubbleSort, "BubbleSort");
	st.TestAlgorithm(SelectSort, "SelectSort");

	return 0;
}