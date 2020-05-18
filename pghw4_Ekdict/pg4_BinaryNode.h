#include <cstdio>
#include "pg4_Record.h"
class BinaryNode :public Record
{
protected:
	BinaryNode* left;
	BinaryNode* right;
public:
	BinaryNode(const char* w="", const char* m="")
		:Record(w,m), left(NULL), right(NULL) {}
	void setLeft(BinaryNode *l) { left = l; }
	void setRight(BinaryNode *r) { right = r; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
	bool isLeaf() { return left == NULL && right == NULL; }
};
