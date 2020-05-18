//201610674 ��ǻ�Ͱ��к� �̿��� 
#include "MinHeap.h"
#include "WGraph.h"
#include "VertexSets.h"

class WGraphMST : public WGraph {
public :
	void Kruskal() {
		MinHeap heap;
		
		for (int i=0; i<size-1; i++)
		for (int j=i+1; j<size; j++)
			if(hasEdge(i,j))
				heap.insert(getEdge(i,j), i, j) ;
		VertexSets set(size);
		int edgeAccepted=0;
		while(edgeAccepted < size-1) {
			HeapNode e = heap.remove();
			int uset=set.findSet(e.getv1());
			int vset=set.findSet(e.getv2());
			if (uset!=vset) {
				printf("���� �߰� : %c - %c (��� : %d)\n", getVertex(e.getv1()), getVertex(e.getv2()),e.getKey());
				set.unionSets(uset, vset);
				edgeAccepted++;
			}
		}
	}
};
