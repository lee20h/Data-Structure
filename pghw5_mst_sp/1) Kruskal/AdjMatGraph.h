//201610674 컴퓨터공학부 이영훈 
#include <cstdio>
#define MAX_VTX 256

class AdjMatGraph {
protected:
	int size;
	char vertices[MAX_VTX];
	int adj[MAX_VTX][MAX_VTX];
public:
	AdjMatGraph() { reset();}
	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size>=MAX_VTX;	}
	
	void reset() {
		size = 0;
		for (int i=0; i<MAX_VTX; i++)
		for (int j=0; j<MAX_VTX; j++)
			setEdge(i,j,0);
	}
	
	void insertVertex(char name) {
		if (!isFull()) vertices[size++] = name;
		else printf("Error: 그래프 정점 개수 초과 \n");
	}
	
	void insertEdge(int u, int v) {
		setEdge(u,v,1);
		setEdge(v,u,1);
	}
	
	void display(FILE *fp = stdout) {
		fprintf(fp, "%d\n", size);
		for (int i=0; i<size; i++) {
			fprintf(fp, "%c ", getVertex(i));
			for (int j=0; j<size; j++)
				fprintf(fp, " %3d", getEdge(i,j));
			fprintf(fp, "\n");
		}
	}
};
