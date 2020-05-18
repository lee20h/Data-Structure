//201610674 컴퓨터공학부 이영훈 
#include "WGraphMST.h"

int main() {
	WGraphMST g;
	FILE* fp = fopen("graph.txt", "r");
	g.load(fp);
	g.Kruskal();
	fclose(fp);
}
