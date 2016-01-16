#include "Vertex.h"

Vertex::Vertex() : _distance(0), _predecessor(NULL), _color(WHITE)
{
	
}

Vertex* Vertex::GetKthNeighbor(int k)
{
	if (k < 0 || k > _neighbors.size())
	{
		return NULL;
	}

	return _neighbors.at(k);
}

void Vertex::AddNeighbor(Vertex* neighbor)
{
	_neighbors.push_back(neighbor); 
}

Vertex* Vertex::GetPredecessor() const
{
	return _predecessor;
}

void Vertex::SetPredecessor(Vertex* predecessor)
{
	if (!predecessor)
	{
		return;
	}

	_predecessor = predecessor;
}

int Vertex::GetDistance() const
{
	return _distance;
}

void Vertex::SetDistance(unsigned int distance)
{
	if (distance < 0 || distance > UINT_MAX)
	{
		return;
	}

	_distance = distance;
}

short Vertex::GetColor() const
{
	return _color;
}

void Vertex::SetColor(short color)
{
	if (color != WHITE	|| 
		color != GRAY	|| 
		color != BLACK	)
	{
		return;
	}

	_color = color;
}