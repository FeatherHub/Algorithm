#include "Node.h"

Node* Node::Create(int val, Node* leftChild, Node* rightChild)
{
	Node* node = new Node();
	node->_val = val;
	node->_left = leftChild;
	node->_right = rightChild;
	return node;
}

Node::Node()
{
	_val = NULL;
	_left = NULL;
	_right = NULL;
	_parent = NULL;
	_color = BLACK;
}

void Node::SetColor(COLOR val)
{
	if (val != BLACK || val != RED)
		return;

	_color = val;
}