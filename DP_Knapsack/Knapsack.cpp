#include "Knapsack.h"
#include "Item.h"

int KnapSack::TopDown(Item* itemArr, int itemNum, int maxWeight)
{
	if (itemNum <= 0 || maxWeight <= 0)
		return 0;

	//넣을 수 있으면 - max(넣은 경우, 안 넣은 경우) 계산
	if (itemArr[itemNum - 1].Weight() <= maxWeight)
	{
		int includeCase = itemArr[itemNum - 1].Price() 
			+ TopDown(itemArr, itemNum - 1, maxWeight - itemArr[itemNum - 1].Weight());

		int notIncludeCase = TopDown(itemArr, itemNum - 1, maxWeight);

		return max(includeCase, notIncludeCase);
	}
	//넣을 수 없으면 - 안 넣은 경우 계산
	else
	{
		return TopDown(itemArr, itemNum - 1, maxWeight);
	}
}

int KnapSack::Memo(Item* itemArr, int itemNum, int maxWeight)
{
	//row : weight [0,maxWeight] -> maxWeight+1
	//col : item id [0, itemNum) -> itemNum
	//memo[i][j] : accumulated price in selecting item j when maxWeight is i

	int** memo = new int*[maxWeight + 1];
	for (int i = 0; i <= maxWeight; i++)
		memo[i] = new int[itemNum];

	//init memo with NOT_CALCULATED
	for (int i = 0; i <= maxWeight; i++)
	{
		for (int j = 0; j < itemNum; j++)
		{
			memo[i][j] = NOT_CALCULATED;
		}
	}

	int res = _Memo(memo, itemArr, itemNum, maxWeight);

	for (int i = 0; i <= maxWeight; i++)
		delete[] memo[i];
	delete[] memo;

	return res;
}

int KnapSack::_Memo(int** memo, Item* itemArr, int itemNum, int maxWeight)
{
	if (itemNum <= 0 || maxWeight <= 0)
		return 0;

	if (memo[maxWeight][itemNum - 1] != NOT_CALCULATED)
		return memo[maxWeight][itemNum - 1];

	int res;

	if (itemArr[itemNum - 1].Weight() <= maxWeight)
	{
		int includeCase = itemArr[itemNum - 1].Price()
			+ TopDown(itemArr, itemNum - 1, maxWeight - itemArr[itemNum - 1].Weight());

		int notIncludeCase = TopDown(itemArr, itemNum - 1, maxWeight);

		res = max(includeCase, notIncludeCase);
	}
	else
	{
		res = TopDown(itemArr, itemNum - 1, maxWeight);
	}

	memo[maxWeight][itemNum - 1] = res;
	
	return res;
}

int KnapSack::BottomUp(Item* itemArr, int itemNum, int maxWeight)
{
	int** table = new int*[maxWeight + 1];
	for (int i = 0; i <= maxWeight; i++)
		table[i] = new int[itemNum];

	for (int i = 0; i <= maxWeight; i++)
	{
		for (int j = 0; j < itemNum; j++)
		{
			table[i][j] = NOT_CALCULATED;
		}
	}

	//초기값 세팅
	//첫번째 아이템을 안 넣음
	table[0][0] = 0;
	//첫번째 아이템을 넣을 수 있으면 넣음
	if(table[itemArr[0].Weight()][0] <= maxWeight)
		itemArr[0].Price();

	//모든 무게에 대해 계산 -> 다음 보물 계산
	//각 칸은 전 칸의 값을 참조하여 자신을 넣거나 안 넣거나해서 자기 칸을 채운다
	for (int itemId = 1; itemId < itemNum; itemId++)
	{
		for (int curWeight = 0; curWeight <= maxWeight; curWeight++)
		{
			if (table[curWeight][itemId-1] != NOT_CALCULATED)
			{
				int availableWeight = maxWeight - curWeight;
				int curItemWeight = itemArr[itemId].Weight();
				int curItemPrice = itemArr[itemId].Price();

				//넣을 수 있을 때 넣은 경우, 현재 보물 위치에 대입
				if (curItemWeight <= availableWeight)
				{
					//availableWeight를 index로 사용할 수 있도록 변환
					int availableIdx = maxWeight - availableWeight;
					table[availableIdx + curItemWeight][itemId] =
						table[curWeight][itemId - 1] + curItemPrice;
				}
				//안 넣는 경우, 큰 값이면 현재 보물 위치에 대입
				table[curWeight][itemId] = max(table[curWeight][itemId],
					table[curWeight][itemId - 1]);
			}
		}
	}

	//마지막 보물 열을 조사해서 최대값 반환
	int maxPrice = 0;
	for (int w = 0; w <= maxWeight; w++)
	{
		maxPrice = max(maxPrice, table[w][itemNum - 1]);
	}

	for (int i = 0; i <= maxWeight; i++)
		delete[] table[i];
	delete[] table;

	return maxPrice;
}