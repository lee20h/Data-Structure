//201610674 ��ǻ�Ͱ��к� �̿��� 
#include "WGraphDijkstra.h"

int main() {
	WGraphDijkstra g;
	FILE *fp = fopen("graph_dijkstra.txt", "r");
	g.load(fp);
	g.ShortestPath(0);
	fclose(fp);
}
