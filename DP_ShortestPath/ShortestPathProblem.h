#pragma once

class Vertex;

class ShortestPathProblem
{
public:
	//DAG에서의 Single source shortest paths
	//Source 고정, Desination이 Source로 이동
	//최단 거리 = 모든 (이전 Vertex 까지의 최단거리 + 이전 Vertex의 값)들 중 최소
	int TopDown(Vertex* s, Vertex* d);
	
	//int Memo()
	//int BottomUp()
private:
	int min(int a, int b) { return a < b ? a : b; }
};