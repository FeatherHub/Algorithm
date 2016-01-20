#pragma once

#include "Config.h"

class Node
{
public:
	static Node* Create(
		int val = 0, 
		COLOR color = BLACK, 
		Node* leftChild = NULL, 
		Node* rightChild = NULL, 
		Node* parent = NULL);

	Node();

	int GetVal() const { return _val; }
	void SetVal(int val) { _val = val; }

	Node* GetLeft() const { return _left; }
	void SetLeft(Node* val) { _left = val; }

	Node* GetRight() const { return _right; }
	void SetRight(Node* val) { _right = val; }

	Node* GetParent() const { return _parent; }
	void SetParent(Node* val) { _parent = val; }

	COLOR GetColor() const { return _color; }
	void SetColor(COLOR val);

private:
	int _val;
	Node* _left;
	Node* _right;
	Node* _parent;
	COLOR _color;
};
