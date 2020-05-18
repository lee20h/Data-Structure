#include "pg4_BinaryTree.h"

class BinSrchTree : public BinaryTree
{
public:
	BinaryNode* search(char* key) { return searchRecur(root, key); }
	BinaryNode* searchRecur(BinaryNode *n, char* key) {
		if (n == NULL)return NULL;
		if (n->compare(key) == 0) return n;
		else if (n->compare(key) < 0)
			return searchRecur(n->getLeft(), key);
		else return searchRecur(n->getRight(), key);
	}

	void insert(BinaryNode* n) {
		if (n == NULL) return;
		if (isEmpty())root = n;
		else insertRecur(root, n);
	}
	void insertRecur(BinaryNode* r, BinaryNode* n) {
		if (n->compare(r) == 0) return;
		else if (n->compare(r) > 0) {
			if (r->getLeft() == NULL) r->setLeft(n);
			else insertRecur(r->getLeft(), n);
		}
		else {
			if (r->getRight() == NULL) r->setRight(n);
			else insertRecur(r->getRight(), n);
		}
	}

	void remove(char* data) {
		if (isEmpty()) return;
		BinaryNode* parent = NULL;
		BinaryNode* node = root;
		while (node != NULL && node->compare(data) != 0) {
			parent = node;
			node = (node->compare(data) < 0)
				? node -> getLeft() : node->getRight();
		}
		if (node != NULL) remove(parent, node);
	}

	void remove(BinaryNode *parent, BinaryNode *node) {
		if (node->isLeaf()) {
			if (parent == NULL)
				root = NULL;
			else {
				if (parent->getLeft() == node)
					parent->setLeft(NULL);
				else
					parent->setRight(NULL);
			}
		}
		else if (node->getLeft() == NULL || node->getRight() == NULL) {
			BinaryNode *child = (node->getLeft() != NULL)
				? node->getLeft() : node->getRight();
			if (node == root) root = child;
			else {
				if (parent->getLeft() == node)
					parent->setLeft(child);
				else
					parent->setRight(child);
			}
		}
		else {
			BinaryNode* succp = node;
			BinaryNode* succ = node->getRight();
			while (succ->getLeft() != NULL) {
				succp = succ;
				succ = succ->getLeft();
			}
			if (succp->getLeft() == succ)
				succp->setLeft(succ->getRight());
			else
				succp->setRight(succ->getRight());
			node = succ;
		}
		delete node;
	}
};
