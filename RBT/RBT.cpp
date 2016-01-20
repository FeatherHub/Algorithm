#include "RBT.h"
#include "Node.h"
#include <iostream>
using namespace  std;

Node* RBT::NIL = new Node();

RBT* RBT::Create(Node* root)
{
	if (!root)
		return 0;

	RBT* rbt = new RBT();
	rbt->_root = root;

	NIL->SetColor(BLACK);
	NIL->SetLeft(NULL);
	NIL->SetRight(NULL);
	NIL->SetParent(NULL);

	return rbt;
}

RBT::RBT()
{
	_root = NULL;
}

void RBT::SetRoot(Node* root)
{
	if (!root)
		return;

	_root = root;
}

void RBT::PrintInOrder()
{
	_PrintInOrder(_root);
	cout << endl;
}

void RBT::_PrintInOrder(Node* node)
{
	if (node == NIL)
		return;

	_PrintInOrder(node->GetLeft());

	if (node->GetColor() == BLACK)
		cout << "B";
	else
		cout << "R";

	cout << node->GetVal() << " ";

	_PrintInOrder(node->GetRight());
}

bool RBT::Insert(Node* toInsert)
{
	if (!toInsert)
		return false;

	Node* parent = NIL;
	Node* curPos = _root;
	
	while (curPos != NIL)
	{
		parent = curPos;

		if (toInsert->GetVal() < curPos->GetVal())
			curPos = curPos->GetLeft();
		else
			curPos = curPos->GetRight();
	}

	toInsert->SetParent(parent);

	if (parent == NIL)
		_root = toInsert;
	else if (toInsert->GetVal() < parent->GetVal())
		parent->SetLeft(toInsert);
	else
		parent->SetRight(toInsert);

	toInsert->SetLeft(NIL);
	toInsert->SetRight(NIL);
	toInsert->SetColor(RED);

	FixInsertion(toInsert);

	return true;
}

bool RBT::FixInsertion(Node* toFix)
{
	if (!toFix)
		return false;

	while (toFix->GetParent()->GetColor() == RED)
	{
		if (toFix == NIL || toFix->GetParent() == NIL || toFix->GetParent()->GetParent() == NIL)
			return true;

		if (toFix->GetParent() == toFix->GetParent()->GetParent()->GetLeft())
		{
			Node* uncle = toFix->GetParent()->GetParent()->GetRight();

			if (uncle->GetColor() == RED)
			{
				toFix->GetParent()->SetColor(BLACK);
				uncle->SetColor(BLACK);
				toFix->GetParent()->GetParent()->SetColor(RED);
				toFix = toFix->GetParent()->GetParent();
			}
			else
			{
				if (toFix == toFix->GetParent()->GetRight())
				{
					toFix = toFix->GetParent();
					LeftRotate(toFix);
				}

				toFix->GetParent()->SetColor(BLACK);
				toFix->GetParent()->GetParent()->SetColor(RED);
				RightRotate(toFix->GetParent()->GetParent());
			}
		}
		//대칭
		else
		{
			Node* uncle = toFix->GetParent()->GetParent()->GetLeft();

			if (uncle->GetColor() == RED)
			{
				toFix->GetParent()->SetColor(BLACK);
				uncle->SetColor(BLACK);
				toFix->GetParent()->GetParent()->SetColor(RED);
				toFix = toFix->GetParent()->GetParent();
			}
			else
			{
				if (toFix == toFix->GetParent()->GetLeft())
				{
					toFix = toFix->GetParent();
					RightRotate(toFix);
				}

				toFix->GetParent()->SetColor(BLACK);
				toFix->GetParent()->GetParent()->SetColor(RED);
				LeftRotate(toFix->GetParent()->GetParent());
			}
		}
	}

	_root->SetColor(BLACK);

	return true;
}

bool RBT::Delete(Node* toDelete)
{
	if (!toDelete)
		return false;

	COLOR deletedColor = toDelete->GetColor();
	Node* toFix;

	if (toDelete->GetLeft() == NIL)
	{
		toFix = toDelete->GetRight();
		Transplant(toDelete, toDelete->GetRight());
	}
	else if (toDelete->GetRight() == NIL)
	{
		toFix = toDelete->GetLeft();
		Transplant(toDelete, toDelete->GetLeft());
	}
	else
	{
		Node* successor = GetSuccessorOf(toDelete);
		deletedColor = successor->GetColor();
		toFix = successor->GetRight();

		if (successor->GetParent() == NIL)
			toFix->SetParent(successor);
		else
		{
			Transplant(successor, successor->GetRight());
			successor->SetRight(toDelete->GetRight());
			successor->GetRight()->SetParent(successor);
		}

		Transplant(toDelete, successor);
		successor->SetLeft(toDelete->GetLeft());
		successor->GetLeft()->SetParent(successor);
		successor->SetColor(toDelete->GetColor());
	}

	if (deletedColor == BLACK)
		FixDeletion(toFix);

	return true;
}

bool RBT::FixDeletion(Node* toFix)
{
	if (!toFix)
		return false;

	/* root까지 올라갔을 경우 - tree의 bh가 1증가 */
	while (toFix != _root && toFix->GetColor() == BLACK)
	{
		if (toFix == toFix->GetParent()->GetLeft())
		{
			Node* sibling = toFix->GetParent()->GetRight();

			if (sibling->GetColor() == RED)
			{
				sibling->SetColor(BLACK);
				toFix->GetParent()->SetColor(RED);
				LeftRotate(toFix->GetParent());
				sibling = toFix->GetParent()->GetRight();
			}

			if (sibling->GetLeft()->GetColor() == BLACK &&
				sibling->GetRight()->GetColor() == BLACK)
			{
				sibling->SetColor(RED);
				toFix = toFix->GetParent();
			}
			else
			{
				if (sibling->GetRight()->GetColor() == BLACK)
				{
					sibling->GetLeft()->SetColor(BLACK);
					sibling->SetColor(RED);
					RightRotate(sibling);
					sibling = toFix->GetParent()->GetRight();
				}

				sibling->SetColor(toFix->GetParent()->GetColor());
				toFix->GetParent()->SetColor(BLACK);
				sibling->GetRight()->SetColor(BLACK);
				LeftRotate(toFix->GetParent());
				toFix = _root; //while문 종료
			}
		}
		//대칭
		else
		{
			Node* sibling = toFix->GetParent()->GetLeft();

			if (sibling->GetColor() == RED)
			{
				sibling->SetColor(BLACK);
				toFix->GetParent()->SetColor(RED);
				RightRotate(toFix->GetParent());
				sibling = toFix->GetParent()->GetLeft();
			}

			if (sibling->GetRight()->GetColor() == BLACK &&
				sibling->GetLeft()->GetColor() == BLACK)
			{
				sibling->SetColor(RED);
				toFix = toFix->GetParent();
			}
			else
			{
				if (sibling->GetLeft()->GetColor() == BLACK)
				{
					sibling->GetRight()->SetColor(BLACK);
					sibling->SetColor(RED);
					LeftRotate(sibling);
					sibling = toFix->GetParent()->GetLeft();
				}

				sibling->SetColor(toFix->GetParent()->GetColor());
				toFix->GetParent()->SetColor(BLACK);
				sibling->GetLeft()->SetColor(BLACK);
				RightRotate(toFix->GetParent());
				toFix = _root; //while문 종료
			}
		}
	}

	toFix->SetColor(BLACK);

	return true;
}

bool RBT::RightRotate(Node* toRR)
{
	if (!toRR)
		return false;

	Node* left = toRR->GetLeft();
	
	toRR->SetLeft(left->GetRight());

	if (left->GetRight() != NIL)
		left->GetRight()->SetParent(toRR);
	
	left->SetParent(toRR->GetParent());

	if (toRR->GetParent() == NIL)
		_root = left;
	else if (toRR == toRR->GetParent()->GetRight())
		toRR->GetParent()->SetRight(left);
	else
		toRR->GetParent()->SetLeft(left);

	left->SetRight(toRR);
	toRR->SetParent(left);

	return true;
}

bool RBT::LeftRotate(Node* toLR)
{
	if (!toLR)
		return false;

	Node* right = toLR->GetRight();

	toLR->SetRight(right->GetLeft());

	if (right->GetLeft() != NIL)
		right->GetLeft()->SetParent(toLR);

	right->SetParent(toLR->GetParent());

	if (toLR->GetParent() == NIL)
		_root = right;
	else if (toLR == toLR->GetParent()->GetLeft())
		toLR->GetParent()->SetLeft(right);
	else
		toLR->GetParent()->SetRight(right);

	right->SetLeft(toLR);
	toLR->SetParent(right);

	return true;
}

bool RBT::Transplant(Node* toRemove, Node* toPlant)
{
	if (!toPlant || !toRemove)
		return false;

	if (toRemove->GetParent() == NIL)
		_root = toPlant;
	else if (toRemove == toRemove->GetParent()->GetLeft())
		toRemove->GetParent()->SetLeft(toPlant);
	else  
		toRemove->GetParent()->SetRight(toPlant);

	toPlant->SetParent(toRemove->GetParent());
	
	return true;
}

Node* RBT::GetSuccessorOf(Node* node)
{
	Node* successor = node->GetRight();

	if (successor != NIL) 
	{
		while (successor->GetLeft() != NIL)
			successor = successor->GetLeft();
	}
	else 
	{
		successor = node->GetParent();

		while (node != successor->GetRight())
		{
			node = successor;
			successor = successor->GetParent();
		}
	
		if (successor == _root)
			successor = NIL;
	}

	return successor;
}
