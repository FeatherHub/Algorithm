#pragma once

class Item
{
public:
	Item(int w, int p) : weight(w), price(p) {}
	int Weight() const { return weight; }
	int Price() const { return price; }

private:
	int weight;
	int price;
};