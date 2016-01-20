#include "Node.h"

Node* Node::Create(int val, COLOR color, Node* leftChild, Node* rightChild, Node* parent)
{
	Node* node = new Node();
	node->_val = val;
	node->_color = color;
	node->_left = leftChild;
	node->_right = rightChild;
	node->_parent = parent;

	return node;
}

Node::Node()
{
	_val = NULL;
	_color = BLACK;
	_left = NULL;
	_right = NULL;
	_parent = NULL;
}

void Node::SetColor(COLOR val)
{
	if (val != BLACK || val != RED)
		return;

	_color = val;
}