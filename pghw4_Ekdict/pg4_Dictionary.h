#include "pg4_BinSrchTree.h"

class Dictionary : public BinSrchTree {
public:
	void printAllWords() {
		printf("    >> ���Ǵܾ���:\n");
		if (!isEmpty()) inorder(root);
	}
	void HanRecur(BinaryNode* node, Dictionary* Han) {
		if (node != NULL) {
			HanRecur(node->getLeft(), Han);
			Han->insert( new BinaryNode(node->getmeaning(), node->getword()));
			HanRecur(node->getRight(), Han);
		}
	}
	void CreateHan(Dictionary* Han) {
		if (Han->root!=NULL) Han->deleteRecur(Han->root);
		HanRecur(root, Han);
	}
	void deleteRecur(BinaryNode* node) {
			if (node != NULL) {
				deleteRecur(node->getLeft());
				deleteRecur(node->getRight());
				delete node;
		}
	}
	BinaryNode* searchWord(char *word) {
		BinaryNode *node = search(word);
		if (node != NULL) {
			printf("     >> ");
			node->display();
		}
		else {
			printf("     >> ��ϵ��� ���� �ܾ�: %s\n", word);
			return node;
		}
	}
};

