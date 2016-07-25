#pragma once

#include <vector>
class Item;

//Greedy algorithm - fractional knapsack
class fKnapsack
{
public:
	static int GrdyFKnapsack(std::vector<Item*>& itemArr, float capacity);
};