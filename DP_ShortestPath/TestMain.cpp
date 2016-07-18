#include <iostream>
using namespace std;

#include "ShortestPathProblem.h"
#include "Vertex.h"

int main()
{
	//강의자료의 그림 참고
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

	ShortestPathProblem sp;
	int res = sp.TopDown(s, z);
	cout << res << endl;

	return 0;
}