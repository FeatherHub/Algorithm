#pragma once

class Vertex;

class Edge
{
public:
	Edge(Vertex* start, Vertex* target, int val) :
		m_start(start), m_target(target), m_val(val)
	{	}
	
	Vertex* StartV() { return m_start; }
	Vertex* TargetV() { return m_target; }
	int Val() { return m_val; }

private:
	Vertex* m_start;
	Vertex* m_target;
	int m_val;
};