#ifndef _CONFIG_H_
#define _CONFIG_H_
#include "Config.h"
#endif

class Node
{
public:
	static Node* Create(int val = 0, Node* leftChild = 0, Node* rightChild = 0);
	Node();

	int GetVal() const { return _val; }
	void SetVal(int val) { _val = val; }

	Node* GetLeftChild() const { return _leftChild; }
	void SetLeftChild(Node* val) { _leftChild = val; }

	Node* GetRightChild() const { return _rightChild; }
	void SetRightChild(Node* val) { _rightChild = val; }

	COLOR GetColor() const { return _color; }
	void SetColor(COLOR val);

private:
	int _val;
	Node* _leftChild;
	Node* _rightChild;
	COLOR _color;
};
