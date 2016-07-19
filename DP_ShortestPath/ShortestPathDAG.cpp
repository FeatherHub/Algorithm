#include "ShortestPathDAG.h"
#include "Vertex.h"
#include <queue>

int ShortestPathDAG::TopDown(Vertex* s, Vertex* d)
{
	if (d == s)
		return 0;

	int shortest = INT_MAX;

	//자신을 가리키는 edge로부터 거슬러 올라갈 vertex를 구한다
	auto& edgeToMeList = d->EdgeToMeList();
	for (auto& edgeToMe = edgeToMeList.begin(); edgeToMe != edgeToMeList.end(); ++edgeToMe)
	{
		int res = TopDown(s, (*edgeToMe)->StartV()) + (*edgeToMe)->Val();

		shortest = min(res, shortest);
	}

	return shortest;
}

int ShortestPathDAG::Memo(Vertex* s, Vertex* d)
{
	if (s == d)
		return 0;

	if (d->ShortestPathWeight() != Vertex::NOT_CALCULATED)
		return d->ShortestPathWeight();

	int shortestPath = INT_MAX;

	auto& edgeToMeList = d->EdgeToMeList();
	for (auto& edgeToMe = edgeToMeList.begin(); edgeToMe != edgeToMeList.end(); ++edgeToMe)
	{
		int res = Memo(s, (*edgeToMe)->StartV()) + (*edgeToMe)->Val();
		
		shortestPath = min(res, shortestPath);
	}

	d->ShortestPathWeight(shortestPath);

	return shortestPath;
}

int ShortestPathDAG::BottomUp(Vertex* s, Vertex* d)
{
	//소스를 큐에 넣는다
	//큐에 빼면서 이웃들을 넣는다
	//각 V의 최단거리를 갱신한다, 기존에 있던 값과 비교해서 작은 값으로 갱신한다

	s->ShortestPathWeight(0);

	std::queue<Vertex*> verticesToVisit;
	verticesToVisit.push(s);
	while (verticesToVisit.empty() == false)
	{
		auto& curV = verticesToVisit.back();
		verticesToVisit.pop();

		auto& adjEdgeList = curV->EdgeToOtherList();
		for (auto& e = adjEdgeList.begin(); e != adjEdgeList.end(); ++e)
		{
			auto neighborV = (*e)->TargetV();
			int neightborSP = neighborV->ShortestPathWeight();
			neightborSP = min(neightborSP, curV->ShortestPathWeight() + (*e)->Val());
			neighborV->ShortestPathWeight(neightborSP);

			verticesToVisit.push(neighborV);
		}
	}

	return d->ShortestPathWeight();
}
