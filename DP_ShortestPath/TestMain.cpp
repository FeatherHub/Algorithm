#include <iostream>
using namespace std;

#include "ShortestPathDAG.h"
#include "ShortestPathDCG.h"
#include "Vertex.h"

void TestDAG();
void TestDCG();

int main()
{
	TestDAG(); //Directed Acycle Graph
	TestDCG(); //Directed Cycle Graph

	return 0;
}

void TestDAG()
{
	//강의자료의 그림을 참고해서 구성했음

	Vertex* s = new Vertex();
	Vertex* r = new Vertex();
	Vertex* t = new Vertex();
	Vertex* x = new Vertex();
	Vertex* y = new Vertex();
	Vertex* z = new Vertex();

	s->AddEdgeToOther(r, 3);
	s->AddEdgeToOther(t, 2);
	r->AddEdgeToOther(z, 5);
	r->AddEdgeToOther(x, 1);
	t->AddEdgeToOther(y, 4);
	x->AddEdgeToOther(z, 2);
	x->AddEdgeToOther(y, 1);
	y->AddEdgeToOther(z, 1);

	z->AddEdgeToMe(r, 5);
	z->AddEdgeToMe(x, 2);
	z->AddEdgeToMe(y, 1);
	y->AddEdgeToMe(x, 1);
	y->AddEdgeToMe(t, 4);
	x->AddEdgeToMe(r, 1);
	r->AddEdgeToMe(s, 3);
	t->AddEdgeToMe(s, 2);

	ShortestPathDAG sp;
	int tdRes = sp.TopDown(s, z);
	cout << tdRes << endl;

	int mmRes = sp.Memo(s, z);
	cout << mmRes << endl;

	int buRes = sp.BottomUp(s, z);
	cout << buRes << endl;
}

void TestDCG()
{
	Vertex::ResetSerial();

	//강의자료의 그림 참고해서 구성했음

	Vertex* s = new Vertex();
	Vertex* v1 = new Vertex();
	Vertex* v2 = new Vertex();
	Vertex* v3 = new Vertex();

	s->AddEdgeToOther(v1, 1);
	v1->AddEdgeToOther(v2, 1);
	v1->AddEdgeToOther(v3, 1);
	v2->AddEdgeToOther(v3, 1);
	v3->AddEdgeToOther(v1, 1);
	v3->AddEdgeToOther(s, 1);

	s->AddEdgeToMe(v3, 1);
	v1->AddEdgeToMe(s, 1);
	v1->AddEdgeToMe(v3, 1);
	v2->AddEdgeToMe(v1, 1);
	v3->AddEdgeToMe(v1, 1);
	v3->AddEdgeToMe(v2, 1);

	ShortestPathDCG sp;
	int tpRes = sp.TopDownMemod(s, v3, 4);
	cout << tpRes << endl;

}