//201610674 ��ǻ�Ͱ��к� �̿���
#include <cstdio>


class Node{
	Node* link;
	int r,c;
public:
	Node(int row, int col): r(row),c(col), link(NULL) {	}
	Node* getLink() {return link;}
	void setLink(Node* next) {link=next;}
	void display() {printf("<%2d,%2d>",r,c);}
	int rerow() {return r;}
	int recol() {return c;}
};
