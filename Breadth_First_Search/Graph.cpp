#include "Graph.h"
#include <queue>

Graph::Graph(Vertex* startVertex) : _startVertex(startVertex)
{

}

Vertex* Graph::GetStartVertex()
{
	return _startVertex;
}

void Graph::BreadthFirstSearch()
{
	for (Vertex* vertex : _vertices)
	{
		vertex->SetPredecessor(NULL);
		vertex->SetColor(WHITE);
		vertex->SetDistance(INT_MAX);
	}

	queue<Vertex*> reservedVertices;
	reservedVertices.push(_startVertex);
	
	_startVertex->SetPredecessor(NULL);
	_startVertex->SetColor(GRAY);
	_startVertex->SetDistance(0);

	while (!reservedVertices.empty())
	{
		Vertex* curVisiting = reservedVertices.back();
		reservedVertices.pop();

		int k = 0;
		while (Vertex* neighbor = curVisiting->GetKthNeighbor(k++))
		{
			if (neighbor->GetColor() == WHITE)
			{
				reservedVertices.push(neighbor);
				neighbor->SetColor(GRAY);
				neighbor->SetDistance(curVisiting->GetDistance() + 1);
				neighbor->SetPredecessor(curVisiting);
			}
		}
		curVisiting->SetColor(BLACK);
	}
}