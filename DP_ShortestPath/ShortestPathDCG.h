#pragma once

class Vertex;

class ShortestPathDCG
{
public:
	int TopDownMemod(Vertex* s, Vertex* d, int vertexNum);
	int BottomUp(Vertex* s, Vertex* d, int vertexNum);

private:
	int _TopDownMemod(Vertex* s, Vertex* d, int** memo, int step);
	int min(int a, int b) { return a < b ? a : b; }
};