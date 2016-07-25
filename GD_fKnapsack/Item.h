#pragma once

class Item
{
public:
	Item(float weight, float price) : m_weight(weight), m_price(price)
	{
	}

	float Weight() const { return m_weight; }
	float Price() const { return m_price; }

private:
	float m_weight;
	float m_price;
};

