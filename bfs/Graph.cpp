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
	queue<Vertex*> reservedVertices;
	reservedVertices.push(_startVertex);

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

