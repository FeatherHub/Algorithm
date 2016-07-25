#include "fKnapsack.h"
#include <vector>
#include "Item.h"

#include <iostream>

int main()
{
	std::vector<Item*> items;
	items.emplace_back(new Item(10, 60));
	items.emplace_back(new Item(20, 100));
	items.emplace_back(new Item(30, 120));

	int capactiy = 50;

	int res = fKnapsack::GrdyFKnapsack(items, capactiy);
	std::cout << res << std::endl;

	return 0;
}