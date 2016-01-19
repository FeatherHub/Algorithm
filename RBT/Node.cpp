#ifndef _NODE_H_
#define _NODE_H_
#include "Node.h"
#endif

Node* Node::Create(int val, Node* leftChild, Node* rightChild)
{
	Node* node = new Node();
	node->_val = val;
	node->_leftChild = leftChild;
	node->_rightChild = rightChild;
	return node;
}

Node::Node()
{
	_val = 0;
	_leftChild = 0;
	_rightChild = 0;
}

void Node::SetColor(COLOR val)
{
	if (val != BLACK || val != RED)
		return;

	_color = val;
}
