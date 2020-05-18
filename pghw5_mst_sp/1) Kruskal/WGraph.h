//201610674 컴퓨터공학부 이영훈 
#include "AdjMatGraph.h"
#define INF 9999

class WGraph : public AdjMatGraph {
public :
	void insertEdge(int u, int v, int weight) {
		if (weight > INF) weight = INF;
		setEdge(u,v,weight);
	}
	bool hasEdge(int i, int j) { return (getEdge(i,j)<INF);	}
	void load(FILE *fp) {
		if(fp != NULL) {
			int n, val;
			fscanf(fp, "%d", &n);
			for (int i=0; i<n; i++) {
				char str[80];
				int val;
				fscanf(fp, "%s", str);
				insertVertex(str[0]);
				for(int j=0; j<n; j++) {
					fscanf(fp, "%d", &val);
					insertEdge(i,j,val);
				}
			}
		}
	}
};
