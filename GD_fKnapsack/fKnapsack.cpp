#include "fKnapsack.h"
#include "Item.h"
#include <algorithm> //sort

int fKnapsack::GrdyFKnapsack(std::vector<Item*>& itemArr, float capacity)
{
	if (itemArr.size() <= 0 || capacity <= 0)
		return 0;

	std::sort(itemArr.begin(), itemArr.end(),
		//non-capture / parameter / return type
		[](Item* i, Item* j)->bool
	{ 
		//descending order by mileage 
		return (i->Price() / i->Weight()) > (j->Price() / j->Weight()) ? true : false; 
	});

	float totalPrice = 0.f;

	int i = 0;
	while (i < itemArr.size() && capacity > 0)
	{
		float mileage = itemArr[i]->Price() / itemArr[i]->Weight();
		if (itemArr[i]->Weight() > capacity)
		{
			totalPrice += capacity * mileage;
			capacity = 0;
		}
		else //현재 보물 무게 <= 현재 여유 무게
		{
			totalPrice += itemArr[i]->Weight() * mileage;
			capacity -= itemArr[i]->Weight();
		}

		i++;
	}

	return totalPrice;
}