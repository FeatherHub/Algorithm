#include "RBT.h"
#include "Node.h"
#include <iostream>

using namespace std;

void TestRBT()
{
	Node* A = Node::Create(10, BLACK);
	Node* B = Node::Create(20);
	Node* C = Node::Create(30);
	Node* D = Node::Create(40);
	Node* E = Node::Create(50);
	Node* F = Node::Create(60);

	RBT* rbt = RBT::Create(A);

	rbt->Insert(B);
	rbt->Insert(C);
	rbt->Insert(D);
	rbt->Insert(E);
	rbt->Insert(F);

	rbt->PrintInOrder();

	rbt->Delete(A);
	rbt->Delete(B);
	rbt->Delete(C);
	rbt->Delete(D);
	rbt->Delete(E);

	rbt->PrintInOrder();

	delete A;
	delete B;
	delete C;
	delete D;
	delete E;
	delete rbt;
}

int main()
{
	int* a = 0;
	int* b = a;

	if (a==b)
		TestRBT();
	
	return 0;
}