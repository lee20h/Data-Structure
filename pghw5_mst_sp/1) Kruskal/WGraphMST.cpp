//201610674 ��ǻ�Ͱ��к� �̿��� 
#include "WGraphMST.h"

int main() {
	WGraphMST g;
	FILE* fp = fopen("graph.txt", "r");
	g.load(fp);
	g.Kruskal();
	fclose(fp);
}
