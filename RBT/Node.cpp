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
	_val = 0;
	_color = RED;
	_left = RBT::NIL;
	_right = RBT::NIL;
	_parent = RBT::NIL;
}

void Node::SetColor(COLOR val)
{
	if (val != BLACK || val != RED)
		return;

	_color = val;
}