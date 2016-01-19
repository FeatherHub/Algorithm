#include "Node.h"

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
