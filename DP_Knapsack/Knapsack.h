#pragma once

class Item;

class KnapSack
{
public:
	static int TopDown(Item* itemArr, int itemNum, int maxWeight);

	static int Memo(Item* itemArr, int itemNum, int maxWeight);

	static int BottomUp(Item* itemArr, int itemNum, int maxWeight);
private:
	static int _Memo(int** memo, Item* itemArr, int itemNum, int maxWeight);

	static int max(int a, int b) { return a > b ? a : b; }

	enum { NOT_CALCULATED = -1 };
};