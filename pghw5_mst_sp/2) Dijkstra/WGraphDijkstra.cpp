//201610674 컴퓨터공학부 이영훈 
#include "WGraphDijkstra.h"

int main() {
	WGraphDijkstra g;
	FILE *fp = fopen("graph_dijkstra.txt", "r");
	g.load(fp);
	g.ShortestPath(0);
	fclose(fp);
}
