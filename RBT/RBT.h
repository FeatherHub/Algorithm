class Node;

class RBT
{
public:
	static RBT* Create(Node* root);
	RBT();

	bool Insert(Node* toInsert);
	bool Delete(Node* toDelete);
	bool Search(Node* toSearch);

	Node* GetRoot() const { return _root; }
	void SetRoot(Node* val);

private:
	void RightRotate(Node* toRR);
	void LeftRotate(Node* toLR);
	void FixInsertion(Node* toFix);
	void FixDeletion(Node* toFix);
	void Transplant(Node* toRemove, Node* toPlant);

	Node* _root;
};