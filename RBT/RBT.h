#pragma once

class Node;

class RBT
{
public:
	static RBT* Create(Node* root);
	RBT();

	bool Insert(Node* toInsert);
	bool Delete(Node* toDelete);

	Node* GetRoot() const { return _root; }
	void SetRoot(Node* val);

	Node* NIL() const { return _NIL; }

	void PrintInOrder();

private:
	bool FixInsertion(Node* toFix);
	bool FixDeletion(Node* toFix);

	bool RightRotate(Node* toRR);
	bool LeftRotate(Node* toLR);

	bool Transplant(Node* toRemove, Node* toPlant);
	Node* GetSuccessorOf(Node* node);

	void _PrintInOrder(Node* node);

	Node* _root;
	Node* _NIL;
};