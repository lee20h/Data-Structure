//201610674 ��ǻ�Ͱ��к� �̿��� 
class VertexSets {
	int parent[1000];
	int nSets;
public :
	VertexSets (int n) : nSets(n) {
		for (int i=0; i<nSets; i++) {
			parent[i] = -1;
		}
	}
	bool isRoot(int i) { return parent[i] < 0; }
	int findSet(int v) {
		while(!isRoot(v)) v = parent[v];
		return v;
	}
	void unionSets(int s1, int s2) {
		parent[s1] = s2;
		nSets--;
	}
};
