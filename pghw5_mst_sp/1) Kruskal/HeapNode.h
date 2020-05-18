//201610674 컴퓨터공학부 이영훈 
#include <cstdio>

class HeapNode {
		int key;
		int v1;
		int v2;
public :
		HeapNode(int k, int u, int v) : key(k), v1(u), v2(v) {		}
		HeapNode() {		}
		void setKey(int k) { key= k; }
		void setKey(int k, int u, int v) {
			key = k;
			v1 = u;
			v2 = v;
		}
		int getKey() { return key; }
		int getv1() { return v1; }
		int getv2() { return v2; }
		
}; 
