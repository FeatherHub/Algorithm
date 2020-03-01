#pragma once

#include <vector>
#include "Vertex.h"

class Graph
{
public:
	Graph(Vertex* startVertext);

	Vertex* GetStartVertex();
	void BreadthFirstSearch();

private:
	vector<Vertex*> _vertices;
	Vertex* _startVertex;
};
