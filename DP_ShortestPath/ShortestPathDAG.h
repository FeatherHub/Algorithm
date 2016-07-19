#pragma once

class Vertex;

class ShortestPathDAG
{
public:
	//DAG에서의 Single source shortest paths
	//Source 고정, Desination이 Source로 이동
	//최단 거리 = 모든 (이전 Vertex 까지의 최단거리 + 이전 Vertex의 값)들 중 최소
	int TopDown(Vertex* s, Vertex* d);
	
	//각 Vertex는 s로부터 자신에게까지의 최단경로를 저장하는 멤버를 가진다
	//그 멤버를 Memo로 활용한다
	int Memo(Vertex* s, Vertex* d);

	//Breadth First Search와 비슷하다
	//source 빼고 이웃들 넣고 계산하고 갱신하고 하면서 destination까지 진행한다
	//혹은 queue가 비면 끝낸다
	int BottomUp(Vertex* s, Vertex* d);

private:
	int min(int a, int b) { return a < b ? a : b; }
};