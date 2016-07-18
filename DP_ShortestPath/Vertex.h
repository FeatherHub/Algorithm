#pragma once

#include "Edge.h"

#include <list>
using namespace std;

class Vertex
{
public:
	list<Edge *>& EdgeToOtherList() { return m_edgeToOtherList; }
	list<Edge *>& EdgeToMeList() { return m_edgeToMeList; }
	int ShortestPathWeight() const { return m_shortestPathWeight; }
	void ShortestPathWeight(int val) { m_shortestPathWeight = val; }

	void AddEdgeToOther(Vertex* pointedV, int val)
	{
		m_edgeToOtherList.emplace_back(new Edge{ this, pointedV, val });
	}

	void AddEdgeToMe(Vertex* pointingV, int val)
	{
		m_edgeToMeList.emplace_back(new Edge{ pointingV, this, val });
	}

private:
	list<Edge*> m_edgeToOtherList;
	list<Edge*> m_edgeToMeList;
	//for memoization
	int m_shortestPathWeight;
};
