#ifndef _RBT_H_
#define _RBT_H_
#include "RBT.h"
#endif 

RBT* RBT::Create(Node* root)
{
	if (!root)
		return 0;

	RBT* rbt = new RBT();
	rbt->_root = root;

	return rbt;
}

RBT::RBT()
{
	_root = 0;
}

bool RBT::Insert(Node* toInsert)
{

}

bool RBT::Delete(Node* toDelete)
{

}

bool RBT::Search(Node* toSearch)
{

}

void RBT::SetRoot(Node* root)
{
	if (!root)
		return;

	_root = root;
}

void RBT::RightRotate(Node* toRR)
{

}

void RBT::LeftRotate(Node* toLR)
{

}

void RBT::FixInsertion(Node* toFix)
{

}

void RBT::FixDeletion(Node* toFix)
{

}

void RBT::Transplant(Node* toRemove, Node* toPlant)
{

}
