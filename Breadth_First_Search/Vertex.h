#pragma once

#include <vector>
#include "config.h"

class Vertex
{
public:
	Vertex();

	Vertex* GetKthNeighbor(int k);
	void AddNeighbor(Vertex* neighbor);

	Vertex* GetPredecessor() const;
	void SetPredecessor(Vertex* predecessor);

	int GetDistance() const;
	void SetDistance(unsigned int distance);

	short GetColor() const;
	void SetColor(short color);

private:
	vector<Vertex*> _neighbors;
	Vertex* _predecessor;
	unsigned int _distance;
	short _color;
};
