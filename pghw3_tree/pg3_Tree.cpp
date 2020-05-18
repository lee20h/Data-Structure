//201610674 컴퓨터공학부 이영훈
#include "Pg3_Node.h"

class BinaryTree {
		BinaryNode* root;
	public :
		BinaryTree(): root(NULL) {	}
		void setRoot(BinaryNode* node) { root = node; }
		BinaryNode* getRoot() { return root; }
		bool isEmpty() { return root==NULL;	}
		int getCount () { return isEmpty() ? 0 : getCount(root); }
		int getCount (BinaryNode *node) {
			if (node == NULL) return 0;
			return 1 + getCount(node->getLeft()) + getCount(node->getRight());
		}
		int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
		int getLeafCount(BinaryNode *node) {
			if ( node == NULL ) return 0;
			if ( node -> isLeaf()) return 1;
			else return getLeafCount(node->getLeft()) + getCount(node->getRight());
		}
		int getHeight() { return isEmpty() ? 0 : getHeight(root); }
		int getHeight(BinaryNode *node) {
			if (node == NULL) return 0;
			int hLeft = getHeight(node->getLeft());
			int hRight = getHeight(node->getRight());
			return (hLeft>hRight) ? hLeft + 1 : hRight + 1;
		}
		bool isFull() {
			printf("isFull : ");
			bool chk = isFull(root);
			if (chk) printf("TRUE \n");
			else printf("FALSE \n");
			return chk;
		}
		bool isFull(BinaryNode* node) {
			if (node!=NULL) {
				if (node->getRight() != NULL) {
					if (node->getLeft() == NULL) return false;
					else return isFull( node->getLeft() ) && isFull( node->getRight() );
				}
				else return isFull(node->getLeft());
			}
			else return true;
		}
		int level(BinaryNode *node) {
    		return level(root, node);
        }
        int level(BinaryNode *node1, BinaryNode *node2, int lev = 1) {
	        if (node1 == NULL)
	            return 0;
	        if (node1 == node2)
	        	return lev;
	        if (node1->getLeft() == NULL && node1->getRight() == NULL)
	            return 0;
	        int left = level(node1->getLeft(), node2, lev + 1);
	        int right = level(node1->getRight(), node2, lev + 1);
	        if (!left)
	        	return right;
        	else
				return left;
        }
        bool isBalanced() {
        	bool chk = isBalanced(root);
        	printf("isBalanced : ");
        	if(chk)
        		printf("TRUE \n");
        	else
        		printf("FALSE \n");
            return chk;
        }
        bool isBalanced(BinaryNode *node) {
	        int leftHeight;
	        int rightHeight;
	    	if (node == NULL)
        		return true;
        	leftHeight = getHeight(node->getLeft());
        	rightHeight = getHeight(node->getRight());
            if ((leftHeight - rightHeight) <= 1 && (leftHeight - rightHeight) >= -1 && isBalanced(node->getLeft()) && isBalanced(node->getRight()))
                return true;
            return false;
        }
		bool reverse() {
			bool chk = reverse(root);
			if(chk) printf("Reverse! \n");
			else printf("node is null \n");
    		return chk;
    	}
		bool reverse(BinaryNode *node) {
               if (node == NULL)
                    return false;
               else {
                   reverse(node->getLeft());
                   reverse(node->getRight());
                   BinaryNode *temp = node->getLeft();
                   node->setLeft(node->getRight());
                   node->setRight(temp);
               }
               return true;
        }
};

int main() {
	BinaryTree tree;
	BinaryNode *d = new BinaryNode('D', NULL, NULL);
	BinaryNode *e = new BinaryNode('E', NULL, NULL);
	BinaryNode *b = new BinaryNode('B', d, e);
	BinaryNode *f = new BinaryNode('F', NULL, NULL);
	BinaryNode *c = new BinaryNode('C', f, NULL);
	BinaryNode *a = new BinaryNode('A', b, c);
	tree.setRoot(a);
	
	tree.isFull();
	printf("B node level : %d \n",tree.level(b));
	tree.isBalanced();
	tree.reverse();
	tree.isFull();
}


