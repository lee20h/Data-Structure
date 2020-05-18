//201610674 컴퓨터공학부 이영훈 
#include <cstdio>
#include "LinkedQueue.h"



const int MAZE_SIZE=6;
char map[MAZE_SIZE][MAZE_SIZE];

bool isValidLoc (int r, int c) {
	if (r<0 || c<0 || r>=MAZE_SIZE || c>=MAZE_SIZE)
		return false;
	else
		return map[r][c] == '0' || map[r][c] == 'x';
}

int main() {
	char c;
	int row=0, col=0;
	FILE *fp = fopen("map.txt", "r");
	if(fp==NULL) {
		printf("파일이 없습니다.");
		return 0;
	}
		while ((c = getc(fp)) != EOF) {
			if (c=='\n')
				continue;
			map[col][row++] = c;
			if (row==MAZE_SIZE) {
				col++;
				row=0;
			}
		}
	LinkedQueue queue;
	queue.enqueue(new Node(1,0));
	while(queue.isEmpty() == false) {
		Node *here = queue.peek();
		int r = here->rerow();
		int c = here->recol();
		queue.dequeue();

		printf("(%d,%d)", r, c);
		if (map[r][c] == 'x') {
			printf("\n미로 탐색 성공\n");
			return 0;
		}
		else {
			map[r][c] ='.';
			if (isValidLoc(r-1,c)) queue.enqueue(new Node(r-1,c));
			if (isValidLoc(r+1,c)) queue.enqueue(new Node(r+1,c));
			if (isValidLoc(r,c-1)) queue.enqueue(new Node(r,c-1));
			if (isValidLoc(r,c+1)) queue.enqueue(new Node(r,c+1));
		}
	}
	printf("미로 탐색 실패");
}
