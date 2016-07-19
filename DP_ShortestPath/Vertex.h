#pragma once

#include "Edge.h"

#include <list>
using namespace std;

class Vertex
{
public:
	Vertex() :m_id(m_serial++), m_shortestPathWeight(NOT_CALCULATED) {}

	static void ResetSerial() { m_serial = 0; }

	list<Edge *>& EdgeToOtherList() { return m_edgeToOtherList; }
	list<Edge *>& EdgeToMeList() { return m_edgeToMeList; }
	int Id() { return m_id; }
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

public:
	enum { NOT_CALCULATED = INT_MAX };

private:
	list<Edge*> m_edgeToOtherList;
	list<Edge*> m_edgeToMeList;

	int m_id;
	static int m_serial;

	//for memoization
	int m_shortestPathWeight;
};

