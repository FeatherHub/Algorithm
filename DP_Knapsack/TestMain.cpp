#include <iostream>
using namespace std;

#include "Knapsack.h"
#include "Item.h"

int main()
{
	Item itemArr[3]{ Item(10, 60), Item(20, 100),Item(30, 120) };
	int itemNum = sizeof(itemArr) / sizeof(Item);
	int maxWeight = 50;

	int tdRes = KnapSack::TopDown(itemArr, itemNum, maxWeight);
	cout << tdRes << endl;

	int mmRes = KnapSack::Memo(itemArr, itemNum, maxWeight);
	cout << mmRes << endl;

	int buRes = KnapSack::BottomUp(itemArr, itemNum, maxWeight);
	cout << buRes << endl;

	return 0;
}